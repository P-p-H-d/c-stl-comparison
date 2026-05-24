# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   708.60 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   970.81 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1410.71 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   38.07 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   41.77 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   43.91 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   78.83 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   461.03 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   642.56 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1094.96 ms | 7 | 8
8 |  M*LIB |        Queue(Buffer)    |   1367.17 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1981.94 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 2 | 8
2 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K| 1 | 4
3 |  M*LIB |       Queue(SPSC P2)   |   397.31K| 1 | 8
4 |  M*LIB |    Queue(Shared ptr)   |   528.38K| 8 | 9
5 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
6 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
7 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
8 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 7
9 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 8

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   789.24 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   826.37 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   828.93 ms | 1 | 3
4 |  STC |           Seq(Array)    |   841.38 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   875.81 ms | 1 | 5
6 |  M*LIB |            Seq(List)    |   888.46 ms | 7 | 12
7 |  CTL |            Seq(List)    |   901.80 ms | 6 | 12
8 |  M*LIB |          Seq(DPList)    |   908.28 ms | 8 | 12
9 |  STC |            Seq(List)    |   908.37 ms | 6 | 12
10 |  UT-HASH |            Seq(List)    |   924.41 ms | 6 | 12
11 |  POTTERY |            Seq(List)    |   947.68 ms | 7 | 11
12 |  TommyDS |            Seq(List)    |   958.50 ms | 11 | 18
13 |  CC |            Seq(List)    |   1018.37 ms | 12 | 14
14 |  CollectionC |            Seq(List)    |   1021.47 ms | 13 | 16
15 |  M*LIB |           Seq(Deque)    |   1042.50 ms | 6 | 16
16 |  GLIB |            Seq(List)    |   1065.28 ms | 14 | 16
17 |  KLIB |            Seq(List)    |   1160.60 ms | 17 | 23
18 |  STL |            Seq(List)    |   1267.71 ms | 13 | 18
19 |  STB-DS |        Seq(DynArray)    |   1629.09 ms | 17 | 24
20 |  STL |           Seq(Array)    |   1831.52 ms | 19 | 22
21 |  TommyDS |           Seq(Array)    |   1847.15 ms | 19 | 26
22 |  CC |           Seq(Array)    |   1847.61 ms | 19 | 24
23 |  CMC |           Seq(Array)    |   1865.21 ms | 19 | 23
24 |  STL |           Seq(Deque)    |   2015.87 ms | 21 | 24
25 |  CollectionC |           Seq(Array)    |   2336.52 ms | 23 | 26
26 |  QLIBC |            Seq(List)    |   2447.06 ms | 25 | 26
27 |  POTTERY |           Seq(Array)    |   2788.01 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   3303.48 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   4340.03 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   6357.41 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
3 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
4 |  STL |            Seq(List)   |   1.28G| 2 | 10
5 |  M*LIB |            Seq(List)   |   1.28G| 3 | 10
6 |  CTL |            Seq(List)   |   1.28G| 2 | 10
7 |  M*LIB |          Seq(DPList)   |   1.28G| 5 | 10
8 |  STC |            Seq(List)   |   1.28G| 1 | 10
9 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 10
10 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
18 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
19 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
20 |  CTL |           Seq(Array)   |   1.60G| 18 | 20
21 |  STC |           Seq(Array)   |   1.60G| 17 | 21
22 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 22
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
1 |  STC |                 Sort    |   1206.66 ms | 1 | 2
2 |  STL |                 Sort    |   1229.62 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1328.44 ms | 3 | 5
4 |  STL |          Stable Sort    |   1408.74 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1431.31 ms | 4 | 5
6 |  CTL |                 Sort    |   1674.22 ms | 6 | 7
7 |  KLIB |                 Sort    |   1801.06 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1829.07 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1886.09 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1889.86 ms | 9 | 10
11 |  GLIB |                 Sort    |   1965.37 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3309.36 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.82M| 1 | 3
3 |  STC |                 Sort   |   41.96M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.02M| 5 | 5
6 |  M*LIB |                 Sort   |   81.16M| 6 | 8
7 |  M*LIB |          Stable Sort   |   82.20M| 6 | 8
8 |  UT-HASH |                 Sort   |   82.21M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   166.20M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   873.03 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1076.37 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2323.25 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2801.20 ms | 3 | 5
5 |  STL |         SSet(Rbtree)    |   3286.90 ms | 4 | 9
6 |  CTL |            SSet(set)    |   3704.00 ms | 4 | 9
7 |  TommyDS |         SSet(Rbtree)    |   4016.16 ms | 7 | 10
8 |  CollectionC |      SSet(TreeTable)    |   4039.40 ms | 6 | 8
9 |  CMC |           SSet(tree)    |   4454.80 ms | 4 | 8
10 |  GLIB |          SSet(GTree)    |   4593.38 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   5046.29 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.43M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.01M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
5 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
6 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
7 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
8 |  CTL |            SSet(set)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   127.93M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   393.09 ms | 1 | 1
2 |  M*LIB |        String Concat    |   545.28 ms | 2 | 2
3 |  STL |        String Concat    |   611.01 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1599.87 ms | 4 | 4
5 |  SDS |        String Concat    |   2516.80 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3264.06 ms | 6 | 6
7 |  CTL |        String Concat    |   3916.03 ms | 7 | 7
8 |  GLIB |        String Concat    |   4275.73 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   553.92 ms | 1 | 1
2 |  STL |       String Replace    |   1143.67 ms | 2 | 3
3 |  STC |       String Replace    |   1409.97 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.18M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   415.08M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   912.93 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1045.01 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3333.41 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   8615.00 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   170.46M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.61M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   906.91 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   976.89 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   1054.59 ms | 3 | 3
4 |  KLIB |      UMap U64(khash)    |   1348.12 ms | 4 | 5
5 |  BOOST |  UMap U64(uflat_map)    |   1452.54 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2039.17 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2398.33 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2615.77 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   3174.80 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3965.98 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   4032.03 ms | 9 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4704.07 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   7633.15 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   9321.59 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   11249.50 ms | 14 | 15
16 |  UT-HASH |       UMap U64(dict)    |   12216.87 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.72M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   557.69M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   590.03M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.12M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.21M| 6 | 9
9 |  CC |        UMap U64(map)   |   906.22M| 6 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1234.15 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1652.72 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   2059.93 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   2114.18 ms | 3 | 8
5 |  TommyDS |       UMap Big(dict)    |   2355.31 ms | 4 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2405.64 ms | 5 | 7
7 |  POTTERY |  UMap Big(open hash)    |   2533.18 ms | 8 | 10
8 |  KLIB |      UMap Big(khash)    |   2577.20 ms | 5 | 9
9 |  STC |       UMap Big(hmap)    |   2714.64 ms | 5 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2891.64 ms | 7 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   3642.64 ms | 11 | 12
12 |  KLIB |     UMap Big(khashl)    |   3673.97 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4820.11 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4965.39 ms | 13 | 14

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
1 |  BOOST | USet Longest(uflat_s    |   488.05 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   761.45 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   867.08 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   999.12 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1085.27 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1327.23 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1477.53 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1584.33 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   4175.08 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   5647.34 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.22M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   119.72M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 6
6 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   214.87M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.14M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.01M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 10


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
