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
CFLAGS=-Os -march=native -Wall -DNDEBUG -fsanitize=address,undefined,leak
LDFLAGS=-lgmp
RM=rm -rf
AR=ar
ARFLAGS=cr

.PHONY: all array

all: array

clean:
	$(RM) *~ *.exe

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

###########################################################
# 		Build external Libraries
###########################################################

Collections-C/src/libCollections-C.a: Collections-C
	cd Collections-C/src && $(CC) $(CFLAGS) -Iinclude -c *.c
	cd Collections-C/src && $(AR) $(ARFLAGS) libCollections-C.a *.o

###########################################################
# 		Build example for array
###########################################################

array: array-mpz-mlib.exe array-mpz-stc.exe array-mpz-ctl.exe array-mpz-cmc.exe array-mpz-stl.exe array-mpz-collectionsC.exe array-mpz-CC.exe array-mpz-glib.exe \
       array-int-mlib.exe array-int-stc.exe array-int-ctl.exe array-int-cmc.exe array-int-stl.exe array-int-collectionsC.exe array-int-CC.exe array-int-glib.exe \
       array-str-mlib.exe array-str-stc.exe array-str-ctl.exe array-str-cmc.exe array-str-stl.exe array-str-collectionsC.exe array-str-CC.exe array-str-glib.exe 

array-mpz-stl.exe: test-mpz/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-int-stl.exe: test-int/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-str-stl.exe: test-str/array-stl.cc
	$(CXX) $(CFLAGS) $< -o $@ -lgmpxx $(LDFLAGS)

array-mpz-mlib.exe: test-mpz/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-int-mlib.exe: test-int/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-str-mlib.exe: test-str/array-mlib.c mlib 
	$(CC) $(CFLAGS) -Imlib $< -o $@ $(LDFLAGS)

array-mpz-stc.exe: test-mpz/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-int-stc.exe: test-int/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-str-stc.exe: test-str/array-stc.c STC 
	$(CC) $(CFLAGS) -ISTC/include $< -o $@ $(LDFLAGS)

array-mpz-ctl.exe: test-mpz/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-int-ctl.exe: test-int/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-str-ctl.exe: test-str/array-ctl.c ctl 
	$(CC) $(CFLAGS) -Ictl/ $< -o $@ $(LDFLAGS)

array-mpz-cmc.exe: test-mpz/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-int-cmc.exe: test-int/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-str-cmc.exe: test-str/array-cmc.c C-Macro-Collections 
	$(CC) $(CFLAGS) -IC-Macro-Collections/src $< -o $@ $(LDFLAGS)

array-mpz-collectionsC.exe: test-mpz/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-int-collectionsC.exe: test-int/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-str-collectionsC.exe: test-str/array-collectionsC.c Collections-C Collections-C/src/libCollections-C.a 
	$(CC) $(CFLAGS) -ICollections-C/src/include $< -o $@ $(LDFLAGS) Collections-C/src/libCollections-C.a

array-mpz-CC.exe: test-mpz/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-int-CC.exe: test-int/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-str-CC.exe: test-str/array-CC.c CC 
	$(C11) $(CFLAGS) -ICC $< -o $@ $(LDFLAGS)

array-mpz-glib.exe: test-mpz/array-glib.c
	$(CC) $(CFLAGS) `pkg-config --cflags --libs glib-2.0` $< -o $@ $(LDFLAGS)

array-int-glib.exe: test-int/array-glib.c
	$(CC) $(CFLAGS) `pkg-config --cflags --libs glib-2.0` $< -o $@ $(LDFLAGS)

array-str-glib.exe: test-str/array-glib.c
	$(CC) $(CFLAGS) `pkg-config --cflags --libs glib-2.0` $< -o $@ $(LDFLAGS)
