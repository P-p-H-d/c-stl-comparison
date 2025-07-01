# Copyright (c) 2022-2023, Patrick Pelissier
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# + Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# + Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

CC=cc -std=c99
C11=cc -std=c11
CXX=c++ -std=c++11
# To mesure code size, we need to remove the sanitizers
CFLAGS=-O0 -Wall -DNDEBUG -fsanitize=address,undefined,leak -Werror=incompatible-pointer-types -g
LDFLAGS=-lgmp
RM=rm -rf
AR=ar
ARFLAGS=cr

.PHONY: all array

all: array umap glib

clean:
	$(RM) *~ *.exe **/*~
	cd bench && $(MAKE) clean

###########################################################
# 		Get external Libraries
###########################################################

distclean: clean
	$(RM) mlib
	$(RM) STC
	$(RM) ctl
	$(RM) C-Macro-Collections
	$(RM) Collections-C
	$(RM) CC
	$(RM) klib
	$(RM) sc

mlib:
	git clone https://github.com/P-p-H-d/mlib.git

STC:
	git clone https://github.com/tylov/STC.git

ctl:
	git clone https://github.com/rurban/ctl.git

C-Macro-Collections:
	git clone https://github.com/LeoVen/C-Macro-Collections.git -b v0.25.0

Collections-C:
	git clone https://github.com/srdja/Collections-C.git

CC:
	git clone https://github.com/JacksonAllan/CC.git

klib:
	git clone https://github.com/attractivechaos/klib.git

sc:
	git clone https://github.com/tezc/sc.git

###########################################################
# 		Build external Libraries
###########################################################

Collections-C/src/libCollections-C.a: Collections-C
	cd Collections-C/src && $(CC) $(CFLAGS) -Iinclude -c *.c
	cd Collections-C/src && $(AR) $(ARFLAGS) libCollections-C.a *.o
	# Build optimized version
	cd Collections-C/src && $(CC) -O2 -Wall -march=native -DNDEBUG -Iinclude -c *.c
	cd Collections-C/src && $(AR) $(ARFLAGS) libCollections-C-fast.a *.o

###########################################################
# 		Build example for array
###########################################################

array: array-mpz-mlib.exe array-mpz-stc.exe array-mpz-ctl.exe array-mpz-cmc.exe array-mpz-stl.exe array-mpz-collectionsC.exe array-mpz-CC.exe \
       array-int-mlib.exe array-int-stc.exe array-int-ctl.exe array-int-cmc.exe array-int-stl.exe array-int-collectionsC.exe array-int-CC.exe \
       array-str-mlib.exe array-str-stc.exe array-str-ctl.exe array-str-cmc.exe array-str-stl.exe array-str-collectionsC.exe array-str-CC.exe  \
	array-mpz-klib.exe array-int-klib.exe array-str-klib.exe

array-mpz-stl.exe: array-mpz/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-int-stl.exe: array-int/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-str-stl.exe: array-str/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-mpz-mlib.exe: array-mpz/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-int-mlib.exe: array-int/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-str-mlib.exe: array-str/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-mpz-stc.exe: array-mpz/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-int-stc.exe: array-int/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-str-stc.exe: array-str/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-mpz-ctl.exe: array-mpz/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-int-ctl.exe: array-int/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-str-ctl.exe: array-str/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-mpz-cmc.exe: array-mpz/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-int-cmc.exe: array-int/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-str-cmc.exe: array-str/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-mpz-collectionsC.exe: array-mpz/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-int-collectionsC.exe: array-int/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-str-collectionsC.exe: array-str/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-mpz-CC.exe: array-mpz/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-int-CC.exe: array-int/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-str-CC.exe: array-str/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-mpz-klib.exe: array-mpz/array-klib.c klib
	$(CC) $(CFLAGS) -Iklib $< -o $@ $(LDFLAGS)

array-int-klib.exe: array-int/array-klib.c klib
	$(CC) $(CFLAGS) -Iklib $< -o $@ $(LDFLAGS)

array-str-klib.exe: array-str/array-klib.c klib
	$(CC) $(CFLAGS) -Iklib $< -o $@ $(LDFLAGS)



###########################################################
# 		Build example for Unordered map
###########################################################

umap: umap-mpz-mlib.exe umap-mpz-stc.exe umap-mpz-ctl.exe umap-mpz-cmc.exe umap-mpz-stl.exe umap-mpz-collectionsC.exe umap-mpz-CC.exe \
      umap-int-mlib.exe umap-int-stc.exe umap-int-ctl.exe umap-int-cmc.exe umap-int-stl.exe umap-int-collectionsC.exe umap-int-CC.exe \
      umap-str-mlib.exe umap-str-stc.exe umap-str-ctl.exe umap-str-cmc.exe umap-str-stl.exe umap-str-collectionsC.exe umap-str-CC.exe  

umap-mpz-stl.exe: umap-mpz/umap-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

umap-int-stl.exe: umap-int/umap-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

umap-str-stl.exe: umap-str/umap-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

umap-mpz-mlib.exe: umap-mpz/umap-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

umap-int-mlib.exe: umap-int/umap-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

umap-str-mlib.exe: umap-str/umap-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

umap-mpz-stc.exe: umap-mpz/umap-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

umap-int-stc.exe: umap-int/umap-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

umap-str-stc.exe: umap-str/umap-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

umap-mpz-ctl.exe: umap-mpz/umap-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

umap-int-ctl.exe: umap-int/umap-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

umap-str-ctl.exe: umap-str/umap-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

umap-mpz-cmc.exe: umap-mpz/umap-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

umap-int-cmc.exe: umap-int/umap-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

umap-str-cmc.exe: umap-str/umap-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

umap-mpz-collectionsC.exe: umap-mpz/umap-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

umap-int-collectionsC.exe: umap-int/umap-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

umap-str-collectionsC.exe: umap-str/umap-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

umap-mpz-CC.exe: umap-mpz/umap-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

umap-int-CC.exe: umap-int/umap-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

umap-str-CC.exe: umap-str/umap-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)


###########################################################
# 		Build example for system GLIB
###########################################################

glib:
	@(pkg-config glib-2.0 && $(MAKE) all-glib) || echo "GLIB not installed"

all-glib: array-mpz-glib.exe array-int-glib.exe array-str-glib.exe \
          umap-mpz-glib.exe  umap-int-glib.exe  umap-str-glib.exe

array-mpz-glib.exe: array-mpz/array-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)

array-int-glib.exe: array-int/array-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)

array-str-glib.exe: array-str/array-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)

umap-mpz-glib.exe: umap-mpz/umap-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)

umap-int-glib.exe: umap-int/umap-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)

umap-str-glib.exe: umap-str/umap-glib.c
	$(CC) $(CFLAGS) $< -o $@ `pkg-config --cflags --libs glib-2.0` $(LDFLAGS)
