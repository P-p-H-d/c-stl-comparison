# Introduction

The goal of this project is to compare several C libraries
that provide some STL like capabilities of the C++ (container template) but are targeting classic C language.
A STL like library for C is a C library providing several classic generic containers for the C language,
like vector, list, map, unordered_map, and so on.

The goal is not to compare their performance (multiple benchmark already exist) but their other characteristics.

To do this, the same simple programs will be implemented by the libraries
in the more straight-forward way possible,
for different kind of containers and for different types.
Then the API ergonomics of each programs can be compared each other according to the user taste.

Objective characteristics of the libraries are directly compared in this file.


# Disclaimer

I am the main author of M\*LIB, one of theses libraries.

This work is still a WIP.


# Comparison Program Constraints

The array test shall respect the following conditions:

* it shall use a basic type (int), a non POD type (the type mpz\_t of the GMP library) and a string as the primary type of a dynamic array.
* it shall not comment the code (the code is assumed to be clear on what it does by itself) except if there is some workaround,
* it shall not produce any compilation warnings,
* it shall execute properly,
* it shall not leak any memory
* it shall abort on error,
* it shall link dynamically with the GMP library (https://gmplib.org/).
* it shall link statically with the container library,
* the optional assertions shall be turned off.

The program shall perform the following operations:

* declare a dynamic array of int (resp. mpz_t, a string of the container library),
* initialize this array with the small unsigned integers values 17, 42 and 9 (performing a conversion from unsigned integer to mpz_t for GMP) or the constant strings "Hello", "World" and "!" for strings,
* sort this array,
* iterate the array to print the values.

A workaround is defined as a way to implement this program which is **not natural** for the library. This typically includes:

* create wrapper structure,
* create wrapper functions or macros,
* accessing internal fields of the containers (typically for using the qsort function).

For example, if a container library manual requests to define some macro for its use, then it won't be considered as a workaround. 


# Execution

The different programs are available in this repository.
To build then, you just need to have
a working C compiler, a make tool and git
to build it.

Simply run "make" to perform a clone of the projects
and generate the different executables.


# Analysis

The following characteristics are used to compare the different C libraries. The C++ STL is also included as as reference.

* What is the supported C language (C89, C99, C11 or C23),
* Is it a pure C program (no need for external preprocessor)?
* Header only?
* Generic mechanism: A)void pointer, B)macro, C)_Generic and macro, D)intrusive field, E)code generation by include, F)code generation by macro
* Is-it type safe (aka. using an incompatible type produces at least a compilation warning)
* support of integer/floats as basic type,
* support of struct POD data as basic type,
* containers don't steal ownership of object given as parameter by default: passing an object data to a container will create a copy of the object data,
* support of optional move semantics, 
* support of array as basic type,
* support of object like data (needing custom constructor, destructor...),
* support of C++ class as basic type,
* container / basic type spatial separation: the association of the methods of the basic type to the needed operators of the container library can be defined when the basic type is defined (ensuring spatial coherency of the basic type) and not only when the container is defined,
* support of API Interface Adapter to transform the interface of the provided method to the expected interface of the operator, 
* support of basic 'emplace'
* support of multiple, enhanced 'emplace' based on the initialized arguments,
* support of iterator abstraction
* support of sort algorithm
* support of sort algorithm with custom comparison,
* support of separate declaration and definition (external linkage definition),
* full abstraction of the dynamic array type (user shall not use internal fields)
* contract violation checks (assertions on invalid inputs, on input contract violation)
* natural usage of array (using of [] operator on the object)
* basic type is stored in the array, not a pointer to it.
* don't need explicit instanciation of the array with the basic type,
* functions are properly prefixed,
* memory error handling (return code, exception, abort, none)
* On exception, destructors of objects on stack are properly called.
* custom memory functions
* support of serialization
* support of JSON serialization
* support of XML serialization


# Synthesis

| Characteristics                   | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     |  GLIB  |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|--------|
| C language                        | NA        | >=C99  | >=C99   | >=C99  | >=C99 | >=C99| >=C11* or >=C23 | >= C89 |
| Pure C                            | NA        | Y      | Y       | Y       | Y     | Y            | Y      | Y      |
| Header only                       | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| Generic mechanism                 | template  | F      | E       | F       | E     | A            | C      | A      |
| type safe                         | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| integer/float support             | Y         | Y      | Y       | Y       | Y     | Y            | Y      | Y*     |
| struct POD support                | Y         | Y      | Y       | Y       | Y     | N            | Y      | Y*     |
| No default steal of ownership     | Y         | Y      | Y       | N       | N     | Y            | N      | Y      |
| Optional move semantics           | Y         | Y      | N       | N       | N     | N            | N      | N      |
| C++ class support                 | Y         | Y      | N       | N       | N     | N            | N      | N      |
| C object support                  | Y         | Y      | Y       | Y       | Y     | N            | Y      | Y*     |
| container/basic spatial separation | Y        | Y      | N       | N       | N     | NA           | Y      | NA     |
| API Interface Adaptator           | N         | Y      | N       | N       | N     | N            | N      | N      |
| basic emplace support             | Y         | Y      | Y       | N       | N     | N            | N      | N      |
| Enhance emplace support           | Y         | Y      | N       | N       | N     | N            | N      | N      |
| Iterator support                  | Y         | Y      | Y       | N       | Y     | Y            | Y      | N      |
| Sort algorithm                    | Y         | Y      | Y       | N       | Y     | Y            | N      | Y      |
| Enhanced Sort algorithm           | Y         | Y      | Y       | N       | Y     | Y            | N      | Y      |
| separate declare & define         | N         | N      | Y       | Y       | N     | Y            | N      | Y      |
| Full abstraction                  | Y         | Y      | N       | Y       | N     | Y            | Y      | N      |
| Contract violation checks         | Y         | Y      | N       | N       | N     | N            | N      | N      |
| Natural usage                     | Y         | N      | N       | N       | N     | N            | N      | N      |
| Basic type is stored              | Y         | Y      | Y       | Y       | Y     | N            | Y      | N      |
| No explicit instanciation         | Y         | N      | N       | N       | N     | Y            | Y      | Y      |
| prefixed function                 | Y         | Y      | Y       | Y       | Y     | Y            | Y      | Y      |
| memory handling                   | exception | abort, exception | retcode | retcode | none|retcode |retcode|retcode|
| destructors on exception          | Y         | Y*     | NA      | NA      | NA    | NA           | NA     | N      |
| custom memory support             | Y         | Y      | Y       | Y       | N     | Y            | Y      | N      |
| Serialization                     | N         | Y      | N       | N       | N     | N            | N      | N      |
| JSON Serialization                | N         | Y      | N       | N       | N     | N            | N      | N      |
| XML Serialization                 | N         | N      | N       | N       | N     | N            | N      | N      |

* C11*: means C11 + extension
* Y*: Yes with some limitations.

| Comparison programs               | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC | CC     |  GLIB  |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|--------|--------|
| int:number of characters          | 236       | 370    | 480     | 1011    | 593   | 874          | 604    | 696    |
| int:number of line of codes       | 12        | 16     | 26      | 36      | 22    | 35           | 30     | 38     |
| int:number of workarounds         | 0         | 0      | 0       | 2       | 2     | 1            | 1      | 0      |
| mpz:number of characters          | 261       | 500    | 1152    | 1859    | 1456  | 1288         | 1108   | 840    |
| mpz:number of line of codes       | 13        | 18     | 36      | 52      | 37    | 58           | 39     | 47     |
| mpz:number of workarounds         | 0         | 0      | 3       | 8       | 6     | 1            | 2      | 0      |

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
| weak_ptr                          | Y         | N      | N       | N       | N     | N            | N      | N    |
| Function Object                   | Y         | Y      | N       | N       | N     | N            | N      | N    |
| Span                              | Y         | N      | Y       | N       | N     | N            | N      | N    |
| MDSpan                            | Y         | N      | Y       | N       | N     | N            | N      | N    |
| Bounded String                    | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register SPSC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register MPSC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register SPMC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| Atomic Shared Register MPMC       | N         | Y      | N       | N       | N     | N            | N      | N    |
| concurrent<>                      | N         | Y      | N       | N       | N     | N            | N      | N    |
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
M\*LIB         | d17fa4530bffb23c2eb4cb0658b4cfec9bed1ae9
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

This is a WIP, and some reviews are needed to help this comparison.

If you see any errors in this report,
or want to include another C library,
or want to include another point of comparison,
do not hesitate to open a pull request.
