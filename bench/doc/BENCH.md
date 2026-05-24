# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   708.40 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   972.01 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1411.64 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   35.22 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   42.10 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   44.16 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   78.22 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   475.41 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   701.57 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1100.37 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1451.23 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1988.81 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 4
2 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
3 |  M*LIB |     Queue(Buffer P2)   |   397.31K| 3 | 9
4 |  M*LIB |       Queue(SPSC P2)   |   454.66K| 1 | 8
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
6 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |           Seq(Array)    |   786.46 ms | 2 | 5
2 |  STC |           Seq(Array)    |   834.88 ms | 1 | 4
3 |  KLIB |           Seq(Array)    |   848.85 ms | 1 | 5
4 |  M*LIB |           Seq(Array)    |   849.37 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   866.57 ms | 1 | 5
6 |  CTL |            Seq(List)    |   901.14 ms | 6 | 12
7 |  UT-HASH |            Seq(List)    |   901.79 ms | 6 | 12
8 |  M*LIB |            Seq(List)    |   914.17 ms | 7 | 12
9 |  M*LIB |          Seq(DPList)    |   914.69 ms | 8 | 12
10 |  STC |            Seq(List)    |   918.55 ms | 6 | 12
11 |  POTTERY |            Seq(List)    |   943.40 ms | 7 | 11
12 |  CC |            Seq(List)    |   975.62 ms | 12 | 14
13 |  TommyDS |            Seq(List)    |   980.49 ms | 11 | 18
14 |  M*LIB |           Seq(Deque)    |   1007.85 ms | 6 | 16
15 |  CollectionC |            Seq(List)    |   1008.23 ms | 13 | 16
16 |  GLIB |            Seq(List)    |   1115.45 ms | 14 | 16
17 |  KLIB |            Seq(List)    |   1138.69 ms | 17 | 23
18 |  STL |            Seq(List)    |   1253.51 ms | 13 | 18
19 |  STL |           Seq(Array)    |   1784.32 ms | 19 | 22
20 |  TommyDS |           Seq(Array)    |   1847.58 ms | 19 | 26
21 |  CMC |           Seq(Array)    |   1871.72 ms | 19 | 23
22 |  STB-DS |        Seq(DynArray)    |   1905.45 ms | 17 | 24
23 |  STL |           Seq(Deque)    |   1997.85 ms | 21 | 24
24 |  CC |           Seq(Array)    |   2093.62 ms | 19 | 24
25 |  CollectionC |           Seq(Array)    |   2335.40 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   2381.19 ms | 25 | 26
27 |  POTTERY |           Seq(Array)    |   2833.19 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   3316.44 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4297.43 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6157.28 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
2 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
3 |  STL |            Seq(List)   |   1.28G| 2 | 10
4 |  CTL |            Seq(List)   |   1.28G| 2 | 10
5 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
6 |  M*LIB |            Seq(List)   |   1.28G| 3 | 10
7 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
8 |  STC |            Seq(List)   |   1.28G| 1 | 10
9 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
10 |  CC |            Seq(List)   |   1.28G| 1 | 9
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
15 |  CC |           Seq(Array)   |   1.60G| 12 | 15
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
19 |  STC |           Seq(Array)   |   1.60G| 17 | 21
20 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
21 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
22 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
23 |  STL |           Seq(Array)   |   1.61G| 23 | 23
24 |  STL |           Seq(Deque)   |   1.68G| 24 | 24
25 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 25
26 |  TommyDS |            Seq(List)   |   1.92G| 26 | 26
27 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 28
28 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
29 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 29
30 |  GLIB |           Seq(Array)   |   4.80G| 30 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1201.55 ms | 1 | 2
2 |  STL |                 Sort    |   1226.95 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1326.23 ms | 3 | 5
4 |  STL |          Stable Sort    |   1409.32 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1436.13 ms | 4 | 5
6 |  CTL |                 Sort    |   1663.04 ms | 6 | 7
7 |  KLIB |                 Sort    |   1802.25 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1825.83 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1886.36 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1890.92 ms | 9 | 10
11 |  GLIB |                 Sort    |   1957.70 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3225.55 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.16M| 1 | 3
3 |  CTL |                 Sort   |   41.96M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.72M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  M*LIB |                 Sort   |   81.69M| 6 | 8
8 |  UT-HASH |                 Sort   |   81.95M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   164.44M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   840.60 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1086.32 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2235.57 ms | 3 | 5
4 |  STL |         SSet(Rbtree)    |   2767.46 ms | 4 | 9
5 |  M*LIB |         SSet(Rbtree)    |   2768.78 ms | 3 | 5
6 |  CMC |           SSet(tree)    |   2933.64 ms | 4 | 8
7 |  CTL |            SSet(set)    |   2958.20 ms | 4 | 9
8 |  CollectionC |      SSet(TreeTable)    |   3146.78 ms | 6 | 8
9 |  TommyDS |         SSet(Rbtree)    |   3382.27 ms | 7 | 10
10 |  GLIB |          SSet(GTree)    |   3635.32 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4836.16 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.67M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.14M| 3 | 3
4 |  TommyDS |         SSet(Rbtree)   |   95.94M| 4 | 8
5 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
6 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
7 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
8 |  CTL |            SSet(set)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   424.03 ms | 1 | 1
2 |  M*LIB |        String Concat    |   534.37 ms | 2 | 2
3 |  STL |        String Concat    |   617.23 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1585.42 ms | 4 | 4
5 |  SDS |        String Concat    |   2465.16 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3297.91 ms | 6 | 6
7 |  CTL |        String Concat    |   3923.84 ms | 7 | 7
8 |  GLIB |        String Concat    |   4260.08 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   520.94 ms | 1 | 1
2 |  STL |       String Replace    |   1161.56 ms | 2 | 3
3 |  STC |       String Replace    |   1410.02 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.24M| 1 | 1
2 |  STC |       String Replace   |   382.32M| 2 | 2
3 |  STL |       String Replace   |   415.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   858.32 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1015.02 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3218.57 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   8318.76 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   169.52M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.62M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap U64(dict)    |   953.83 ms | 1 | 2
2 |  M*LIB | UMap U64 (dict Bulk)    |   958.77 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   1025.44 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1339.44 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1402.15 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2026.05 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2364.05 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2544.92 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   3052.50 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3859.98 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   3916.60 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4445.20 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   7266.98 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   8768.78 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   10437.19 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   11928.30 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.30M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.21M| 2 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   557.60M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.74M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.14M| 6 | 8
8 |  CC |        UMap U64(map)   |   906.20M| 6 | 9
9 |  VERSTABLE |             UMap U64   |   906.22M| 6 | 9
10 |  STL |       UMap U64(umap)   |   933.87M| 9 | 10
11 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 11
12 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 12
13 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 13
14 |  GLIB | UMap U64(GHashTable)   |   1.95G| 13 | 14
15 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 15
16 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 16

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1153.41 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1665.37 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   2050.37 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   2092.71 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   2267.31 ms | 4 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2338.86 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2556.44 ms | 5 | 9
8 |  STC |       UMap Big(hmap)    |   2592.99 ms | 5 | 10
9 |  GLIB | UMap Big(GHashTable)    |   2622.67 ms | 7 | 10
10 |  POTTERY |  UMap Big(open hash)    |   2679.19 ms | 8 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   3443.09 ms | 11 | 12
12 |  KLIB |     UMap Big(khashl)    |   3638.86 ms | 11 | 11
13 |  STL |       UMap Big(umap)    |   4504.99 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4848.85 ms | 13 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.17G| 7 | 7
8 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 8
9 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 10
10 |  CC |        UMap Big(map)   |   3.23G| 8 | 9
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   468.64 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   727.20 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   851.84 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   974.89 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1060.11 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1295.61 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1356.35 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1509.68 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   4116.62 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5446.27 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   117.41M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  VERSTABLE |   USet Longest(hset)   |   191.23M| 3 | 6
6 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   214.99M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.12M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 10


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* STC : 6574a39b26cf24c32fc58ed585209b35c34c7998
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : aa77e89ae48473fec96c014e0db7290c3493ee1c
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 1060908cd84b1f58c68a76ef02bc8b6db83cba07
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
