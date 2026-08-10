# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   644.75 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   868.52 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1254.53 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   29.31 ms | 1 | 2
2 |  M*LIB |       Queue(MPMC P2)    |   37.35 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   46.55 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   74.55 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   432.42 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   828.91 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1203.00 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1297.55 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1916.40 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 8
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 5
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 7
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 7
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |           Seq(Array)    |   646.64 ms | 1 | 5
2 |  UT-HASH |           Seq(Array)    |   688.77 ms | 2 | 5
3 |  M*LIB |           Seq(Array)    |   690.71 ms | 1 | 4
4 |  CTL |           Seq(Array)    |   736.75 ms | 1 | 4
5 |  KLIB |           Seq(Array)    |   766.21 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   896.94 ms | 6 | 16
7 |  UT-HASH |            Seq(List)    |   943.20 ms | 6 | 10
8 |  POTTERY |            Seq(List)    |   957.22 ms | 7 | 11
9 |  STC |            Seq(List)    |   964.43 ms | 6 | 12
10 |  M*LIB |            Seq(List)    |   971.39 ms | 6 | 12
11 |  CTL |            Seq(List)    |   974.28 ms | 6 | 12
12 |  M*LIB |          Seq(DPList)    |   987.20 ms | 8 | 12
13 |  CC |            Seq(List)    |   1056.79 ms | 11 | 14
14 |  TommyDS |            Seq(List)    |   1068.83 ms | 8 | 16
15 |  GLIB |            Seq(List)    |   1107.29 ms | 14 | 17
16 |  CollectionC |            Seq(List)    |   1116.73 ms | 13 | 18
17 |  STL |            Seq(List)    |   1193.67 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1341.23 ms | 17 | 22
19 |  STL |           Seq(Array)    |   1560.62 ms | 19 | 22
20 |  OpenCSTL |            Seq(List)    |   1598.98 ms | 19 | 23
21 |  CMC |           Seq(Array)    |   1615.30 ms | 19 | 24
22 |  STB-DS |        Seq(DynArray)    |   1662.59 ms | 16 | 24
23 |  STL |           Seq(Deque)    |   1799.15 ms | 21 | 25
24 |  CollectionC |           Seq(Array)    |   2130.63 ms | 23 | 26
25 |  CC |           Seq(Array)    |   2292.74 ms | 19 | 25
26 |  OpenCSTL |           Seq(Array)    |   2546.00 ms | 26 | 29
27 |  QLIBC |            Seq(List)    |   2558.24 ms | 25 | 28
28 |  TommyDS |           Seq(Array)    |   2762.80 ms | 20 | 28
29 |  POTTERY |           Seq(Array)    |   2978.36 ms | 27 | 29
30 |  GLIB |           Seq(Array)    |   3263.25 ms | 28 | 30
31 |  OpenCSTL |           Seq(Deque)    |   3846.51 ms | 31 | 32
32 |  LIBSRT |           Seq(Array)    |   4325.36 ms | 29 | 32
33 |  QLIBC |           Seq(Array)    |   6197.97 ms | 30 | 33

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
3 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
4 |  STL |            Seq(List)   |   1.28G| 2 | 10
5 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 9
6 |  POTTERY |            Seq(List)   |   1.28G| 2 | 10
7 |  STC |            Seq(List)   |   1.28G| 1 | 10
8 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
9 |  CTL |            Seq(List)   |   1.28G| 1 | 8
10 |  M*LIB |          Seq(DPList)   |   1.28G| 3 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  OpenCSTL |           Seq(Array)   |   1.60G| 15 | 16
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 17
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 18
18 |  STC |           Seq(Array)   |   1.60G| 17 | 21
19 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
20 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
21 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
22 |  KLIB |           Seq(Array)   |   1.60G| 17 | 23
23 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 23
24 |  STL |           Seq(Array)   |   1.61G| 23 | 24
25 |  OpenCSTL |           Seq(Deque)   |   1.61G| 25 | 25
26 |  STL |           Seq(Deque)   |   1.68G| 24 | 26
27 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 27
28 |  TommyDS |            Seq(List)   |   1.92G| 26 | 28
29 |  OpenCSTL |            Seq(List)   |   1.92G| 29 | 29
30 |  QLIBC |            Seq(List)   |   3.20G| 27 | 31
31 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 31
32 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 32
33 |  GLIB |           Seq(Array)   |   4.81G| 30 | 33

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1055.66 ms | 1 | 1
2 |  STL |                 Sort    |   1105.64 ms | 2 | 2
3 |  POTTERY |                 Sort    |   1157.12 ms | 3 | 4
4 |  M*LIB |          Stable Sort    |   1237.25 ms | 4 | 5
5 |  STL |          Stable Sort    |   1285.71 ms | 3 | 5
6 |  CTL |                 Sort    |   1499.32 ms | 6 | 7
7 |  KLIB |                 Sort    |   1573.31 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1659.80 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1696.66 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1706.60 ms | 9 | 10
11 |  OpenCSTL |                 Sort    |   1767.10 ms | 10 | 12
12 |  GLIB |                 Sort    |   1768.92 ms | 11 | 12
13 |  CollectionC |                 Sort    |   3086.57 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.69M| 1 | 3
2 |  STC |                 Sort   |   41.95M| 1 | 3
3 |  CTL |                 Sort   |   41.96M| 1 | 3
4 |  STL |                 Sort   |   68.41M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.01M| 5 | 5
6 |  OpenCSTL |                 Sort   |   80.41M| 6 | 6
7 |  M*LIB |                 Sort   |   81.29M| 6 | 9
8 |  UT-HASH |                 Sort   |   81.95M| 6 | 9
9 |  M*LIB |          Stable Sort   |   82.20M| 6 | 9
10 |  POTTERY |                 Sort   |   98.98M| 9 | 10
11 |  STL |          Stable Sort   |   100.76M| 10 | 11
12 |  GLIB |                 Sort   |   165.65M| 11 | 12
13 |  CollectionC |                 Sort   |   1.12G| 12 | 13

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   813.29 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1043.04 ms | 2 | 2
3 |  STL |         SSet(Rbtree)    |   2627.84 ms | 4 | 6
4 |  OpenCSTL |            SSet(Set)    |   2712.30 ms | 4 | 7
5 |  STC |           SSet(sset)    |   2822.09 ms | 3 | 4
6 |  CTL |            SSet(set)    |   3009.12 ms | 5 | 8
7 |  CollectionC |      SSet(TreeTable)    |   3044.23 ms | 5 | 8
8 |  M*LIB |         SSet(Rbtree)    |   3092.66 ms | 3 | 7
9 |  CMC |           SSet(tree)    |   3446.34 ms | 6 | 10
10 |  TommyDS |         SSet(Rbtree)    |   3653.71 ms | 7 | 10
11 |  GLIB |          SSet(GTree)    |   4074.09 ms | 8 | 11
12 |  QLIBC |         SSet(Rbtree)    |   5150.44 ms | 11 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.43M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.01M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 5
5 |  CTL |            SSet(set)   |   96.08M| 5 | 8
6 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 6
7 |  CMC |           SSet(tree)   |   96.08M| 6 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
9 |  OpenCSTL |            SSet(Set)   |   96.47M| 9 | 9
10 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 10
11 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 11
12 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 12

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   408.41 ms | 1 | 2
2 |  M*LIB |        String Concat    |   535.55 ms | 1 | 2
3 |  STL |        String Concat    |   607.03 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1544.14 ms | 4 | 4
5 |  SDS |        String Concat    |   2407.23 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3211.86 ms | 6 | 6
7 |  CTL |        String Concat    |   3907.38 ms | 7 | 7
8 |  GLIB |        String Concat    |   4110.04 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   536.51 ms | 1 | 1
2 |  STL |       String Replace    |   1396.06 ms | 2 | 3
3 |  STC |       String Replace    |   1510.41 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.02M| 1 | 1
2 |  STC |       String Replace   |   382.32M| 2 | 2
3 |  STL |       String Replace   |   415.10M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   815.71 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   868.53 ms | 2 | 2
3 |  STC |       UMap Str(hmap)    |   1426.12 ms | 3 | 3
4 |  STL |       UMap Str(umap)    |   2930.79 ms | 3 | 4
5 |  STL |        UMap Str(map)    |   8226.64 ms | 4 | 5

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.24M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.25M| 2 | 2
3 |  STC |       UMap Str(hmap)   |   352.58M| 3 | 3
4 |  STL |       UMap Str(umap)   |   353.51M| 3 | 4
5 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 5

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   737.57 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   923.10 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   934.82 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1257.84 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1464.12 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2033.32 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2328.40 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2362.57 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2934.29 ms | 9 | 9
10 |  STC |       UMap U64(hmap)    |   3250.69 ms | 10 | 11
11 |  OpenCSTL |             UMap U64    |   4332.93 ms | 11 | 13
12 |  TommyDS |       UMap U64(dict)    |   4922.43 ms | 10 | 12
13 |  CollectionC |  UMap U64(HashTable)    |   5037.28 ms | 12 | 13
14 |  CMC |       UMap U64(hmap)    |   8765.22 ms | 13 | 14
15 |  GLIB | UMap U64(GHashTable)    |   9245.68 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   11441.28 ms | 15 | 17
17 |  STL |       UMap U64(umap)    |   11670.18 ms | 15 | 17

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.77M| 2 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.13M| 3 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   557.48M| 3 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.90M| 5 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 6 | 6
7 |  OpenCSTL |             UMap U64   |   872.46M| 7 | 7
8 |  CC |        UMap U64(map)   |   906.21M| 8 | 10
9 |  VERSTABLE |             UMap U64   |   906.22M| 8 | 10
10 |  STC |       UMap U64(hmap)   |   906.22M| 7 | 9
11 |  STL |       UMap U64(umap)   |   933.78M| 10 | 11
12 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 11 | 12
13 |  POTTERY |  UMap U64(open hash)   |   1.71G| 12 | 13
14 |  UT-HASH |       UMap U64(dict)   |   1.87G| 13 | 14
15 |  GLIB | UMap U64(GHashTable)   |   1.95G| 14 | 15
16 |  CMC |       UMap U64(hmap)   |   2.42G| 15 | 16
17 |  TommyDS |       UMap U64(dict)   |   4.16G| 16 | 17

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1139.77 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1347.34 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1710.25 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1749.40 ms | 3 | 7
5 |  KLIB |      UMap Big(khash)    |   2021.70 ms | 7 | 10
6 |  M*LIB |    UMap Big(dict OA)    |   2046.29 ms | 5 | 7
7 |  TommyDS |       UMap Big(dict)    |   2076.76 ms | 3 | 6
8 |  POTTERY |  UMap Big(open hash)    |   2228.86 ms | 7 | 10
9 |  STC |       UMap Big(hmap)    |   2292.69 ms | 5 | 9
10 |  GLIB | UMap Big(GHashTable)    |   2816.97 ms | 8 | 10
11 |  KLIB |     UMap Big(khashl)    |   2968.25 ms | 11 | 12
12 |  CollectionC |  UMap Big(HashTable)    |   3415.41 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4185.96 ms | 13 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4627.03 ms | 14 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.80G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.17G| 7 | 7
8 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 8 | 8
9 |  VERSTABLE |             UMap Big   |   3.23G| 9 | 10
10 |  CC |        UMap Big(map)   |   3.23G| 9 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 11 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 12 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 13 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 14 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   471.62 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   694.18 ms | 2 | 3
3 |  M*LIB | USet Longest(dict oa    |   778.50 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   932.71 ms | 4 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1127.89 ms | 5 | 5
6 |  KLIB | USet Longest(khashl)    |   1265.51 ms | 6 | 7
7 |  OpenCSTL |         USet Longest    |   1301.01 ms | 6 | 8
8 |  CC |   USet Longest(hset)    |   1498.07 ms | 7 | 9
9 |  STC |   USet Longest(hset)    |   1576.53 ms | 8 | 9
10 |  CTL |   USet Longest(hset)    |   4708.55 ms | 9 | 10
11 |  STL | USet Longest(dict oa    |   6189.18 ms | 10 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   117.89M| 3 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 4 | 4
5 |  OpenCSTL |         USet Longest   |   174.28M| 5 | 5
6 |  CC |   USet Longest(hset)   |   191.24M| 5 | 7
7 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 5 | 7
8 |  M*LIB |   USet Longest(dict)   |   216.39M| 7 | 8
9 |  STC |   USet Longest(hset)   |   219.02M| 8 | 9
10 |  STL | USet Longest(dict oa   |   457.03M| 9 | 10
11 |  CTL |   USet Longest(hset)   |   480.60M| 10 | 11


Model name:                              AMD EPYC 7763 64-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* OpenCSTL : ba90449c606887c4d69427bf69201161ff579342
* STC : 7c65ea473240270fcb8c0a287b04257b58902125
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : 2520dc115610ee51dd5fe48a1436ea2d61562164
* mlib : 4acdfe4c12040150e2e531517a005a1aace6b794
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : a82285b615fe5a20836fa1bbe2aa405c1b91c698
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 2c980bb59875b0d32144a71867fbdebb2f77cd20
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : a49bed0b4abb7dff16c73906dcdc8a9718d582d2
* xxHash : c0b5ea995d66691734b1a79ad89e73a0d2fd5a53
