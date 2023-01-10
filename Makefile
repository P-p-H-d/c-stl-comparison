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
CXX=c++ -std=c++11
CFLAGS=-Os -march=native -Wall -DNDEBUG
#-fsanitize=address,undefined,leak
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

mlib:
	git clone https://github.com/P-p-H-d/mlib.git

STC:
	git clone https://github.com/tylov/STC.git

ctl:
	git clone https://github.com/rurban/ctl.git

C-Macro-Collections:
	git clone https://github.com/LeoVen/C-Macro-Collections.git

Collections-C:
	git clone https://github.com/srdja/Collections-C.git

###########################################################
# 		Build external Libraries
###########################################################

Collections-C/src/libCollections-C.a: Collections-C
	cd Collections-C/src && $(CC) $(CFLAGS) -Iinclude -c *.c
	cd Collections-C/src && $(AR) $(ARFLAGS) libCollections-C.a *.o

###########################################################
# 		Build example for array
###########################################################

array: array-mlib.exe array-stc.exe array-ctl.exe array-cmc.exe array-stl.exe array-collectionsC.exe

array-mlib.exe: mlib array-mlib.c
	$(CC) $(CFLAGS) -Imlib array-mlib.c -o array-mlib.exe $(LDFLAGS)

array-stc.exe: STC array-stc.c
	$(CC) $(CFLAGS) -ISTC/include array-stc.c -o array-stc.exe $(LDFLAGS)

array-ctl.exe: ctl array-ctl.c
	$(CC) $(CFLAGS) -Ictl/ array-ctl.c -o array-ctl.exe $(LDFLAGS)

array-cmc.exe: C-Macro-Collections array-cmc.c
	$(CC) $(CFLAGS) -IC-Macro-Collections/src array-cmc.c -o array-cmc.exe $(LDFLAGS)

array-stl.exe: array-stl.cc
	$(CXX) $(CFLAGS) array-stl.cc -o array-stl.exe -lgmpxx $(LDFLAGS)

array-collectionsC.exe: Collections-C Collections-C/src/libCollections-C.a array-collectionsC.c
	$(CC) $(CFLAGS) -ICollections-C/src/include array-collectionsC.c -o array-collectionsC.exe $(LDFLAGS) Collections-C/src/libCollections-C.a
