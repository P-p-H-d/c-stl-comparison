# Introduction

The goal of this project is to compare several generic container C libraries
that provide some STL like capabilities of the C++ (container template) but are targeting classic C language.
A STL like library for C is a C library providing several classic generic containers for the C language,
like vector, list, sorted set, unordered_map, and so on.

To do this, the same simple programs are implemented by the libraries
in the more straight-forward way possible,
for different kind of containers and for different types.
Then the API ergonomics of each programs can be compared each other according to the user taste.

A benchmark to compare their performance is included in the bench directory.

Objective characteristics of the libraries are directly compared in this file.


# Implementing generic code in C

One of the main issue in the C language is how to write generic code, i.e. code that works the same for different kind of objects:
you write once, and it works for several types.
A kind of equivalent of the templates of the C++.

There are several ways of doing so:

## voidp: Everything is a pointer to void.

Each object is handled through a pointer to void. The container store only pointers to these objects.
Potentially, it may also register some callback functions to handle the contained objects for the needed specialized methods (copy, drop, ...). 
From a user point of view, this makes the code harder to use (as you don't have any help from the compiler) and type unsafe since a lot of cast is needed to handle it (so no formal proof of the code is possible). This also generally generate slower code (due to the multiple reduction, indirect callback, increase memory usage and cache miss) even if using link time optimization could reduce this a little. Properly used, it can yet be the most space efficient for the code, but can consume a lot more for the data due to the obligation of using pointers. This is however the easiest to design & code.

Pros:

* easy to develop,
* reduced code.

Cons:

* slow code,
* data memory usage,
* hard to debug for user,
* type unsafe.

## macro: Everything is a macro

Macros are used to access structures in a generic way (using known named fields of a structure — typically size, capacity, etc.). The macro is fully always expanded in the user code. From a user point of view, this can create subtle bugs in the use of the library (as everything is done through macro expansion in the user defined code) and hard to understand warnings. This can be mitigated using proper macros expansion and type checking, but it increases the complexity of the solution. This can generates fully efficient code. From a library developer point of view, this can be quite limiting in what you can offer.

Pros:

* fast to develop,
* efficient code.

Cons:

* type unsafe,
* error prone,
* can have cryptic error message if usage is incorrect
* limited scope of what is possible

## Generic objects

The objects inherited from all the same base object. The base object has a virtual table that provides the callbacks to all the methods needed to handle such object.
The generic code is a simple classic C code that handles only the base object: therefore it uses the provided callback in its vtable to handle the object for any operation.
This is an alternative to everything is a void pointer.

Another alternative of this is encapsulating the methods in macros that detect the type of the argument passed as parameter using _Generics, before calling the associated method according to the given type. The difficulty is how to add pure user types in this generic switch.

Pros:

* reduce code size
* support different kind of objects in the same container (for vtable)

Cons:

* data memory usage (for vtable)
* slow code (for vtable)
* new operation requires rework of vtable
* complex development
* slow compilation (for _Generic)

## Intrusive container

A known structure is put in an intrusive way in the type of all the objects you wan to handle. From a user point of view, he needs to modify its structure and has to perform all the allocation & deallocation code itself (which is good or bad depending on the context). This can generate efficient code (both in speed and size). From a library developer point of view, this is easy to design & code. You need internally a cast to go from a pointer to the known structure to the pointed object (a reverse of offsetof) that is generally type unsafe (except if mixed with the macro generating concept). This is quite limited in what you can do: you can't move your objects so any container that has to move some objects is out-of-question (which means that you cannot use the most efficient container).

Pros:

* reduce code size
* efficient code

Cons:

* data memory usage
* limited scope of what is possible

## Template header

Header files are included multiple times with different macro contexts (which act as arguments of the header) in order to generate different code for each type. 
From a user point of view, this creates a new step before using the container: an instantiating stage that has to be done once per type and per compilation unit (The user is responsible to create only one instance of the container, which can be troublesome if the library doesn't handle proper prefix for its naming convention). This instantiating stage generates the functions handling the container with the correct type, ensuring type safety and control by the compiler. 
The debug of the library is generally reasonable.
It can generate fully specialized & efficient code. 
Incorrectly used, this can generate a lot of code bloat. Properly used, this can even create smaller code than the void pointer variant. 
The interface used to configure the library can be quite tiresome in case of a lot of specialized methods for the used user type to configure: it doesn't enable to chain the configuration from a container to another one easily.
It also cannot have heavy customization of the code. 
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

## Template macros

Macros are used to generate context-dependent C code enabling to generate code for different type. This is pretty much like the template headers solution but with added flexibility. 
From a user point of view, this creates a new step before using the container: an instantiating stage that has to be done once per type and per compilation unit (The user is responsible to create only one instance of the container, which can be troublesome if the library doesn't handle proper prefix for its naming convention). 
This can generate fully specialized & efficient code with the correct type ensuring type safety and control by the compiler. Incorrectly used, this can generate a lot of code bloat. Properly used, this can even create smaller code than the void pointer variant. 
From a library developer point of view, the library is harder to debug: everything being expanded in one line, you can't step in the library (there is however a solution to overcome this limitation by adding another stage to the compilation process). 
This can also generates cryptic error messages at user level if incorrectly used when creating an instance. You can however see the generated code by looking at the preprocessed file. 
You can perform heavy context-dependent customization of the code (transforming the macro preprocessing step into its own language): not only generating one method but N methods depending on the given type.
Properly done, you can also chain the methods from a container to another one easily, enabling quick and easy expansion of the containers. 
Errors in user code are easy to read and natural. Code usage is a little bit more verbose as it uses specialized function names, and not generic ones.

Some people reported "issue" of the template macros with their look due to the use of backslash at the end of the lines however it is due to their coding practices (you need to align backslash at the same column). Another one of the reported "issue" is the lack of support of syntax highlighting and autocomplete in macros but... it was more an issue in their used text editor.

Pros:

* specialized & efficient code
* type safe
* easy to use for user
* maximum flexibility in code generation
* maximum configuration possible

Cons:

* Explicit instance needed
* can generate code bloat if incorrectly used
* little harder to debug for **library** developer
* can have cryptic error message at **instantiation** stage if incorrectly used
* method names are verbose

## Mix

Some mix of the previous solutions can also be chosen for a specific usage.
For example, mixing the macro solution and the voidp solution can mitigates the Cons of both solution.


# C libraries Selection

The following C libraries have been selected as their aim is to provide generic containers to the C language:

* [C-Macro-Collections](https://github.com/LeoVen/C-Macro-Collections)
* [COLLECTIONS-C](https://github.com/srdja/Collections-C)
* CTL [by glouw](https://github.com/glouw/ctl) or [by rurban](https://github.com/rurban/ctl)
* [M\*LIB](https://github.com/P-p-H-d/mlib)
* [STC - Smart Template Container for C](https://github.com/tylov/STC)
* [CC](https://github.com/JacksonAllan/CC.git)
* [GLIB](https://docs.gtk.org/glib/index.html)
* [STB_DS](https://github.com/nothings/stb)
* [KLIB](https://github.com/attractivechaos/klib)

with C++ STL used as the reference baseline.

The used versions for the manual comparison are:

COMPONENT      | VERSION
---------------|-----------------------------------------
C Macro Collections | v0.23.1
CollectionsC   | ff1be366329e2c82cd85b2c803114ef8d2115f7f
CTL            | 3923e6776a231e5d58cf91225ca8a1d61879401b
M\*LIB         | a0818419ab959e05517336e1bea699c1854b29f3
STC            | 5fb5ed08250b5ad4eadd6e7a9fdc44f4519b15ff
CC             | 2012d9d2eb8f035d7dc69f36ec03ca3199ede1bf
GLIB           | 2.74
STB_DS         | 904aa67e1e2d1dec92959df63e700b166d5c1022
KLIB           | 97a0fcb790b43b9e5da8994f4671021fec036f19

More specialized C libraries which provides only one kind of container are not included in this chapter.
sglib is not included due to being abandoned.


# Feature Comparison

## Analysis

The following characteristics are compared. The C++ STL is also included as reference.

* What is the license?
* What is the supported C language (C89, C99, C11 or C23)?
* Is it a pure C program (no need for external preprocessor)?
* Is it a Header only library?
* How is implemented the Generic mechanism? By using  (VP) void pointer, (M) macro, (GO) Generic objects, (IF) intrusive field, (TH) template header, (TM) template macro
* Is it type safe (aka. using an incompatible type produces at least a compilation warning)?
* support of integer/floats as basic type,
* support of struct POD data as basic type,
* support of array as basic type,
* support of object like data (needing custom constructor, copy, destructor...) as basic type,
* support of C++ class as basic type,
* support of Assignment semantics: containers uses the C Assignment operators to set object in them,
* support of copy semantics: containers create a proper copy of the object data as per the object semantic (aka if there is pointer in the structure, it performs a proper copy of the pointed objects),
* support of move semantics: containers steal the ownership of the object given as parameter as per the object semantic, rendering the original object useless (in a destroy or nearly destroy state),
* container / basic type spatial separation: the association of the methods of the basic type to the needed operators of the container library can be defined when the basic type is defined (ensuring spatial coherency of the basic type) and not only when the container is defined,
* support of an adaptation layer to transform the interface of the provided method to the expected interface of the operator, 
* support of basic 'emplace'
* support of multiple, enhanced 'emplace' based on the initialized arguments,
* support of iterator abstraction
* support of sort algorithm
* support of sort algorithm with custom comparison,
* support of single linkage definition (use of declaration only for all files except one than include the container definition),
* full abstraction of the container type (user shall not use internal fields)
* contract violation checks (assertions on invalid inputs, on input contract violation or error reporting)
* natural usage of array (using of [] operator on the object)
* basic type is stored in the container, not a pointer to it.
* Need explicit instantiation of the container with the basic type,
* functions are properly prefixed,
* error handling (return code, exception, abort, none)
* On exception, destructors of objects on stack are properly called.
* custom memory functions
* optional per-container context for custom memory functions
* support of forward declaration of container
* support of serialization (JSON, XML)

## Synthesis

| Characteristics             | STL      | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     |  GLIB  | STB_DS | KLIB |
|-----------------------------|----------|--------|---------|---------|-------|---------|--------|--------|--------|------|
| Licence                     | NA       | BSD2   | MIT     | MIT     | MIT   | LGPL3   | MIT    | LGPL2.1| MIT    | MIT  |
| C language                  | NA       | >=C99  | >=C99   | >=C99   | >=C99 | >=C99| >=C11* or >=C23 | >=C89 | >=C99* or >= C23 | >= C99 |
| Pure C                      | NA       | Y      | Y       | Y       | Y     | Y       | Y      | Y      | Y      | Y    |
| Header only                 | Y        | Y      | Y       | Y       | Y     | N       | Y      | N      | Y      | Y    |
| Generic mechanism           | template | TM     | TH      | TM      | TH    | VP      | M+GO   | VP     | M      | TM   |
| type safe                   | Y        | Y      | Y       | Y       | Y     | N       | Y*     | N      | N*     | Y    |
| integer/float support       | Y        | Y      | Y       | Y       | Y     | Y       | Y      | Y*     | Y      | Y    |
| struct POD support          | Y        | Y      | Y       | Y       | Y     | N       | Y      | Y*     | Y      | Y    |
| C++ class support           | Y        | Y      | N       | N       | N     | N       | N      | N      | N      | N    |
| C object support            | Y        | Y      | Y       | Y       | Y     | N       | Y      | Y*     | N      | Y    |

| Characteristics             | STL      | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     |  GLIB  | STB_DS | KLIB |
|-----------------------------|----------|--------|---------|---------|-------|---------|--------|--------|--------|------|
| Assignment semantics        | Y        | Y      | Y       | Y       | Y     | Y       | Y      | Y      | Y      | Y    |
| Copy semantics              | Y        | Y      | N       | N       | N     | Y       | N      | Y      | N      | N    |
| Move semantics              | Y        | Y      | N       | N       | N     | N       | N      | N      | N      | N    |
| spatial separation          | Y        | Y      | N       | N       | N     | NA      | Y      | NA     | N      | N    |
| Adaptator Layer             | N        | Y      | N       | N       | N     | N       | N      | N      | N      | N    |
| Basic emplace support       | Y        | Y      | Y       | N       | N     | N       | N      | N      | N      | N    |
| Enhance emplace support     | Y        | Y      | N       | N       | N     | N       | N      | N      | N      | N    |
| Iterator support            | Y        | Y      | Y       | N       | Y     | Y       | Y      | N      | N      | Y    |
| Sort algorithm              | Y        | Y      | Y       | N       | Y     | Y       | N      | Y      | N      | Y    |
| Enhanced Sort algorithm     | Y        | Y      | Y       | N       | Y     | Y       | N      | Y      | N      | N    |

| Characteristics             | STL      | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     |  GLIB  | STB_DS | KLIB |
|-----------------------------|----------|--------|---------|---------|-------|---------|--------|--------|--------|------|
| single linkage definition   | N*       | Y      | Y       | Y       | N     | Y       | N      | Y      | Y      | N    |
| Full abstraction            | Y        | Y      | N       | Y       | N     | Y       | Y      | N      | Y      | Y    |
| Contract violation checks   | Y        | Y      | N       | N       | N     | N       | N      | N      | N      | N    |
| Natural usage               | Y        | N      | N       | N       | N     | N       | N      | N      | Y      | N    |
| Basic type is stored        | Y        | Y      | Y       | Y       | Y     | N       | Y      | N      | Y      | Y    |
| Explicit instantiation      | N        | Y      | Y       | Y       | Y     | N       | N      | N      | N      | Y    |
| prefixed function           | Y        | Y      | Y       | Y       | Y     | Y       | Y      | Y      | Y      | Y    |

| Characteristics             | STL      | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     |  GLIB  | STB_DS | KLIB |
|-----------------------------|----------|--------|---------|---------|-------|---------|--------|--------|--------|------|
| memory handling             | except   | abort, except | retcode | retcode |none|retcode |retcode|retcode| none  |retcode|
| destructors on exception    | Y        | Y*     | NA      | NA      | NA    | NA      | NA     | N      | N      | N    |
| custom memory support       | Y        | Y      | Y       | Y       | N     | Y       | Y      | N      | Y      | Y    |
| context for memory support  | N        | Y      | Y       | N       | N     | N       | N      | N      | Y      | N    |
| Forward declaration support | N        | N      | Y       | N       | N     | N       | N      | N      | N      | N    |
| Serialization               | N        | JSON   | N       | N       | N     | N       | N      | N      | N      | N    |

* C11*: means C11 + typeof extension
* C99*: means C99 + typeof extension
* Y*: Yes with some limitations.
* N*: even it appears to be type safe, it is not and it is easy to misuse it.

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     | GLIB |STB_DS | KLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|---------|--------|------|-------|------|
| Singly Linked Non-Intrusive list  | Y         | Y      | N       | N       | Y     | Y       | N      | Y    |N      | Y    |
| Doubly Linked Non-Intrusive list  | Y         | N      | N       | N       | Y     | Y       | Y      | Y    |N      | N    |
| Singly Linked, Dually Push Non-Intrusive list  | N | Y  | Y       | N       | N     | N       | N      | N    |N      | N    |
| Singly Linked Intrusive list      | N         | N      | N       | N       | N     | N       | N      | N    |N      | N    |
| Doubly Linked Intrusive list      | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Dynamic array                     | Y         | Y      | Y       | Y       | Y     | Y       | Y      | Y    |Y      | Y    |
| Static array                      | Y         | N      | N       | N       | Y     | N       | N      | N    |N      | N    |

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     | GLIB |STB_DS | KLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|---------|--------|------|-------|------|
| pair                              | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| tuple                             | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| optional                          | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| variant                           | Y         | Y      | N       | N       | N     | N       | N      | Y    |N      | N    |
| bitset                            | Y         | Y      | Y       | Y       | N     | N       | N      | N    |N      | N    |
| Dynamic character string          | Y         | Y      | Y       | N       | Y     | N       | N      | Y    |N      | Y    |
| string_view                       | Y         | N      | Y       | N       | N     | N       | N      | N    |N      | N    |
| deque                             | Y         | Y      | Y       | Y       | Y     | Y       | N      | Y    |N      | N    |
| queue                             | Y         | Y      | Y       | Y       | Y     | Y       | N      | Y    |N      | N    |
| priority queue                    | Y         | Y      | Y       | Y       | Y     | Y       | N      | N    |N      | N    |
| stack                             | Y         | Y      | Y       | N       | Y     | Y       | N      | N    |N      | N    |
| Bounded Queue                     | N         | Y      | N       | N       | N     | N       | N      | Y    |N      | N    |

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     | GLIB |STB_DS | KLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|---------|--------|------|-------|------|
| set                               | Y         | Y      | Y       | N       | N     | Y       | N      | Y    |N      | Y    |
| multiset                          | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| map                               | Y         | Y      | N       | N       | Y     | Y       | N      | N    |N      | Y    |
| multimap                          | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| unordered_set                     | Y         | Y      | Y       | Y       | Y     | Y       | Y      | N    |Y      | Y    |
| unordered_multiset                | Y         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| unordered_map                     | Y         | Y      | Y       | Y       | Y     | Y       | Y      | N    |Y      | Y    |
| unordered_multimap                | Y         | N      | N       | Y       | N     | N       | N      | Y    |N      | N    |
| flat_set                          | Y         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| flat_multiset                     | Y         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| flat_map                          | Y         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| flat_multimap                     | Y         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     | GLIB |STB_DS | KLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|---------|--------|------|-------|------|
| unique_ptr                        | Y         | N      | Y       | N       | N     | N       | N      | N    |N      | N    |
| shared_ptr                        | Y         | Y      | Y       | N       | N     | N       | N      | N    |N      | N    |
| advanced shared_ptr               | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| weak_ptr                          | Y         | N      | N       | N       | N     | N       | N      | N    |N      | N    |
| Function Object                   | Y         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Span                              | Y         | N      | Y       | N       | N     | N       | N      | N    |N      | N    |
| MDSpan                            | Y         | N      | Y       | N       | N     | N       | N      | N    |N      | N    |
| Bounded String                    | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollecC | CC     | GLIB |STB_DS | KLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|---------|--------|------|-------|------|
| Atomic Shared Register SPSC       | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Atomic Shared Register MPSC       | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Atomic Shared Register SPMC       | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Atomic Shared Register MPMC       | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |
| Skip List                         | N         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| Sorted Bidirectional Map          | N         | N      | N       | Y       | N     | N       | N      | N    |N      | N    |
| Tree                              | N         | Y      | N       | N       | N     | N       | N      | N    |N      | N    |


| Algorithms                        | STL  | M*LIB | STC | CMC | CTL |CollecC| CC | GLIB |STB_DS | KLIB |
|-----------------------------------|------|-------|-----|-----|-----|-------|----|------|-------|------|
| Sort/Min/Max/...                  | Y    | Y     | Y   | N   | Y   | Y     | Y  | Y    | N     |  Y   |

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

For example, if a container library manual requests to define some macro for its use, then it won't be considered as a workaround. 

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

| Array-Int programs      | STL | M*LIB | STC | CMC  | CTL | CollecC | CC  | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|-----|------|-----|---------|-----|------|--------|------|
| number of characters    | 236 | 373   | 558 | 1011 | 593 | 885     | 611 | 696  | 817    | 783  |
| number of line of codes | 13  | 18    | 34  | 46   | 25  | 46      | 34  | 38   | 43     | 28   |
| number of workarounds   | 0   | 0     | 0   | 2    | 2   | 2       | 0   | 0    | 1      | 2    |

| Array-Str programs      | STL | M*LIB | STC | CMC  | CTL | CollecC | CC  | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|-----|------|-----|---------|-----|------|--------|------|
| number of characters    | 274 | 442   | 564 | 1053 | 762 | 839     | 651 | 908  | 881    | 1497 |
| number of line of codes | 14  | 19    | 36  | 45   | 29  | 47      | 33  | 44   | 45     | 55   |
| number of workarounds   | 0   | 0     | 0   | 2    | 3   | 1       | 0   | 0    | 1      | 3    |

| Array-mpz programs      | STL | M*LIB | STC  | CMC  | CTL  | CollecC | CC   | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|------|------|------|---------|------|------|--------|------|
| number of characters    | 261 | 505   | 1222 | 1740 | 1407 | 1337    | 1120 | 840  | 1255   | 1041 |
| number of line of codes | 14  | 20    | 44   | 65   | 42   | 68      | 49   | 47   | 61     | 43   |
| number of workarounds   | 0   | 0     | 3    | 7    | 5    | 1       | 2    | 0    | 4      | 5    |

| UMap-Int programs       | STL | M*LIB | STC | CMC  | CTL  | CollecC | CC  | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|-----|------|------|---------|-----|------|--------|------|
| number of characters    | 359 | 462   | 777 | 1640 | 1090 | 1241    | 442 | 984  | 1035   | 774  |
| number of line of codes | 15  | 19    | 37  | 62   | 47   | 54      | 26  | 42   | 50     | 43   |
| number of workarounds   | 0   | 0     | 0   | 1    | 1    | 0       | 0   | 0    | 3      | 0    |

| UMap-Str programs       | STL | M*LIB | STC | CMC  | CTL  | CollecC | CC  | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|-----|------|------|---------|-----|------|--------|------|
| number of characters    | 436 | 615   | 870 | 1627 | 1756 | 929     | 522 | 1514 | 991    | 837  |
| number of line of codes | 16  | 20    | 37  | 63   | 64   | 35      | 26  | 58   | 48     | 43   |
| number of workarounds   | 0   | 0     | 0   | 1    | 4    | 0       | 0   | 0    | 2      | 0    |

| UMap-mpz programs       | STL | M*LIB | STC  | CMC  | CTL  | CollecC | CC   | GLIB | STB_DS | KLIB |
|-------------------------|-----|-------|------|------|------|---------|------|------|--------|------|
| number of characters    | 797 | 1018  | 1849 | 2387 | 1964 | 1893    | 1443 | 1667 | NA     | 1754 |
| number of line of codes | 38  | 39    | 55   | 99   | 79   | 87      | 62   | 75   | NA     | 84   |
| number of workarounds   | 0   | 0     | 4    | 2    | 4    | 0       | 2    | 0    | NA     | 3    |


As ergonomic is a personal judgement, no conclusion will be provided.
You should open the different provided programs and make your own choice based on your own ergonomic criteria:

* Readability
* Debuggability
* Maintainability


# Performance Comparison

The [bench](https://github.com/P-p-H-d/c-stl-comparison/tree/master/bench)
directory contains a benchmark comparing
the performance of different C libraries (including some C++ ones, like STL and BOOST as references). 

Time and memory usage are provided for these tests and the best run out of 3 is kept to remove external interference, which is a compromise between execution time and reliability.
Compiler flags are `-O2 -march=native`.

More specialized C libraries are added. The tested C libraries are:

* Bstrlib (for string)
* CC
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

The performance programs are performed around the following functionalities:

* sequence container (array, list and deque),
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

The results are archived in git so that you can look at the history of the different runs. Thanks to that, the best rank and worst rank of the 10 previous runs are extracted: this enables detecting external interference during the run (for example, the sequence bench is dependent on the performance of the kernel to allocate pages, and the top 5 libraries are challenger for the first place). This enables to see if the rank is solid (best rank / worst rank are the same rank) or fluctuating.

The conclusion is that the best C libraries can be much faster than the STL.
Such libraries are all based on template-header or template-macros paradigm.
This is due to the over specification of the C++ standard which prevents the STL to achieve good performances in all cases.
Even for C++, more specialized C++ libraries (like boost) are needed to achieve good performance.

# Continuous Integration

This project includes all sources used for this comparison and provides continuous integration to:

* perform the run of the benchmark,
* automated validation
* regression detection

