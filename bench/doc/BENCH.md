# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   707.40 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   971.14 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1410.90 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   37.65 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   43.26 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   44.43 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   78.00 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   473.42 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   629.40 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1100.63 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1416.33 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   2012.97 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 6
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 8
3 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 6
4 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 9
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  LIBLFDS |          Queue(MPMC)   |   585.73K| 4 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |           Seq(Array)    |   757.27 ms | 1 | 4
2 |  STC |           Seq(Array)    |   758.45 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   829.60 ms | 2 | 5
4 |  KLIB |           Seq(Array)    |   837.15 ms | 1 | 5
5 |  UT-HASH |           Seq(Array)    |   865.05 ms | 1 | 5
6 |  STC |            Seq(List)    |   912.55 ms | 6 | 12
7 |  UT-HASH |            Seq(List)    |   922.27 ms | 7 | 12
8 |  M*LIB |          Seq(DPList)    |   924.21 ms | 8 | 12
9 |  M*LIB |            Seq(List)    |   926.59 ms | 7 | 12
10 |  POTTERY |            Seq(List)    |   932.63 ms | 7 | 11
11 |  CTL |            Seq(List)    |   941.65 ms | 6 | 12
12 |  CC |            Seq(List)    |   945.88 ms | 13 | 14
13 |  CollectionC |            Seq(List)    |   999.79 ms | 14 | 17
14 |  TommyDS |            Seq(List)    |   1003.69 ms | 11 | 19
15 |  M*LIB |           Seq(Deque)    |   1037.23 ms | 6 | 14
16 |  GLIB |            Seq(List)    |   1067.98 ms | 15 | 18
17 |  KLIB |            Seq(List)    |   1134.39 ms | 18 | 24
18 |  STL |            Seq(List)    |   1189.80 ms | 13 | 17
19 |  STB-DS |        Seq(DynArray)    |   1635.77 ms | 15 | 22
20 |  STL |           Seq(Array)    |   1768.30 ms | 19 | 21
21 |  TommyDS |           Seq(Array)    |   1835.44 ms | 17 | 26
22 |  CMC |           Seq(Array)    |   1879.12 ms | 19 | 23
23 |  STL |           Seq(Deque)    |   2001.66 ms | 21 | 24
24 |  CC |           Seq(Array)    |   2098.65 ms | 20 | 24
25 |  CollectionC |           Seq(Array)    |   2343.33 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   2488.48 ms | 25 | 27
27 |  POTTERY |           Seq(Array)    |   2886.41 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   3350.64 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4308.37 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6911.54 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  GLIB |            Seq(List)   |   1.28G| 2 | 10
2 |  STL |            Seq(List)   |   1.28G| 4 | 9
3 |  STC |            Seq(List)   |   1.28G| 3 | 10
4 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
5 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
6 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
7 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
8 |  CTL |            Seq(List)   |   1.28G| 1 | 10
9 |  CC |            Seq(List)   |   1.28G| 1 | 8
10 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
14 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
15 |  CC |           Seq(Array)   |   1.60G| 14 | 15
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
19 |  STC |           Seq(Array)   |   1.60G| 18 | 21
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
21 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
22 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
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
1 |  STC |                 Sort    |   1211.38 ms | 1 | 2
2 |  STL |                 Sort    |   1230.63 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1326.89 ms | 3 | 5
4 |  STL |          Stable Sort    |   1406.35 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1437.20 ms | 4 | 5
6 |  CTL |                 Sort    |   1664.61 ms | 6 | 7
7 |  KLIB |                 Sort    |   1804.13 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1834.84 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1886.25 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1892.29 ms | 8 | 10
11 |  GLIB |                 Sort    |   1962.62 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3245.69 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.29M| 1 | 3
3 |  STC |                 Sort   |   41.68M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.59M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
8 |  M*LIB |                 Sort   |   81.16M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   166.31M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   822.37 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1024.55 ms | 2 | 2
3 |  M*LIB |         SSet(Rbtree)    |   2550.60 ms | 4 | 5
4 |  CMC |           SSet(tree)    |   2995.58 ms | 6 | 8
5 |  STC |           SSet(sset)    |   3062.07 ms | 3 | 3
6 |  CTL |            SSet(set)    |   3349.97 ms | 4 | 9
7 |  CollectionC |      SSet(TreeTable)    |   3448.23 ms | 6 | 8
8 |  GLIB |          SSet(GTree)    |   3703.37 ms | 9 | 10
9 |  STL |         SSet(Rbtree)    |   3966.18 ms | 4 | 9
10 |  TommyDS |         SSet(Rbtree)    |   4052.53 ms | 7 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4916.73 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.60M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   57.99M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   95.94M| 4 | 8
5 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
6 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
7 |  CTL |            SSet(set)   |   96.08M| 4 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.17M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   381.06 ms | 1 | 2
2 |  M*LIB |        String Concat    |   525.09 ms | 1 | 2
3 |  STL |        String Concat    |   612.88 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1605.13 ms | 4 | 4
5 |  SDS |        String Concat    |   2483.05 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3361.92 ms | 6 | 6
7 |  CTL |        String Concat    |   3912.54 ms | 7 | 7
8 |  GLIB |        String Concat    |   4108.39 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   509.01 ms | 1 | 1
2 |  STL |       String Replace    |   1121.14 ms | 2 | 3
3 |  STC |       String Replace    |   1426.94 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.18M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   416.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   840.29 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1197.72 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3468.47 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   9091.06 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.99M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.25M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   856.47 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   871.78 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   957.33 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1215.23 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1463.22 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2013.94 ms | 6 | 6
7 |  KLIB |     UMap U64(khashl)    |   2382.10 ms | - | -
8 |  VERSTABLE |             UMap U64    |   2503.86 ms | 7 | 7
9 |  CC |        UMap U64(map)    |   2974.65 ms | 8 | 8
10 |  TommyDS |       UMap U64(dict)    |   3856.84 ms | 9 | 10
11 |  STC |       UMap U64(hmap)    |   3988.90 ms | 9 | 10
12 |  CollectionC |  UMap U64(HashTable)    |   4540.44 ms | 11 | 11
13 |  CMC |       UMap U64(hmap)    |   6893.79 ms | 12 | 12
14 |  GLIB | UMap U64(GHashTable)    |   8245.74 ms | 13 | 13
15 |  STL |       UMap U64(umap)    |   11163.70 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   12053.12 ms | 14 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| - | -
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 1
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.20M| 2 | 3
4 |  M*LIB |    UMap U64(dict OA)   |   557.20M| 2 | 3
5 |  M*LIB |       UMap U64(dict)   |   588.74M| 4 | 4
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 5
7 |  STC |       UMap U64(hmap)   |   906.14M| 6 | 8
8 |  CC |        UMap U64(map)   |   906.21M| 6 | 8
9 |  VERSTABLE |             UMap U64   |   906.35M| 6 | 8
10 |  STL |       UMap U64(umap)   |   933.89M| 9 | 9
11 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 10
12 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 11
13 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 12
14 |  GLIB | UMap U64(GHashTable)   |   1.95G| 13 | 13
15 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 14
16 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 15

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1146.67 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1791.44 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   1969.17 ms | 3 | 8
4 |  VERSTABLE |             UMap Big    |   2085.47 ms | 3 | 4
5 |  M*LIB |    UMap Big(dict OA)    |   2276.78 ms | 5 | 7
6 |  TommyDS |       UMap Big(dict)    |   2349.44 ms | 3 | 6
7 |  KLIB |      UMap Big(khash)    |   2405.73 ms | 5 | 10
8 |  GLIB | UMap Big(GHashTable)    |   2573.11 ms | 7 | 10
9 |  STC |       UMap Big(hmap)    |   2610.68 ms | 5 | 10
10 |  POTTERY |  UMap Big(open hash)    |   2685.42 ms | 8 | 10
11 |  KLIB |     UMap Big(khashl)    |   3338.14 ms | - | -
12 |  CollectionC |  UMap Big(HashTable)    |   3849.13 ms | 11 | 11
13 |  STL |       UMap Big(umap)    |   4984.08 ms | 12 | 12
14 |  UT-HASH |       UMap Big(dict)    |   5189.47 ms | 13 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.17G| - | -
8 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 7
9 |  CC |        UMap Big(map)   |   3.23G| 8 | 9
10 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 9
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 10
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 11
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 12
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   577.18 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   715.87 ms | - | -
3 |  M*LIB | USet Longest(dict oa    |   844.31 ms | 2 | 2
4 |  M*LIB |   USet Longest(dict)    |   968.54 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1170.78 ms | 3 | 4
6 |  KLIB | USet Longest(khashl)    |   1249.47 ms | - | -
7 |  CC |   USet Longest(hset)    |   1352.91 ms | 5 | 6
8 |  STC |   USet Longest(hset)    |   1907.68 ms | 5 | 6
9 |  CTL |   USet Longest(hset)    |   4252.27 ms | 7 | 7
10 |  STL | USet Longest(dict oa    |   5995.63 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.22M| - | -
2 |  KLIB |  USet Longest(khash)   |   115.25M| - | -
3 |  M*LIB | USet Longest(dict oa   |   118.22M| 1 | 1
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 2
5 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 4
6 |  CC |   USet Longest(hset)   |   191.24M| 3 | 4
7 |  M*LIB |   USet Longest(dict)   |   216.39M| 5 | 5
8 |  STC |   USet Longest(hset)   |   218.91M| 6 | 6
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 7
10 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 8


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 88b4a45471c3802ddd50a1bdbb3636b383b8ea1d
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
