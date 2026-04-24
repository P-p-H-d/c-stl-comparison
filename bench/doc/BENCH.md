# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   706.64 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   971.15 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1410.50 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   41.91 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   43.39 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   45.09 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   77.97 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   439.64 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   674.11 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1207.87 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1421.65 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1955.27 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 6
2 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 6
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
4 |  M*LIB |       Queue(SPSC P2)   |   454.66K| 1 | 8
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
6 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 8
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  M*LIB |     Queue(Buffer P2)   |   589.82K| 3 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   1.05M| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |           Seq(Array)    |   786.10 ms | 1 | 4
2 |  KLIB |           Seq(Array)    |   809.84 ms | 1 | 5
3 |  CTL |           Seq(Array)    |   826.80 ms | 2 | 5
4 |  STC |           Seq(Array)    |   843.12 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   868.98 ms | 1 | 5
6 |  CTL |            Seq(List)    |   900.25 ms | 7 | 12
7 |  UT-HASH |            Seq(List)    |   925.49 ms | 8 | 12
8 |  POTTERY |            Seq(List)    |   935.97 ms | 7 | 11
9 |  M*LIB |          Seq(DPList)    |   938.54 ms | 6 | 12
10 |  M*LIB |            Seq(List)    |   947.11 ms | 7 | 12
11 |  STC |            Seq(List)    |   947.44 ms | 6 | 12
12 |  TommyDS |            Seq(List)    |   968.66 ms | 11 | 19
13 |  CC |            Seq(List)    |   1005.24 ms | 13 | 14
14 |  M*LIB |           Seq(Deque)    |   1009.48 ms | 6 | 14
15 |  CollectionC |            Seq(List)    |   1043.51 ms | 11 | 17
16 |  GLIB |            Seq(List)    |   1064.71 ms | 15 | 18
17 |  STL |            Seq(List)    |   1131.04 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1158.23 ms | 17 | 24
19 |  STB-DS |        Seq(DynArray)    |   1713.68 ms | 15 | 22
20 |  CC |           Seq(Array)    |   1796.59 ms | 23 | 24
21 |  STL |           Seq(Array)    |   1836.86 ms | 19 | 21
22 |  TommyDS |           Seq(Array)    |   1843.71 ms | 17 | 26
23 |  CMC |           Seq(Array)    |   1874.07 ms | 19 | 21
24 |  STL |           Seq(Deque)    |   1981.64 ms | 21 | 23
25 |  CollectionC |           Seq(Array)    |   2345.22 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   2404.42 ms | 25 | 27
27 |  POTTERY |           Seq(Array)    |   2765.52 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   3325.62 ms | 27 | 28
29 |  LIBSRT |           Seq(Array)    |   4306.41 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   6914.20 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 8
2 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
3 |  GLIB |            Seq(List)   |   1.28G| 2 | 10
4 |  STL |            Seq(List)   |   1.28G| 4 | 9
5 |  CTL |            Seq(List)   |   1.28G| 1 | 10
6 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
7 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
8 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
9 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
10 |  STC |            Seq(List)   |   1.28G| 3 | 8
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
14 |  CC |           Seq(Array)   |   1.60G| 14 | 15
15 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
19 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
21 |  STC |           Seq(Array)   |   1.60G| 18 | 20
22 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 21
23 |  STL |           Seq(Array)   |   1.61G| 23 | 23
24 |  STL |           Seq(Deque)   |   1.68G| 24 | 24
25 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 25
26 |  TommyDS |            Seq(List)   |   1.92G| 26 | 26
27 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 28
28 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
29 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 29
30 |  GLIB |           Seq(Array)   |   4.81G| 30 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1203.55 ms | 1 | 2
2 |  STL |                 Sort    |   1228.68 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1324.50 ms | 3 | 5
4 |  STL |          Stable Sort    |   1407.07 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1426.46 ms | 4 | 5
6 |  CTL |                 Sort    |   1667.23 ms | 6 | 7
7 |  KLIB |                 Sort    |   1801.08 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1827.99 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1883.01 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1890.36 ms | 8 | 10
11 |  GLIB |                 Sort    |   1963.59 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3192.87 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  CTL |                 Sort   |   41.16M| 1 | 3
3 |  KLIB |                 Sort   |   41.69M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.51M| 5 | 5
6 |  UT-HASH |                 Sort   |   81.69M| 6 | 8
7 |  M*LIB |          Stable Sort   |   81.96M| 6 | 8
8 |  M*LIB |                 Sort   |   82.20M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   162.91M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   868.60 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1112.47 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2397.41 ms | 3 | 3
4 |  M*LIB |         SSet(Rbtree)    |   2780.39 ms | 4 | 5
5 |  STL |         SSet(Rbtree)    |   2883.71 ms | 4 | 9
6 |  CollectionC |      SSet(TreeTable)    |   3435.73 ms | 6 | 8
7 |  CMC |           SSet(tree)    |   3438.80 ms | 6 | 8
8 |  TommyDS |         SSet(Rbtree)    |   3549.58 ms | 7 | 10
9 |  CTL |            SSet(set)    |   3600.65 ms | 4 | 6
10 |  GLIB |          SSet(GTree)    |   4327.15 ms | 9 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4929.40 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.67M| 1 | 1
2 |  STC |           SSet(sset)   |   49.43M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.01M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   95.94M| 4 | 7
5 |  STL |         SSet(Rbtree)   |   95.94M| 4 | 8
6 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
7 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  CTL |            SSet(set)   |   96.08M| 4 | 7
9 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   369.79 ms | 1 | 2
2 |  M*LIB |        String Concat    |   518.38 ms | 1 | 2
3 |  STL |        String Concat    |   602.88 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1596.48 ms | 4 | 4
5 |  SDS |        String Concat    |   2551.90 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3329.83 ms | 6 | 6
7 |  CTL |        String Concat    |   3985.09 ms | 7 | 7
8 |  GLIB |        String Concat    |   4112.47 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   526.06 ms | 1 | 1
2 |  STL |       String Replace    |   1081.23 ms | 2 | 3
3 |  STC |       String Replace    |   1422.95 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.01M| 1 | 1
2 |  STC |       String Replace   |   382.74M| 2 | 2
3 |  STL |       String Replace   |   416.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   887.80 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1019.38 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3142.21 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   8082.26 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.46M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.12M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   858.26 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   872.61 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   964.28 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1282.34 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1372.96 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1944.99 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2289.79 ms | 7 | 7
8 |  CC |        UMap U64(map)    |   3081.67 ms | 8 | 8
9 |  STC |       UMap U64(hmap)    |   3738.66 ms | 9 | 10
10 |  TommyDS |       UMap U64(dict)    |   3760.01 ms | 9 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   4164.79 ms | 11 | 11
12 |  CMC |       UMap U64(hmap)    |   7027.76 ms | 12 | 12
13 |  GLIB | UMap U64(GHashTable)    |   8617.30 ms | 13 | 13
14 |  STL |       UMap U64(umap)    |   10053.59 ms | 14 | 15
15 |  UT-HASH |       UMap U64(dict)    |   11538.66 ms | 14 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.32M| 2 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   556.52M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.75M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 5
6 |  VERSTABLE |             UMap U64   |   906.22M| 7 | 8
7 |  CC |        UMap U64(map)   |   906.22M| 6 | 8
8 |  STC |       UMap U64(hmap)   |   906.24M| 6 | 7
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
1 |  M*LIB |       UMap Big(dict)    |   1216.10 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1628.10 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1937.88 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   2018.24 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   2209.03 ms | 3 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2281.51 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2407.54 ms | 5 | 10
8 |  STC |       UMap Big(hmap)    |   2417.43 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2418.54 ms | 8 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2741.59 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   3426.93 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   4372.48 ms | 12 | 12
13 |  UT-HASH |       UMap Big(dict)    |   4760.14 ms | 13 | 13

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
1 |  BOOST | USet Longest(uflat_s    |   473.94 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   826.40 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   956.98 ms | 3 | 4
4 |  VERSTABLE |   USet Longest(hset)    |   1046.95 ms | 3 | 4
5 |  CC |   USet Longest(hset)    |   1393.74 ms | 5 | 6
6 |  STC |   USet Longest(hset)    |   1580.56 ms | 5 | 6
7 |  CTL |   USet Longest(hset)    |   4131.04 ms | 7 | 7
8 |  STL | USet Longest(dict oa    |   5569.82 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   117.34M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 2
3 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 4
4 |  CC |   USet Longest(hset)   |   191.24M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.15M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.03M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 8


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 749e2d8f11c21899c4c878c4a7c8cda679a8b958
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : 03acf23efed88da4cbf39103d7e12e92003b4fff
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 1060908cd84b1f58c68a76ef02bc8b6db83cba07
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
