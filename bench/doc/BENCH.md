# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   644.08 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   862.69 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1252.94 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   28.55 ms | 1 | 2
2 |  M*LIB |       Queue(MPMC P2)    |   41.35 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   44.86 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   76.96 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   422.89 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   822.46 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1163.01 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1305.56 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1865.93 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 4
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 8
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 8
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   1.05M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   664.54 ms | 1 | 5
2 |  STC |           Seq(Array)    |   686.58 ms | 1 | 4
3 |  M*LIB |           Seq(Array)    |   729.92 ms | 1 | 4
4 |  CTL |           Seq(Array)    |   741.21 ms | 1 | 3
5 |  UT-HASH |           Seq(Array)    |   744.79 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   911.86 ms | 6 | 16
7 |  STC |            Seq(List)    |   938.82 ms | 6 | 12
8 |  UT-HASH |            Seq(List)    |   944.08 ms | 6 | 12
9 |  M*LIB |            Seq(List)    |   950.87 ms | 6 | 12
10 |  CTL |            Seq(List)    |   951.61 ms | 6 | 12
11 |  POTTERY |            Seq(List)    |   954.20 ms | 7 | 11
12 |  M*LIB |          Seq(DPList)    |   982.50 ms | 8 | 12
13 |  TommyDS |            Seq(List)    |   1023.62 ms | 11 | 18
14 |  CC |            Seq(List)    |   1057.94 ms | 12 | 14
15 |  GLIB |            Seq(List)    |   1109.96 ms | 14 | 16
16 |  CollectionC |            Seq(List)    |   1127.37 ms | 13 | 16
17 |  STL |            Seq(List)    |   1187.67 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1267.73 ms | 17 | 23
19 |  CMC |           Seq(Array)    |   1612.40 ms | 19 | 23
20 |  STL |           Seq(Array)    |   1617.43 ms | 19 | 22
21 |  STB-DS |        Seq(DynArray)    |   1693.59 ms | 17 | 24
22 |  STL |           Seq(Deque)    |   1782.61 ms | 21 | 24
23 |  CollectionC |           Seq(Array)    |   2116.44 ms | 23 | 26
24 |  CC |           Seq(Array)    |   2216.45 ms | 19 | 24
25 |  QLIBC |            Seq(List)    |   2573.14 ms | 25 | 26
26 |  TommyDS |           Seq(Array)    |   2751.06 ms | 19 | 26
27 |  POTTERY |           Seq(Array)    |   2959.29 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   3260.96 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4347.81 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6187.62 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
3 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
4 |  STL |            Seq(List)   |   1.28G| 2 | 10
5 |  STC |            Seq(List)   |   1.28G| 1 | 10
6 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
7 |  M*LIB |            Seq(List)   |   1.28G| 3 | 10
8 |  CTL |            Seq(List)   |   1.28G| 2 | 10
9 |  POTTERY |            Seq(List)   |   1.28G| 1 | 10
10 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
18 |  STC |           Seq(Array)   |   1.60G| 17 | 21
19 |  M*LIB |           Seq(Array)   |   1.60G| 18 | 21
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 20
21 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
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
1 |  STC |                 Sort    |   1043.46 ms | 1 | 2
2 |  STL |                 Sort    |   1104.59 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1155.73 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1239.99 ms | 4 | 5
5 |  STL |          Stable Sort    |   1280.50 ms | 3 | 5
6 |  CTL |                 Sort    |   1495.44 ms | 6 | 7
7 |  KLIB |                 Sort    |   1574.01 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1666.64 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1693.89 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1697.60 ms | 9 | 10
11 |  GLIB |                 Sort    |   1746.72 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2979.36 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  CTL |                 Sort   |   41.29M| 1 | 3
3 |  KLIB |                 Sort   |   42.20M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.44M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
8 |  M*LIB |                 Sort   |   81.95M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   162.79M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   843.25 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   895.70 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2065.20 ms | 3 | 5
4 |  STL |         SSet(Rbtree)    |   2360.78 ms | 4 | 9
5 |  CTL |            SSet(set)    |   2468.88 ms | 4 | 9
6 |  M*LIB |         SSet(Rbtree)    |   2552.67 ms | 3 | 5
7 |  CollectionC |      SSet(TreeTable)    |   2876.47 ms | 6 | 8
8 |  GLIB |          SSet(GTree)    |   3015.50 ms | 8 | 10
9 |  CMC |           SSet(tree)    |   3017.29 ms | 4 | 9
10 |  TommyDS |         SSet(Rbtree)    |   3205.04 ms | 7 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4589.77 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.60M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.01M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   95.94M| 4 | 7
5 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
6 |  CTL |            SSet(set)   |   96.08M| 4 | 8
7 |  CMC |           SSet(tree)   |   96.08M| 5 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   422.40 ms | 1 | 1
2 |  M*LIB |        String Concat    |   534.85 ms | 2 | 2
3 |  STL |        String Concat    |   614.31 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1531.42 ms | 4 | 4
5 |  SDS |        String Concat    |   2404.34 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3190.96 ms | 6 | 6
7 |  CTL |        String Concat    |   3869.70 ms | 7 | 7
8 |  GLIB |        String Concat    |   4086.20 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   504.81 ms | 1 | 1
2 |  STL |       String Replace    |   1274.35 ms | 2 | 3
3 |  STC |       String Replace    |   1517.37 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.17M| 1 | 1
2 |  STC |       String Replace   |   382.95M| 2 | 2
3 |  STL |       String Replace   |   415.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   728.37 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   791.91 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   2520.52 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   6758.22 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.59M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.60M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   712.72 ms | 1 | 2
2 |  M*LIB |    UMap U64(dict OA)    |   889.45 ms | 3 | 3
3 |  M*LIB |       UMap U64(dict)    |   892.84 ms | 1 | 2
4 |  KLIB |      UMap U64(khash)    |   1191.55 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1323.03 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1915.23 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2149.70 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2301.67 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2714.60 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3089.90 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   4587.89 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4763.14 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   8312.45 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   8568.10 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   10628.90 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   10662.53 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.49M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   557.84M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.90M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.14M| 6 | 8
8 |  CC |        UMap U64(map)   |   906.21M| 6 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1004.87 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1251.37 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1545.04 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1587.00 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   1941.53 ms | 4 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   1949.51 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   1988.59 ms | 6 | 9
8 |  STC |       UMap Big(hmap)    |   2045.88 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2090.85 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2352.20 ms | 7 | 10
11 |  KLIB |     UMap Big(khashl)    |   2788.66 ms | 11 | 12
12 |  CollectionC |  UMap Big(HashTable)    |   2991.65 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   3655.67 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4183.79 ms | 13 | 14

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
1 |  BOOST | USet Longest(uflat_s    |   463.52 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   643.86 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   731.64 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   869.71 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   968.74 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1176.67 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1327.20 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1414.91 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   4399.23 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5538.34 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.38M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   118.45M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.02M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 10


Model name:                              AMD EPYC 7763 64-Core Processor

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
