# Introduction

This project is to compare several C libraries
that provide some STL like capabilities of the C++ but targeting classic C.
A STL like library for C is a C library providing several classic generic containers for the C language,
like vector, list, map, unordered_map, and so on.

The goal is not to compare their performance (multiple benchmark already exist) but their other characteristics.

To do this, the same simple program using vector will be implemented by the libraries
in the more straight-forward way possible,
and the resulted programs will be compared each other.


# Disclaimer

I am the main author of M\*LIB, one of theses libraries.


# Program Constraints

The test of a C container library shall respect the following conditions:

* it shall use a non POD type, aka the type mpz\_t of the GMP library, as the primary type of a dynamic array.
* it shall not comment the code (the code is assumed to be clear on what it does by itself),
* it shall not produce any compilation warnings,
* it shall execute properly,
* it shall not leak any memory
* it shall abort on error,
* it shall link statically with the library.
* it shall link dynamically with the GMP library (https://gmplib.org/).
* optional assertions are turned off

It shall perform the following operations:

* declare a dynamic array of mpz_t (non POD data),
* initialize this array with the small unsigned integers values 17, 42 and 9 (performing a conversion from unsigned integer to mpz_t)
* sort this array
* iterate the array to print the values.


# Analysis

The following criteria are used to compare the different C libraries. The C++ STL is also included as as reference.

* supported C language (C89, C99, C11 or C23)
* pure C program (no need for external preprocessor),
* number of characters
* number of line of codes
* size of the executable
* number of implemented workarounds
* type safe (using a wrong type produces at least a compilation warning)
* support of integer/floats as basic type,
* support of struct POD data as basic type,
* support of C++ class as basic type,
* support of array as basic type,
* support of object like data (constructor, ...),
* association of the provided methods of the basic type to the needed operators of the container library can be defined basic type level (ensuring spatial coherency),
* support of API adapter to automatically transform the interface of the provided method to the expected interface of the required operator, 
* support of basic 'emplace'
* support of enhanced 'emplace' based on the initialized arguments,
* support of iterator abstraction
* support of sort algorithm
* support of sort algorithm with custom comparison,
* support of separate declaration and definition (external linkage definition),
* full abstraction of the dynamic array type (no use of internal fields)
* contract violation checks (assertions)
* natural usage of array
* natural usage of ownership (non-implicit lost of ownership),
* basic type is stored in the array, not a pointer to it.
* don't need explicit instanciation of the array with the basic type,
* functions are properly prefixed,
* memory error handling (return code, exception, abort, none)
* custom memory functions
* support of RAII (no, no jump, exception safe) -- potentially through macro.


# Execution

The different programs are available in this repository.
To build then, you just need to have
a working C compiler, a make tool and git
to build it.

Simply run "make" to perform a clone of the projects
and generate the different executables.


# Synthesis

| Criteria                          | STL       | M*LIB  | STC     | CMC     | CTL   | CollectionsC |
|-----------------------------------|-----------|--------|---------|---------|-------|--------------|
| C language                        | NA        | >=C99  | >=C99   | >=C99   | >=C99 | >= C99       |
| Pure C                            | NA        | Y      | Y       | Y       | Y     | Y            |
| number of characters              | 261       | 500    | 1152    | 1859    | 1456  | 1288         |
| number of line of codes           | 13        | 18     | 36      | 52      | 37    | 58           |
| size of the executable            | 19264     | 17168  | 17032   | 18600   | 17400 | 23192        |
| number of implemented workarounds | 0         | 0      | 3       | 8       | 6     | 1            |
| type safe                         | Y         | Y      | Y       | Y       | Y     | N            |
| integer/float support             | Y         | Y      | Y       | Y       | Y     | Y            |
| struct POD support                | Y         | Y      | Y       | Y       | Y     | N            |
| class support                     | Y         | Y      | N       | N       | N     | N            |
| object support                    | Y         | Y      | Y       | Y       | Y     | N            |
| operators / methods association   | Y         | Y      | N       | N       | N     | N            |
| API adaptator                     | N         | Y      | N       | N       | N     | N            |
| basic emplace support             | Y         | Y      | Y       | N       | N     | N            |
| Enhance emplace support           | Y         | Y      | N       | N       | N     | N            |
| Iterator support                  | Y         | Y      | Y       | N       | Y     | Y            |
| Sort algorithm                    | Y         | Y      | Y       | N       | Y     | Y            |
| Enhanced Sort algorithm           | Y         | Y      | Y       | N       | Y     | Y            |
| separate declare & define         | N         | N      | Y       | Y       | N     | Y            |
| Enhanced Sort algorithm           | Y         | Y      | Y       | N       | Y     | Y            |
| Full abstraction                  | Y         | Y      | N       | Y       | N     | Y            |
| Contract violation checks         | Y         | Y      | N       | N       | N     | N            |
| Natural usage                     | Y         | N      | N       | N       | N     | N            |
| Natural usage of ownership        | Y         | Y      | Y       | N       | N     | Y            |
| Basic type is stored              | Y         | Y      | Y       | Y       | Y     | N            |
| No explicit instanciation         | Y         | N      | N       | N       | N     | Y            |
| prefixed function                 | Y         | Y      | Y       | Y       | Y     | Y            |
| memory handling                   | exception | abort  | retcode | retcode | none  | retcode      |
| custom memory support             | Y         | Y      | Y       | Y       | N     | Y            |
| RAII                              | exception | nojump | nojump  | N       | N     | N            |

The used versions are:


The used versions are:

COMPONENT      | VERSION
---------------|-----------------------------------------
GCC            | 10.2
C Macro Collections | v0.23.1
CollectionsC   | ff1be366329e2c82cd85b2c803114ef8d2115f7f
CTL            | 3923e6776a231e5d58cf91225ca8a1d61879401b
M\*LIB         | d17fa4530bffb23c2eb4cb0658b4cfec9bed1ae9
STC            | 5fb5ed08250b5ad4eadd6e7a9fdc44f4519b15ff

* [C-Macro-Collections](https://github.com/LeoVen/C-Macro-Collections)
* [COLLECTIONS-C](https://github.com/srdja/Collections-C)
* CTL [by glouw](https://github.com/glouw/ctl) or [by rurban](https://github.com/rurban/ctl)
* [M\*LIB](https://github.com/P-p-H-d/mlib)
* [STC - Smart Template Container for C](https://github.com/tylov/STC)

If you see any errors in this report,
or want to include another C library,
feel free to open a pull request.
