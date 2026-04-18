# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   643.38 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   867.21 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1252.90 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   28.10 ms | 1 | 3
2 |  M*LIB |       Queue(SPSC P2)    |   45.65 ms | 2 | 3
3 |  M*LIB |       Queue(MPMC P2)    |   49.75 ms | 1 | 3
4 |  M*LIB |          Queue(MPMC)    |   74.90 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   430.10 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   806.83 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1131.43 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1326.70 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1839.31 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 6
2 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 6
3 |  M*LIB |       Queue(SPSC P2)   |   397.31K| 1 | 8
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 8
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 9
8 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 2 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   638.16 ms | 1 | 5
2 |  CTL |           Seq(Array)    |   681.19 ms | 2 | 5
3 |  STC |           Seq(Array)    |   697.98 ms | 1 | 4
4 |  M*LIB |           Seq(Array)    |   745.01 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   745.33 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   908.11 ms | 6 | 14
7 |  M*LIB |            Seq(List)    |   924.56 ms | 7 | 12
8 |  STC |            Seq(List)    |   940.05 ms | 6 | 12
9 |  M*LIB |          Seq(DPList)    |   944.36 ms | 6 | 12
10 |  UT-HASH |            Seq(List)    |   947.55 ms | 8 | 13
11 |  POTTERY |            Seq(List)    |   967.54 ms | 7 | 11
12 |  CTL |            Seq(List)    |   968.71 ms | 7 | 12
13 |  TommyDS |            Seq(List)    |   1013.48 ms | 11 | 19
14 |  CC |            Seq(List)    |   1059.38 ms | 13 | 14
15 |  CollectionC |            Seq(List)    |   1118.89 ms | 8 | 17
16 |  GLIB |            Seq(List)    |   1139.79 ms | 15 | 18
17 |  STL |            Seq(List)    |   1178.20 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1260.40 ms | 17 | 24
19 |  STL |           Seq(Array)    |   1584.11 ms | 19 | 21
20 |  CMC |           Seq(Array)    |   1612.07 ms | 19 | 22
21 |  STB-DS |        Seq(DynArray)    |   1706.20 ms | 15 | 22
22 |  STL |           Seq(Deque)    |   1792.76 ms | 21 | 23
23 |  CollectionC |           Seq(Array)    |   2124.60 ms | 23 | 26
24 |  CC |           Seq(Array)    |   2327.49 ms | 21 | 24
25 |  QLIBC |            Seq(List)    |   2546.79 ms | 25 | 27
26 |  TommyDS |           Seq(Array)    |   2764.84 ms | 17 | 26
27 |  POTTERY |           Seq(Array)    |   2951.75 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   3251.90 ms | 27 | 28
29 |  LIBSRT |           Seq(Array)    |   4743.23 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   6570.28 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 8
2 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
3 |  GLIB |            Seq(List)   |   1.28G| 2 | 10
4 |  STL |            Seq(List)   |   1.28G| 4 | 9
5 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
6 |  STC |            Seq(List)   |   1.28G| 3 | 8
7 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
8 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
9 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
10 |  CTL |            Seq(List)   |   1.28G| 1 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
14 |  CC |           Seq(Array)   |   1.60G| 14 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
19 |  STC |           Seq(Array)   |   1.60G| 18 | 20
20 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
21 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 21
22 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
23 |  STL |           Seq(Array)   |   1.61G| 23 | 23
24 |  STL |           Seq(Deque)   |   1.68G| 24 | 24
25 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 25
26 |  TommyDS |            Seq(List)   |   1.92G| 26 | 26
27 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
28 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 28
29 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 29
30 |  GLIB |           Seq(Array)   |   4.81G| 30 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1046.81 ms | 1 | 2
2 |  STL |                 Sort    |   1107.56 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1155.96 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1243.06 ms | 4 | 5
5 |  STL |          Stable Sort    |   1283.83 ms | 3 | 5
6 |  CTL |                 Sort    |   1499.80 ms | 6 | 7
7 |  KLIB |                 Sort    |   1575.03 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1667.57 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1694.66 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1699.86 ms | 8 | 10
11 |  GLIB |                 Sort    |   1752.20 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2901.15 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.29M| 1 | 3
2 |  STC |                 Sort   |   41.82M| 1 | 3
3 |  KLIB |                 Sort   |   42.08M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.42M| 5 | 5
6 |  M*LIB |                 Sort   |   81.15M| 6 | 8
7 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
8 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   162.12M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   793.73 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   883.51 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1857.34 ms | 3 | 3
4 |  M*LIB |         SSet(Rbtree)    |   2362.65 ms | 4 | 7
5 |  CTL |            SSet(set)    |   2412.68 ms | 4 | 6
6 |  STL |         SSet(Rbtree)    |   2554.41 ms | 4 | 9
7 |  CMC |           SSet(tree)    |   2761.86 ms | 6 | 9
8 |  CollectionC |      SSet(TreeTable)    |   2845.67 ms | 6 | 8
9 |  GLIB |          SSet(GTree)    |   3035.43 ms | 9 | 10
10 |  TommyDS |         SSet(Rbtree)    |   3338.43 ms | 5 | 10
11 |  QLIBC |         SSet(Rbtree)    |   3979.30 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.60M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.01M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
5 |  CTL |            SSet(set)   |   96.08M| 4 | 7
6 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
7 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  CMC |           SSet(tree)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   401.05 ms | 1 | 2
2 |  M*LIB |        String Concat    |   523.84 ms | 1 | 2
3 |  STL |        String Concat    |   606.84 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1536.86 ms | 4 | 4
5 |  SDS |        String Concat    |   2397.03 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3292.45 ms | 6 | 6
7 |  CTL |        String Concat    |   3860.07 ms | 7 | 7
8 |  GLIB |        String Concat    |   4050.32 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat   |   1.04G| 1 | 1
2 |  STC |        String Concat   |   1.36G| 2 | 2
3 |  STL |        String Concat   |   1.78G| 3 | 3
4 |  SDS |        String Concat   |   2.00G| 4 | 4
5 |  POTTERY |        String Concat   |   2.04G| 5 | 5
6 |  BSTRLIB |        String Concat   |   3.28G| 6 | 6
7 |  CTL |        String Concat   |   4.02G| 7 | 7
8 |  GLIB |        String Concat   |   7.76G| 8 | 8

# Performance test: string replacement

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace    |   514.68 ms | 1 | 1
2 |  STL |       String Replace    |   1344.07 ms | 2 | 3
3 |  STC |       String Replace    |   1515.13 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   238.68M| 1 | 1
2 |  STC |       String Replace   |   382.74M| 2 | 2
3 |  STL |       String Replace   |   415.10M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   806.26 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   827.08 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2623.37 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   7270.33 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.11M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.12M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   688.88 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   832.37 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   867.38 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1200.51 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1407.25 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1876.83 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2076.14 ms | 7 | 7
8 |  CC |        UMap U64(map)    |   2762.64 ms | 8 | 8
9 |  STC |       UMap U64(hmap)    |   3054.10 ms | 9 | 10
10 |  TommyDS |       UMap U64(dict)    |   4515.38 ms | 9 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   5045.96 ms | 11 | 11
12 |  CMC |       UMap U64(hmap)    |   8168.33 ms | 12 | 12
13 |  GLIB | UMap U64(GHashTable)    |   8416.12 ms | 13 | 13
14 |  STL |       UMap U64(umap)    |   10220.27 ms | 14 | 15
15 |  UT-HASH |       UMap U64(dict)    |   10459.48 ms | 14 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 1
2 |  M*LIB |    UMap U64(dict OA)   |   556.14M| 2 | 3
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.64M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.37M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 5
6 |  STC |       UMap U64(hmap)   |   906.15M| 6 | 7
7 |  VERSTABLE |             UMap U64   |   906.21M| 7 | 8
8 |  CC |        UMap U64(map)   |   906.21M| 6 | 8
9 |  STL |       UMap U64(umap)   |   933.87M| 9 | 9
10 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 10
11 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 11
12 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 12
13 |  GLIB | UMap U64(GHashTable)   |   1.95G| 13 | 13
14 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 14
15 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 15

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1109.31 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1281.40 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1547.20 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1588.00 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   1875.37 ms | 3 | 6
6 |  KLIB |      UMap Big(khash)    |   1946.67 ms | 5 | 10
7 |  M*LIB |    UMap Big(dict OA)    |   1958.17 ms | 5 | 7
8 |  STC |       UMap Big(hmap)    |   2056.14 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2135.01 ms | 8 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2578.65 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   2909.89 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   3664.36 ms | 12 | 13
13 |  UT-HASH |       UMap Big(dict)    |   4283.83 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 7
8 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 9
9 |  CC |        UMap Big(map)   |   3.23G| 8 | 9
10 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 10
11 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 11
12 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 12
13 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   495.63 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   736.91 ms | 2 | 2
3 |  VERSTABLE |   USet Longest(hset)    |   953.94 ms | 4 | 4
4 |  M*LIB |   USet Longest(dict)    |   976.90 ms | 3 | 3
5 |  CC |   USet Longest(hset)    |   1206.40 ms | 5 | 6
6 |  STC |   USet Longest(hset)    |   1403.24 ms | 5 | 6
7 |  CTL |   USet Longest(hset)    |   4314.53 ms | 7 | 7
8 |  STL | USet Longest(dict oa    |   5502.51 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   118.45M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 2
3 |  CC |   USet Longest(hset)   |   191.24M| 3 | 4
4 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   216.63M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.02M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.00M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 8


Model name:                              AMD EPYC 7763 64-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : f295db7f24626e2f4d4ad6f25f3769e55d36f9cb
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : 795b1b4ba6db09786bafa79b192f021851e64a4c
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
