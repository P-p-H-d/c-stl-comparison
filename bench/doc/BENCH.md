# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   688.37 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   698.77 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1327.04 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   51.65 ms | 1 | 1
2 |  M*LIB |       Queue(SPSC P2)    |   61.59 ms | 2 | 2
3 |  M*LIB |       Queue(MPMC P2)    |   128.73 ms | 3 | 3
4 |  M*LIB |          Queue(MPMC)    |   197.51 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   569.84 ms | 5 | 5
6 |  M*LIB |     Queue(Buffer P2)    |   799.11 ms | 6 | 6
7 |  BOOST | Queue MPMC (lockfree    |   1439.69 ms | 7 | 7
8 |  M*LIB |        Queue(Buffer)    |   2063.09 ms | 7 | 8
9 |  M*LIB |    Queue(Shared ptr)    |   3312.39 ms | 8 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   77.82K| 3 | 3
2 |  M*LIB |       Queue(SPSC P2)   |   77.82K| 4 | 4
3 |  M*LIB |       Queue(MPMC P2)   |   200.70K| 1 | 1
4 |  M*LIB |     Queue(Buffer P2)   |   200.70K| 2 | 2
5 |  LIBLFDS |          Queue(MPMC)   |   606.21K| 5 | 5
6 |  M*LIB |        Queue(Buffer)   |   851.97K| 6 | 6
7 |  M*LIB |          Queue(MPMC)   |   872.45K| 7 | 7
8 |  BOOST | Queue MPMC (lockfree   |   987.14K| 8 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   5.25M| 9 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |           Seq(Array)    |   659.50 ms | 3 | 4
2 |  STC |           Seq(Array)    |   681.78 ms | 2 | 2
3 |  KLIB |           Seq(Array)    |   685.64 ms | 1 | 5
4 |  M*LIB |           Seq(Array)    |   743.62 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   764.08 ms | 4 | 5
6 |  M*LIB |           Seq(Deque)    |   964.46 ms | 6 | 6
7 |  STB-DS |        Seq(DynArray)    |   1329.26 ms | 7 | 7
8 |  GLIB |            Seq(List)    |   1374.87 ms | 7 | 8
9 |  UT-HASH |            Seq(List)    |   1430.62 ms | 8 | 11
10 |  CTL |            Seq(List)    |   1431.49 ms | 9 | 12
11 |  M*LIB |          Seq(DPList)    |   1449.13 ms | 10 | 12
12 |  POTTERY |            Seq(List)    |   1450.40 ms | 12 | 13
13 |  STC |            Seq(List)    |   1462.77 ms | 9 | 12
14 |  M*LIB |            Seq(List)    |   1478.22 ms | 8 | 19
15 |  CollectionC |            Seq(List)    |   1535.31 ms | 13 | 14
16 |  STL |           Seq(Array)    |   1599.44 ms | 14 | 16
17 |  STL |            Seq(List)    |   1608.32 ms | 15 | 17
18 |  CC |            Seq(List)    |   1649.41 ms | 16 | 17
19 |  TommyDS |            Seq(List)    |   1713.76 ms | 18 | 20
20 |  CMC |           Seq(Array)    |   1765.16 ms | 17 | 19
21 |  STL |           Seq(Deque)    |   1857.92 ms | 20 | 21
22 |  TommyDS |           Seq(Array)    |   1923.64 ms | 21 | 22
23 |  KLIB |            Seq(List)    |   2172.24 ms | 22 | 24
24 |  CC |           Seq(Array)    |   2454.29 ms | 22 | 23
25 |  CollectionC |           Seq(Array)    |   2712.86 ms | 24 | 25
26 |  POTTERY |           Seq(Array)    |   3931.75 ms | 25 | 26
27 |  QLIBC |            Seq(List)    |   4179.11 ms | 26 | 27
28 |  LIBSRT |           Seq(Array)    |   6420.72 ms | 27 | 28
29 |  GLIB |           Seq(Array)    |   7339.89 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   23644.80 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  GLIB |            Seq(List)   |   788.60M| 1 | 1
2 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 2
3 |  CTL |            Seq(List)   |   1.28G| 5 | 5
4 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 4
5 |  POTTERY |            Seq(List)   |   1.28G| 6 | 6
6 |  STC |            Seq(List)   |   1.28G| 3 | 3
7 |  M*LIB |            Seq(List)   |   1.28G| 10 | 10
8 |  CollectionC |            Seq(List)   |   1.28G| 7 | 7
9 |  STL |            Seq(List)   |   1.28G| 8 | 8
10 |  CC |            Seq(List)   |   1.28G| 9 | 9
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 22 | 22
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 12
14 |  QLIBC |           Seq(Array)   |   1.60G| 20 | 20
15 |  CC |           Seq(Array)   |   1.60G| 13 | 13
16 |  LIBSRT |           Seq(Array)   |   1.60G| 14 | 14
17 |  CTL |           Seq(Array)   |   1.60G| 17 | 17
18 |  STC |           Seq(Array)   |   1.60G| 16 | 16
19 |  KLIB |           Seq(Array)   |   1.60G| 19 | 19
20 |  M*LIB |           Seq(Array)   |   1.60G| 15 | 15
21 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 18
22 |  M*LIB |           Seq(Deque)   |   1.60G| 21 | 21
23 |  STL |           Seq(Array)   |   1.61G| 22 | 23
24 |  STL |           Seq(Deque)   |   1.68G| 23 | 24
25 |  POTTERY |           Seq(Array)   |   1.70G| 24 | 25
26 |  TommyDS |            Seq(List)   |   1.92G| 25 | 26
27 |  TommyDS |           Seq(Array)   |   3.20G| 26 | 27
28 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
29 |  CollectionC |           Seq(Array)   |   3.22G| 28 | 29
30 |  GLIB |           Seq(Array)   |   4.81G| 29 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STL |                 Sort    |   911.00 ms | 1 | 1
2 |  STC |                 Sort    |   995.81 ms | 2 | 2
3 |  M*LIB |          Stable Sort    |   1163.28 ms | 3 | 4
4 |  POTTERY |                 Sort    |   1168.39 ms | 3 | 4
5 |  STL |          Stable Sort    |   1194.74 ms | 5 | 5
6 |  KLIB |                 Sort    |   1348.76 ms | 6 | 6
7 |  LIBSRT |                 Sort    |   1641.66 ms | 7 | 7
8 |  CTL |                 Sort    |   1651.79 ms | 8 | 8
9 |  M*LIB |                 Sort    |   1675.30 ms | 9 | 10
10 |  UT-HASH |                 Sort    |   1681.72 ms | 9 | 10
11 |  GLIB |                 Sort    |   1845.15 ms | 11 | 11
12 |  CollectionC |                 Sort    |   3825.49 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.12M| 2 | 2
2 |  KLIB |                 Sort   |   41.46M| 1 | 1
3 |  CTL |                 Sort   |   41.67M| 3 | 3
4 |  STL |                 Sort   |   68.76M| 4 | 4
5 |  LIBSRT |                 Sort   |   77.88M| 5 | 5
6 |  M*LIB |                 Sort   |   80.78M| 8 | 8
7 |  UT-HASH |                 Sort   |   81.31M| 6 | 6
8 |  M*LIB |          Stable Sort   |   82.08M| 7 | 7
9 |  POTTERY |                 Sort   |   99.01M| 9 | 9
10 |  STL |          Stable Sort   |   103.33M| 10 | 10
11 |  GLIB |                 Sort   |   165.31M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   1093.00 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1639.03 ms | 2 | 2
3 |  M*LIB |         SSet(Rbtree)    |   3206.46 ms | 3 | 5
4 |  STL |         SSet(Rbtree)    |   3393.63 ms | 4 | 6
5 |  STC |           SSet(sset)    |   3519.52 ms | 3 | 4
6 |  CTL |            SSet(set)    |   3778.21 ms | 5 | 6
7 |  CollectionC |      SSet(TreeTable)    |   3935.59 ms | 7 | 8
8 |  CMC |           SSet(tree)    |   3972.81 ms | 7 | 9
9 |  TommyDS |         SSet(Rbtree)    |   4020.61 ms | 8 | 9
10 |  GLIB |          SSet(GTree)    |   4995.84 ms | 10 | 10
11 |  QLIBC |         SSet(Rbtree)    |   5784.86 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.78M| 1 | 1
2 |  STC |           SSet(sset)   |   49.33M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   55.88M| 3 | 3
4 |  CMC |           SSet(tree)   |   96.26M| 7 | 7
5 |  TommyDS |         SSet(Rbtree)   |   96.32M| 4 | 4
6 |  CTL |            SSet(set)   |   96.33M| 6 | 6
7 |  M*LIB |         SSet(Rbtree)   |   96.35M| 5 | 5
8 |  STL |         SSet(Rbtree)   |   96.68M| 8 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.11M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   178.88M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.17M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        String Concat    |   520.70 ms | 1 | 1
2 |  STC |        String Concat    |   698.91 ms | 2 | 2
3 |  STL |        String Concat    |   941.08 ms | 3 | 3
4 |  POTTERY |        String Concat    |   2500.85 ms | 4 | 4
5 |  SDS |        String Concat    |   3888.43 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   5400.98 ms | 6 | 7
7 |  CTL |        String Concat    |   5762.12 ms | 5 | 7
8 |  GLIB |        String Concat    |   6634.34 ms | 6 | 8

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
1 |  M*LIB |       String Replace    |   704.93 ms | 1 | 1
2 |  STC |       String Replace    |   2602.45 ms | 2 | 2
3 |  STL |       String Replace    |   2962.44 ms | 3 | 3
4 |  BSTRLIB |       String Replace    |   3139.01 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   238.99M| 1 | 1
2 |  STC |       String Replace   |   382.42M| 2 | 2
3 |  STL |       String Replace   |   415.38M| 3 | 3
4 |  BSTRLIB |       String Replace   |   687.89M| 4 | 4

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST |  UMap Str(uflat_map)    |   1058.51 ms | 1 | 1
2 |  M*LIB |       UMap Str(dict)    |   1078.13 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2939.38 ms | 2 | 3
4 |  STL |        UMap Str(map)    |   7782.16 ms | 3 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   171.05M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.81M| 2 | 2
3 |  STL |       UMap Str(umap)   |   354.06M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.76M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   957.24 ms | 1 | 1
2 |  M*LIB |       UMap U64(dict)    |   1040.22 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   1209.69 ms | 2 | 3
4 |  BOOST |  UMap U64(uflat_map)    |   1914.71 ms | 4 | 4
5 |  KLIB |      UMap U64(khash)    |   2086.52 ms | 3 | 6
6 |  POTTERY |  UMap U64(open hash)    |   2630.47 ms | 4 | 6
7 |  CC |        UMap U64(map)    |   2912.71 ms | 6 | 8
8 |  VERSTABLE |             UMap U64    |   2921.68 ms | 5 | 8
9 |  STC |       UMap U64(hmap)    |   3188.38 ms | 7 | 9
10 |  TommyDS |       UMap U64(dict)    |   6474.90 ms | 8 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   9256.51 ms | 9 | 11
12 |  GLIB | UMap U64(GHashTable)    |   9418.76 ms | 10 | 12
13 |  STL |       UMap U64(umap)    |   12637.38 ms | 11 | 13
14 |  CMC |       UMap U64(hmap)    |   14235.06 ms | 12 | 14
15 |  UT-HASH |       UMap U64(dict)    |   15636.09 ms | 13 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.91M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.55M| 3 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   558.06M| 2 | 2
4 |  M*LIB |       UMap U64(dict)   |   590.49M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   806.23M| 5 | 5
6 |  VERSTABLE |             UMap U64   |   906.38M| 7 | 7
7 |  CC |        UMap U64(map)   |   906.42M| 6 | 6
8 |  STC |       UMap U64(hmap)   |   906.42M| 8 | 8
9 |  STL |       UMap U64(umap)   |   934.46M| 9 | 9
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
1 |  BOOST |  UMap Big(uflat_map)    |   1771.62 ms | 1 | 2
2 |  M*LIB |       UMap Big(dict)    |   1834.52 ms | 1 | 2
3 |  VERSTABLE |             UMap Big    |   2384.02 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   2488.94 ms | 2 | 4
5 |  TommyDS |       UMap Big(dict)    |   2796.77 ms | 6 | 6
6 |  STC |       UMap Big(hmap)    |   2853.42 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2925.73 ms | 7 | 8
8 |  M*LIB |    UMap Big(dict OA)    |   3004.24 ms | 4 | 5
9 |  POTTERY |  UMap Big(open hash)    |   3173.69 ms | 8 | 9
10 |  GLIB | UMap Big(GHashTable)    |   3835.65 ms | 9 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   4125.81 ms | 10 | 11
12 |  STL |       UMap Big(umap)    |   5042.26 ms | 11 | 12
13 |  UT-HASH |       UMap Big(dict)    |   6013.55 ms | 12 | 13

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
13 |  POTTERY |  UMap Big(open hash)   |   6.44G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   915.79 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   1060.63 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   1201.64 ms | 3 | 3
4 |  CC |   USet Longest(hset)    |   1542.81 ms | 4 | 5
5 |  VERSTABLE |   USet Longest(hset)    |   1546.40 ms | 4 | 5
6 |  STC |   USet Longest(hset)    |   1846.37 ms | 6 | 6
7 |  STL | USet Longest(dict oa    |   7604.84 ms | 7 | 7
8 |  CTL |   USet Longest(hset)    |   8542.41 ms | 8 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   119.78M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   160.47M| 2 | 2
3 |  CC |   USet Longest(hset)   |   191.46M| 3 | 3
4 |  VERSTABLE |   USet Longest(hset)   |   191.50M| 4 | 4
5 |  M*LIB |   USet Longest(dict)   |   214.79M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.08M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.56M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.74M| 8 | 8


Model name:                              Intel(R) Core(TM) i5-3210M CPU @ 2.50GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 074fbcd92b9e4b72a6ccb20bf91871fb5a02a52e
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : f224bdc7361dc8342171e99032e4a1657f8fb02a
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* libdynamic : da348d4234608a1aa3d699f0e16f656d66709fff
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : e3ae4b514511d7d7f45e2975a742c32e4799b57d
* nedtries : c370fef72146abec435ec805a56f37b912a65774
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 904aa67e1e2d1dec92959df63e700b166d5c1022
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 2031adfd8cd6f8f498e0f4a9055648b19496f12e
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
