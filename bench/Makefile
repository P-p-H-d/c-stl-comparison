# Copyright (c) 2017-2026, Patrick Pelissier
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

CC=cc -std=c11
CXX=c++ -std=c++11
CFLAGS=-O2 -march=native -Wall
XCFLAGS=
CPPFLAGS=
N=4
BENCH_DEF=
RM=rm -rf
LOG=--quiet --best --repeat 3| tee -a logs.txt

.PHONY: all pgo container queue string plain bench-mlib bench-stl bench-qt bench-glib bench-klib bench-sparsepp bench-collectionc bench-tommyds bench-flathashmap bench-emilib bench-emhash bench-hopscotchmap bench-mlib-thread bench-liblfds bench-concurrentqueue bench-boost bench-string bench-plain bench-rigtorp-mpmc-queue bench-cmc

all: container-c container-cpp queue plain

pgo:
	$(MAKE) all XCFLAGS="-fprofile-generate=pgo"
	$(MAKE) all XCFLAGS="-fprofile-use=pgo"

#########################################################################

container-c: bench-mlib bench-glib bench-klib bench-ctl bench-stc bench-CC bench-cmc bench-collectionc bench-tommyds bench-uthash bench-qlibc bench-libsrt bench-pottery bench-verstable bench-xxhash bench-bstrlib bench-sds
	@echo
	@echo

container-cpp: bench-stl bench-qt bench-sparsepp bench-densehashmap bench-flathashmap bench-emilib bench-emhash bench-hopscotchmap bench-rigtorp-hashmap bench-boost bench-rapidjson
	@echo
	@echo

queue: bench-mlib-thread bench-liblfds bench-concurrentqueue bench-rigtorp-mpmc-queue bench-boost-queue
	@echo
	@echo

string: bench-string
	@echo
	@echo

plain: bench-plain
	@echo
	@echo

# Test if MLIB directory exists, otherwise bootstrap it (and all other libraries too)
pre-bench:
	@test -d $(MLIB) || ( cd .. && make )

#########################################################################
# Directories of the checkout libraries
# There are always present (no environment option to set)
MLIB=../external/mlib
CMC=../external/C-Macro-Collections/src/
STC=../external/STC/
CTL=../external/ctl
CCLIB=../external/CC
COLLECTIONC=../external/Collections-C
KLIB=../external/klib

############################################################################
# C Libraries
############################################################################

bench-mlib: pre-bench
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) -pthread bench-mlib.c common.c -o bench-mlib.exe
	@./bench-mlib.exe 100 $(LOG)
	@./bench-mlib.exe 101 $(LOG)
	@./bench-mlib.exe 110 $(LOG)
	@./bench-mlib.exe 120 $(LOG)
	@./bench-mlib.exe 200 $(LOG)
	@./bench-mlib.exe 210 $(LOG)
	@./bench-mlib.exe 300 $(LOG)
	@./bench-mlib.exe 301 $(LOG)
	@./bench-mlib.exe 302 2> /dev/null $(LOG)
	@./bench-mlib.exe 310 $(LOG)
	@./bench-mlib.exe 320 $(LOG)
	@./bench-mlib.exe 321 $(LOG)
	@./bench-mlib.exe 330 $(LOG)
	@./bench-mlib.exe 340 $(LOG)
	@./bench-mlib.exe 500 $(LOG)
	@./bench-mlib.exe 510 $(LOG)
	@./bench-mlib.exe 700 $(LOG)
	@./bench-mlib.exe 701 $(LOG)
	@./bench-mlib.exe 850 $(LOG)
	@./bench-mlib.exe 860 $(LOG)
	@./bench-mlib.exe 870 $(LOG)
	@./bench-mlib.exe 900 $(LOG)
	@./bench-mlib.exe 910 $(LOG)

bench-mlib-thread:
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(MLIB) bench-mlib.c common.c -DMULTI_THREAD_MEASURE -pthread -o bench-mlib-thread.exe
	@./bench-mlib-thread.exe 600 $(LOG)
	@./bench-mlib-thread.exe 601 $(LOG)
	@./bench-mlib-thread.exe 602 $(LOG)
	@./bench-mlib-thread.exe 603 $(LOG)
	@./bench-mlib-thread.exe 604 $(LOG)
	@./bench-mlib-thread.exe 605 $(LOG)
	@./bench-mlib-thread.exe 610 $(LOG)

bench-CC:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(CCLIB) bench-CC.c common.c -o bench-CC.exe
	@./bench-CC.exe 100 $(LOG)
	@./bench-CC.exe 110 $(LOG)
	@./bench-CC.exe 300 $(LOG)
	@./bench-CC.exe 320 $(LOG)
	@./bench-CC.exe 340 $(LOG)

bench-klib:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -Wno-unused-function -I $(KLIB) bench-klib.c common.c -o bench-klib.exe
	@./bench-klib.exe 100 $(LOG)
	@./bench-klib.exe 110 $(LOG)
	@./bench-klib.exe 200 $(LOG)
	@./bench-klib.exe 300 $(LOG)
	@./bench-klib.exe 320 $(LOG)
#	@./bench-klib.exe 340 $(LOG)	# Result is buggy: not run
	@./bench-klib.exe 500 $(LOG)

bench-cmc:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(CMC) bench-cmc.c common.c -o bench-cmc.exe
	@./bench-cmc.exe 110 $(LOG)
	@./bench-cmc.exe 200 $(LOG)
	@./bench-cmc.exe 300 $(LOG)

bench-collectionc:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(COLLECTIONC)/src/include/  bench-collectionc.c common.c $(COLLECTIONC)/src/libCollections-C-fast.a -o bench-collectionc.exe
	@./bench-collectionc.exe 100 $(LOG)
	@./bench-collectionc.exe 110 $(LOG)
	@./bench-collectionc.exe 200 $(LOG)
	@./bench-collectionc.exe 300 $(LOG)
	@./bench-collectionc.exe 320 $(LOG)
	@./bench-collectionc.exe 500 $(LOG)

bench-ctl:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) -I $(CTL) bench-ctl.c common.c -o bench-ctl.exe
	@./bench-ctl.exe 100 $(LOG)
	@./bench-ctl.exe 110 $(LOG)
	@./bench-ctl.exe 200 $(LOG)
	@./bench-ctl.exe 300 $(LOG)
	@./bench-ctl.exe 340 $(LOG)
	@./bench-ctl.exe 500 $(LOG)
#	@./bench-ctl.exe 900 $(LOG)	# Result is way too slow, so it is not run
	@./bench-ctl.exe 910 $(LOG)

bench-stc:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(STC)/include bench-stc.c common.c -o bench-stc.exe
	@./bench-stc.exe 100 $(LOG)
	@./bench-stc.exe 110 $(LOG)
	@./bench-stc.exe 200 $(LOG)
	@./bench-stc.exe 300 $(LOG)
	@./bench-stc.exe 320 $(LOG)
	@./bench-stc.exe 340 $(LOG)
	@./bench-stc.exe 500 $(LOG)
	@./bench-stc.exe 900 $(LOG)
	@./bench-stc.exe 910 $(LOG)

bench-pottery:
	@cd .. && make external/pottery
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/pottery/util -I ../external/pottery/include -I ../external/mlib bench-pottery.c common.c ../external/pottery/util/pottery/string/string.c -o bench-pottery.exe
	@./bench-pottery.exe 100 $(LOG)
	@./bench-pottery.exe 110 $(LOG)
#	@./bench-pottery.exe 200 $(LOG)	# Result is incorrect, so it is not run
	@./bench-pottery.exe 300 $(LOG)
	@./bench-pottery.exe 320 $(LOG)
	@./bench-pottery.exe 500 $(LOG)
#	@./bench-pottery.exe 900 $(LOG)	# Result is too slow, so it is not run
	@./bench-pottery.exe 910 $(LOG)

bench-verstable:
	@cd .. && make external/Verstable
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/Verstable -I ../external/mlib bench-verstable.c common.c -o bench-verstable.exe
	@./bench-verstable.exe 300 $(LOG)
	@./bench-verstable.exe 320 $(LOG)
	@./bench-verstable.exe 340 $(LOG)

# GLIB shall point to the the directory containing the file .pc are stored (can be let empty if system installed)
bench-glib:
	@(PKG_CONFIG_PATH="$${GLIB}" pkg-config glib-2.0 && $(MAKE) bench-glib0) || echo "GLIB not installed"
bench-glib0:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) bench-glib.c common.c -o bench-glib.exe `PKG_CONFIG_PATH="$${GLIB}" pkg-config --libs --cflags glib-2.0`
	@./bench-glib.exe 100 $(LOG)
	@./bench-glib.exe 110 $(LOG)
	@./bench-glib.exe 200 $(LOG)
	@./bench-glib.exe 300 $(LOG)	# Quite slow. To disable?
	@./bench-glib.exe 320 $(LOG)
	@./bench-glib.exe 500 $(LOG)
#	@./bench-glib.exe 900 $(LOG)	# Result is too slow, so it is not run
	@./bench-glib.exe 910 $(LOG)

bench-tommyds:
	@cd .. && make external/tommyds
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "../external/tommyds" bench-tommyds.c ../external/tommyds/tommyds/tommyarray.c ../external/tommyds/tommyds/tommylist.c ../external/tommyds/tommyds/tommytree.c ../external/tommyds/tommyds/tommyhashlin.c common.c -o bench-tommyds.exe
	@./bench-tommyds.exe 100 $(LOG)
	@./bench-tommyds.exe 110 $(LOG)
	@./bench-tommyds.exe 200 $(LOG)
	@./bench-tommyds.exe 300 $(LOG)
	@./bench-tommyds.exe 320 $(LOG)

bench-uthash:
	@cd .. && make external/uthash
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/uthash bench-uthash.c common.c -o bench-uthash.exe
	@./bench-uthash.exe 100 $(LOG)
	@./bench-uthash.exe 110 $(LOG)
	@./bench-uthash.exe 300 $(LOG)
	@./bench-uthash.exe 320 $(LOG)
	@./bench-uthash.exe 500 $(LOG)

bench-qlibc:
	@cd .. && make external/qlibc/lib/libqlibc.a
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "../external/qlibc/include" -pthread bench-qlibc.c common.c ../external/qlibc/lib/libqlibc.a -o bench-qlibc.exe
	@./bench-qlibc.exe 100 $(LOG)
	@./bench-qlibc.exe 110 $(LOG)
	@./bench-qlibc.exe 200 $(LOG)

bench-libsrt:
	@cd .. && make external/libsrt/src/.libs/libsrt.a
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "../external/libsrt/src" bench-libsrt.c common.c -o bench-libsrt.exe ../external/libsrt/src/.libs/libsrt.a 
	@./bench-libsrt.exe 110 $(LOG)
	@./bench-libsrt.exe 500 $(LOG)

bench-liblfds:
	@cd .. && make external/liblfds7.1.1/bin/liblfds711.a
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/mlib -I "../external/liblfds7.1.1/inc" -Wno-unknown-pragmas bench-liblfds.c common.c -DMULTI_THREAD_MEASURE -o bench-liblfds.exe ../external/liblfds7.1.1/bin/liblfds711.a -lpthread
	@./bench-liblfds.exe 600 $(LOG)

bench-xxhash:
	@cd .. && make external/xxHash
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "../external/xxHash/" bench-xxhash.c common.c -o bench-xxhash.exe
	@./bench-xxhash.exe 700 $(LOG)

bench-sds:
	@cd .. && make external/sds
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/sds bench-sds.c common.c ../external/sds/sds.c -o bench-sds.exe
#	@./bench-sds.exe 900 $(LOG)	# Result is too slow, so it is not run
	@./bench-sds.exe 910 $(LOG)

bench-bstrlib:
	@cd .. && make external/bstrlib/libbstrlib.a
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/bstrlib bench-bstrlib.c common.c ../external/bstrlib/libbstrlib.a -o bench-bstrlib.exe
	@./bench-bstrlib.exe 900 $(LOG)
	@./bench-bstrlib.exe 910 $(LOG)

############################################################################
# C++ Libraries
############################################################################

bench-stl:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) bench-stl.cpp common.c -o bench-stl.exe
	@./bench-stl.exe 100 $(LOG)
	@./bench-stl.exe 110 $(LOG)
	@./bench-stl.exe 120 $(LOG)
	@./bench-stl.exe 200 $(LOG)
#	@./bench-stl.exe 300 $(LOG)	# Too slow
	@./bench-stl.exe 301 $(LOG)
	@./bench-stl.exe 320 $(LOG)
	@./bench-stl.exe 330 $(LOG)
	@./bench-stl.exe 331 $(LOG)
	@./bench-stl.exe 340 $(LOG)
	@./bench-stl.exe 500 $(LOG)
	@./bench-stl.exe 510 $(LOG)
	@./bench-stl.exe 900 $(LOG)
	@./bench-stl.exe 910 $(LOG)

# QT shall point to the the directory containing the file .pc are stored (can be let empty if system installed)
bench-qt:
	@(PKG_CONFIG_PATH="$${QT}" pkg-config Qt5Core && $(MAKE) bench-qt0) || echo "QT not installed"
bench-qt0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -fPIC bench-qt.cpp common.c -o bench-qt.exe `PKG_CONFIG_PATH="$${QT}" pkg-config --libs --cflags Qt5Core`
	@./bench-qt.exe 10
	@./bench-qt.exe 20
	@./bench-qt.exe 30
	@./bench-qt.exe 40
	@./bench-qt.exe 41
	@./bench-qt.exe 42
	@./bench-qt.exe 50

# BOOST shall point to the header location.
bench-boost:
	@if test -n "$${BOOST}" ; then $(MAKE) bench-boost0 ; else echo "Nothing to be done for BOOST." ; fi
bench-boost0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) -I "$${BOOST}" bench-boost.cpp common.c -o bench-boost.exe -lpthread
	@./bench-boost.exe 300 $(LOG)
	@./bench-boost.exe 310 $(LOG)
	@./bench-boost.exe 320 $(LOG)
	@./bench-boost.exe 330 $(LOG)

bench-boost-queue:
	@if test -n "$${BOOST}" ; then $(MAKE) bench-boost-queue0 ; else echo "Nothing to be done for BOOST." ; fi
bench-boost-queue0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) -I "$${BOOST}" bench-boost.cpp common.c -DMULTI_THREAD_MEASURE -o bench-boost-thread.exe -lpthread
	@./bench-boost-thread.exe 600 $(LOG)

# SPARSEPP shall point to the directory where the headers are
bench-sparsepp:
	@if test -n "$${SPARSEPP}" ; then $(MAKE) bench-sparsepp0 ; else echo "Nothing to be done for SPARSEPP." ; fi
bench-sparsepp0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${SPARSEPP}"  -I "$${SPARSEPP}/.." bench-sparsepp.cpp common.c -o bench-sparsepp.exe
	@./bench-sparsepp.exe 41
	@./bench-sparsepp.exe 42
	@./bench-sparsepp.exe 43

# DENSEHASHMAP shall point to the directory where the src are
bench-densehashmap:
	@if test -n "$${DENSEHASHMAP}" ; then $(MAKE) bench-densehashmap0 ; else echo "Nothing to be done Google DENSEHASHMAP." ; fi
bench-densehashmap0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${DENSEHASHMAP}"  -I "$${DENSEHASHMAP}/.." bench-densehashmap.cpp common.c -o bench-densehashmap.exe
	@./bench-densehashmap.exe 41
	@./bench-densehashmap.exe 42
	@./bench-densehashmap.exe 43

# FLATHASHMAP shall point to the directory where the headers are
bench-flathashmap:
	@if test -n "$${FLATHASHMAP}" ; then $(MAKE) bench-flathashmap0 ; else echo "Nothing to be done for FLATHASHMAP." ; fi
bench-flathashmap0:
	$(CXX) -std=c++14 $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${FLATHASHMAP}" bench-flathashmap.cpp common.c -o bench-flathashmap.exe
	@./bench-flathashmap.exe 41
	@./bench-flathashmap.exe 42
	@./bench-flathashmap.exe 46
	@./bench-flathashmap.exe 43

# EMILIB shall point to the directory where the headers are
bench-emilib:
	@if test -n "$${EMILIB}" ; then $(MAKE) bench-emilib0 ; else echo "Nothing to be done for EMILIB." ; fi
bench-emilib0:
	$(CXX) -std=c++14 $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${EMILIB}" bench-emilib.cpp common.c -o bench-emilib.exe
	@./bench-emilib.exe 41
	@./bench-emilib.exe 42
	@./bench-emilib.exe 46
	@./bench-emilib.exe 43

# EMHASh shall point to the directory where the headers are
bench-emhash:
	@if test -n "$${EMHASH}" ; then $(MAKE) bench-emhash0 ; else echo "Nothing to be done for EMHASH." ; fi
bench-emhash0:
	$(CXX) -std=c++14 $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${EMHASH}" bench-emhash.cpp common.c -o bench-emhash.exe
	@./bench-emhash.exe 41
	@./bench-emhash.exe 42
	@./bench-emhash.exe 46
	@./bench-emhash.exe 43

# HOPSCOTCHMAP shall point to the directory where the source are
bench-hopscotchmap:
	@if test -n "$${HOPSCOTCHMAP}" ; then $(MAKE) bench-hopscotchmap0 ; else echo "Nothing to be done for HOPSCOTCHMAP." ; fi
bench-hopscotchmap0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${HOPSCOTCHMAP}/include/tsl" bench-hopscotchmap.cpp common.c -o bench-hopscotchmap.exe
	@./bench-hopscotchmap.exe 41
	@./bench-hopscotchmap.exe 42
	@./bench-hopscotchmap.exe 43

# CONCURRENTQUEUE shall point to the directory where the bin/build/inc/obj/src directories are
# The library shall be built.
bench-concurrentqueue:
	@if test -n "$${CONCURRENTQUEUE}" ; then $(MAKE) bench-concurrentqueue0 ; else echo "Nothing to be done for CONCURRENTQUEUE." ; fi
bench-concurrentqueue0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${CONCURRENTQUEUE}/" bench-concurrentqueue.cpp common.c -DMULTI_THREAD_MEASURE  -o bench-concurrentqueue.exe -lpthread
	@./bench-concurrentqueue.exe 60

# RIGTORP_HASHMAP shall point to the directory where the headers are
bench-rigtorp-hashmap:
	@if test -n "$${RIGTORP_HASHMAP}" ; then $(MAKE) bench-rigtorp-hashmap0 ; else echo "Nothing to be done for RIGTORP_HASHMAP." ; fi
bench-rigtorp-hashmap0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${RIGTORP_HASHMAP}/include" bench-rigtorp-hashmap.cpp common.c -o bench-rigtorp-hashmap.exe
	@./bench-rigtorp-hashmap.exe 42
	@./bench-rigtorp-hashmap.exe 41
	@./bench-rigtorp-hashmap.exe 43

# RIGTORP_MPMC_QUEUE shall point to the directory where the headers are
bench-rigtorp-mpmc-queue:
	@if test -n "$${RIGTORP_MPMC_QUEUE}" ; then $(MAKE) bench-rigtorp-mpmc-queue0 ; else echo "Nothing to be done for RIGTORP_MPMC_QUEUE." ; fi
bench-rigtorp-mpmc-queue0:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I "$${RIGTORP_MPMC_QUEUE}" bench-rigtorp-mpmcqueue.cpp common.c -DMULTI_THREAD_MEASURE -o bench-mpmcqueue.exe -lpthread
	@./bench-mpmcqueue.exe 60

bench-rapidjson:
	@cd .. && make external/rapidjson
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I ../external/rapidjson/include bench-rapidjson.cpp common.c -o bench-rapidjson.exe
	@./bench-rapidjson.exe 850 $(LOG)
	@./bench-rapidjson.exe 860 $(LOG)
	@./bench-rapidjson.exe 870 $(LOG)

############################################################################

bench-plain:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) bench-plain-c.c -o bench-plain-c.exe
	@./bench-plain-c.exe

############################################################################

bench-maxdict:
	$(CC) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) max-dict.c -o bench-max-dict.exe
	@./bench-max-dict.exe

############################################################################

# BSTRLIB shall point to the BSTRLIB sources
# LIBSRT shall point to the LIBSRT sources
bench-string:
	@if test -n "$${BSTRLIB}" ; then $(MAKE) bench-string-step2 BENCH_DEF="-DBENCH_CAN_USE_BSTRLIB -I ${BSTRLIB} $${BSTRLIB}/obj/bstrlib.o $${BSTRLIB}/obj/bstraux.o $${BSTRLIB}/obj/bstrwrap.o" ; else $(MAKE) bench-string-step2 ; fi

#NOTE: Need to build by hand sds.o since it is not build by default and sds.c is not compatible with C++
bench-string-step2:
	@if test -n "$${SDS}" ; then $(MAKE) bench-string-step4 BENCH_DEF="$(BENCH_DEF) -fpermissive -DBENCH_CAN_USE_SDS -I$${SDS}/ $${SDS}/sds.o" ; else $(MAKE) bench-string-step4 BENCH_DEF="$(BENCH_DEF)"; fi

bench-string-step4:
	@PKG_CONFIG_PATH=$${GLIB} pkg-config glib-2.0 && $(MAKE) bench-string-step6 BENCH_DEF="$(BENCH_DEF) -DBENCH_CAN_USE_GLIB $$(PKG_CONFIG_PATH=$${GLIB} pkg-config --cflags --libs glib-2.0)" || $(MAKE) bench-string-step6 BENCH_DEF="$(BENCH_DEF)"

bench-string-step6:
	$(CXX) $(CFLAGS) $(XCFLAGS) $(CPPFLAGS) -I $(MLIB) -I ../external/pottery/util -I ../external/pottery/include -I ../external/libsrt/src bench-string.cpp common.c ../external/pottery/util/pottery/string/string.c ../external/libsrt/src/.libs/libsrt.a $(BENCH_DEF) -o bench-string.exe 
	@./bench-string.exe

############################################################################

clean:
	$(RM) *.o bench-*.exe
	$(RM) bench-*.s *~ massif.out.*
	$(RM) plot-*.dat
	$(RM) pgo logs.txt
	$(RM) tmp-serial.*
	cd nucleotide && $(MAKE) clean

############################################################################

massif-do: all
	@valgrind --tool=massif ./bench-mlib.exe $(N)
	@valgrind --tool=massif ./bench-stl.exe $(N)
	@valgrind --tool=massif ./bench-qt.exe $(N)
	@valgrind --tool=massif ./bench-glib.exe $(N)
	@test -f ./bench-klib.exe && valgrind --tool=massif ./bench-klib.exe $(N)

massif-visu:
	test -f massif.out.* || $(MAKE) massif-do
	for i in massif.out.* ; do ms_print $$i|head -30 ; done

############################################################################

report: report-seq report-sset report-umap report-umap-big report-umap-str report-sort report-queue report-hash report-str-replace report-str-concat report-uset
	@mkdir -p doc
	@cat BENCH-*.md > doc/BENCH.md
	@echo >> doc/BENCH.md
	@LANG=C lscpu |grep "Model name" >> doc/BENCH.md
	@echo >> doc/BENCH.md
	@cd ../external &&  for i in * ; do cd $$i ; echo "* $$i $$(git show HEAD|grep commit|head -1|sed -e 's/commit/:/g')" ; cd - > /dev/null ;done >> ../bench/doc/BENCH.md
	@rm BENCH-*.md
	@cat doc/BENCH.md

report-seq:
	@echo "# Bench for best sequence container" > BENCH-SEQ.md
	@echo >> BENCH-SEQ.md
	@echo "Rank|Library|Container|Time" >> BENCH-SEQ.md
	@echo "----|-------|---------|----" >> BENCH-SEQ.md
	@grep Seq logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-SEQ.md
	@echo >> BENCH-SEQ.md
	@echo "Note: Bench for Array based containers works on dataset 10x bigger than size of List based containers." >> BENCH-SEQ.md
	@echo >> BENCH-SEQ.md

report-sset:
	@echo "# Bench for best sorted set container" > BENCH-SSET.md
	@echo >> BENCH-SSET.md
	@echo "Rank|Library|Container|Time" >> BENCH-SSET.md
	@echo "----|-------|---------|----" >> BENCH-SSET.md
	@grep SSet logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-SSET.md
	@echo >> BENCH-SSET.md

report-umap:
	@echo "# Bench for best unordered map U64 container" > BENCH-UMAP.md
	@echo >> BENCH-UMAP.md
	@echo "Rank|Library|Container|Time" >> BENCH-UMAP.md
	@echo "----|-------|---------|----" >> BENCH-UMAP.md
	@grep "UMap U64" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-UMAP.md
	@echo >> BENCH-UMAP.md

report-umap-big:
	@echo "# Bench for best unordered map BIG container" > BENCH-UMAP2.md
	@echo >> BENCH-UMAP2.md
	@echo "Rank|Library|Container|Time" >> BENCH-UMAP2.md
	@echo "----|-------|---------|----" >> BENCH-UMAP2.md
	@grep "UMap Big" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-UMAP2.md
	@echo >> BENCH-UMAP2.md

report-umap-str:
	@echo "# Bench for best unordered map string container" > BENCH-UMAP-STR.md
	@echo >> BENCH-UMAP-STR.md
	@echo "Rank|Library|Container|Time" >> BENCH-UMAP-STR.md
	@echo "----|-------|---------|----" >> BENCH-UMAP-STR.md
	@grep "UMap Str" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-UMAP-STR.md
	@echo >> BENCH-UMAP-STR.md

report-uset:
	@echo "# Bench for best unordered set container" > BENCH-USET.md
	@echo >> BENCH-USET.md
	@echo "Rank|Library|Container|Time" >> BENCH-USET.md
	@echo "----|-------|---------|----" >> BENCH-USET.md
	@grep "USet Longest" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-USET.md
	@echo >> BENCH-USET.md

report-sort:
	@echo "# Bench for best sort container" > BENCH-SORT.md
	@echo >> BENCH-SORT.md
	@echo "Rank|Library|Container|Time" >> BENCH-SORT.md
	@echo "----|-------|---------|----" >> BENCH-SORT.md
	@grep "Sort" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-SORT.md
	@echo >> BENCH-SORT.md

report-queue:
	@echo "# Bench for best thread queue container" > BENCH-QUEUE.md
	@echo >> BENCH-QUEUE.md
	@echo "Rank|Library|Container|Time" >> BENCH-QUEUE.md
	@echo "----|-------|---------|----" >> BENCH-QUEUE.md
	@grep "Queue" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-QUEUE.md
	@echo >> BENCH-QUEUE.md

report-hash:
	@echo "# Bench for best hash" > BENCH-HASH.md
	@echo >> BENCH-HASH.md
	@echo "Rank|Library|Container|Time" >> BENCH-HASH.md
	@echo "----|-------|---------|----" >> BENCH-HASH.md
	@grep "Hash " logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-HASH.md
	@echo >> BENCH-HASH.md

report-str-replace:
	@echo "# Bench for best string replacement" > BENCH-STR-REPLACE.md
	@echo >> BENCH-STR-REPLACE.md
	@echo "Rank|Library|Container|Time" >> BENCH-STR-REPLACE.md
	@echo "----|-------|---------|----" >> BENCH-STR-REPLACE.md
	@grep "String Replace" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-STR-REPLACE.md
	@echo >> BENCH-STR-REPLACE.md
	@echo "GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow">> BENCH-STR-REPLACE.md
	@echo >> BENCH-STR-REPLACE.md

report-str-concat:
	@echo "# Bench for best string concat" > BENCH-STR-CONCAT.md
	@echo >> BENCH-STR-CONCAT.md
	@echo "Rank|Library|Container|Time" >> BENCH-STR-CONCAT.md
	@echo "----|-------|---------|----" >> BENCH-STR-CONCAT.md
	@grep "String Concat" logs.txt |awk -F'=' '{print $$2, "=", $$1}'|sort -g|awk -F'=' '{print $$2,"=",$$1}'|sed 's/\[.*\]//g'|sed 's/time  =/:/g'|awk -F':' '{print NR, "|", $$1,"|",$$2,"|",$$3}' >> BENCH-STR-CONCAT.md
	@echo >> BENCH-STR-CONCAT.md
