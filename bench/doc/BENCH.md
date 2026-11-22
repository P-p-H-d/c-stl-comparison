# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  XXHASH |      Hash (xxhash64)    |   551.60 ms | 1 | 2
2 |  M*LIB |     Hash (Core Hash)    |   551.86 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1096.65 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3
3 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   31.81 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   38.97 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   39.54 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   60.16 ms | 4 | 4
5 |  M*LIB |     Queue(Buffer P2)    |   282.20 ms | 5 | 6
6 |  LIBLFDS |          Queue(MPMC)    |   387.81 ms | 5 | 6
7 |  M*LIB |        Queue(Buffer)    |   927.27 ms | 7 | 8
8 |  M*LIB |    Queue(Shared ptr)    |   1174.66 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1647.97 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(Buffer P2)   |   262.14K| 3 | 7
2 |  M*LIB |     Queue(SPSC Bulk)   |   319.49K| 1 | 8
3 |  M*LIB |       Queue(SPSC P2)   |   319.49K| 2 | 5
4 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 9
5 |  LIBLFDS |          Queue(MPMC)   |   393.22K| 4 | 8
6 |  M*LIB |          Queue(MPMC)   |   393.22K| 5 | 8
7 |  M*LIB |        Queue(Buffer)   |   393.22K| 3 | 7
8 |  M*LIB |       Queue(MPMC P2)   |   450.56K| 1 | 7
9 |  M*LIB |    Queue(Shared ptr)   |   655.36K| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |           Seq(Array)    |   506.96 ms | 1 | 4
2 |  STC |           Seq(Array)    |   515.33 ms | 1 | 5
3 |  M*LIB |           Seq(Array)    |   521.46 ms | 1 | 4
4 |  KLIB |           Seq(Array)    |   541.84 ms | 1 | 5
5 |  UT-HASH |           Seq(Array)    |   638.75 ms | 2 | 5
6 |  M*LIB |           Seq(Deque)    |   798.17 ms | 6 | 16
7 |  CTL |            Seq(List)    |   829.02 ms | 6 | 12
8 |  POTTERY |            Seq(List)    |   830.52 ms | 7 | 11
9 |  STC |            Seq(List)    |   831.11 ms | 7 | 12
10 |  M*LIB |            Seq(List)    |   840.48 ms | 6 | 12
11 |  M*LIB |          Seq(DPList)    |   842.89 ms | 8 | 12
12 |  UT-HASH |            Seq(List)    |   843.68 ms | 6 | 10
13 |  TommyDS |            Seq(List)    |   866.41 ms | 8 | 16
14 |  CC |            Seq(List)    |   915.39 ms | 11 | 14
15 |  GLIB |            Seq(List)    |   978.20 ms | 14 | 17
16 |  STL |            Seq(List)    |   1022.69 ms | 13 | 18
17 |  CollectionC |            Seq(List)    |   1028.41 ms | 13 | 18
18 |  TommyDS |           Seq(Array)    |   1033.65 ms | 20 | 28
19 |  KLIB |            Seq(List)    |   1099.53 ms | 17 | 22
20 |  STB-DS |        Seq(DynArray)    |   1239.37 ms | 16 | 24
21 |  CC |           Seq(Array)    |   1316.77 ms | 21 | 25
22 |  CMC |           Seq(Array)    |   1356.55 ms | 19 | 24
23 |  OpenCSTL |            Seq(List)    |   1363.58 ms | 19 | 23
24 |  STL |           Seq(Array)    |   1377.82 ms | 19 | 22
25 |  STL |           Seq(Deque)    |   1603.33 ms | 21 | 25
26 |  OpenCSTL |           Seq(Array)    |   2098.23 ms | 26 | 29
27 |  QLIBC |            Seq(List)    |   2136.14 ms | 25 | 28
28 |  POTTERY |           Seq(Array)    |   2150.44 ms | 27 | 29
29 |  CollectionC |           Seq(Array)    |   2200.58 ms | 23 | 26
30 |  CCC |           Seq(Array)    |   2331.22 ms | - | -
31 |  GLIB |           Seq(Array)    |   2560.41 ms | 28 | 30
32 |  OpenCSTL |           Seq(Deque)    |   3423.61 ms | 31 | 32
33 |  LIBSRT |           Seq(Array)    |   3429.53 ms | 29 | 32
34 |  QLIBC |           Seq(Array)    |   5085.08 ms | 30 | 33

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STL |            Seq(List)   |   1.28G| 2 | 10
2 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
3 |  CTL |            Seq(List)   |   1.28G| 1 | 9
4 |  POTTERY |            Seq(List)   |   1.28G| 2 | 10
5 |  STC |            Seq(List)   |   1.28G| 3 | 10
6 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
7 |  M*LIB |          Seq(DPList)   |   1.28G| 3 | 10
8 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 9
9 |  CC |            Seq(List)   |   1.28G| 1 | 10
10 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
13 |  CC |           Seq(Array)   |   1.60G| 12 | 15
14 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
15 |  OpenCSTL |           Seq(Array)   |   1.60G| 15 | 16
16 |  CCC |           Seq(Array)   |   1.60G| - | -
17 |  OpenCSTL |           Seq(Deque)   |   1.60G| 25 | 25
18 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 17
19 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
20 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 18
21 |  STC |           Seq(Array)   |   1.60G| 18 | 21
22 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
23 |  KLIB |           Seq(Array)   |   1.60G| 17 | 23
24 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
25 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 23
26 |  STL |           Seq(Array)   |   1.61G| 23 | 24
27 |  STL |           Seq(Deque)   |   1.68G| 24 | 26
28 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 27
29 |  OpenCSTL |            Seq(List)   |   1.92G| 29 | 29
30 |  TommyDS |            Seq(List)   |   1.92G| 26 | 28
31 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 31
32 |  QLIBC |            Seq(List)   |   3.20G| 27 | 31
33 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 32
34 |  GLIB |           Seq(Array)   |   4.80G| 30 | 33

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   924.57 ms | 1 | 1
2 |  STL |                 Sort    |   964.47 ms | 2 | 2
3 |  POTTERY |                 Sort    |   1056.58 ms | 3 | 4
4 |  STL |          Stable Sort    |   1132.54 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1140.57 ms | 4 | 5
6 |  CTL |                 Sort    |   1292.64 ms | 6 | 7
7 |  KLIB |                 Sort    |   1416.63 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1527.86 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1542.16 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1544.01 ms | 9 | 10
11 |  OpenCSTL |                 Sort    |   1557.82 ms | 10 | 12
12 |  GLIB |                 Sort    |   1577.62 ms | 11 | 12
13 |  CollectionC |                 Sort    |   2680.37 ms | 12 | 13
14 |  CCC |                 Sort    |   7290.77 ms | - | -

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   40.19M| 1 | 3
2 |  CTL |                 Sort   |   40.24M| 1 | 3
3 |  KLIB |                 Sort   |   40.24M| 1 | 3
4 |  CCC |                 Sort   |   40.24M| - | -
5 |  STL |                 Sort   |   67.35M| 4 | 4
6 |  LIBSRT |                 Sort   |   77.59M| 5 | 5
7 |  M*LIB |          Stable Sort   |   80.22M| 6 | 9
8 |  UT-HASH |                 Sort   |   80.22M| 6 | 9
9 |  M*LIB |                 Sort   |   80.22M| 6 | 9
10 |  OpenCSTL |                 Sort   |   80.22M| 6 | 6
11 |  POTTERY |                 Sort   |   97.64M| 9 | 10
12 |  STL |          Stable Sort   |   100.76M| 10 | 11
13 |  GLIB |                 Sort   |   160.04M| 11 | 12
14 |  CollectionC |                 Sort   |   1.12G| 12 | 13

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   862.06 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1043.00 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1998.03 ms | 3 | 5
4 |  STL |         SSet(Rbtree)    |   2444.76 ms | 3 | 6
5 |  OpenCSTL |            SSet(Set)    |   2459.88 ms | 4 | 7
6 |  CMC |           SSet(tree)    |   2599.17 ms | 6 | 10
7 |  CollectionC |      SSet(TreeTable)    |   2633.48 ms | 5 | 8
8 |  TommyDS |         SSet(Rbtree)    |   2682.13 ms | 7 | 10
9 |  CTL |            SSet(set)    |   2771.88 ms | 5 | 8
10 |  CCC |           SSet(Tree)    |   3093.93 ms | - | -
11 |  M*LIB |         SSet(Rbtree)    |   3202.76 ms | 3 | 8
12 |  QLIBC |         SSet(Rbtree)    |   4472.30 ms | 11 | 12
13 |  GLIB |          SSet(GTree)    |   4839.04 ms | 8 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   48.20M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.06M| 3 | 3
4 |  CMC |           SSet(tree)   |   95.94M| 6 | 8
5 |  CCC |           SSet(Tree)   |   95.99M| - | -
6 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 5
7 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  CTL |            SSet(set)   |   96.08M| 5 | 8
9 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 6
10 |  OpenCSTL |            SSet(Set)   |   96.47M| 9 | 9
11 |  CollectionC |      SSet(TreeTable)   |   127.93M| 9 | 10
12 |  GLIB |          SSet(GTree)   |   160.10M| 10 | 11
13 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 12

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   363.94 ms | 1 | 2
2 |  M*LIB |        String Concat    |   423.18 ms | 1 | 2
3 |  STL |        String Concat    |   592.97 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1405.72 ms | 4 | 4
5 |  SDS |        String Concat    |   2097.50 ms | 5 | 5
6 |  GLIB |        String Concat    |   2823.98 ms | 8 | 8
7 |  BSTRLIB |        String Concat    |   2825.06 ms | 6 | 6
8 |  CTL |        String Concat    |   2990.69 ms | 7 | 7

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat   |   1.04G| 1 | 1
2 |  STC |        String Concat   |   1.36G| 2 | 2
3 |  STL |        String Concat   |   1.79G| 3 | 3
4 |  SDS |        String Concat   |   2.00G| 4 | 4
5 |  POTTERY |        String Concat   |   2.09G| 5 | 5
6 |  BSTRLIB |        String Concat   |   3.28G| 6 | 6
7 |  CTL |        String Concat   |   4.02G| 7 | 7
8 |  GLIB |        String Concat   |   7.76G| 8 | 8

# Performance test: string replacement

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace    |   498.45 ms | 1 | 1
2 |  STL |       String Replace    |   985.18 ms | 2 | 3
3 |  STC |       String Replace    |   1119.29 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   238.16M| 1 | 1
2 |  STC |       String Replace   |   380.27M| 2 | 2
3 |  STL |       String Replace   |   414.07M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST |  UMap Str(uflat_map)    |   900.08 ms | 2 | 2
2 |  M*LIB |       UMap Str(dict)    |   978.13 ms | 1 | 1
3 |  STC |       UMap Str(hmap)    |   1557.82 ms | 3 | 3
4 |  STL |       UMap Str(umap)    |   3106.43 ms | 3 | 4
5 |  STL |        UMap Str(map)    |   7780.44 ms | 4 | 5

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.43M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.07M| 2 | 2
3 |  STC |       UMap Str(hmap)   |   352.61M| 3 | 3
4 |  STL |       UMap Str(umap)   |   353.38M| 3 | 4
5 |  BOOST |  UMap Str(uflat_map)   |   384.04M| 4 | 5

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   820.99 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   904.76 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   993.37 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1313.25 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1332.79 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1960.15 ms | 6 | 6
7 |  KLIB |     UMap U64(khashl)    |   2388.74 ms | 7 | 8
8 |  VERSTABLE |             UMap U64    |   2489.48 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2783.24 ms | 9 | 9
10 |  TommyDS |       UMap U64(dict)    |   3271.76 ms | 10 | 12
11 |  STC |       UMap U64(hmap)    |   4300.07 ms | 10 | 11
12 |  CCC |      UMap U64(FHash)    |   4360.31 ms | - | -
13 |  OpenCSTL |             UMap U64    |   5080.94 ms | 11 | 13
14 |  CollectionC |  UMap U64(HashTable)    |   5714.46 ms | 12 | 13
15 |  CMC |       UMap U64(hmap)    |   7080.95 ms | 13 | 14
16 |  STL |       UMap U64(umap)    |   10266.64 ms | 15 | 17
17 |  GLIB | UMap U64(GHashTable)    |   11766.79 ms | 14 | 15
18 |  UT-HASH |       UMap U64(dict)    |   12244.06 ms | 15 | 17

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.25M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.72M| 2 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   553.77M| 3 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   553.78M| 3 | 4
5 |  M*LIB |       UMap U64(dict)   |   588.64M| 5 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.44M| 6 | 6
7 |  STL |       UMap U64(umap)   |   836.91M| 10 | 11
8 |  OpenCSTL |             UMap U64   |   872.46M| 7 | 7
9 |  CC |        UMap U64(map)   |   906.21M| 8 | 10
10 |  VERSTABLE |             UMap U64   |   906.22M| 8 | 10
11 |  STC |       UMap U64(hmap)   |   906.22M| 7 | 10
12 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 11 | 12
13 |  CCC |      UMap U64(FHash)   |   1.45G| - | -
14 |  POTTERY |  UMap U64(open hash)   |   1.71G| 12 | 13
15 |  UT-HASH |       UMap U64(dict)   |   1.87G| 13 | 14
16 |  GLIB | UMap U64(GHashTable)   |   2.02G| 14 | 15
17 |  CMC |       UMap U64(hmap)   |   2.44G| 15 | 16
18 |  TommyDS |       UMap U64(dict)   |   4.16G| 16 | 17

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1303.83 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1704.48 ms | 2 | 2
3 |  CCC |      UMap Big(FHash)    |   1860.59 ms | - | -
4 |  TommyDS |       UMap Big(dict)    |   2003.17 ms | 3 | 7
5 |  CC |        UMap Big(map)    |   2244.24 ms | 3 | 7
6 |  VERSTABLE |             UMap Big    |   2340.22 ms | 3 | 4
7 |  GLIB | UMap Big(GHashTable)    |   2646.30 ms | 8 | 10
8 |  KLIB |      UMap Big(khash)    |   2674.12 ms | 5 | 10
9 |  M*LIB |    UMap Big(dict OA)    |   2772.26 ms | 5 | 7
10 |  STC |       UMap Big(hmap)    |   2805.21 ms | 5 | 9
11 |  POTTERY |  UMap Big(open hash)    |   3035.36 ms | 7 | 10
12 |  KLIB |     UMap Big(khashl)    |   3526.32 ms | 11 | 12
13 |  CollectionC |  UMap Big(HashTable)    |   3630.75 ms | 11 | 12
14 |  STL |       UMap Big(umap)    |   4213.73 ms | 13 | 13
15 |  UT-HASH |       UMap Big(dict)    |   4338.60 ms | 14 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.16G| 7 | 7
8 |  CCC |      UMap Big(FHash)   |   2.41G| - | -
9 |  BOOST |  UMap Big(uflat_map)   |   2.77G| 8 | 8
10 |  STC |       UMap Big(hmap)   |   3.20G| 11 | 11
11 |  CC |        UMap Big(map)   |   3.21G| 9 | 10
12 |  VERSTABLE |             UMap Big   |   3.21G| 9 | 10
13 |  M*LIB |    UMap Big(dict OA)   |   4.55G| 12 | 12
14 |  TommyDS |       UMap Big(dict)   |   5.09G| 13 | 13
15 |  POTTERY |  UMap Big(open hash)   |   6.15G| 14 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   490.84 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   717.06 ms | 2 | 3
3 |  M*LIB | USet Longest(dict oa    |   834.39 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   928.85 ms | 4 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1014.20 ms | 5 | 5
6 |  CC |   USet Longest(hset)    |   1152.41 ms | 7 | 9
7 |  KLIB | USet Longest(khashl)    |   1163.35 ms | 6 | 7
8 |  OpenCSTL |         USet Longest    |   1220.72 ms | 6 | 8
9 |  CCC |  USet Longest(FHash)    |   1389.27 ms | - | -
10 |  STC |   USet Longest(hset)    |   2134.35 ms | 8 | 9
11 |  CTL |   USet Longest(hset)    |   4597.37 ms | 9 | 10
12 |  STL | USet Longest(dict oa    |   5353.01 ms | 10 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.39M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.06M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   115.60M| 3 | 3
4 |  CCC |  USet Longest(FHash)   |   151.93M| - | -
5 |  BOOST | USet Longest(uflat_s   |   159.81M| 4 | 4
6 |  OpenCSTL |         USet Longest   |   174.34M| 5 | 5
7 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 5 | 7
8 |  CC |   USet Longest(hset)   |   191.24M| 5 | 7
9 |  M*LIB |   USet Longest(dict)   |   214.36M| 7 | 8
10 |  STC |   USet Longest(hset)   |   218.94M| 8 | 9
11 |  STL | USet Longest(dict oa   |   456.97M| 9 | 10
12 |  CTL |   USet Longest(hset)   |   498.89M| 10 | 11


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : 99f08e2b6e446e03fa3c7321b58e40ff3796d747
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* OpenCSTL : ba90449c606887c4d69427bf69201161ff579342
* STC : 7928d53440aa2df51d434d5fed8d314df1fb371f
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ccc : 88925e9058e6864f14ee554c379d6a3b6130528b
* ctl : ede5f455392f2380dd16aead26835eece6cd20e4
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : 2520dc115610ee51dd5fe48a1436ea2d61562164
* mlib : 93cddfb56c32976d8aeefd45ef9094167f64b285
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 43ad409875ecc29e3bad6a7bdc1d2ba6ff98cad3
* rapidjson : 297637bc0a0f00dc504dbc1a47ebdaa577f8ae19
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 6b5799bae8a1fe3792691ef4b72ae26434c3e799
* tommyds : dbfa731e6ad5cb33bc2003910d1540e7f037b37b
* uthash : a49bed0b4abb7dff16c73906dcdc8a9718d582d2
* xxHash : 2ec67caeb18ec15ae60c0853174331089acddfc0
