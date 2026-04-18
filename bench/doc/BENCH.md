# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   643.10 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   861.84 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1251.35 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   32.86 ms | 1 | 3
2 |  M*LIB |       Queue(SPSC P2)    |   45.28 ms | 2 | 3
3 |  M*LIB |       Queue(MPMC P2)    |   48.46 ms | 1 | 3
4 |  M*LIB |          Queue(MPMC)    |   72.16 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   442.31 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   820.48 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1159.15 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1345.41 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1886.81 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 8
2 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 6
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
4 |  M*LIB |     Queue(SPSC Bulk)   |   454.66K| 1 | 6
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
6 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 8
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   690.27 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   720.58 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   721.51 ms | 2 | 5
4 |  STC |           Seq(Array)    |   743.91 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   750.75 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   915.20 ms | 6 | 14
7 |  M*LIB |            Seq(List)    |   959.71 ms | 9 | 12
8 |  M*LIB |          Seq(DPList)    |   965.35 ms | 6 | 12
9 |  STC |            Seq(List)    |   969.48 ms | 6 | 12
10 |  POTTERY |            Seq(List)    |   974.08 ms | 7 | 11
11 |  CTL |            Seq(List)    |   974.76 ms | 7 | 12
12 |  UT-HASH |            Seq(List)    |   995.70 ms | 8 | 13
13 |  TommyDS |            Seq(List)    |   1070.66 ms | 11 | 19
14 |  CC |            Seq(List)    |   1073.68 ms | 13 | 14
15 |  GLIB |            Seq(List)    |   1127.88 ms | 15 | 18
16 |  CollectionC |            Seq(List)    |   1144.58 ms | 8 | 17
17 |  STL |            Seq(List)    |   1201.83 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1277.57 ms | 17 | 24
19 |  CMC |           Seq(Array)    |   1588.73 ms | 19 | 22
20 |  STL |           Seq(Array)    |   1590.42 ms | 19 | 21
21 |  STB-DS |        Seq(DynArray)    |   1692.72 ms | 15 | 22
22 |  STL |           Seq(Deque)    |   1756.74 ms | 21 | 23
23 |  CollectionC |           Seq(Array)    |   2105.38 ms | 23 | 26
24 |  CC |           Seq(Array)    |   2295.96 ms | 21 | 24
25 |  QLIBC |            Seq(List)    |   2521.81 ms | 24 | 27
26 |  TommyDS |           Seq(Array)    |   2760.09 ms | 17 | 26
27 |  POTTERY |           Seq(Array)    |   2971.57 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   3259.88 ms | 27 | 28
29 |  LIBSRT |           Seq(Array)    |   4368.34 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   6568.54 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 8
2 |  GLIB |            Seq(List)   |   1.28G| 2 | 10
3 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
4 |  STL |            Seq(List)   |   1.28G| 4 | 9
5 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
6 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
7 |  STC |            Seq(List)   |   1.28G| 3 | 8
8 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
9 |  CTL |            Seq(List)   |   1.28G| 1 | 10
10 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 7
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
14 |  CC |           Seq(Array)   |   1.60G| 14 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
19 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
20 |  STC |           Seq(Array)   |   1.60G| 18 | 20
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
1 |  STC |                 Sort    |   1042.17 ms | 1 | 2
2 |  STL |                 Sort    |   1104.01 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1157.70 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1235.29 ms | 4 | 5
5 |  STL |          Stable Sort    |   1286.36 ms | 3 | 5
6 |  CTL |                 Sort    |   1494.13 ms | 6 | 7
7 |  KLIB |                 Sort    |   1571.41 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1665.36 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1691.09 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1698.50 ms | 8 | 10
11 |  GLIB |                 Sort    |   1748.95 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2897.67 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.16M| 1 | 3
2 |  CTL |                 Sort   |   41.69M| 1 | 3
3 |  STC |                 Sort   |   41.82M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.55M| 5 | 5
6 |  M*LIB |                 Sort   |   81.16M| 6 | 8
7 |  M*LIB |          Stable Sort   |   81.29M| 6 | 8
8 |  UT-HASH |                 Sort   |   81.69M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   164.44M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   753.93 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   884.13 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1825.99 ms | 3 | 3
4 |  M*LIB |         SSet(Rbtree)    |   2068.36 ms | 4 | 9
5 |  CTL |            SSet(set)    |   2306.41 ms | 4 | 6
6 |  CollectionC |      SSet(TreeTable)    |   2479.34 ms | 6 | 8
7 |  TommyDS |         SSet(Rbtree)    |   2597.38 ms | 5 | 10
8 |  CMC |           SSet(tree)    |   2718.23 ms | 6 | 9
9 |  STL |         SSet(Rbtree)    |   2764.05 ms | 4 | 8
10 |  GLIB |          SSet(GTree)    |   2856.84 ms | 9 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4285.65 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.57M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.06M| 3 | 3
4 |  TommyDS |         SSet(Rbtree)   |   95.94M| 5 | 8
5 |  CMC |           SSet(tree)   |   95.94M| 4 | 8
6 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
7 |  CTL |            SSet(set)   |   96.08M| 4 | 7
8 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 7
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   396.56 ms | 1 | 2
2 |  M*LIB |        String Concat    |   523.17 ms | 1 | 2
3 |  STL |        String Concat    |   612.80 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1544.65 ms | 4 | 4
5 |  SDS |        String Concat    |   2345.07 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3224.99 ms | 6 | 6
7 |  CTL |        String Concat    |   3863.95 ms | 5 | 7
8 |  GLIB |        String Concat    |   4017.35 ms | 6 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat   |   1.04G| 1 | 1
2 |  STC |        String Concat   |   1.36G| 2 | 2
3 |  STL |        String Concat   |   1.79G| 3 | 3
4 |  SDS |        String Concat   |   2.00G| 4 | 4
5 |  POTTERY |        String Concat   |   2.04G| 5 | 5
6 |  BSTRLIB |        String Concat   |   3.28G| 6 | 6
7 |  CTL |        String Concat   |   4.02G| 7 | 7
8 |  GLIB |        String Concat   |   7.76G| 8 | 8

# Performance test: string replacement

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace    |   516.34 ms | 1 | 1
2 |  STL |       String Replace    |   1277.78 ms | 2 | 3
3 |  STC |       String Replace    |   1521.34 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.17M| 1 | 1
2 |  STC |       String Replace   |   382.18M| 2 | 2
3 |  STL |       String Replace   |   416.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   699.63 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   832.95 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2560.75 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   7100.91 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.99M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.25M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   698.02 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   843.13 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   874.30 ms | 1 | 3
4 |  KLIB |      UMap U64(khash)    |   1192.85 ms | 3 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1350.34 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2008.45 ms | 5 | 6
7 |  VERSTABLE |             UMap U64    |   2154.22 ms | 6 | 7
8 |  CC |        UMap U64(map)    |   2629.06 ms | 7 | 8
9 |  STC |       UMap U64(hmap)    |   3035.46 ms | 8 | 10
10 |  TommyDS |       UMap U64(dict)    |   4492.48 ms | 9 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   4861.58 ms | 10 | 11
12 |  CMC |       UMap U64(hmap)    |   8256.56 ms | 11 | 12
13 |  GLIB | UMap U64(GHashTable)    |   8427.20 ms | 12 | 13
14 |  UT-HASH |       UMap U64(dict)    |   10599.57 ms | 13 | 15
15 |  STL |       UMap U64(umap)    |   10675.47 ms | 14 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.11M| 2 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   556.13M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.04M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 5
6 |  STC |       UMap U64(hmap)   |   906.14M| 6 | 7
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
1 |  M*LIB |       UMap Big(dict)    |   943.91 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1378.15 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   1561.31 ms | 3 | 8
4 |  VERSTABLE |             UMap Big    |   1608.39 ms | 3 | 4
5 |  TommyDS |       UMap Big(dict)    |   1830.75 ms | 3 | 6
6 |  KLIB |      UMap Big(khash)    |   1898.56 ms | 5 | 10
7 |  M*LIB |    UMap Big(dict OA)    |   1925.85 ms | 5 | 8
8 |  STC |       UMap Big(hmap)    |   1955.26 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2128.73 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2317.44 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   2806.47 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   3719.19 ms | 12 | 13
13 |  UT-HASH |       UMap Big(dict)    |   4006.20 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 7
8 |  CC |        UMap Big(map)   |   3.23G| 9 | 9
9 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 8
10 |  STC |       UMap Big(hmap)   |   3.25G| 10 | 10
11 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 11
12 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 12
13 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   453.24 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   729.86 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   935.70 ms | 3 | 3
4 |  VERSTABLE |   USet Longest(hset)    |   1033.46 ms | 4 | 4
5 |  STC |   USet Longest(hset)    |   1182.56 ms | 6 | 6
6 |  CC |   USet Longest(hset)    |   1188.64 ms | 5 | 5
7 |  CTL |   USet Longest(hset)    |   4388.47 ms | 7 | 7
8 |  STL | USet Longest(dict oa    |   5685.70 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   117.51M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 2
3 |  CC |   USet Longest(hset)   |   191.24M| 3 | 4
4 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.10M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.03M| 7 | 7
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
