# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  XXHASH |      Hash (xxhash64)    |   549.26 ms | 1 | 2
2 |  M*LIB |     Hash (Core Hash)    |   549.82 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1094.69 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3
3 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   30.43 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   32.31 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   36.42 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   60.26 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   382.59 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   520.50 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   910.32 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1307.40 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1663.75 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | Queue MPMC (lockfree   |   393.22K| 2 | 9
2 |  M*LIB |       Queue(SPSC P2)   |   397.31K| 1 | 4
3 |  M*LIB |     Queue(Buffer P2)   |   397.31K| 3 | 8
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 4 | 7
5 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
6 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 1 | 8
7 |  M*LIB |     Queue(SPSC Bulk)   |   585.73K| 1 | 4
8 |  LIBLFDS |          Queue(MPMC)   |   659.46K| 5 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   790.53K| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |           Seq(Array)    |   556.86 ms | 1 | 4
2 |  KLIB |           Seq(Array)    |   587.84 ms | 1 | 5
3 |  STC |           Seq(Array)    |   589.17 ms | 1 | 4
4 |  CTL |           Seq(Array)    |   651.34 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   678.77 ms | 4 | 5
6 |  UT-HASH |            Seq(List)    |   714.57 ms | 6 | 12
7 |  M*LIB |            Seq(List)    |   723.28 ms | 6 | 10
8 |  TommyDS |            Seq(List)    |   730.63 ms | 11 | 18
9 |  STC |            Seq(List)    |   733.25 ms | 6 | 12
10 |  M*LIB |          Seq(DPList)    |   746.06 ms | 8 | 12
11 |  POTTERY |            Seq(List)    |   749.46 ms | 7 | 11
12 |  CTL |            Seq(List)    |   762.49 ms | 6 | 12
13 |  CC |            Seq(List)    |   774.20 ms | 12 | 14
14 |  GLIB |            Seq(List)    |   811.07 ms | 14 | 16
15 |  CollectionC |            Seq(List)    |   846.14 ms | 13 | 16
16 |  M*LIB |           Seq(Deque)    |   905.76 ms | 6 | 16
17 |  STL |            Seq(List)    |   921.02 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   932.63 ms | 17 | 23
19 |  STL |           Seq(Array)    |   1398.48 ms | 19 | 22
20 |  TommyDS |           Seq(Array)    |   1413.87 ms | 19 | 26
21 |  CC |           Seq(Array)    |   1416.41 ms | 19 | 24
22 |  CMC |           Seq(Array)    |   1454.41 ms | 19 | 23
23 |  STB-DS |        Seq(DynArray)    |   1527.81 ms | 17 | 24
24 |  STL |           Seq(Deque)    |   1594.91 ms | 21 | 24
25 |  CollectionC |           Seq(Array)    |   1842.58 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   1907.74 ms | 25 | 26
27 |  POTTERY |           Seq(Array)    |   1966.74 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   2670.04 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   3451.28 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   5318.78 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
2 |  M*LIB |            Seq(List)   |   1.28G| 3 | 9
3 |  STC |            Seq(List)   |   1.28G| 1 | 10
4 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
5 |  POTTERY |            Seq(List)   |   1.28G| 1 | 10
6 |  CTL |            Seq(List)   |   1.28G| 2 | 10
7 |  CC |            Seq(List)   |   1.28G| 1 | 10
8 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
9 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
10 |  STL |            Seq(List)   |   1.28G| 2 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CC |           Seq(Array)   |   1.60G| 12 | 15
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  M*LIB |           Seq(Array)   |   1.60G| 18 | 21
18 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
19 |  STC |           Seq(Array)   |   1.60G| 17 | 21
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 20
21 |  UT-HASH |           Seq(Array)   |   1.60G| 20 | 22
22 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
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
1 |  STC |                 Sort    |   938.52 ms | 1 | 2
2 |  STL |                 Sort    |   950.74 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1022.66 ms | 3 | 5
4 |  STL |          Stable Sort    |   1095.19 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1142.24 ms | 4 | 5
6 |  CTL |                 Sort    |   1301.13 ms | 6 | 7
7 |  KLIB |                 Sort    |   1392.32 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1424.25 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1451.82 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1470.27 ms | 9 | 10
11 |  GLIB |                 Sort    |   1525.25 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2705.10 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.29M| 1 | 3
2 |  CTL |                 Sort   |   41.82M| 1 | 3
3 |  STC |                 Sort   |   41.82M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.52M| 5 | 5
6 |  UT-HASH |                 Sort   |   81.29M| 6 | 8
7 |  M*LIB |                 Sort   |   81.82M| 6 | 8
8 |  M*LIB |          Stable Sort   |   82.09M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   165.78M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   736.32 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1038.31 ms | 2 | 2
3 |  M*LIB |         SSet(Rbtree)    |   2732.62 ms | 3 | 6
4 |  STC |           SSet(sset)    |   2781.04 ms | 3 | 5
5 |  STL |         SSet(Rbtree)    |   2999.59 ms | 4 | 9
6 |  CollectionC |      SSet(TreeTable)    |   3365.80 ms | 6 | 8
7 |  CTL |            SSet(set)    |   3461.64 ms | 4 | 9
8 |  TommyDS |         SSet(Rbtree)    |   3580.94 ms | 7 | 10
9 |  CMC |           SSet(tree)    |   3646.92 ms | 4 | 9
10 |  GLIB |          SSet(GTree)    |   4274.95 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4553.65 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.67M| 1 | 1
2 |  STC |           SSet(sset)   |   49.57M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.14M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
5 |  M*LIB |         SSet(Rbtree)   |   96.21M| 4 | 7
6 |  CTL |            SSet(set)   |   96.21M| 4 | 8
7 |  TommyDS |         SSet(Rbtree)   |   96.21M| 4 | 8
8 |  CMC |           SSet(tree)   |   96.21M| 5 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.17M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   320.77 ms | 1 | 1
2 |  M*LIB |        String Concat    |   429.12 ms | 2 | 2
3 |  STL |        String Concat    |   502.00 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1284.64 ms | 4 | 4
5 |  SDS |        String Concat    |   1854.77 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   2522.06 ms | 6 | 6
7 |  CTL |        String Concat    |   2892.09 ms | 7 | 7
8 |  GLIB |        String Concat    |   3342.53 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   440.21 ms | 1 | 1
2 |  STL |       String Replace    |   978.06 ms | 2 | 3
3 |  STC |       String Replace    |   1105.92 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.38M| 1 | 1
2 |  STC |       String Replace   |   382.45M| 2 | 2
3 |  STL |       String Replace   |   415.04M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   908.79 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   987.24 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   3081.43 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   8130.83 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.50M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.20M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.57M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   766.44 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   818.88 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   874.64 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1202.58 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1252.87 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1753.79 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2080.40 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2369.99 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2899.08 ms | 8 | 9
10 |  TommyDS |       UMap U64(dict)    |   3584.17 ms | 9 | 11
11 |  STC |       UMap U64(hmap)    |   3617.73 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4051.37 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   6458.30 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   7917.60 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   9840.13 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   11461.23 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.41M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.76M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.71M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   556.77M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   590.03M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.26M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.34M| 6 | 9
9 |  CC |        UMap U64(map)   |   906.35M| 6 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1131.18 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1464.05 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1862.28 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1907.72 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   2093.98 ms | 4 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2162.78 ms | 5 | 7
7 |  STC |       UMap Big(hmap)    |   2274.02 ms | 5 | 10
8 |  KLIB |      UMap Big(khash)    |   2361.28 ms | 6 | 9
9 |  POTTERY |  UMap Big(open hash)    |   2477.57 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2491.61 ms | 7 | 10
11 |  KLIB |     UMap Big(khashl)    |   3131.01 ms | 11 | 12
12 |  CollectionC |  UMap Big(HashTable)    |   3345.57 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4279.90 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4443.71 ms | 13 | 14

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
10 |  CC |        UMap Big(map)   |   3.23G| 8 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   411.46 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   720.45 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   755.18 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   896.18 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   981.82 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1163.76 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1373.28 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1686.10 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   3952.27 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5295.79 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.36M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.38M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   118.53M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.37M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   216.52M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.15M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.72M| 8 | 10


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
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
