# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   678.63 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   694.92 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1321.76 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   53.06 ms | 1 | 1
2 |  M*LIB |       Queue(SPSC P2)    |   61.84 ms | 2 | 2
3 |  M*LIB |       Queue(MPMC P2)    |   125.75 ms | 3 | 3
4 |  M*LIB |          Queue(MPMC)    |   224.50 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   553.27 ms | 5 | 5
6 |  M*LIB |     Queue(Buffer P2)    |   769.09 ms | 6 | 6
7 |  BOOST | Queue MPMC (lockfree    |   1373.48 ms | 7 | 7
8 |  M*LIB |        Queue(Buffer)    |   2107.11 ms | 7 | 8
9 |  M*LIB |    Queue(Shared ptr)    |   3327.54 ms | 8 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   77.82K| 1 | 3
2 |  M*LIB |       Queue(MPMC P2)   |   139.26K| 1 | 3
3 |  M*LIB |     Queue(Buffer P2)   |   151.55K| 2 | 4
4 |  M*LIB |       Queue(SPSC P2)   |   200.70K| 2 | 4
5 |  LIBLFDS |          Queue(MPMC)   |   638.98K| 5 | 5
6 |  M*LIB |        Queue(Buffer)   |   856.06K| 6 | 6
7 |  M*LIB |          Queue(MPMC)   |   901.12K| 7 | 7
8 |  BOOST | Queue MPMC (lockfree   |   1.03M| 8 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   9.67M| 9 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   617.18 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   638.03 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   672.52 ms | 1 | 4
4 |  STC |           Seq(Array)    |   676.58 ms | 1 | 2
5 |  UT-HASH |           Seq(Array)    |   712.38 ms | 4 | 5
6 |  M*LIB |           Seq(Deque)    |   938.22 ms | 6 | 6
7 |  STB-DS |        Seq(DynArray)    |   1272.37 ms | 7 | 7
8 |  POTTERY |            Seq(List)    |   1432.48 ms | 8 | 13
9 |  CTL |            Seq(List)    |   1447.56 ms | 9 | 12
10 |  UT-HASH |            Seq(List)    |   1457.96 ms | 8 | 11
11 |  M*LIB |            Seq(List)    |   1479.90 ms | 8 | 20
12 |  M*LIB |          Seq(DPList)    |   1480.44 ms | 10 | 13
13 |  STC |            Seq(List)    |   1488.71 ms | 9 | 13
14 |  STL |           Seq(Array)    |   1562.62 ms | 14 | 16
15 |  GLIB |            Seq(List)    |   1582.51 ms | 7 | 15
16 |  STL |            Seq(List)    |   1612.63 ms | 15 | 17
17 |  CC |            Seq(List)    |   1642.51 ms | 16 | 18
18 |  CollectionC |            Seq(List)    |   1684.07 ms | 13 | 18
19 |  TommyDS |           Seq(Array)    |   1710.44 ms | 19 | 22
20 |  M*LIB |            Seq(List)    |   1761.97 ms | 8 | 20
21 |  CMC |           Seq(Array)    |   1770.90 ms | 17 | 21
22 |  TommyDS |            Seq(List)    |   1787.34 ms | 18 | 22
23 |  STL |           Seq(Deque)    |   1866.59 ms | 20 | 23
24 |  KLIB |            Seq(List)    |   2194.44 ms | 22 | 24
25 |  CC |           Seq(Array)    |   2317.89 ms | 22 | 25
26 |  OpenCSTL |            Seq(List)    |   2827.20 ms | 26 | 26
27 |  CollectionC |           Seq(Array)    |   2907.09 ms | 24 | 27
28 |  OpenCSTL |           Seq(Array)    |   3425.89 ms | 28 | 28
29 |  POTTERY |           Seq(Array)    |   3969.80 ms | 25 | 29
30 |  QLIBC |            Seq(List)    |   4223.69 ms | 26 | 30
31 |  LIBSRT |           Seq(Array)    |   5888.32 ms | 27 | 31
32 |  GLIB |           Seq(Array)    |   7264.64 ms | 28 | 32
33 |  OpenCSTL |           Seq(Deque)    |   7299.82 ms | 33 | 33
34 |  QLIBC |           Seq(Array)    |   7941.47 ms | 29 | 34
35 |  CCC |           Seq(Array)    |   7974.56 ms | 35 | 35

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  GLIB |            Seq(List)   |   788.58M| 1 | 1
2 |  POTTERY |            Seq(List)   |   1.28G| 2 | 6
3 |  CTL |            Seq(List)   |   1.28G| 3 | 5
4 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 4
5 |  M*LIB |            Seq(List)   |   1.28G| 6 | 11
6 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 7
7 |  STC |            Seq(List)   |   1.28G| 3 | 6
8 |  STL |            Seq(List)   |   1.28G| 8 | 9
9 |  CC |            Seq(List)   |   1.28G| 9 | 10
10 |  CollectionC |            Seq(List)   |   1.28G| 7 | 10
11 |  M*LIB |            Seq(List)   |   1.28G| 6 | 11
12 |  KLIB |            Seq(List)   |   1.44G| 11 | 12
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 22
14 |  CMC |           Seq(Array)   |   1.60G| 12 | 14
15 |  CC |           Seq(Array)   |   1.60G| 13 | 15
16 |  OpenCSTL |           Seq(Array)   |   1.60G| 16 | 16
17 |  LIBSRT |           Seq(Array)   |   1.60G| 14 | 17
18 |  KLIB |           Seq(Array)   |   1.60G| 19 | 19
19 |  M*LIB |           Seq(Array)   |   1.60G| 15 | 20
20 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
21 |  STC |           Seq(Array)   |   1.60G| 16 | 18
22 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
23 |  QLIBC |           Seq(Array)   |   1.60G| 14 | 23
24 |  CCC |           Seq(Array)   |   1.60G| 24 | 24
25 |  M*LIB |           Seq(Deque)   |   1.60G| 21 | 25
26 |  STL |           Seq(Array)   |   1.61G| 22 | 26
27 |  OpenCSTL |           Seq(Deque)   |   1.61G| 27 | 27
28 |  STL |           Seq(Deque)   |   1.68G| 23 | 28
29 |  POTTERY |           Seq(Array)   |   1.70G| 24 | 29
30 |  TommyDS |            Seq(List)   |   1.92G| 25 | 30
31 |  OpenCSTL |            Seq(List)   |   1.92G| 31 | 31
32 |  TommyDS |           Seq(Array)   |   3.20G| 26 | 32
33 |  QLIBC |            Seq(List)   |   3.20G| 27 | 33
34 |  CollectionC |           Seq(Array)   |   3.22G| 28 | 34
35 |  GLIB |           Seq(Array)   |   4.80G| 29 | 35

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STL |                 Sort    |   921.35 ms | 1 | 2
2 |  STC |                 Sort    |   1039.70 ms | 1 | 2
3 |  KLIB |                 Sort    |   1056.49 ms | 3 | 6
4 |  STL |          Stable Sort    |   1087.41 ms | 4 | 5
5 |  POTTERY |                 Sort    |   1117.91 ms | 3 | 5
6 |  M*LIB |          Stable Sort    |   1144.71 ms | 3 | 6
7 |  CTL |                 Sort    |   1625.86 ms | 7 | 8
8 |  UT-HASH |                 Sort    |   1632.36 ms | 8 | 10
9 |  M*LIB |                 Sort    |   1672.53 ms | 9 | 10
10 |  LIBSRT |                 Sort    |   1689.61 ms | 7 | 10
11 |  GLIB |                 Sort    |   1883.00 ms | 11 | 11
12 |  OpenCSTL |                 Sort    |   1953.60 ms | 12 | 12
13 |  CollectionC |                 Sort    |   3915.14 ms | 12 | 13
14 |  CCC |                 Sort    |   16361.34 ms | 14 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.19M| 1 | 2
2 |  KLIB |                 Sort   |   41.41M| 1 | 2
3 |  CTL |                 Sort   |   41.71M| 3 | 3
4 |  CCC |                 Sort   |   42.02M| 4 | 4
5 |  STL |                 Sort   |   70.03M| 4 | 5
6 |  LIBSRT |                 Sort   |   79.77M| 5 | 6
7 |  M*LIB |          Stable Sort   |   80.39M| 7 | 8
8 |  M*LIB |                 Sort   |   80.63M| 6 | 8
9 |  OpenCSTL |                 Sort   |   80.78M| 9 | 9
10 |  UT-HASH |                 Sort   |   81.00M| 6 | 10
11 |  POTTERY |                 Sort   |   98.32M| 9 | 11
12 |  STL |          Stable Sort   |   102.27M| 10 | 12
13 |  GLIB |                 Sort   |   163.43M| 11 | 13
14 |  CollectionC |                 Sort   |   1.12G| 12 | 14

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   1215.77 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1697.20 ms | 2 | 2
3 |  OpenCSTL |            SSet(Set)    |   2922.63 ms | 3 | 3
4 |  M*LIB |         SSet(Rbtree)    |   3337.86 ms | 3 | 5
5 |  CTL |            SSet(set)    |   3400.13 ms | 5 | 6
6 |  STL |         SSet(Rbtree)    |   3584.04 ms | 4 | 7
7 |  STC |           SSet(sset)    |   3641.82 ms | 3 | 5
8 |  CCC |           SSet(Tree)    |   3817.05 ms | 8 | 8
9 |  TommyDS |         SSet(Rbtree)    |   3907.60 ms | 8 | 9
10 |  CMC |           SSet(tree)    |   3931.56 ms | 7 | 10
11 |  CollectionC |      SSet(TreeTable)    |   3992.64 ms | 7 | 11
12 |  GLIB |          SSet(GTree)    |   5250.93 ms | 10 | 12
13 |  QLIBC |         SSet(Rbtree)    |   5408.39 ms | 11 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.79M| 1 | 1
2 |  STC |           SSet(sset)   |   48.51M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.18M| 3 | 3
4 |  CCC |           SSet(Tree)   |   96.08M| 4 | 4
5 |  CMC |           SSet(tree)   |   96.19M| 4 | 7
6 |  TommyDS |         SSet(Rbtree)   |   96.24M| 4 | 6
7 |  CTL |            SSet(set)   |   96.27M| 6 | 7
8 |  M*LIB |         SSet(Rbtree)   |   96.35M| 5 | 8
9 |  OpenCSTL |            SSet(Set)   |   96.76M| 9 | 9
10 |  STL |         SSet(Rbtree)   |   96.80M| 8 | 10
11 |  CollectionC |      SSet(TreeTable)   |   128.23M| 9 | 11
12 |  GLIB |          SSet(GTree)   |   178.88M| 10 | 12
13 |  QLIBC |         SSet(Rbtree)   |   288.18M| 11 | 13

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat    |   504.32 ms | 1 | 1
2 |  STC |        String Concat    |   670.92 ms | 2 | 2
3 |  STL |        String Concat    |   1029.16 ms | 3 | 3
4 |  POTTERY |        String Concat    |   2370.01 ms | 4 | 4
5 |  SDS |        String Concat    |   3831.00 ms | 5 | 5
6 |  CTL |        String Concat    |   4290.76 ms | 5 | 7
7 |  BSTRLIB |        String Concat    |   5396.42 ms | 6 | 7
8 |  GLIB |        String Concat    |   6504.51 ms | 6 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat   |   1.04G| 1 | 1
2 |  STC |        String Concat   |   1.36G| 2 | 2
3 |  STL |        String Concat   |   1.79G| 3 | 3
4 |  SDS |        String Concat   |   2.00G| 4 | 4
5 |  POTTERY |        String Concat   |   2.04G| 5 | 5
6 |  BSTRLIB |        String Concat   |   3.28G| 6 | 6
7 |  CTL |        String Concat   |   4.02G| 7 | 7
8 |  GLIB |        String Concat   |   8.01G| 8 | 8

# Performance test: string replacement

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace    |   624.25 ms | 1 | 1
2 |  STC |       String Replace    |   2518.94 ms | 2 | 2
3 |  STL |       String Replace    |   3040.92 ms | 3 | 3
4 |  BSTRLIB |       String Replace    |   3189.24 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   238.48M| 1 | 1
2 |  STC |       String Replace   |   383.65M| 2 | 2
3 |  STL |       String Replace   |   416.40M| 3 | 3
4 |  BSTRLIB |       String Replace   |   688.07M| 4 | 4

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   976.21 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1110.59 ms | 1 | 2
3 |  STC |       UMap Str(hmap)    |   1994.99 ms | - | -
4 |  STL |       UMap Str(umap)    |   3087.35 ms | 2 | 3
5 |  STL |        UMap Str(map)    |   8095.60 ms | 3 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.80M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.97M| 2 | 2
3 |  STC |       UMap Str(hmap)   |   352.80M| - | -
4 |  STL |       UMap Str(umap)   |   354.22M| 3 | 3
5 |  BOOST |  UMap Str(uflat_map)   |   384.86M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   939.11 ms | 1 | 1
2 |  M*LIB |       UMap U64(dict)    |   1052.67 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   1097.25 ms | 2 | 3
4 |  BOOST |  UMap U64(uflat_map)    |   1835.25 ms | 4 | 4
5 |  KLIB |      UMap U64(khash)    |   2159.04 ms | 3 | 6
6 |  POTTERY |  UMap U64(open hash)    |   2539.95 ms | 4 | 6
7 |  VERSTABLE |             UMap U64    |   2958.11 ms | 5 | 8
8 |  CC |        UMap U64(map)    |   2981.42 ms | 6 | 8
9 |  KLIB |     UMap U64(khashl)    |   2991.56 ms | 9 | 9
10 |  STC |       UMap U64(hmap)    |   3113.53 ms | 7 | 10
11 |  OpenCSTL |             UMap U64    |   4631.83 ms | 11 | 11
12 |  CCC |      UMap U64(FHash)    |   5437.92 ms | 12 | 12
13 |  TommyDS |       UMap U64(dict)    |   6000.75 ms | 8 | 13
14 |  GLIB | UMap U64(GHashTable)    |   9281.40 ms | 10 | 14
15 |  CollectionC |  UMap U64(HashTable)    |   10453.74 ms | 9 | 15
16 |  STL |       UMap U64(umap)    |   12863.35 ms | 11 | 16
17 |  CMC |       UMap U64(hmap)    |   13310.11 ms | 12 | 17
18 |  UT-HASH |       UMap U64(dict)    |   13965.45 ms | 13 | 18

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.50M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.85M| 1 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   557.58M| 2 | 3
4 |  M*LIB |    UMap U64(dict OA)   |   558.04M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   590.88M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   806.26M| 5 | 6
7 |  OpenCSTL |             UMap U64   |   872.70M| 7 | 7
8 |  VERSTABLE |             UMap U64   |   906.41M| 6 | 8
9 |  STC |       UMap U64(hmap)   |   906.42M| 8 | 10
10 |  CC |        UMap U64(map)   |   906.44M| 6 | 9
11 |  STL |       UMap U64(umap)   |   934.56M| 9 | 11
12 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 12
13 |  CCC |      UMap U64(FHash)   |   1.45G| 13 | 13
14 |  GLIB | UMap U64(GHashTable)   |   1.68G| 13 | 14
15 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 15
16 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 16
17 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 17
18 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 18

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1784.25 ms | 1 | 2
2 |  BOOST |  UMap Big(uflat_map)    |   1797.71 ms | 1 | 2
3 |  CCC |      UMap Big(FHash)    |   2283.76 ms | 3 | 3
4 |  VERSTABLE |             UMap Big    |   2337.76 ms | 3 | 4
5 |  CC |        UMap Big(map)    |   2399.11 ms | 2 | 5
6 |  M*LIB |    UMap Big(dict OA)    |   2653.68 ms | 4 | 8
7 |  TommyDS |       UMap Big(dict)    |   2856.85 ms | 5 | 7
8 |  STC |       UMap Big(hmap)    |   2872.14 ms | 5 | 8
9 |  POTTERY |  UMap Big(open hash)    |   2932.27 ms | 8 | 9
10 |  KLIB |      UMap Big(khash)    |   3062.85 ms | 7 | 10
11 |  GLIB | UMap Big(GHashTable)    |   3838.54 ms | 9 | 11
12 |  KLIB |     UMap Big(khashl)    |   3920.18 ms | 12 | 12
13 |  CollectionC |  UMap Big(HashTable)    |   4310.89 ms | 10 | 13
14 |  STL |       UMap Big(umap)    |   5240.01 ms | 11 | 14
15 |  UT-HASH |       UMap Big(dict)    |   6097.45 ms | 12 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  GLIB | UMap Big(GHashTable)   |   1.68G| 2 | 3
3 |  STL |       UMap Big(umap)   |   1.68G| 2 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.76G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.17G| 7 | 7
8 |  CCC |      UMap Big(FHash)   |   2.70G| 8 | 8
9 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 9
10 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 10
11 |  CC |        UMap Big(map)   |   3.23G| 9 | 11
12 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 12
13 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 13
14 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 14
15 |  POTTERY |  UMap Big(open hash)   |   6.47G| 13 | 15

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   836.92 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   1077.54 ms | 2 | 2
3 |  KLIB |  USet Longest(khash)    |   1134.68 ms | 3 | 3
4 |  M*LIB |   USet Longest(dict)    |   1138.32 ms | 3 | 4
5 |  CC |   USet Longest(hset)    |   1536.18 ms | 4 | 5
6 |  VERSTABLE |   USet Longest(hset)    |   1560.62 ms | 4 | 6
7 |  KLIB | USet Longest(khashl)    |   1702.07 ms | 7 | 7
8 |  STC |   USet Longest(hset)    |   1743.07 ms | 6 | 8
9 |  OpenCSTL |         USet Longest    |   2343.25 ms | 9 | 9
10 |  CCC |  USet Longest(FHash)    |   2757.22 ms | 10 | 10
11 |  STL | USet Longest(dict oa    |   7314.16 ms | 7 | 11
12 |  CTL |   USet Longest(hset)    |   8556.20 ms | 8 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.44M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.39M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   118.57M| 1 | 3
4 |  CCC |  USet Longest(FHash)   |   152.10M| 4 | 4
5 |  BOOST | USet Longest(uflat_s   |   160.49M| 2 | 5
6 |  OpenCSTL |         USet Longest   |   174.48M| 6 | 6
7 |  VERSTABLE |   USet Longest(hset)   |   191.42M| 4 | 7
8 |  CC |   USet Longest(hset)   |   191.46M| 3 | 8
9 |  M*LIB |   USet Longest(dict)   |   216.56M| 5 | 9
10 |  STC |   USet Longest(hset)   |   219.25M| 6 | 10
11 |  STL | USet Longest(dict oa   |   457.62M| 7 | 11
12 |  CTL |   USet Longest(hset)   |   480.78M| 8 | 12


Model name:                              Intel(R) Core(TM) i5-3210M CPU @ 2.50GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* OpenCSTL : 8b5b4c6f3f0f5bb81b5111c4ec2d52ff9300e19a
* STC : 4ebfb1de9a9bee42a43b2928670f9e39bdcc00b8
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ccc : 00708b83855c91eaa45097e26c4007c2421901aa
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
