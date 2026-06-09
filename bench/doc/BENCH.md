# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  XXHASH |      Hash (xxhash64)    |   549.21 ms | 1 | 2
2 |  M*LIB |     Hash (Core Hash)    |   549.30 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1094.31 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3
3 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   32.09 ms | 1 | 2
2 |  M*LIB |       Queue(MPMC P2)    |   33.37 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   35.76 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   61.59 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   366.63 ms | 5 | 5
6 |  M*LIB |     Queue(Buffer P2)    |   506.44 ms | 6 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   894.73 ms | 7 | 7
8 |  M*LIB |        Queue(Buffer)    |   1302.93 ms | 8 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1409.36 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 9
2 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K| 1 | 7
3 |  M*LIB |       Queue(SPSC P2)   |   454.66K| 1 | 5
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
5 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
6 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
7 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 1 | 8
8 |  LIBLFDS |          Queue(MPMC)   |   659.46K| 4 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   1.57M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |           Seq(Array)    |   591.65 ms | 1 | 4
2 |  UT-HASH |           Seq(Array)    |   627.08 ms | 3 | 5
3 |  CTL |           Seq(Array)    |   644.44 ms | 1 | 4
4 |  KLIB |           Seq(Array)    |   657.77 ms | 1 | 5
5 |  STC |           Seq(Array)    |   663.08 ms | 1 | 4
6 |  CTL |            Seq(List)    |   683.37 ms | 6 | 12
7 |  UT-HASH |            Seq(List)    |   694.47 ms | 6 | 12
8 |  M*LIB |          Seq(DPList)    |   722.01 ms | 8 | 12
9 |  M*LIB |            Seq(List)    |   737.30 ms | 6 | 11
10 |  POTTERY |            Seq(List)    |   752.57 ms | 7 | 11
11 |  CC |            Seq(List)    |   756.74 ms | 12 | 14
12 |  STC |            Seq(List)    |   758.83 ms | 6 | 11
13 |  TommyDS |            Seq(List)    |   800.39 ms | 8 | 14
14 |  CollectionC |            Seq(List)    |   811.20 ms | 13 | 16
15 |  GLIB |            Seq(List)    |   836.43 ms | 14 | 17
16 |  M*LIB |           Seq(Deque)    |   899.78 ms | 6 | 16
17 |  STL |            Seq(List)    |   956.90 ms | 16 | 18
18 |  KLIB |            Seq(List)    |   959.70 ms | 17 | 18
19 |  STB-DS |        Seq(DynArray)    |   1323.85 ms | 19 | 24
20 |  TommyDS |           Seq(Array)    |   1430.55 ms | 20 | 26
21 |  STL |           Seq(Array)    |   1431.97 ms | 19 | 22
22 |  CMC |           Seq(Array)    |   1462.22 ms | 19 | 23
23 |  CC |           Seq(Array)    |   1478.28 ms | 19 | 24
24 |  STL |           Seq(Deque)    |   1565.32 ms | 22 | 24
25 |  CollectionC |           Seq(Array)    |   1850.23 ms | 23 | 25
26 |  QLIBC |            Seq(List)    |   1884.43 ms | 25 | 26
27 |  POTTERY |           Seq(Array)    |   1962.83 ms | 27 | 27
28 |  GLIB |           Seq(Array)    |   2665.81 ms | 28 | 28
29 |  LIBSRT |           Seq(Array)    |   3438.55 ms | 29 | 29
30 |  QLIBC |           Seq(Array)    |   5276.77 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |            Seq(List)   |   1.28G| 2 | 10
2 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 10
3 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
4 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
5 |  POTTERY |            Seq(List)   |   1.28G| 4 | 10
6 |  CC |            Seq(List)   |   1.28G| 1 | 10
7 |  STC |            Seq(List)   |   1.28G| 1 | 10
8 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
9 |  GLIB |            Seq(List)   |   1.28G| 1 | 8
10 |  STL |            Seq(List)   |   1.28G| 2 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 13 | 15
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
17 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
18 |  UT-HASH |           Seq(Array)   |   1.60G| 19 | 22
19 |  CTL |           Seq(Array)   |   1.60G| 17 | 20
20 |  KLIB |           Seq(Array)   |   1.60G| 16 | 21
21 |  STC |           Seq(Array)   |   1.60G| 17 | 21
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
1 |  STC |                 Sort    |   944.99 ms | 1 | 1
2 |  STL |                 Sort    |   950.35 ms | 2 | 2
3 |  POTTERY |                 Sort    |   1020.52 ms | 3 | 3
4 |  STL |          Stable Sort    |   1092.71 ms | 4 | 5
5 |  M*LIB |          Stable Sort    |   1143.82 ms | 4 | 5
6 |  CTL |                 Sort    |   1300.04 ms | 6 | 6
7 |  KLIB |                 Sort    |   1395.46 ms | 7 | 7
8 |  LIBSRT |                 Sort    |   1418.70 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1447.59 ms | 9 | 9
10 |  M*LIB |                 Sort    |   1471.10 ms | 10 | 10
11 |  GLIB |                 Sort    |   1523.14 ms | 11 | 11
12 |  CollectionC |                 Sort    |   2572.05 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.29M| 1 | 3
2 |  STC |                 Sort   |   41.29M| 1 | 3
3 |  CTL |                 Sort   |   41.81M| 1 | 3
4 |  STL |                 Sort   |   68.40M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.72M| 5 | 5
6 |  UT-HASH |                 Sort   |   81.29M| 6 | 8
7 |  M*LIB |                 Sort   |   81.82M| 6 | 8
8 |  M*LIB |          Stable Sort   |   81.83M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   160.95M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   665.78 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   791.12 ms | 2 | 2
3 |  STC |           SSet(sset)    |   1782.62 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2072.67 ms | 3 | 6
5 |  STL |         SSet(Rbtree)    |   2249.28 ms | 4 | 9
6 |  CMC |           SSet(tree)    |   2365.29 ms | 4 | 9
7 |  CTL |            SSet(set)    |   2437.81 ms | 5 | 9
8 |  CollectionC |      SSet(TreeTable)    |   2574.62 ms | 6 | 8
9 |  TommyDS |         SSet(Rbtree)    |   2743.91 ms | 7 | 10
10 |  GLIB |          SSet(GTree)    |   3215.35 ms | 8 | 10
11 |  QLIBC |         SSet(Rbtree)    |   3873.71 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.67M| 1 | 1
2 |  STC |           SSet(sset)   |   49.73M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.15M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
5 |  M*LIB |         SSet(Rbtree)   |   96.21M| 4 | 6
6 |  CMC |           SSet(tree)   |   96.21M| 5 | 8
7 |  CTL |            SSet(set)   |   96.21M| 5 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.21M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.19M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   302.21 ms | 1 | 1
2 |  M*LIB |        String Concat    |   412.70 ms | 2 | 2
3 |  STL |        String Concat    |   495.44 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1275.74 ms | 4 | 4
5 |  SDS |        String Concat    |   1958.61 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   2501.51 ms | 6 | 6
7 |  CTL |        String Concat    |   2916.43 ms | 7 | 7
8 |  GLIB |        String Concat    |   3309.03 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   412.05 ms | 1 | 1
2 |  STL |       String Replace    |   949.88 ms | 2 | 2
3 |  STC |       String Replace    |   1086.37 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.14M| 1 | 1
2 |  STC |       String Replace   |   382.45M| 2 | 2
3 |  STL |       String Replace   |   415.04M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   713.80 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   839.44 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   2744.93 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   6874.80 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   169.96M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.20M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.58M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   745.87 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   789.49 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   851.94 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1147.02 ms | 4 | 4
5 |  BOOST |  UMap U64(uflat_map)    |   1172.71 ms | 5 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1686.07 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   1936.19 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2133.67 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2572.80 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3374.60 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   3394.51 ms | 10 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   3779.29 ms | 11 | 12
13 |  CMC |       UMap U64(hmap)    |   6116.56 ms | 12 | 13
14 |  GLIB | UMap U64(GHashTable)    |   7292.35 ms | 13 | 14
15 |  STL |       UMap U64(umap)    |   9233.62 ms | 14 | 16
16 |  UT-HASH |       UMap U64(dict)    |   10582.95 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.41M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.76M| 1 | 2
3 |  M*LIB |    UMap U64(dict OA)   |   556.61M| 2 | 4
4 |  M*LIB | UMap U64 (dict Bulk)   |   557.50M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.17M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  STC |       UMap U64(hmap)   |   906.26M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.34M| 6 | 9
9 |  CC |        UMap U64(map)   |   906.34M| 7 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   977.29 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1344.41 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   1720.01 ms | 3 | 4
4 |  VERSTABLE |             UMap Big    |   1721.73 ms | 3 | 4
5 |  TommyDS |       UMap Big(dict)    |   1920.93 ms | 5 | 6
6 |  STC |       UMap Big(hmap)    |   2037.27 ms | 7 | 9
7 |  M*LIB |    UMap Big(dict OA)    |   2073.36 ms | 5 | 7
8 |  GLIB | UMap Big(GHashTable)    |   2171.34 ms | 8 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2177.50 ms | 7 | 10
10 |  KLIB |      UMap Big(khash)    |   2286.27 ms | 6 | 8
11 |  KLIB |     UMap Big(khashl)    |   3026.34 ms | 11 | 12
12 |  CollectionC |  UMap Big(HashTable)    |   3033.21 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   3897.28 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4045.36 ms | 13 | 14

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
9 |  CC |        UMap Big(map)   |   3.23G| 8 | 10
10 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   380.53 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   623.74 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   698.93 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   825.69 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   856.19 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1062.20 ms | 6 | 6
7 |  CC |   USet Longest(hset)    |   1108.09 ms | 5 | 7
8 |  STC |   USet Longest(hset)    |   1261.44 ms | 5 | 8
9 |  CTL |   USet Longest(hset)    |   3571.87 ms | 7 | 9
10 |  STL | USet Longest(dict oa    |   4783.61 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.36M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.38M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   119.84M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  CC |   USet Longest(hset)   |   191.37M| 3 | 6
6 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 6
7 |  M*LIB |   USet Longest(dict)   |   215.00M| 5 | 7
8 |  STC |   USet Longest(hset)   |   219.15M| 6 | 8
9 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
10 |  CTL |   USet Longest(hset)   |   480.73M| 8 | 10


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
