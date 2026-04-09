# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   642.21 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   864.32 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1252.98 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   29.09 ms | 1 | 3
2 |  M*LIB |       Queue(MPMC P2)    |   41.72 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   45.09 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   75.61 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   490.54 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   832.97 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1183.72 ms | 7 | 9
8 |  M*LIB |        Queue(Buffer)    |   1332.16 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1888.20 ms | 7 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 8
2 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K| 1 | 6
3 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
4 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 5 | 8
5 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 2 | 9
7 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 1 | 4
8 |  M*LIB |       Queue(SPSC P2)   |   585.73K| 1 | 4
9 |  M*LIB |    Queue(Shared ptr)   |   1.18M| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  UT-HASH |           Seq(Array)    |   662.63 ms | 1 | 5
2 |  CTL |           Seq(Array)    |   673.37 ms | 1 | 5
3 |  STC |           Seq(Array)    |   688.16 ms | 2 | 4
4 |  M*LIB |           Seq(Array)    |   704.69 ms | 1 | 4
5 |  KLIB |           Seq(Array)    |   729.42 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   901.18 ms | 6 | 13
7 |  STC |            Seq(List)    |   936.17 ms | 7 | 13
8 |  UT-HASH |            Seq(List)    |   940.97 ms | 8 | 13
9 |  M*LIB |          Seq(DPList)    |   958.50 ms | 6 | 12
10 |  CTL |            Seq(List)    |   961.71 ms | 7 | 12
11 |  POTTERY |            Seq(List)    |   964.93 ms | 7 | 13
12 |  M*LIB |            Seq(List)    |   984.67 ms | 9 | 19
13 |  TommyDS |            Seq(List)    |   1038.57 ms | 13 | 20
14 |  CC |            Seq(List)    |   1056.39 ms | 13 | 18
15 |  GLIB |            Seq(List)    |   1138.33 ms | 7 | 18
16 |  CollectionC |            Seq(List)    |   1160.38 ms | 8 | 17
17 |  STL |            Seq(List)    |   1179.98 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1278.27 ms | 17 | 24
19 |  STL |           Seq(Array)    |   1543.15 ms | 14 | 21
20 |  CMC |           Seq(Array)    |   1608.15 ms | 17 | 22
21 |  STB-DS |        Seq(DynArray)    |   1692.04 ms | 7 | 21
22 |  STL |           Seq(Deque)    |   1778.33 ms | 20 | 23
23 |  CC |           Seq(Array)    |   2022.08 ms | 21 | 24
24 |  CollectionC |           Seq(Array)    |   2132.50 ms | 23 | 25
25 |  QLIBC |            Seq(List)    |   2530.93 ms | 24 | 27
26 |  TommyDS |           Seq(Array)    |   2760.97 ms | 17 | 26
27 |  POTTERY |           Seq(Array)    |   2976.16 ms | 25 | 27
28 |  GLIB |           Seq(Array)    |   3262.51 ms | 27 | 29
29 |  LIBSRT |           Seq(Array)    |   4367.52 ms | 27 | 29
30 |  QLIBC |           Seq(Array)    |   6553.87 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  GLIB |            Seq(List)   |   1.28G| 1 | 10
3 |  CollectionC |            Seq(List)   |   1.28G| 3 | 10
4 |  STL |            Seq(List)   |   1.28G| 4 | 9
5 |  STC |            Seq(List)   |   1.28G| 3 | 8
6 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 6
7 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 8
8 |  CTL |            Seq(List)   |   1.28G| 1 | 10
9 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
10 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 22
14 |  CC |           Seq(Array)   |   1.60G| 13 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 14 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 14 | 20
17 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 21
18 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
19 |  STC |           Seq(Array)   |   1.60G| 16 | 20
20 |  M*LIB |           Seq(Array)   |   1.60G| 15 | 20
21 |  KLIB |           Seq(Array)   |   1.60G| 16 | 20
22 |  M*LIB |           Seq(Deque)   |   1.60G| 21 | 22
23 |  STL |           Seq(Array)   |   1.61G| 22 | 23
24 |  STL |           Seq(Deque)   |   1.68G| 23 | 24
25 |  POTTERY |           Seq(Array)   |   1.70G| 24 | 25
26 |  TommyDS |            Seq(List)   |   1.92G| 25 | 26
27 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
28 |  TommyDS |           Seq(Array)   |   3.20G| 26 | 28
29 |  CollectionC |           Seq(Array)   |   3.22G| 28 | 29
30 |  GLIB |           Seq(Array)   |   4.80G| 29 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1049.18 ms | 1 | 2
2 |  STL |                 Sort    |   1104.99 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1157.66 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1236.17 ms | 3 | 5
5 |  STL |          Stable Sort    |   1284.06 ms | 3 | 5
6 |  CTL |                 Sort    |   1500.93 ms | 6 | 8
7 |  KLIB |                 Sort    |   1570.32 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1662.12 ms | 7 | 9
9 |  UT-HASH |                 Sort    |   1694.37 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1700.06 ms | 8 | 10
11 |  GLIB |                 Sort    |   1752.74 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2968.35 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.96M| 1 | 3
3 |  CTL |                 Sort   |   42.20M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.59M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.69M| 6 | 8
7 |  M*LIB |                 Sort   |   81.69M| 6 | 8
8 |  UT-HASH |                 Sort   |   82.20M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   165.65M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   838.53 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   936.07 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2308.01 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2650.42 ms | 3 | 9
5 |  CTL |            SSet(set)    |   2712.18 ms | 5 | 6
6 |  STL |         SSet(Rbtree)    |   2756.56 ms | 4 | 6
7 |  CollectionC |      SSet(TreeTable)    |   2863.64 ms | 7 | 8
8 |  CMC |           SSet(tree)    |   2903.56 ms | 6 | 9
9 |  TommyDS |         SSet(Rbtree)    |   3252.61 ms | 5 | 10
10 |  GLIB |          SSet(GTree)    |   3358.76 ms | 9 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4342.48 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.59M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   55.73M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
5 |  CTL |            SSet(set)   |   96.08M| 5 | 7
6 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
7 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   397.34 ms | 1 | 2
2 |  M*LIB |        String Concat    |   543.77 ms | 1 | 2
3 |  STL |        String Concat    |   623.55 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1538.54 ms | 4 | 4
5 |  SDS |        String Concat    |   2341.03 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3299.28 ms | 6 | 6
7 |  CTL |        String Concat    |   3882.20 ms | 5 | 7
8 |  GLIB |        String Concat    |   4080.09 ms | 6 | 8

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
1 |  M*LIB |       String Replace    |   485.05 ms | 1 | 1
2 |  STL |       String Replace    |   1295.41 ms | 2 | 3
3 |  STC |       String Replace    |   1544.55 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.25M| 1 | 1
2 |  STC |       String Replace   |   382.61M| 2 | 2
3 |  STL |       String Replace   |   416.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   771.94 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   783.55 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2641.69 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   7157.64 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   169.85M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.25M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   714.85 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   884.66 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   885.85 ms | 1 | 3
4 |  KLIB |      UMap U64(khash)    |   1208.49 ms | 3 | 6
5 |  BOOST |  UMap U64(uflat_map)    |   1375.40 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1900.15 ms | 5 | 6
7 |  VERSTABLE |             UMap U64    |   2177.93 ms | 6 | 8
8 |  CC |        UMap U64(map)    |   2699.29 ms | 7 | 8
9 |  STC |       UMap U64(hmap)    |   3043.67 ms | 8 | 9
10 |  TommyDS |       UMap U64(dict)    |   4571.06 ms | 9 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   5265.19 ms | 10 | 11
12 |  CMC |       UMap U64(hmap)    |   8455.02 ms | 11 | 14
13 |  GLIB | UMap U64(GHashTable)    |   8505.87 ms | 12 | 13
14 |  UT-HASH |       UMap U64(dict)    |   10571.36 ms | 13 | 15
15 |  STL |       UMap U64(umap)    |   10693.18 ms | 13 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.53M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.01M| 2 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   556.03M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.89M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 5
6 |  CC |        UMap U64(map)   |   906.21M| 6 | 8
7 |  STC |       UMap U64(hmap)   |   906.21M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.22M| 6 | 8
9 |  STL |       UMap U64(umap)   |   933.80M| 9 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1034.46 ms | 1 | 2
2 |  BOOST |  UMap Big(uflat_map)    |   1247.17 ms | 1 | 2
3 |  VERSTABLE |             UMap Big    |   1558.37 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1614.90 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   1942.24 ms | 3 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2029.74 ms | 5 | 8
7 |  KLIB |      UMap Big(khash)    |   2032.07 ms | 5 | 10
8 |  POTTERY |  UMap Big(open hash)    |   2091.01 ms | 7 | 9
9 |  STC |       UMap Big(hmap)    |   2123.67 ms | 5 | 9
10 |  GLIB | UMap Big(GHashTable)    |   2460.48 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   2972.13 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   3890.65 ms | 12 | 13
13 |  UT-HASH |       UMap Big(dict)    |   4257.07 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 7
8 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 8
9 |  CC |        UMap Big(map)   |   3.23G| 9 | 9
10 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 10
11 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 11
12 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 12
13 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   439.84 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   739.30 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   904.06 ms | 3 | 3
4 |  VERSTABLE |   USet Longest(hset)    |   987.02 ms | 4 | 5
5 |  CC |   USet Longest(hset)    |   1253.85 ms | 4 | 5
6 |  STC |   USet Longest(hset)    |   1619.93 ms | 6 | 6
7 |  CTL |   USet Longest(hset)    |   4524.11 ms | 7 | 8
8 |  STL | USet Longest(dict oa    |   5601.17 ms | 7 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   117.83M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 2
3 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 4
4 |  CC |   USet Longest(hset)   |   191.37M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   216.52M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.01M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.03M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 8


Model name:                              AMD EPYC 7763 64-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : e9d3bcab70db85a7a5225aacb53eb5595216b638
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : a9e9cbb07ed36a53e547748b2e6fab359c2517a1
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 28d546d5eb77d4585506a20480f4de2e706dff4c
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : 668362bb89b7ca00bc37a58a10d37cb811dbe6a9
