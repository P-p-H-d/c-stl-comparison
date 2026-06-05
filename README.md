# Introduction

The goal of this project is to compare several generic container C libraries
that provide some STL like capabilities of the C++ (container template) but are targeting classic C language.

The Standard Template Library [STL](https://en.wikipedia.org/wiki/Standard_Template_Library) was a software library for the C++ programming language that influenced many parts of the C++ Standard Library. It provided a set of container classes for C++ that can be used with any type. Now the parts of the C++ Standard Library directly influenced/inherited from this STL are what are commonly called "the STL".

So, a STL like library for the C is a C library providing several classic generic containers for the C language,
like vector, list, sorted set, unordered_map, and so on.

To do this, the same simple programs are implemented by the libraries
in the more straight-forward way possible,
for different kind of containers and for different types.
Then the API ergonomics of each programs can be compared each other according to the user taste.

A benchmark to compare their performance is included in the bench directory.

Objective characteristics of the libraries are directly compared in this file.

But first, let's see how we can implement generic code in C.


# Implementing generic code in C

One of the main issue in the C language is how to write generic code, i.e. code that works the same for different kind of objects:
you write once, and it works for several types.
A kind of equivalent of the templates of the C++.

There are several ways of doing so:

## voidp: Everything is a pointer to void.

Each object is handled through a pointer to void. The container store only pointers to these objects.
Potentially, it may also register some callback functions to handle the contained objects for the needed specialized methods (copy, drop, ...). 
From a user point of view, this makes the code harder to use and to debug (as you don't have any help from the compiler) and type unsafe since a lot of cast is needed to handle it (so no formal proof of the code is usually possible). 
This also generally generate slower code (due to the multiple reduction, indirect callback, increase memory usage and cache miss) even if using link time optimization and full inline functions could reduce this a little (with inlining and LTO, some callback overhead can be reduced but it is really dependent on the compilers and will increase your compilation time).
Properly used, it can yet be the most space efficient for the code, but can consume more for the data due to the obligation of using pointers (depending on your use case). 
This is however the easiest to design & code.

Pros:

* easy to develop,
* reduced code.

Cons:

* slow code,
* data memory usage,
* hard to debug for user,
* type unsafe.

> Note: See synthesis for mixing macros with typed handles and void * elements and creating hybrid solutions.

## macro: Everything is a macro

Macros are expanded in the user code and used to access structures in a generic way (using known named fields of a structure — typically size, capacity, etc.). The macro is fully always expanded in the user code. From a user point of view, this can create subtle bugs in the use of the library (as everything is done through macro expansion in the user defined code) and hard to understand warnings. This can be mitigated using proper macros expansion and type checking, but it increases the complexity of the solution. This can generates fully efficient code. From a library developer point of view, this can be quite limiting in what you can offer.

This technique can also enforce the type consistency by encoding the type in the macro name or by using typeof/_Generic internally to check for the right types.

A key macro pitfall is evaluating arguments multiple times, and a good library should prevent misuse of this if possible.

Pros:

* fast to develop,
* efficient code.

Cons:

* potentially type unsafe,
* error prone,
* macro Side-effect,
* can have cryptic error message if usage is incorrect
* can have incorrect code usage without any error message if usage is incorrect

>Note: Not to be confused with Template macros.

## OO-style object

The objects inherited from all the same base object. The base object has a virtual table that provides the callbacks to all the methods needed to handle such object.
The generic code is a simple classic C code that handles only the base object: therefore it uses the provided callback in its vtable to handle the object for any operation.
This is an alternative to everything is a void pointer.

Indirect calls are usually slower even if modern CPUs and branch prediction often make this cost modest (the overhead may still be negligible).

It can be a good fit for a specialized API with only custom types and custom algorithms that don't need a lot of speed.

Pros:

* reduce code size
* support different kind of objects in the same container

Cons:

* data memory usage
* slow code
* new operation requires rework of vtable
* complex development

## Generic objects

Another alternative is encapsulating the methods in macros that detect the type of the argument passed as parameter using _Generics, before calling the associated method according to the given type. 

The C standard mandates to have valid C expressions in all cases of the _Generic. This is not a problem for very simple use of _Generic (such as the examples provided in the standard to return a different function depending on the types). But more advanced uses cannot be implemented so simply: they need to generate complex expression. Therefore, such library usually uses a double _Generic switch to overcome this limitation (increasing the number of used _Generic a lot and making code more awkward). There is discussion to remove this limitation in future C standards.

The difficulty is how to add pure user types in this generic switch (possible, just awkward and it needs high C skill level to do it).

Using this technique means using a lot of _Generic in the code. Real examples of it show notable slower compilation. Maybe it is due to compiler naive implementation of _Generic?

It is usually not used alone but with other technics (like void pointer or container instantiations) in order to create an hybrid approach.

As they need to hide the _Generic in a macro, they are subject to the key macro pitfall in evaluating arguments multiple times (a good library should prevent misuse of this if possible).

Pros:

* uniform interface provided to the user.

Cons:

* macro Side-effect shall be protected,
* support of custom user types is difficult.
* potential slow compilation

## Intrusive container

A known structure is put in an intrusive way in the type of all the objects you wan to handle. From a user point of view, he needs to modify its structure and has to perform all the allocation & deallocation code itself (which is good or bad depending on the context). This can generate efficient code (both in speed and size). From a library developer point of view, this is easy to design & code. You need internally a cast to go from a pointer to the known structure to the pointed object (a reverse of offsetof) that is generally type unsafe (except if mixed with the macro generating concept). 

This is quite limited in what you can do: you usually don't want to move your objects so any container that has to move some objects is not a good fit (which means that you cannot use the most efficient container). Indeed You can move intrusive objects if you update or rebuild the intrusive links appropriately, but it will be awkward and impact performance.

Intrusive containers are a good fit when object lifetime is managed externally (e.g., kernel structures) as all allocations are usually let to the user.
They are also a good fit when the same object can be within several containers.

Pros:

* reduce code size
* efficient code
* external object lifetime

Cons:

* data memory usage
* limited scope of the containers

## Template header

Header files are included multiple times with different macro contexts (which act as arguments of the header) in order to generate different code for each type. 

From a user point of view, this creates a new step before using the container: an instantiating stage that has to be done once per type and per compilation unit (The user is responsible to create only one instance of the container, which can be troublesome if the library doesn't handle proper prefix for its naming convention). This instantiating stage generates the functions handling the container with the correct type, ensuring type safety and control by the compiler. 

This instantiating stage can generate only the external interface (extern declaration), the implementation or inline implementation in function of what the user requests (reducing code bloat for containers which are heavily used so that only one instance exists in the whole program).

The debug of the library is generally reasonable.
It can generate fully specialized & efficient code. 
Incorrectly used, this can generate a lot of code bloat. Properly used, this can even create smaller code than the void pointer variant. 
The interface used to configure the library can be quite tiresome in case of a lot of specialized methods for configuring the used user type: it doesn't enable to chain the configuration from a container to another one easily.

The user code is a little bit more verbose as it uses specialized function names, and not generic ones.

Pros:

* specialized & efficient code
* type safe
* easy to use for user
* reasonable to develop and understand

Cons:

* Explicit instance needed
* can generate code bloat if incorrectly used
* can have cryptic error message at **instantiation** stage if incorrectly used
* method names are more verbose
* unnatural usage of headers.

## Template macros

Macros are used to generate context-dependent C code enabling to generate code for different type. This is pretty much like the template headers solution but with added flexibility. 
From a user point of view, this creates a new step before using the container: an instantiating stage that has to be done once per type and per compilation unit (The user is responsible to create only one instance of the container, which can be troublesome if the library doesn't handle proper prefix for its naming convention). 

This can generate fully specialized & efficient code with the correct type ensuring type safety and control by the compiler. Incorrectly used, this can generate a lot of code bloat. Properly used, this can even create smaller code than the void pointer variant. 

This instantiating stage can generate only the external interface (extern declaration), the implementation or inline implementation in function of what the user requests (reducing code bloat for containers which are heavily used so that only one instance exists in the whole program).

From a library developer point of view, the library is harder to debug: everything being expanded in one line, you can't step in the library (there is however a solution to overcome this limitation by adding another stage to the compilation process: generating the preprocessed file (-E), cleaning it of the lines directives, and recompiling this file). But this should not impact the user if the library is properly maintained.

This can also generates cryptic error messages at user level if incorrectly used when creating an instance. You can however see the generated code by looking at the preprocessed file.

You can perform heavy context-dependent customization of the code (transforming the macro preprocessing step into its own language): you can generate a variable number of methods depending on the given arguments of your instantiation, which is not possible easily with any other methods.
Also, Properly done, you can also chain the methods from a container to another one easily, enabling quick and easy expansion of the containers. 
Errors in user code are easy to read and natural. Code usage is a little bit more verbose as it uses specialized function names, and not generic ones.

Template macros are not subject to the key macro pitfall of evaluating arguments multiple times.

>Note: not to be confused with usage of Macro for meta-programming. Template Macros are much closer to Template Headers.

>Note: Some people reported "issue" of the template macros with their look due to the use of backslash at the end of the lines however it is due to their coding practices (you need to align backslash at the same column). Another one of the reported "issue" is the lack of support of syntax highlighting and autocomplete in macros but... it was more an issue in their used text editor.

Pros:

* specialized & efficient code
* type safe
* easy to use for user
* maximum flexibility in code generation

Cons:

* Explicit instance needed
* can generate code bloat if incorrectly used
* little harder to debug for the **library** developer
* can have cryptic error message at **instantiation** stage if incorrectly used
* method names are verbose

## Synthesis

Even if a container is usually slow, it may be a good fit for your use case. There is no universal answer.

Some hybrid patterns of the previous solutions (e.g., _Generic + templates, opaque wrappers around void *)
can also be chosen for a specific usage, in order to mitigate the Cons of both solution,
increasing their added value.

For example, a common pattern is to define the public API using some types (e.g., struct my_vec *), but internally performs some cast to void * to use functions on void pointers. This gives better ergonomics and some type safety at the container level, even if element type is ultimately erased.

In practice, Template headers are often the best compromise between ease of development and what is possible with it. Template macros are a little bit harder to develop but increases the generation possibility. void pointer solutions are often the one that generate the smaller code but at the cost of performance and harder debug at user level.


# C libraries Selection

The following C libraries have been selected as their aim is to provide generic containers to the C language:

* [C-Macro-Collections](https://github.com/LeoVen/C-Macro-Collections)
* [CC](https://github.com/JacksonAllan/CC.git)
* [ccc](https://github.com/SkeletOSS/ccc.git)
* [COLLECTIONS-C](https://github.com/srdja/Collections-C)
* CTL [by glouw](https://github.com/glouw/ctl) or [by rurban](https://github.com/rurban/ctl)
* [GLIB](https://docs.gtk.org/glib/index.html)
* [KLIB](https://github.com/attractivechaos/klib)
* [M\*LIB](https://github.com/P-p-H-d/mlib)
* [STB_DS](https://github.com/nothings/stb)
* [STC - Smart Template Container for C](https://github.com/tylov/STC)

with C++ STL used as the reference baseline.

The used versions for the manual feature comparison are:

COMPONENT      | VERSION
---------------|-----------------------------------------
C Macro Collections | v0.23.1
CC             | 2012d9d2eb8f035d7dc69f36ec03ca3199ede1bf
ccc            | 22f8c17e863d52cad120dc9dfedbd0452f8625a9
CollectionsC   | ff1be366329e2c82cd85b2c803114ef8d2115f7f
CTL            | 3923e6776a231e5d58cf91225ca8a1d61879401b
GLIB           | 2.74
KLIB           | 97a0fcb790b43b9e5da8994f4671021fec036f19
M\*LIB         | a0818419ab959e05517336e1bea699c1854b29f3
STB_DS         | 904aa67e1e2d1dec92959df63e700b166d5c1022
STC            | 5fb5ed08250b5ad4eadd6e7a9fdc44f4519b15ff

CI uses more up-to-date versions of theses libraries for the performance comparisons (See this section for details).

More specialized C libraries which provides only one kind of container are not included in this chapter.
sglib is not included due to being abandoned.


# Feature Comparison

## Analysis

The following characteristics are compared. The C++ STL is also included as reference.
For a container of such library that encapsulates a collection of objects of basic type, the following criterions are analyzed:

* What is the license?
* What is the supported C language? (C89, C99, C11 or C23, with or without extension)
* Is it a pure C program? (no need for external preprocessor)
* Is it Header only?
* How is implemented the Generic mechanism? By using  (VP) void pointer, (M) macro, (OO) Object Oriented, (GO) Generic objects, (IF) intrusive field, (TH) template header, (TM) template macro
* Is it type safe (aka. using an incompatible type produces at least a compilation warning)?
* Does it support of integer/floats as basic type?
* Does it support of struct POD data as basic type?
* Does it support of array as basic type?
* Does it support of object like data (needing custom constructor, copy, destructor...) as basic type?
* Does it support of C++ class as basic type?
* Does it support of Assignment semantics? (container uses the C Assignment operators to set object in them)
* Does it support of Deep Copy semantics? (container creates a proper copy of the object data as per the object semantic: if there is pointer in the structure, it performs a proper copy of the pointed objects)
* Does it support of move semantics? (container steals the ownership of the object given as parameter as per the object semantic, rendering the original object in a destroyed or nearly destroyed state)
* Can the container and its basic type be defined fully separately in the source code? (spatial separation: the association of the methods of the basic type to the needed operators of the container library can be defined when the basic type is defined -ensuring spatial coherency of the basic type- and not only when the container is defined)
* Does it support of an adaptation layer? (a way to transform the interface of the provided method of the basic type to the expected interface of the operator of the container without writing explicitly a wrapper) 
* Does it support of basic 'emplace'? (Being able to construct an item directly within the container by givng one argument to this constructor)
* Does it support of multiple, enhanced 'emplace' based on the initialized arguments?
* Does it support of iterator abstraction?
* Does it support of sort algorithm?
* Does it support of sort algorithm with custom comparison?
* Does it support of single definition for the whole program? (use of declaration only for all files except one that includes the container definition)
* Does it support of full abstraction of the container type? (user should not access internal fields of structures)
* Does it support of contract violation checks? (assertions on invalid inputs, on input contract violation or error reporting)
* Does it support of natural usage of array? (using of Array subscripting on the container)
* Is the basic type stored in the container, not a pointer to it?
* Does it need an explicit instantiation of the container with the basic type before its usage?
* Are the functions properly prefixed?
* How are the memory errors handled? (return code, exception, abort, none)
* Are destructors of objects on stack properly called on exception?
* Does it support custom memory functions?
* Does it support optional per-container context for custom memory functions?
* Does it support of forward declaration of container?
* Does it support of serialization? (JSON, XML, YAML)

## Synthesis

| Characteristics   | CC     | CCC    | CMC   | CollecC | CTL   | GLIB    | KLIB  | M*LIB | STB_DS | STC   | STL      |
|-------------------|--------|--------|-------|---------|-------|---------|-------|-------|--------|-------|----------|
| License           | MIT    | Apache | MIT   | LGPL3   | MIT   | LGPL2.1 | MIT   | BSD2  | MIT    | MIT   | NA       |
| C language        | >=C11* | >=C23  | >=C99 | >=C99   | >=C99 | >=C89   | >=C99 | >=C99 | >=C99* | >=C99 | NA       |
| Pure C            | Y      | Y      | Y     | Y       | Y     | Y       | Y     | Y     | Y      | Y     | NA       |
| Header only       | Y      | N      | Y     | N       | Y     | N       | Y     | Y     | Y      | Y*    | Y        |
| Generic mechanism | M+GO   | VP     | TM    | VP      | TH    | VP      | TM    | TM    | M      | TH    | template |
| type safe         | Y*     | N      | Y     | N       | Y     | N       | Y     | Y     | N*     | Y     | Y        |

| Characteristics       | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-----------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| integer/float support | Y  | Y   | Y   | Y*      | Y   | Y*   | Y    | Y     | Y      | Y   | Y   |
| struct POD support    | Y  | Y   | Y   | Y*      | Y   | Y*   | Y    | Y     | Y      | Y   | Y   |
| array support         | N  | Y   | N   | Y*      | N   | Y*   | N    | Y     | N      | N   | Y   |
| C object support      | Y  | Y   | Y   | Y*      | Y   | Y*   | Y    | Y     | N      | Y   | Y   |
| C++ class support     | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |

| Characteristics          | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|--------------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| Assignment semantics     | Y  | Y   | Y   | Y       | Y   | Y    | Y    | Y     | Y      | Y   | Y   |
| Deep Copy semantics      | N  | Y*  | N   | Y       | Y*  | Y    | N    | Y     | N      | Y*  | Y   |
| Move semantics           | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| spatial separation       | Y  | NA  | N   | NA      | N   | NA   | N    | Y     | N      | N   | Y   |
| Adaptor Layer            | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Basic emplace support    | N  | N   | N   | N       | N   | N    | N    | Y     | N      | Y   | Y   |
| Enhanced emplace support | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| Iterator support         | Y  | Y   | N   | Y       | Y   | N    | Y    | Y     | N      | Y   | Y   |
| Sort algorithm           | N  | Y   | N   | Y       | Y   | Y    | Y    | Y     | N      | Y   | Y   |
| Enhanced Sort algorithm  | N  | Y   | N   | Y       | Y   | Y    | N    | Y     | N      | Y   | Y   |

| Characteristics           | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|---------------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| single linkage definition | N  | Y   | Y   | Y       | N   | Y    | N    | Y     | Y      | Y   | N*  |
| Full abstraction          | Y  | N   | Y   | Y       | N   | N    | Y    | Y     | Y      | N   | Y   |
| Contract violation checks | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| Natural usage             | N  | N   | N   | N       | N   | N    | N    | N     | Y      | N   | Y   |
| Basic type is stored      | Y  | Y?  | Y   | N       | Y   | N    | Y    | Y     | Y      | Y   | Y   |
| Explicit instantiation    | N  | N   | Y   | N       | Y   | N    | Y    | Y     | N      | Y   | N   |
| prefixed function         | Y  | Y   | Y   | Y       | Y   | Y    | Y    | Y     | Y      | Y   | Y   |

| Characteristics             | CC      | CCC     | CMC     | CollecC | CTL  | GLIB    | KLIB    | M*LIB         | STB_DS | STC     | STL    |
|-----------------------------|---------|---------|---------|---------|------|---------|---------|---------------|--------|---------|--------|
| memory error handling       | retcode | retcode | retcode | retcode | none | retcode | retcode | abort, except | none   | retcode | except |
| destructors on exception    | N       | N       | N       | N       | N    | N       | N       | Y*            | N      | N       | Y      |
| custom memory support       | Y       | Y       | Y       | Y       | N    | N       | Y       | Y             | Y      | Y       | Y      |
| context for memory support  | N       | Y       | N       | N       | N    | N       | N       | Y             | Y      | Y       | N      |
| Forward declaration support | N       | N       | N       | N       | N    | N       | N       | Y*            | N      | Y       | N      |
| Serialization               | N       | N       | N       | N       | N    | N       | N       | JSON          | N      | N       | N      |

* C11*: means C11 + typeof extension
* C99*: means C99 + typeof extension
* Y*: Yes with some limitations.
* N*: even it appears to be type safe, it is not and it is easy to misuse it.
* NA: the question has no meaning for this library.

This information is also available as a [JSON file](lib-features.json) with more precision.

| Containers                                    | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-----------------------------------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| Singly Linked Non-Intrusive list              | N  | Y   | N   | Y       | Y   | Y    | Y    | Y     | N      | N   | Y   |
| Doubly Linked Non-Intrusive list              | Y  | N   | N   | Y       | Y   | Y    | N    | N     | N      | N   | Y   |
| Singly Linked, Dually Push Non-Intrusive list | N  | N   | N   | N       | N   | N    | N    | Y     | N      | Y   | N   |
| Singly Linked Intrusive list                  | N  | Y   | N   | N       | N   | N    | N    | N     | N      | N   | N   |
| Doubly Linked Intrusive list                  | N  | Y   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Dynamic array                                 | Y  | Y   | Y   | Y       | Y   | Y    | Y    | Y     | Y      | Y   | Y   |
| Static array                                  | N  | Y   | N   | N       | Y   | N    | N    | N     | N      | N   | Y   |

| Containers               | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|--------------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| pair                     | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| tuple                    | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| optional                 | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| variant                  | N  | N   | N   | N       | N   | Y    | N    | Y     | N      | N   | Y   |
| bitset                   | N  | Y   | Y   | N       | N   | N    | N    | Y     | N      | Y   | Y   |
| Dynamic character string | N  | N   | N   | N       | Y   | Y    | Y    | Y     | N      | Y   | Y   |
| string_view              | N  | N   | N   | N       | N   | N    | N    | N     | N      | Y   | Y   |
| deque                    | N  | Y   | Y   | Y       | Y   | Y    | N    | Y     | N      | Y   | Y   |
| queue                    | N  | N   | Y   | Y       | Y   | Y    | N    | Y     | N      | Y   | Y   |
| priority queue           | N  | Y   | Y   | Y       | Y   | N    | N    | Y     | N      | Y   | Y   |
| stack                    | N  | N   | N   | Y       | Y   | N    | N    | Y     | N      | Y   | Y   |
| Bounded Queue            | N  | Y   | N   | N       | N   | Y    | N    | Y     | N      | N   | N   |

| Containers         | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|--------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| set                | N  | Y   | N   | Y       | N   | Y    | Y    | Y     | N      | Y   | Y   |
| multiset           | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| map                | N  | N   | N   | Y       | Y   | N    | Y    | Y     | N      | N   | Y   |
| multimap           | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| unordered_set      | Y  | Y   | Y   | Y       | Y   | N    | Y    | Y     | Y      | Y   | Y   |
| unordered_multiset | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | Y   |
| unordered_map      | Y  | N   | Y   | Y       | Y   | N    | Y    | Y     | Y      | Y   | Y   |
| unordered_multimap | N  | N   | Y   | N       | N   | Y    | N    | N     | N      | N   | Y   |
| flat_set           | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | Y   |
| flat_multiset      | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | Y   |
| flat_map           | N  | Y   | Y   | N       | N   | N    | N    | N     | N      | N   | Y   |
| flat_multimap      | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | Y   |

| Containers          | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|---------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| unique_ptr          | N  | N   | N   | N       | N   | N    | N    | N     | N      | Y   | Y   |
| shared_ptr          | N  | N   | N   | N       | N   | N    | N    | Y     | N      | Y   | Y   |
| advanced shared_ptr | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| weak_ptr            | N  | N   | N   | N       | N   | N    | N    | N     | N      | N   | Y   |
| Function Object     | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | Y   |
| Span                | N  | N   | N   | N       | N   | N    | N    | N     | N      | Y   | Y   |
| MDSpan              | N  | N   | N   | N       | N   | N    | N    | N     | N      | Y   | Y   |
| Bounded String      | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |

| Containers                  | CC | CCC | CMC | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-----------------------------|----|-----|-----|---------|-----|------|------|-------|--------|-----|-----|
| Atomic Shared Register SPSC | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Atomic Shared Register MPSC | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Atomic Shared Register SPMC | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Atomic Shared Register MPMC | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |
| Skip List                   | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | N   |
| Sorted Bidirectional Map    | N  | N   | Y   | N       | N   | N    | N    | N     | N      | N   | N   |
| Tree                        | N  | N   | N   | N       | N   | N    | N    | Y     | N      | N   | N   |


This information is also available as a [JSON file](lib-containers.json).

| Maintenance                                         | CC          | CCC        | CMC         | CollecC     | CTL         | GLIB        | KLIB        | M*LIB      | STB_DS      | STC        |
|-----------------------------------------------------|-------------|------------|-------------|-------------|-------------|-------------|-------------|------------|-------------|------------|
| Number of stars                                     | 460         | 20         | 597         | 2995        | 287         | 1733        | 4667        | 1115       | 33730       | 1901       |
| Last commit age                                     | 326.56 days | 1.58 days  | 696.64 days | 11.88 days  | 102.97 days | 2.52 days   | 153.31 days | 4.56 days  | 38.63 days  | 11.00 days |
| Number of commits                                   | 350         | 2056       | 517         | 664         | 943         | 33024       | 398         | 3940       | 2230        | 3321       |
| How old is the project?                             | 3.48 years  | 2.35 years | 7.17 years  | 11.77 years | 5.66 years  | 27.95 years | 15.36 years | 9.26 years | 12.00 years | 6.22 years |
| Last release date                                   | 2025-07-01  | 2026-05-22 | NA          | NA          | 2021-02-22  | NA          | NA          | 2025-05-12 | NA          | 2025-01-12 |
| Number of release per year                          | 4.89        | 63.94      | 0           | 0           | 0.35        | 0           | 0           | 1.51       | 0           | 2.09       |
| Percent of open issues / total (open+closed) issues | 30.00%      | NA         | 69.44%      | 22.22%      | 53.85%      | NA          | 46.67%      | 0.00%      | 24.41%      | 5.38%      |
| Average Time to answer an issue                     | 47.36 h     | NA         | 1632.95 h   | 857.47 h    | 15839.79 h  | NA          | 886.20 h    | 21.52 h    | 85.91 h     | 1044.45 h  |
| Number of main authors                              | 1           | 1          | 1           | 3           | 2           | 2           | 3           | 1          | 2           | 1          |
| Number of OS supported by CI                        | 1           | 3          | 1           | 3           | 4           | 0           | 0           | 4          | 1           | 4          |
| Number of hardware architecture supported by CI     | 1           | 3          | 1           | 1           | 1           | 0           | 0           | 6          | 1           | 1          |
| Number of compilers supported by CI                 | 1           | 2          | 1           | 3           | 3           | 0           | 0           | 4          | 0           | 3          |


This information is also available as a [JSON file](lib-maintenance.json).

If you see any mistakes in this report,
or want to include another C library,
or want to include another point of comparison,
do not hesitate to open a pull request.


# Ergonomic comparison

## Rules

The test programs shall respect the following conditions:

* it shall use a basic type (int), a non POD type (the type mpz\_t of the GMP library) and a string as the primary type of the container.
* if a dynamic string container exists in the container library, it shall be used instead of a C string,
* it shall not comment the code (the code is assumed to be clear on what it does by itself) except if there is some workaround,
* it shall not produce any compilation warnings,
* it shall execute properly,
* it shall not leak any memory,
* it shall abort on error,
* it shall link dynamically with the GMP library (https://gmplib.org/) if needed,
* it shall link statically with the container library if needed,
* the optional assertions shall be turned off.

A workaround is defined as a way to implement this program which is **not natural** for the library. This typically includes:

* create wrapper structure,
* create wrapper functions or macros,
* accessing internal fields of the containers (typically for using the qsort function).

For example, if a container library manual requests to define some macro for its use, then it won't be considered as a workaround. Workarounds are allowed but are counted separately.

## Array tests

The program shall perform the following operations:

* declare a dynamic array of int (resp. mpz_t, a string),
* initialize this array with the small unsigned integers values 17, 42 and 9 (performing a conversion from unsigned integer to mpz_t for GMP) or the constant strings "Hello", "World" and "!" for strings,
* sort this array,
* iterate the array to print the values.

## Associative array tests

The program shall perform the following operations:

* declare a non-ordered associative array from int (resp. mpz_t, a string) to int (resp. mpz_t, a string),
* initialize this array with the association of signed integers values 17 to 4585, 42 to 4856 and -9 to 1452 (performing a conversion from signed integer to mpz_t for GMP) or the strings "Hello" to "LIB", "Welcome" to "Program" and "Sincerely" to "Your map" for strings,
* search for the key "Hello" and display it if successful,
* iterate the associative array to print the values.

## Execution

The different programs are available in this repository.
To build them, you just need to have
a working C11 compiler, a make tool, git,
the GMP library, and the GLIB library.

Simply run "make" to perform clones of the C libraries
and generate the different executables.

## Conclusion

What can be objectively compared is the size of the programs:

| Array-Int programs      | CC  | CCC  | CMC  | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-------------------------|-----|------|------|---------|-----|------|------|-------|--------|-----|-----|
| number of characters    | 611 | 1395 | 1011 | 885     | 593 | 696  | 783  | 373   | 817    | 558 | 236 |
| number of line of codes | 34  | 55   | 46   | 46      | 25  | 38   | 28   | 18    | 43     | 34  | 13  |
| number of workarounds   | 0   | 0    | 2    | 2       | 2   | 0    | 2    | 0     | 1      | 0   | 0   |

| Array-Str programs      | CC  | CCC  | CMC  | CollecC | CTL | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-------------------------|-----|------|------|---------|-----|------|------|-------|--------|-----|-----|
| number of characters    | 651 | 1478 | 1053 | 839     | 762 | 908  | 1497 | 442   | 881    | 564 | 274 |
| number of line of codes | 33  | 54   | 45   | 47      | 29  | 44   | 55   | 19    | 45     | 36  | 14  |
| number of workarounds   | 0   | 0    | 2    | 1       | 3   | 0    | 3    | 0     | 1      | 0   | 0   |

| Array-mpz programs      | CC   | CCC  | CMC  | CollecC | CTL  | GLIB | KLIB | M*LIB | STB_DS | STC  | STL |
|-------------------------|------|------|------|---------|------|------|------|-------|--------|------|-----|
| number of characters    | 1120 | 1585 | 1740 | 1337    | 1407 | 840  | 1041 | 505   | 1255   | 1222 | 261 |
| number of line of codes | 49   | 61   | 65   | 68      | 42   | 47   | 43   | 20    | 61     | 44   | 14  |
| number of workarounds   | 2    | 0    | 7    | 1       | 5    | 0    | 5    | 0     | 4      | 3    | 0   |

| UMap-Int programs       | CC  | CCC  | CMC  | CollecC | CTL  | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-------------------------|-----|------|------|---------|------|------|------|-------|--------|-----|-----|
| number of characters    | 442 | 2140 | 1640 | 1241    | 1090 | 984  | 774  | 462   | 1035   | 777 | 359 |
| number of line of codes | 26  | 85   | 62   | 54      | 47   | 42   | 43   | 19    | 50     | 37  | 15  |
| number of workarounds   | 0   | 0    | 1    | 0       | 1    | 0    | 0    | 0     | 3      | 0   | 0   |

| UMap-Str programs       | CC  | CCC  | CMC  | CollecC | CTL  | GLIB | KLIB | M*LIB | STB_DS | STC | STL |
|-------------------------|-----|------|------|---------|------|------|------|-------|--------|-----|-----|
| number of characters    | 522 | 2350 | 1627 | 929     | 1756 | 1514 | 837  | 615   | 991    | 870 | 436 |
| number of line of codes | 26  | 93   | 63   | 35      | 64   | 58   | 43   | 20    | 48     | 37  | 16  |
| number of workarounds   | 0   | 0    | 1    | 0       | 4    | 0    | 0    | 0     | 2      | 0   | 0   |

| UMap-mpz programs       | CC   | CCC  | CMC  | CollecC | CTL  | GLIB | KLIB | M*LIB | STB_DS | STC  | STL |
|-------------------------|------|------|------|---------|------|------|------|-------|--------|------|-----|
| number of characters    | 1443 | 3137 | 2387 | 1893    | 1964 | 1667 | 1754 | 1018  | NA     | 1849 | 797 |
| number of line of codes | 62   | 132  | 99   | 87      | 79   | 75   | 84   | 39    | NA     | 55   | 38  |
| number of workarounds   | 2    | 1    | 2    | 0       | 4    | 0    | 3    | 0     | NA     | 4    | 0   |


As ergonomic is a personal judgement, no conclusion will be provided.
You should open the different provided programs and make your own choice based on your own ergonomic criteria:

* Readability
* Debuggability
* Maintainability

However, we can still conclude that even the best C library in this domain is more verbose than the C++.

We can also compare the size of the generated programs.
The programs are built and link with "-ffunction-sections -fdata-sections -Wl,--gc-sections"
in order to get a fair comparison (so that the functions not used are discarded).
Compiler used is GCC 16.1

| array-int size | bytes |
|----------------|-------|
| STC            | 15768 |
| GLIB           | 15800 |
| CC             | 15856 |
| M*LIB          | 15944 |
| CTL            | 16152 |
| CollecC        | 16176 |
| KLIB           | 16192 |
| CCC            | 16392 |
| STL            | 16392 |
| STB_DS         | 20872 |
| CMC            | 21344 |

| array-str size | bytes |
|----------------|-------|
| GLIB           | 15944 |
| CC             | 16160 |
| M*LIB          | 16200 |
| CollecC        | 16224 |
| KLIB           | 16360 |
| CCC            | 16440 |
| CTL            | 16584 |
| STL            | 18160 |
| STC            | 20752 |
| STB_DS         | 20872 |
| CMC            | 21392 |

| array-mpz size | bytes |
|----------------|-------|
| STC            | 15864 |
| GLIB           | 15936 |
| CC             | 16032 |
| M*LIB          | 16096 |
| CollecC        | 16312 |
| CTL            | 16320 |
| KLIB           | 16320 |
| CCC            | 16536 |
| STL            | 17360 |
| STB_DS         | 21008 |
| CMC            | 21624 |

| umap-int size | bytes |
|---------------|-------|
| KLIB          | 15864 |
| STC           | 15880 |
| GLIB          | 15904 |
| M*LIB         | 16040 |
| CC            | 16072 |
| CollecC       | 16416 |
| CTL           | 16424 |
| CCC           | 16848 |
| CMC           | 17128 |
| STL           | 17368 |
| STB_DS        | 20784 |

| umap-str size | bytes |
|---------------|-------|
| KLIB          | 15960 |
| GLIB          | 16048 |
| CC            | 16336 |
| CollecC       | 16344 |
| M*LIB         | 16344 |
| CCC           | 16904 |
| CTL           | 16936 |
| CMC           | 17200 |
| STL           | 19136 |
| STB_DS        | 20784 |
| STC           | 20912 |

| umap-mpz size | bytes |
|---------------|-------|
| STC           | 15976 |
| GLIB          | 16032 |
| KLIB          | 16032 |
| M*LIB         | 16280 |
| CC            | 16304 |
| CollecC       | 16544 |
| CTL           | 16552 |
| STL           | 18592 |
| CCC           | 21128 |
| CMC           | 21520 |

As conclusion, the size of most programs are practically the same.

NOTE: GLIB is dynamically linked instead of being statically linked which provides it a notable advantage.

We can also check the compilation time:

> Note: compilation time in absolute doesn't matter as it depends on the host. Only relative difference matters.

| array-int compilation | time |
|-----------------------|------|
| CollecC               | 0.07 |
| CCC                   | 0.08 |
| CTL                   | 0.13 |
| GLIB                  | 0.13 |
| STC                   | 0.13 |
| CC                    | 0.16 |
| KLIB                  | 0.25 |
| CMC                   | 0.31 |
| STB_DS                | 0.38 |
| M*LIB                 | 0.60 |
| STL                   | 0.69 |

| array-str compilation | time |
|-----------------------|------|
| CollecC               | 0.06 |
| CCC                   | 0.07 |
| GLIB                  | 0.13 |
| CC                    | 0.20 |
| CTL                   | 0.23 |
| CMC                   | 0.30 |
| KLIB                  | 0.30 |
| STC                   | 0.31 |
| STB_DS                | 0.38 |
| M*LIB                 | 0.75 |
| STL                   | 0.78 |

| array-mpz compilation | time |
|-----------------------|------|
| CollecC               | 0.08 |
| CCC                   | 0.09 |
| GLIB                  | 0.13 |
| CTL                   | 0.14 |
| STC                   | 0.15 |
| CC                    | 0.18 |
| CMC                   | 0.32 |
| KLIB                  | 0.38 |
| STB_DS                | 0.40 |
| M*LIB                 | 0.53 |
| STL                   | 1.05 |

| umap-int compilation | time |
|----------------------|------|
| CollecC              | 0.07 |
| CCC                  | 0.09 |
| GLIB                 | 0.13 |
| STC                  | 0.14 |
| KLIB                 | 0.17 |
| CTL                  | 0.21 |
| M*LIB                | 0.29 |
| CC                   | 0.32 |
| CMC                  | 0.33 |
| STB_DS               | 0.39 |
| STL                  | 0.70 |

| umap-str compilation | time |
|----------------------|------|
| CollecC              | 0.07 |
| CCC                  | 0.09 |
| GLIB                 | 0.14 |
| KLIB                 | 0.18 |
| CMC                  | 0.32 |
| CTL                  | 0.32 |
| STC                  | 0.33 |
| CC                   | 0.38 |
| STB_DS               | 0.38 |
| M*LIB                | 0.45 |
| STL                  | 0.79 |

| umap-mpz compilation | time |
|----------------------|------|
| CollecC              | 0.09 |
| CCC                  | 0.10 |
| GLIB                 | 0.14 |
| STC                  | 0.16 |
| KLIB                 | 0.20 |
| CTL                  | 0.25 |
| M*LIB                | 0.33 |
| CC                   | 0.34 |
| CMC                  | 0.36 |
| STL                  | 1.07 |

C++ is the slowest to compile by far. M\*LIB is also quite slow to compile.
Except that that, the voidp based libraries are naturally faster to compile,
but the speed difference is not particulary notable on this small example and should be compared on a more complex example.

# Performance Comparison

The [bench](https://github.com/P-p-H-d/c-stl-comparison/tree/master/bench)
directory contains a benchmark comparing
the performance of different C libraries (including some C++ ones, like STL and BOOST as references). 

Time and memory usage are provided for these tests and the best run out of 3 is kept to remove external interference, which is a compromise between execution time and reliability.
Compiler flags are `-O2 -march=native`.

More specialized C libraries are added. The tested C libraries are:

* Bstrlib (for string)
* CC
* CCC
* CMC
* Collections C
* CTL
* GLIB
* KLIB
* liblfds (for thread communication)
* libsrt
* M\*LIB
* Pottery
* Qlibc
* SDS (for string)
* STC
* TOMMY DS 
* UT HASH (for hash table)
* VERSTABLE (for hash table)
* XXHASH (for hash function)

Rather than measuring the performance of each individual methods exported by the library on some dataset,
it measures the time taken by some test programs implementing a defined algorithm using the methods of the containers for this (to provide more real world examples). Of course, it doesn't mean that these algorithms match with your use cases, so you should take them with a grain of salt.

Each dataset size is chosen so that the time using by the best library is around 1 second (which is a compromise between execution time and reliability of the test result).

For the hash tables, the load factor is let at the default defined by the library. Instead we measure and rank the memory consumption during the test, the ones using a low load factor being necessarily at a disadvantageous.

The performance programs are performed around the following functionalities:

* sequence container (array, list and deque) where two containers are growing at the same time (on 64 bits type),
* sorted set container,
* unordered map container (on unsigned 64 bits type, on 256 bits type and on string type) with a 50% found/un-found ratio,
* unordered set container (on 32 bits type) with a low found/un-found ratio,
* string concat,
* string replacement,
* sort algorithm,
* hash function,
* multithread communication queue container.

Exact program exact behaviors, code source and dataset size are provided in the bench directory for further analysis.

## Conclusion

Results are available [for i5-3210M](https://github.com/P-p-H-d/c-stl-comparison/blob/master/bench/doc/BENCH.md) and [for AMD EPYC 7763](https://github.com/P-p-H-d/c-stl-comparison/blob/result/bench/doc/BENCH.md) (the latter is generated by CI).

The results are archived in git so that you can look at the history of the different runs. Thanks to that, the best rank and worst rank of the 10 previous runs are extracted: this enables detecting external interference during the run when the ranking is not stable. For example, the sequence container bench is also dependent on the performance of the kernel to allocate pages, and the top 5 libraries are challenger for the first place depending on how the kernel serves them during the bench. Extracting the best/worst ranks enables to have a better view of the relative performance of the libraries.

The conclusion is that the best C libraries can be much faster than the STL.
Such libraries are all based on template-header or template-macros paradigm.
This is due to the over specification of the C++ standard which prevents the STL to achieve good performances in all cases.
Even for C++, more specialized C++ libraries (like boost) are needed to achieve good performance.

# Continuous Integration

This project includes all sources used for this comparison and provides continuous integration to:

* perform the run of the benchmark,
* automated validation
* regression detection

