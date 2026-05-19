# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   706.34 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   970.63 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1410.17 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   35.70 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   42.35 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   47.24 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   78.49 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   477.88 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   636.36 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1223.11 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1637.20 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   2104.63 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 4
2 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
3 |  M*LIB |       Queue(SPSC P2)   |   397.31K| 1 | 8
4 |  M*LIB |     Queue(Buffer P2)   |   401.41K| 3 | 9
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |        Queue(Buffer)   |   532.48K| 3 | 6
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 6
9 |  M*LIB |    Queue(Shared ptr)   |   1.45M| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   759.53 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   812.83 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   839.19 ms | 2 | 5
4 |  STC |           Seq(Array)    |   846.63 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   889.95 ms | 1 | 5
6 |  UT-HASH |            Seq(List)    |   890.51 ms | 7 | 12
7 |  POTTERY |            Seq(List)    |   900.96 ms | 7 | 11
8 |  M*LIB |            Seq(List)    |   904.68 ms | 7 | 12
9 |  CTL |            Seq(List)    |   906.63 ms | 6 | 12
10 |  STC |            Seq(List)    |   911.65 ms | 6 | 12
11 |  M*LIB |          Seq(DPList)    |   944.68 ms | 8 | 12
12 |  CC |            Seq(List)    |   985.43 ms | 12 | 14
13 |  CollectionC |            Seq(List)    |   997.32 ms | 13 | 17
14 |  TommyDS |            Seq(List)    |   1007.65 ms | 11 | 18
15 |  M*LIB |           Seq(Deque)    |   1014.25 ms | 6 | 16
16 |  GLIB |            Seq(List)    |   1039.39 ms | 14 | 16
17 |  STL |            Seq(List)    |   1074.55 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1148.77 ms | 17 | 23
19 |  STL |           Seq(Array)    |   1822.47 ms | 19 | 22
20 |  TommyDS |           Seq(Array)    |   1831.12 ms | 19 | 26
21 |  CMC |           Seq(Array)    |   1841.77 ms | 19 | 23
22 |  CC |           Seq(Array)    |   1945.51 ms | 19 | 24
23 |  STL |           Seq(Deque)    |   1956.57 ms | 21 | 24
24 |  STB-DS |        Seq(DynArray)    |   2233.13 ms | 15 | 23
25 |  CollectionC |           Seq(Array)    |   2366.03 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   2482.38 ms | 25 | 26
27 |  POTTERY |           Seq(Array)    |   2817.47 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   3331.82 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4278.73 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6292.89 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
2 |  STL |            Seq(List)   |   1.28G| 2 | 10
3 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
4 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
5 |  M*LIB |            Seq(List)   |   1.28G| 3 | 10
6 |  CTL |            Seq(List)   |   1.28G| 2 | 10
7 |  STC |            Seq(List)   |   1.28G| 1 | 10
8 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
9 |  CC |            Seq(List)   |   1.28G| 1 | 9
10 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
19 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 21
21 |  STC |           Seq(Array)   |   1.60G| 17 | 21
22 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
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
1 |  STC |                 Sort    |   1210.33 ms | 1 | 2
2 |  STL |                 Sort    |   1224.52 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1326.73 ms | 3 | 5
4 |  STL |          Stable Sort    |   1410.27 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1432.75 ms | 4 | 5
6 |  CTL |                 Sort    |   1666.12 ms | 6 | 7
7 |  KLIB |                 Sort    |   1800.41 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1823.49 ms | 8 | 9
9 |  UT-HASH |                 Sort    |   1883.40 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1892.87 ms | 8 | 10
11 |  GLIB |                 Sort    |   1955.65 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3229.86 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.29M| 1 | 3
3 |  STC |                 Sort   |   41.95M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.45M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
8 |  M*LIB |                 Sort   |   81.69M| 6 | 8
9 |  POTTERY |                 Sort   |   99.02M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   163.58M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   846.35 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1068.27 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2391.74 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2670.40 ms | 3 | 5
5 |  CTL |            SSet(set)    |   3006.47 ms | 4 | 9
6 |  STL |         SSet(Rbtree)    |   3331.52 ms | 4 | 9
7 |  CMC |           SSet(tree)    |   3395.94 ms | 4 | 8
8 |  CollectionC |      SSet(TreeTable)    |   3532.83 ms | 6 | 8
9 |  GLIB |          SSet(GTree)    |   3847.49 ms | 8 | 10
10 |  TommyDS |         SSet(Rbtree)    |   3940.56 ms | 7 | 10
11 |  QLIBC |         SSet(Rbtree)    |   5327.26 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.57M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.06M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   95.94M| 4 | 8
5 |  TommyDS |         SSet(Rbtree)   |   95.94M| 4 | 8
6 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
7 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
8 |  CTL |            SSet(set)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   412.72 ms | 1 | 2
2 |  M*LIB |        String Concat    |   521.43 ms | 1 | 2
3 |  STL |        String Concat    |   597.76 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1614.60 ms | 4 | 4
5 |  SDS |        String Concat    |   2513.58 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3286.32 ms | 6 | 6
7 |  CTL |        String Concat    |   3895.84 ms | 7 | 7
8 |  GLIB |        String Concat    |   4158.89 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   501.27 ms | 1 | 1
2 |  STL |       String Replace    |   1081.19 ms | 2 | 3
3 |  STC |       String Replace    |   1374.94 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.01M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   415.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   877.32 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1028.21 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3339.70 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   9156.96 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.98M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.62M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   850.93 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   876.78 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   948.16 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1214.21 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1371.31 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2003.68 ms | 6 | 6
7 |  KLIB |     UMap U64(khashl)    |   2387.84 ms | 7 | 8
8 |  VERSTABLE |             UMap U64    |   2392.04 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   3051.19 ms | 8 | 9
10 |  TommyDS |       UMap U64(dict)    |   3770.23 ms | 9 | 11
11 |  STC |       UMap U64(hmap)    |   3772.68 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4223.67 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   6890.87 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   8607.56 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   10381.95 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   11791.65 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.16M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.69M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   557.94M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.75M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.15M| 6 | 8
8 |  CC |        UMap U64(map)   |   906.22M| 6 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1178.83 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1643.29 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   2009.30 ms | 3 | 8
4 |  VERSTABLE |             UMap Big    |   2022.95 ms | 3 | 4
5 |  M*LIB |    UMap Big(dict OA)    |   2265.28 ms | 5 | 7
6 |  TommyDS |       UMap Big(dict)    |   2287.67 ms | 3 | 6
7 |  KLIB |      UMap Big(khash)    |   2300.78 ms | 5 | 10
8 |  STC |       UMap Big(hmap)    |   2531.61 ms | 5 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2546.40 ms | 8 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2554.48 ms | 7 | 10
11 |  KLIB |     UMap Big(khashl)    |   3269.01 ms | 11 | 11
12 |  CollectionC |  UMap Big(HashTable)    |   3456.30 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4568.53 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4855.29 ms | 13 | 14

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
1 |  BOOST | USet Longest(uflat_s    |   476.96 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   691.83 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   821.42 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   931.44 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1168.13 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1245.71 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1442.44 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1774.42 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   3970.49 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5495.86 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   116.97M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.80M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 7
8 |  STC |   USet Longest(hset)   |   218.91M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.58M| 8 | 10


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* STC : 6574a39b26cf24c32fc58ed585209b35c34c7998
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : aa77e89ae48473fec96c014e0db7290c3493ee1c
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : 1060908cd84b1f58c68a76ef02bc8b6db83cba07
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 31c1ad37456438565541f4919958214b6e762fb4
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : e573d4d2aaeaba0f3e5a0a9a54144a1f2b4b56e7
