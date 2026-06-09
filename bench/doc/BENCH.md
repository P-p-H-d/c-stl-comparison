# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   760.97 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   831.25 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1271.16 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   29.76 ms | 1 | 2
2 |  M*LIB |       Queue(SPSC P2)    |   80.31 ms | 2 | 3
3 |  M*LIB |       Queue(MPMC P2)    |   167.17 ms | 1 | 3
4 |  M*LIB |          Queue(MPMC)    |   335.26 ms | 4 | 4
5 |  M*LIB |     Queue(Buffer P2)    |   520.82 ms | 6 | 6
6 |  LIBLFDS |          Queue(MPMC)    |   1055.99 ms | 5 | 5
7 |  M*LIB |        Queue(Buffer)    |   1724.78 ms | 8 | 8
8 |  M*LIB |    Queue(Shared ptr)    |   1742.07 ms | 7 | 7
9 |  BOOST | Queue MPMC (lockfree    |   2574.17 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 8
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 5
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 7
4 |  BOOST | Queue MPMC (lockfree   |   528.38K| 1 | 9
5 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 7
7 |  M*LIB |        Queue(Buffer)   |   532.48K| 3 | 7
8 |  LIBLFDS |          Queue(MPMC)   |   659.46K| 4 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   18.14M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   618.92 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   620.83 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   627.43 ms | 1 | 4
4 |  STC |           Seq(Array)    |   631.89 ms | 1 | 5
5 |  UT-HASH |           Seq(Array)    |   665.92 ms | 2 | 5
6 |  M*LIB |           Seq(Deque)    |   766.38 ms | 6 | 16
7 |  CTL |            Seq(List)    |   1040.84 ms | 6 | 12
8 |  POTTERY |            Seq(List)    |   1057.11 ms | 7 | 11
9 |  STC |            Seq(List)    |   1063.06 ms | 6 | 12
10 |  UT-HASH |            Seq(List)    |   1067.35 ms | 6 | 10
11 |  M*LIB |          Seq(DPList)    |   1074.51 ms | 8 | 12
12 |  M*LIB |            Seq(List)    |   1112.36 ms | 6 | 11
13 |  STL |            Seq(List)    |   1156.79 ms | 16 | 18
14 |  CC |            Seq(List)    |   1172.46 ms | 11 | 14
15 |  TommyDS |            Seq(List)    |   1194.72 ms | 8 | 16
16 |  STB-DS |        Seq(DynArray)    |   1211.42 ms | 19 | 24
17 |  GLIB |            Seq(List)    |   1211.83 ms | 14 | 17
18 |  CollectionC |            Seq(List)    |   1211.97 ms | 13 | 16
19 |  CMC |           Seq(Array)    |   1349.88 ms | 19 | 24
20 |  STL |           Seq(Array)    |   1461.85 ms | 19 | 22
21 |  STL |           Seq(Deque)    |   1543.96 ms | 22 | 25
22 |  KLIB |            Seq(List)    |   1582.21 ms | 17 | 18
23 |  OpenCSTL |            Seq(List)    |   1608.45 ms | 19 | 22
24 |  TommyDS |           Seq(Array)    |   1609.99 ms | 20 | 28
25 |  CC |           Seq(Array)    |   1641.03 ms | 19 | 24
26 |  CollectionC |           Seq(Array)    |   2180.36 ms | 23 | 26
27 |  OpenCSTL |           Seq(Array)    |   2429.12 ms | 26 | 29
28 |  QLIBC |            Seq(List)    |   2588.49 ms | 25 | 27
29 |  POTTERY |           Seq(Array)    |   2643.22 ms | 27 | 29
30 |  GLIB |           Seq(Array)    |   2797.41 ms | 28 | 30
31 |  OpenCSTL |           Seq(Deque)    |   2880.00 ms | 31 | 32
32 |  LIBSRT |           Seq(Array)    |   3877.51 ms | 29 | 32
33 |  QLIBC |           Seq(Array)    |   5343.19 ms | 30 | 33

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |            Seq(List)   |   1.28G| 1 | 8
2 |  POTTERY |            Seq(List)   |   1.28G| 4 | 10
3 |  STC |            Seq(List)   |   1.28G| 1 | 10
4 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 9
5 |  M*LIB |          Seq(DPList)   |   1.28G| 3 | 10
6 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
7 |  STL |            Seq(List)   |   1.28G| 2 | 10
8 |  CC |            Seq(List)   |   1.28G| 1 | 10
9 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
10 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  OpenCSTL |           Seq(Array)   |   1.60G| 15 | 16
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 17
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 18
18 |  KLIB |           Seq(Array)   |   1.60G| 17 | 23
19 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
20 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
21 |  STC |           Seq(Array)   |   1.60G| 17 | 21
22 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
23 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 23
24 |  STL |           Seq(Array)   |   1.61G| 23 | 24
25 |  OpenCSTL |           Seq(Deque)   |   1.61G| 25 | 25
26 |  STL |           Seq(Deque)   |   1.68G| 24 | 26
27 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 27
28 |  TommyDS |            Seq(List)   |   1.92G| 26 | 28
29 |  OpenCSTL |            Seq(List)   |   1.92G| 29 | 29
30 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 31
31 |  QLIBC |            Seq(List)   |   3.20G| 27 | 31
32 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 32
33 |  GLIB |           Seq(Array)   |   4.81G| 30 | 33

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   914.28 ms | 1 | 1
2 |  STL |                 Sort    |   915.52 ms | 2 | 2
3 |  STL |          Stable Sort    |   1058.57 ms | 4 | 5
4 |  POTTERY |                 Sort    |   1088.56 ms | 3 | 3
5 |  M*LIB |          Stable Sort    |   1089.27 ms | 4 | 5
6 |  KLIB |                 Sort    |   1315.60 ms | 7 | 7
7 |  CTL |                 Sort    |   1405.07 ms | 6 | 6
8 |  LIBSRT |                 Sort    |   1522.38 ms | 8 | 8
9 |  M*LIB |                 Sort    |   1546.93 ms | 10 | 10
10 |  OpenCSTL |                 Sort    |   1547.47 ms | 11 | 12
11 |  UT-HASH |                 Sort    |   1556.64 ms | 9 | 9
12 |  GLIB |                 Sort    |   1560.35 ms | 11 | 12
13 |  CollectionC |                 Sort    |   2772.19 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.29M| 1 | 3
2 |  CTL |                 Sort   |   41.29M| 1 | 3
3 |  STC |                 Sort   |   41.29M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.15M| 5 | 5
6 |  OpenCSTL |                 Sort   |   80.55M| 6 | 6
7 |  M*LIB |          Stable Sort   |   81.82M| 6 | 9
8 |  M*LIB |                 Sort   |   82.21M| 6 | 9
9 |  UT-HASH |                 Sort   |   82.33M| 6 | 8
10 |  POTTERY |                 Sort   |   99.11M| 9 | 10
11 |  STL |          Stable Sort   |   100.75M| 10 | 11
12 |  GLIB |                 Sort   |   165.37M| 11 | 12
13 |  CollectionC |                 Sort   |   1.12G| 12 | 13

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   883.86 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1215.80 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2647.13 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2977.08 ms | 3 | 7
5 |  CollectionC |      SSet(TreeTable)    |   3033.88 ms | 6 | 8
6 |  STL |         SSet(Rbtree)    |   3067.17 ms | 4 | 9
7 |  OpenCSTL |            SSet(Set)    |   3182.30 ms | 4 | 5
8 |  CTL |            SSet(set)    |   3295.68 ms | 5 | 8
9 |  CMC |           SSet(tree)    |   3415.70 ms | 4 | 10
10 |  TommyDS |         SSet(Rbtree)    |   3513.24 ms | 7 | 10
11 |  GLIB |          SSet(GTree)    |   4025.08 ms | 8 | 11
12 |  QLIBC |         SSet(Rbtree)    |   4908.59 ms | 11 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.67M| 1 | 1
2 |  STC |           SSet(sset)   |   49.73M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.06M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 5
5 |  M*LIB |         SSet(Rbtree)   |   96.21M| 4 | 6
6 |  CTL |            SSet(set)   |   96.21M| 5 | 8
7 |  CMC |           SSet(tree)   |   96.21M| 6 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.21M| 4 | 8
9 |  OpenCSTL |            SSet(Set)   |   96.60M| 9 | 9
10 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 10
11 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 11
12 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 12

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat    |   478.56 ms | 2 | 2
2 |  STC |        String Concat    |   491.89 ms | 1 | 1
3 |  STL |        String Concat    |   660.22 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1487.47 ms | 4 | 4
5 |  SDS |        String Concat    |   2012.01 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   2934.82 ms | 6 | 6
7 |  CTL |        String Concat    |   3724.20 ms | 7 | 7
8 |  GLIB |        String Concat    |   4919.55 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   417.58 ms | 1 | 1
2 |  STC |       String Replace    |   1283.27 ms | 3 | 3
3 |  STL |       String Replace    |   1635.32 ms | 2 | 2

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.14M| 1 | 1
2 |  STC |       String Replace   |   382.32M| 2 | 2
3 |  STL |       String Replace   |   416.06M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   877.05 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   1080.76 ms | 2 | 2
3 |  STC |       UMap Str(hmap)    |   1479.99 ms | - | -
4 |  STL |       UMap Str(umap)    |   2810.50 ms | 3 | 3
5 |  STL |        UMap Str(map)    |   8003.56 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.53M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.23M| 2 | 2
3 |  STC |       UMap Str(hmap)   |   352.59M| - | -
4 |  STL |       UMap Str(umap)   |   353.61M| 3 | 3
5 |  BOOST |  UMap Str(uflat_map)   |   384.18M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap U64(dict)    |   804.21 ms | 1 | 3
2 |  M*LIB | UMap U64 (dict Bulk)    |   844.09 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   899.76 ms | 2 | 3
4 |  BOOST |  UMap U64(uflat_map)    |   1223.87 ms | 5 | 5
5 |  KLIB |      UMap U64(khash)    |   1249.96 ms | 4 | 4
6 |  POTTERY |  UMap U64(open hash)    |   1756.35 ms | 6 | 6
7 |  KLIB |     UMap U64(khashl)    |   2029.10 ms | 7 | 8
8 |  VERSTABLE |             UMap U64    |   2169.81 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2572.52 ms | 9 | 9
10 |  TommyDS |       UMap U64(dict)    |   3266.05 ms | 10 | 12
11 |  STC |       UMap U64(hmap)    |   3292.71 ms | 10 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   3522.08 ms | 12 | 13
13 |  OpenCSTL |             UMap U64    |   4261.93 ms | 11 | 13
14 |  CMC |       UMap U64(hmap)    |   6335.12 ms | 13 | 14
15 |  GLIB | UMap U64(GHashTable)    |   7072.76 ms | 14 | 15
16 |  STL |       UMap U64(umap)    |   9101.22 ms | 15 | 17
17 |  UT-HASH |       UMap U64(dict)    |   9398.93 ms | 15 | 17

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.42M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.79M| 2 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.40M| 3 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   556.81M| 3 | 4
5 |  M*LIB |       UMap U64(dict)   |   590.03M| 5 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 6 | 6
7 |  OpenCSTL |             UMap U64   |   874.69M| 7 | 7
8 |  STC |       UMap U64(hmap)   |   906.27M| 7 | 9
9 |  CC |        UMap U64(map)   |   906.34M| 8 | 10
10 |  VERSTABLE |             UMap U64   |   906.35M| 8 | 9
11 |  STL |       UMap U64(umap)   |   933.87M| 10 | 11
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
1 |  M*LIB |       UMap Big(dict)    |   1286.99 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1818.20 ms | 2 | 2
3 |  TommyDS |       UMap Big(dict)    |   1934.08 ms | 5 | 6
4 |  VERSTABLE |             UMap Big    |   2027.62 ms | 3 | 4
5 |  STC |       UMap Big(hmap)    |   2208.26 ms | 6 | 9
6 |  M*LIB |    UMap Big(dict OA)    |   2358.27 ms | 5 | 7
7 |  CC |        UMap Big(map)    |   2502.45 ms | 3 | 4
8 |  KLIB |      UMap Big(khash)    |   2583.66 ms | 7 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2605.15 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2651.90 ms | 8 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   2812.20 ms | 11 | 12
12 |  KLIB |     UMap Big(khashl)    |   2900.20 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4038.86 ms | 13 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4571.14 ms | 14 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
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
1 |  BOOST | USet Longest(uflat_s    |   407.01 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   723.40 ms | 3 | 3
3 |  KLIB |  USet Longest(khash)    |   785.01 ms | 2 | 2
4 |  M*LIB |   USet Longest(dict)    |   796.21 ms | 4 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1026.33 ms | 5 | 5
6 |  KLIB | USet Longest(khashl)    |   1167.00 ms | 6 | 7
7 |  CC |   USet Longest(hset)    |   1235.06 ms | 7 | 9
8 |  OpenCSTL |         USet Longest    |   1399.99 ms | 6 | 7
9 |  STC |   USet Longest(hset)    |   1652.17 ms | 8 | 9
10 |  CTL |   USet Longest(hset)    |   3608.13 ms | 9 | 10
11 |  STL | USet Longest(dict oa    |   4725.32 ms | 10 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.36M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.38M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   117.72M| 3 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.80M| 4 | 4
5 |  OpenCSTL |         USet Longest   |   174.45M| 5 | 5
6 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 5 | 7
7 |  CC |   USet Longest(hset)   |   191.37M| 5 | 6
8 |  M*LIB |   USet Longest(dict)   |   214.50M| 7 | 8
9 |  STC |   USet Longest(hset)   |   219.15M| 8 | 9
10 |  STL | USet Longest(dict oa   |   456.93M| 9 | 10
11 |  CTL |   USet Longest(hset)   |   480.73M| 10 | 11


Model name:                              Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* OpenCSTL : c02efabbf563b2fedb7dcd4f0581638afe2935cc
* STC : 4ebfb1de9a9bee42a43b2928670f9e39bdcc00b8
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : c49d8ea15ad07622b39b3113b6605b1f36e92ff7
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 1060908cd84b1f58c68a76ef02bc8b6db83cba07
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 5ada598b0d9799cd2555eb9c87fd8854b359c62c
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
