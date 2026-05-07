# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  XXHASH |      Hash (xxhash64)    |   549.14 ms | 2 | 2
2 |  M*LIB |     Hash (Core Hash)    |   549.39 ms | 1 | 1
3 |  M*LIB |        Hash (M_HASH)    |   1093.94 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3
3 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   34.05 ms | 1 | 2
2 |  M*LIB |       Queue(MPMC P2)    |   34.41 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   36.68 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   64.92 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   379.27 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   470.46 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   847.92 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1229.18 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1678.79 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 8
2 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 6
3 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K| 1 | 4
4 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 9
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  M*LIB |    Queue(Shared ptr)   |   528.38K| 5 | 9
9 |  LIBLFDS |          Queue(MPMC)   |   659.46K| 4 | 8

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |           Seq(Array)    |   609.07 ms | 1 | 4
2 |  M*LIB |           Seq(Array)    |   621.26 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   645.31 ms | 2 | 5
4 |  UT-HASH |           Seq(Array)    |   647.77 ms | 1 | 5
5 |  KLIB |           Seq(Array)    |   656.05 ms | 1 | 5
6 |  STC |            Seq(List)    |   703.85 ms | 6 | 12
7 |  CTL |            Seq(List)    |   711.70 ms | 6 | 12
8 |  M*LIB |            Seq(List)    |   724.41 ms | 7 | 12
9 |  UT-HASH |            Seq(List)    |   731.05 ms | 7 | 12
10 |  POTTERY |            Seq(List)    |   731.60 ms | 7 | 11
11 |  M*LIB |          Seq(DPList)    |   749.29 ms | 8 | 12
12 |  CC |            Seq(List)    |   765.44 ms | 12 | 14
13 |  TommyDS |            Seq(List)    |   773.31 ms | 11 | 19
14 |  GLIB |            Seq(List)    |   805.48 ms | 15 | 18
15 |  CollectionC |            Seq(List)    |   807.05 ms | 13 | 17
16 |  M*LIB |           Seq(Deque)    |   895.70 ms | 6 | 15
17 |  STL |            Seq(List)    |   903.85 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   949.28 ms | 17 | 24
19 |  CC |           Seq(Array)    |   1405.51 ms | 20 | 24
20 |  CMC |           Seq(Array)    |   1416.34 ms | 19 | 23
21 |  TommyDS |           Seq(Array)    |   1418.91 ms | 17 | 26
22 |  STL |           Seq(Array)    |   1447.98 ms | 19 | 21
23 |  STB-DS |        Seq(DynArray)    |   1528.09 ms | 15 | 22
24 |  STL |           Seq(Deque)    |   1552.07 ms | 21 | 24
25 |  CollectionC |           Seq(Array)    |   1934.17 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   1946.29 ms | 25 | 27
27 |  POTTERY |           Seq(Array)    |   2016.45 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   2669.10 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   3453.36 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   4975.78 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |            Seq(List)   |   1.28G| 3 | 10
2 |  CTL |            Seq(List)   |   1.28G| 1 | 10
3 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
4 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
5 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
6 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
7 |  CC |            Seq(List)   |   1.28G| 1 | 9
8 |  GLIB |            Seq(List)   |   1.28G| 1 | 10
9 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
10 |  STL |            Seq(List)   |   1.28G| 2 | 9
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CC |           Seq(Array)   |   1.60G| 14 | 15
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  STC |           Seq(Array)   |   1.60G| 18 | 21
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
19 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
20 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
21 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
22 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
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
1 |  STC |                 Sort    |   938.16 ms | 1 | 2
2 |  STL |                 Sort    |   951.95 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1023.25 ms | 3 | 5
4 |  STL |          Stable Sort    |   1091.48 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1143.35 ms | 4 | 5
6 |  CTL |                 Sort    |   1301.04 ms | 6 | 7
7 |  KLIB |                 Sort    |   1393.26 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1419.94 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1447.14 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1466.63 ms | 8 | 10
11 |  GLIB |                 Sort    |   1524.73 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2580.31 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.29M| 1 | 3
2 |  CTL |                 Sort   |   41.82M| 1 | 3
3 |  KLIB |                 Sort   |   41.82M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.72M| 5 | 5
6 |  UT-HASH |                 Sort   |   81.82M| 6 | 8
7 |  M*LIB |          Stable Sort   |   82.08M| 6 | 8
8 |  M*LIB |                 Sort   |   82.34M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   160.82M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   660.73 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   740.32 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1775.98 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2101.81 ms | 3 | 5
5 |  STL |         SSet(Rbtree)    |   2317.10 ms | 4 | 9
6 |  CTL |            SSet(set)    |   2378.84 ms | 4 | 9
7 |  CMC |           SSet(tree)    |   2515.75 ms | 4 | 8
8 |  CollectionC |      SSet(TreeTable)    |   2636.90 ms | 6 | 8
9 |  TommyDS |         SSet(Rbtree)    |   2820.62 ms | 7 | 10
10 |  GLIB |          SSet(GTree)    |   3153.99 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4079.12 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.67M| 1 | 1
2 |  STC |           SSet(sset)   |   49.80M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.14M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
5 |  M*LIB |         SSet(Rbtree)   |   96.21M| 4 | 7
6 |  CTL |            SSet(set)   |   96.21M| 4 | 8
7 |  CMC |           SSet(tree)   |   96.21M| 4 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   327.61 ms | 1 | 2
2 |  M*LIB |        String Concat    |   417.26 ms | 1 | 2
3 |  STL |        String Concat    |   504.44 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1292.01 ms | 4 | 4
5 |  SDS |        String Concat    |   1966.28 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   2542.84 ms | 6 | 6
7 |  CTL |        String Concat    |   2931.63 ms | 7 | 7
8 |  GLIB |        String Concat    |   3392.42 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   413.43 ms | 1 | 1
2 |  STL |       String Replace    |   936.46 ms | 2 | 3
3 |  STC |       String Replace    |   1112.09 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.15M| 1 | 1
2 |  STC |       String Replace   |   382.87M| 2 | 2
3 |  STL |       String Replace   |   416.03M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   710.68 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   855.54 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2829.54 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   6931.35 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.40M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.07M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.57M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   743.62 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   784.70 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   851.42 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1168.37 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1173.42 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1701.01 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   1944.02 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2142.71 ms | 7 | 7
9 |  CC |        UMap U64(map)    |   2549.35 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3409.53 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   3470.12 ms | 9 | 10
12 |  CollectionC |  UMap U64(HashTable)    |   3829.32 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   6128.95 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   7254.43 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   9077.85 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   10482.67 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.41M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.76M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.09M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   557.01M| 2 | 3
5 |  M*LIB |       UMap U64(dict)   |   590.30M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.28M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.34M| 6 | 9
9 |  CC |        UMap U64(map)   |   906.34M| 6 | 8
10 |  STL |       UMap U64(umap)   |   933.75M| 9 | 10
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
1 |  M*LIB |       UMap Big(dict)    |   976.76 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1359.95 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   1691.36 ms | 3 | 8
4 |  VERSTABLE |             UMap Big    |   1751.59 ms | 3 | 4
5 |  TommyDS |       UMap Big(dict)    |   1930.69 ms | 3 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2032.02 ms | 5 | 7
7 |  STC |       UMap Big(hmap)    |   2111.91 ms | 5 | 10
8 |  KLIB |      UMap Big(khash)    |   2191.22 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2202.18 ms | 8 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2263.49 ms | 7 | 10
11 |  KLIB |     UMap Big(khashl)    |   2977.18 ms | 11 | 11
12 |  CollectionC |  UMap Big(HashTable)    |   3069.57 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   3892.47 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   3985.72 ms | 13 | 14

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
9 |  CC |        UMap Big(map)   |   3.23G| 8 | 9
10 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   383.72 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   629.35 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   705.40 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   827.68 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   861.68 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1068.72 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1112.33 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1253.74 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   3567.88 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   4865.36 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.36M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.38M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   116.71M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.37M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 5
7 |  M*LIB |   USet Longest(dict)   |   214.63M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.14M| 6 | 8
9 |  STL | USet Longest(dict oa   |   456.93M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.72M| 8 | 10


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 8a3696053e83aecf58969d52595baf415c2bd6ba
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : fc94367acd402f7af9c652563dbdda2c603ede91
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 1060908cd84b1f58c68a76ef02bc8b6db83cba07
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
