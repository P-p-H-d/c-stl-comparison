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

Each object is handled through a pointer to void. The container store only pointers to theses objects.
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
* can have cryptic error message at instantiation stage if incorrectly used
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

Some people reported "issue" of the template macros with their look due to the use of backslash at the end of the lines: this was because they didn't align properly the backslashes at the 80. Another one of the reported "issue" is the lack of support of syntax highlighting and autocomplete in macros but... it was an issue in their textual editor.

Pros:

* specialized & efficient code
* type safe
* easy to use for user
* maximum flexibility in code generation
* maximum configuration possible

Cons:

* Explicit instance needed
* can generate code bloat if incorrectly used
* little harder to debug for library developer
* can have cryptic error message at instantiation stage if incorrectly used
* method names are verbose

## Mix

Some mix of the previous solutions can also be chosen for a specific usage.
For example, mixing the macro solution and the voidp solution can mitigates the Cons of both solution.



# Comparison

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
To build then, you just need to have
a working C11 compiler, a make tool, git,
the GMP library, and the GLIB library
to build then.

Simply run "make" to perform a clone of the projects
and generate the different executables.

## Analysis and synthesis

The following characteristics are compared. The C++ STL is also included as as reference.

* What is the supported C language (C89, C99, C11 or C23)?
* Is it a pure C program (no need for external preprocessor)?
* Is it a Header only library?
* How is implemented the Generic mechanism? By using  VP)void pointer, M)macro, GO) Generic objects, IF)intrusive field, TH)template header, TM)template macro
* Is-it type safe (aka. using an incompatible type produces at least a compilation warning)?
* support of integer/floats as basic type,
* support of struct POD data as basic type,
* support of array as basic type,
* support of object like data (needing custom constructor, destructor...) as basic type,
* support of C++ class as basic type,
* support of copy semantics: containers don't steal the ownership of the object given as parameter (passing an object data to a container will create a proper copy of the object data as per the object semantic),
* support of move semantics: containers steal the ownership of the object given as parameter,
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

| Characteristics                   | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     |  GLIB  |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|--------|
| C language                        | NA        | >=C99  | >=C99   | >=C99  | >=C99 | >=C99| >=C11* or >=C23 | >= C89 |
| Pure C                            | NA        | Y      | Y       | Y       | Y     | Y            | Y      | Y      |
| Header only                       | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| Generic mechanism                 | template  | TM     | TH      | TM      | TH    | VP           | GO     | VP     |
| type safe                         | Y         | Y      | Y       | Y       | Y     | N            | Y*     | N      |
| integer/float support             | Y         | Y      | Y       | Y       | Y     | Y            | Y      | Y*     |
| struct POD support                | Y         | Y      | Y       | Y       | Y     | N            | Y      | Y*     |
| C++ class support                 | Y         | Y      | N       | N       | N     | N            | N      | N      |
| C object support                  | Y         | Y      | Y       | Y       | Y     | N            | Y      | Y*     |
| Copy semantics                    | Y         | Y      | N       | N       | N     | Y            | N      | Y      |
| Move semantics                    | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| container/basic spatial separation | Y        | Y      | N       | N       | N     | NA           | Y      | NA     |
| Adaptator Layer                   | N         | Y      | N       | N       | N     | N            | N      | N      |
| Basic emplace support             | Y         | Y      | Y       | N       | N     | N            | N      | N      |
| Enhance emplace support           | Y         | Y      | N       | N       | N     | N            | N      | N      |
| Iterator support                  | Y         | Y      | Y       | N       | Y     | Y            | Y      | N      |
| Sort algorithm                    | Y         | Y      | Y       | N       | Y     | Y            | N      | Y      |
| Enhanced Sort algorithm           | Y         | Y      | Y       | N       | Y     | Y            | N      | Y      |
| single linkage definition         | N*        | Y      | Y       | Y       | N     | Y            | N      | Y      |
| Full abstraction                  | Y         | Y      | N       | Y       | N     | Y            | Y      | N      |
| Contract violation checks         | Y         | Y      | N       | N       | N     | N            | N      | N      |
| Natural usage                     | Y         | N      | N       | N       | N     | N            | N      | N      |
| Basic type is stored              | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| Explicit instanciation            | N         | Y      | Y       | Y       | Y     | N            | N      | N      |
| prefixed function                 | Y         | Y      | Y       | Y       | Y     | Y            | Y      | Y      |
| memory handling                   | exception | abort, exception | retcode | retcode | none|retcode |retcode|retcode|
| destructors on exception          | Y         | Y*     | NA      | NA      | NA    | NA           | NA     | N      |
| custom memory support             | Y         | Y      | Y       | Y       | N     | Y            | Y      | N      |
| context for custom memory support | N         | Y      | Y       | N       | N     | N            | N      | N      |
| Forward declaration support       | N         | N      | Y       | N       | N     | N            | N      | N      |
| Serialization                     | N         | JSON   | N       | N       | N     | N            | N      | N      |

* C11*: means C11 + extension
* Y*: Yes with some limitations.

| Comparison programs               | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     |  GLIB  |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|--------|
| int:number of characters          | 236       | 370    | 558     | 1011    | 593   | 885          | 611    | 696    |
| int:number of line of codes       | 12        | 16     | 28      | 36      | 22    | 35           | 31     | 36     |
| int:number of workarounds         | 0         | 0      | 0       | 2       | 2     | 1            | 1      | 0      |
| mpz:number of characters          | 261       | 500    | 1222    | 1740    | 1407  | 1337         | 1120   | 840    |
| mpz:number of line of codes       | 13        | 18     | 37      | 52      | 37    | 58           | 40     | 45     |
| mpz:number of workarounds         | 0         | 0      | 3       | 7       | 5     | 1            | 2      | 0      |

| Containers                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     | GLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|------|
| Singly Linked Non-Intrusive list  | Y         | Y      | N       | N       | Y     | Y            | N      | Y    |
| Doubly Linked Non-Intrusive list  | Y         | N      | N       | N       | Y     | Y            | Y      | Y    |
| Singly Linked, Dualy Push Non-Intrusive list  | N | Y  | Y       | N       | N     | N            | N      | N    |
| Singly Linked Intrusive list      | N         | N      | N       | N       | N     | N            | N      | N    |
| Doubly Linked Intrusive list      | N         | Y      | N       | N       | N     | N            | N      | N    |
| Dynamic array                     | Y         | Y      | Y       | Y       | Y     | Y            | Y      | Y    |
| Static array                      | Y         | N      | N       | N       | Y     | N            | N      | N    |
| pair                              | Y         | Y      | N       | N       | N     | N            | N      | N    |
| tuple                             | Y         | Y      | N       | N       | N     | N            | N      | N    |
| optional                          | Y         | Y      | N       | N       | N     | N            | N      | N    |
| variant                           | Y         | Y      | N       | N       | N     | N            | N      | Y    |
| bitset                            | Y         | Y      | Y       | Y       | N     | N            | N      | N    |
| Dynamic character string          | Y         | Y      | Y       | N       | Y     | N            | N      | Y    |
| string_view                       | Y         | N      | Y       | N       | N     | N            | N      | N    |
| deque                             | Y         | Y      | Y       | Y       | Y     | Y            | N      | Y    |
| queue                             | Y         | Y      | Y       | Y       | Y     | Y            | N      | Y    |
| priority queue                    | Y         | Y      | Y       | Y       | Y     | Y            | N      | N    |
| stack                             | Y         | Y      | Y       | N       | Y     | Y            | N      | N    |
| Bounded Queue                     | N         | Y      | N       | N       | N     | N            | N      | Y    |
| set                               | Y         | Y      | Y       | N       | N     | Y            | N      | Y    |
| multiset                          | Y         | Y      | N       | N       | N     | N            | N      | N    |
| map                               | Y         | Y      | N       | N       | Y     | Y            | N      | N    |
| multimap                          | Y         | Y      | N       | N       | N     | N            | N      | N    |
| unordered_set                     | Y         | Y      | Y       | Y       | Y     | Y            | Y      | N    |
| unordered_multiset                | Y         | N      | N       | Y       | N     | N            | N      | N    |
| unordered_map                     | Y         | Y      | Y       | Y       | Y     | Y            | Y      | N    |
| unordered_multimap                | Y         | N      | N       | Y       | N     | N            | N      | Y    |
| flat_set                          | Y         | N      | N       | Y       | N     | N            | N      | N    |
| flat_multiset                     | Y         | N      | N       | Y       | N     | N            | N      | N    |
| flat_map                          | Y         | N      | N       | Y       | N     | N            | N      | N    |
| flat_multimap                     | Y         | N      | N       | Y       | N     | N            | N      | N    |
| unique_ptr                        | Y         | N      | Y       | N       | N     | N            | N      | N    |
| shared_ptr                        | Y         | Y      | Y       | N       | N     | N            | N      | N    |
| advanced shared_ptr               | N         | Y      | N       | N       | N     | N            | N      | N    |
| weak_ptr                          | Y         | N      | N       | N       | N     | N            | N      | N    |
| Function Object                   | Y         | Y      | N       | N       | N     | N            | N      | N    |
| Span                              | Y         | N      | Y       | N       | N     | N            | N      | N    |
| MDSpan                            | Y         | N      | Y       | N       | N     | N            | N      | N    |
| Bounded String                    | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register SPSC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register MPSC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register SPMC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register MPMC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Skip List                         | N         | N      | N       | Y       | N     | N            | N      | N    |
| Sorted Bidirectional Map          | N         | N      | N       | Y       | N     | N            | N      | N    |
| Tree                              | N         | Y      | N       | N       | N     | N            | N      | N    |


| Algorithms                        | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     | GLIB |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|------|
| TODO                              | Y         | Y      | Y       | N       | Y     | Y            | Y      | Y    |

The used versions are:

COMPONENT      | VERSION
---------------|-----------------------------------------
GCC            | 10.2
C Macro Collections | v0.23.1
CollectionsC   | ff1be366329e2c82cd85b2c803114ef8d2115f7f
CTL            | 3923e6776a231e5d58cf91225ca8a1d61879401b
M\*LIB         | a0818419ab959e05517336e1bea699c1854b29f3
STC            | 5fb5ed08250b5ad4eadd6e7a9fdc44f4519b15ff
CC             | 2012d9d2eb8f035d7dc69f36ec03ca3199ede1bf
GLIB           | 2.74

* [C-Macro-Collections](https://github.com/LeoVen/C-Macro-Collections)
* [COLLECTIONS-C](https://github.com/srdja/Collections-C)
* CTL [by glouw](https://github.com/glouw/ctl) or [by rurban](https://github.com/rurban/ctl)
* [M\*LIB](https://github.com/P-p-H-d/mlib)
* [STC - Smart Template Container for C](https://github.com/tylov/STC)
* [CC](https://github.com/JacksonAllan/CC.git)
* [GLIB](https://docs.gtk.org/glib/index.html)

**This is a WIP, and some reviews are needed to help this comparison.**

If you see any mistakes in this report,
or want to include another C library,
or want to include another point of comparison,
do not hesitate to open a pull request.

# Benchmark

The [bench](https://github.com/P-p-H-d/c-stl-comparison/tree/master/bench)
directory contains a small benchmark comparing
the performance of different libraries.

Results are available [for i5-3210M](https://github.com/P-p-H-d/c-stl-comparison/blob/master/bench/doc/BENCH.md) and [for AMD EPYC 7763](https://github.com/P-p-H-d/c-stl-comparison/blob/result/bench/doc/BENCH.md)

