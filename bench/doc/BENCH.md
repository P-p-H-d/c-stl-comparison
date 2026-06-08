# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   651.92 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   870.08 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1253.35 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   24.52 ms | 1 | 2
2 |  M*LIB |       Queue(SPSC P2)    |   45.52 ms | 2 | 3
3 |  M*LIB |       Queue(MPMC P2)    |   52.06 ms | 1 | 3
4 |  M*LIB |          Queue(MPMC)    |   77.00 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   436.69 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   873.42 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1155.70 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1364.80 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1788.23 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 8
2 |  M*LIB |     Queue(SPSC Bulk)   |   454.66K| 1 | 7
3 |  M*LIB |        Queue(Buffer)   |   528.38K| 4 | 7
4 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 5 | 9
5 |  M*LIB |       Queue(SPSC P2)   |   528.38K| 1 | 4
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   3.41M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |           Seq(Array)    |   654.05 ms | 1 | 4
2 |  STC |           Seq(Array)    |   658.54 ms | 1 | 4
3 |  UT-HASH |           Seq(Array)    |   734.06 ms | 4 | 5
4 |  M*LIB |           Seq(Array)    |   747.62 ms | 1 | 4
5 |  KLIB |           Seq(Array)    |   771.55 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   888.33 ms | 6 | 16
7 |  UT-HASH |            Seq(List)    |   915.60 ms | 6 | 12
8 |  POTTERY |            Seq(List)    |   961.02 ms | 7 | 11
9 |  STC |            Seq(List)    |   966.46 ms | 6 | 12
10 |  CTL |            Seq(List)    |   966.87 ms | 6 | 12
11 |  M*LIB |            Seq(List)    |   985.88 ms | 6 | 10
12 |  M*LIB |          Seq(DPList)    |   990.38 ms | 8 | 12
13 |  TommyDS |            Seq(List)    |   1065.26 ms | 8 | 18
14 |  CC |            Seq(List)    |   1079.29 ms | 12 | 14
15 |  CollectionC |            Seq(List)    |   1106.30 ms | 13 | 16
16 |  STL |            Seq(List)    |   1156.79 ms | 13 | 18
17 |  GLIB |            Seq(List)    |   1163.29 ms | 14 | 16
18 |  KLIB |            Seq(List)    |   1335.72 ms | 17 | 23
19 |  STL |           Seq(Array)    |   1594.38 ms | 19 | 22
20 |  CMC |           Seq(Array)    |   1599.48 ms | 19 | 23
21 |  STB-DS |        Seq(DynArray)    |   1691.04 ms | 17 | 24
22 |  STL |           Seq(Deque)    |   1764.66 ms | 21 | 24
23 |  CC |           Seq(Array)    |   2028.99 ms | 19 | 24
24 |  CollectionC |           Seq(Array)    |   2091.39 ms | 23 | 26
25 |  QLIBC |            Seq(List)    |   2542.76 ms | 25 | 26
26 |  TommyDS |           Seq(Array)    |   2772.82 ms | 20 | 26
27 |  POTTERY |           Seq(Array)    |   3027.36 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   3266.54 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4347.02 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6189.62 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
3 |  STL |            Seq(List)   |   1.28G| 2 | 10
4 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
5 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 10
6 |  POTTERY |            Seq(List)   |   1.28G| 1 | 10
7 |  STC |            Seq(List)   |   1.28G| 1 | 10
8 |  CTL |            Seq(List)   |   1.28G| 2 | 10
9 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
10 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  CTL |           Seq(Array)   |   1.60G| 18 | 20
18 |  STC |           Seq(Array)   |   1.60G| 17 | 21
19 |  UT-HASH |           Seq(Array)   |   1.60G| 20 | 22
20 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
21 |  KLIB |           Seq(Array)   |   1.60G| 16 | 21
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
1 |  STC |                 Sort    |   1044.51 ms | 1 | 2
2 |  STL |                 Sort    |   1106.22 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1157.01 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1242.17 ms | 4 | 5
5 |  STL |          Stable Sort    |   1279.58 ms | 3 | 5
6 |  CTL |                 Sort    |   1502.22 ms | 6 | 7
7 |  KLIB |                 Sort    |   1574.53 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1656.77 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1692.84 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1698.44 ms | 9 | 10
11 |  GLIB |                 Sort    |   1756.34 ms | 10 | 11
12 |  CollectionC |                 Sort    |   2980.79 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.16M| 1 | 3
3 |  CTL |                 Sort   |   41.95M| 1 | 3
4 |  STL |                 Sort   |   68.41M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.45M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
8 |  M*LIB |                 Sort   |   81.16M| 6 | 8
9 |  POTTERY |                 Sort   |   99.04M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   162.12M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   731.73 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   882.11 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1952.48 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2114.79 ms | 3 | 6
5 |  STL |         SSet(Rbtree)    |   2334.14 ms | 4 | 9
6 |  CTL |            SSet(set)    |   2447.45 ms | 4 | 9
7 |  CollectionC |      SSet(TreeTable)    |   2603.52 ms | 6 | 8
8 |  CMC |           SSet(tree)    |   2636.18 ms | 4 | 9
9 |  TommyDS |         SSet(Rbtree)    |   2698.45 ms | 7 | 10
10 |  GLIB |          SSet(GTree)    |   3141.93 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   3937.64 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.39M| 2 | 2
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
1 |  STC |        String Concat    |   433.07 ms | 1 | 1
2 |  M*LIB |        String Concat    |   526.34 ms | 2 | 2
3 |  STL |        String Concat    |   621.02 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1522.97 ms | 4 | 4
5 |  SDS |        String Concat    |   2389.73 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3254.92 ms | 6 | 6
7 |  CTL |        String Concat    |   3930.89 ms | 7 | 7
8 |  GLIB |        String Concat    |   4181.82 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   533.80 ms | 1 | 1
2 |  STL |       String Replace    |   1346.99 ms | 2 | 3
3 |  STC |       String Replace    |   1529.60 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.24M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   416.06M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   714.69 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   841.90 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   2566.45 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   6720.39 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.46M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.48M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   742.31 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   924.34 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   956.54 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1285.31 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1361.69 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1797.81 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2037.33 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2390.37 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2851.75 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3206.76 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   4528.31 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4952.83 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   8470.43 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   9886.21 ms | 13 | 14
15 |  UT-HASH |       UMap U64(dict)    |   10295.49 ms | 14 | 16
16 |  STL |       UMap U64(umap)    |   11010.96 ms | 14 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.73M| 2 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   557.14M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.37M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.15M| 6 | 8
8 |  CC |        UMap U64(map)   |   906.23M| 7 | 9
9 |  VERSTABLE |             UMap U64   |   906.35M| 6 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   972.84 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1267.59 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1527.59 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1659.95 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   1824.90 ms | 4 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   1998.16 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2041.91 ms | 6 | 9
8 |  STC |       UMap Big(hmap)    |   2080.98 ms | 5 | 9
9 |  POTTERY |  UMap Big(open hash)    |   2113.46 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2429.33 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   2985.55 ms | 11 | 12
12 |  KLIB |     UMap Big(khashl)    |   3061.48 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   3744.62 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   3941.41 ms | 13 | 14

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
1 |  BOOST | USet Longest(uflat_s    |   433.31 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   739.44 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   756.50 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   906.08 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   906.50 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1206.42 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1263.27 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1333.27 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   4579.68 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5506.53 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   116.91M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.02M| 6 | 8
9 |  STL | USet Longest(dict oa   |   456.90M| 7 | 9
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
