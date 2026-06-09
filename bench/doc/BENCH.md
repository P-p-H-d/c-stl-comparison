# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   709.01 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   971.09 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1411.25 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   38.39 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   43.49 ms | 1 | 2
3 |  M*LIB |       Queue(SPSC P2)    |   44.90 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   82.59 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   456.41 ms | 5 | 5
6 |  M*LIB |     Queue(Buffer P2)    |   601.87 ms | 6 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1085.43 ms | 7 | 7
8 |  M*LIB |        Queue(Buffer)    |   1850.93 ms | 8 | 8
9 |  BOOST | Queue MPMC (lockfree    |   2074.40 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 7
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 5
3 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 8
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 9
9 |  M*LIB |    Queue(Shared ptr)   |   1.31M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |           Seq(Array)    |   731.75 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   829.44 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   842.67 ms | 1 | 4
4 |  UT-HASH |           Seq(Array)    |   848.32 ms | 2 | 5
5 |  KLIB |           Seq(Array)    |   848.57 ms | 1 | 5
6 |  M*LIB |            Seq(List)    |   894.50 ms | 6 | 11
7 |  CTL |            Seq(List)    |   898.75 ms | 6 | 12
8 |  M*LIB |          Seq(DPList)    |   902.48 ms | 8 | 12
9 |  STC |            Seq(List)    |   908.01 ms | 6 | 12
10 |  UT-HASH |            Seq(List)    |   937.86 ms | 6 | 10
11 |  POTTERY |            Seq(List)    |   954.92 ms | 7 | 11
12 |  CC |            Seq(List)    |   1002.86 ms | 11 | 14
13 |  M*LIB |           Seq(Deque)    |   1019.65 ms | 6 | 16
14 |  CollectionC |            Seq(List)    |   1039.95 ms | 13 | 16
15 |  GLIB |            Seq(List)    |   1063.64 ms | 14 | 17
16 |  TommyDS |            Seq(List)    |   1066.76 ms | 8 | 14
17 |  KLIB |            Seq(List)    |   1177.27 ms | 17 | 18
18 |  STL |            Seq(List)    |   1179.80 ms | 16 | 18
19 |  OpenCSTL |            Seq(List)    |   1503.65 ms | - | -
20 |  STB-DS |        Seq(DynArray)    |   1702.20 ms | 19 | 24
21 |  CC |           Seq(Array)    |   1822.56 ms | 19 | 24
22 |  STL |           Seq(Array)    |   1841.47 ms | 19 | 22
23 |  TommyDS |           Seq(Array)    |   1846.04 ms | 20 | 26
24 |  CMC |           Seq(Array)    |   1869.01 ms | 19 | 23
25 |  STL |           Seq(Deque)    |   2011.83 ms | 22 | 24
26 |  CollectionC |           Seq(Array)    |   2333.17 ms | 23 | 25
27 |  QLIBC |            Seq(List)    |   2431.55 ms | 25 | 26
28 |  POTTERY |           Seq(Array)    |   2885.46 ms | 27 | 27
29 |  OpenCSTL |           Seq(Array)    |   3105.18 ms | - | -
30 |  GLIB |           Seq(Array)    |   3299.24 ms | 28 | 28
31 |  LIBSRT |           Seq(Array)    |   4324.12 ms | 29 | 29
32 |  OpenCSTL |           Seq(Deque)    |   5574.53 ms | - | -
33 |  QLIBC |           Seq(Array)    |   6380.54 ms | 30 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
3 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
4 |  STL |            Seq(List)   |   1.28G| 2 | 10
5 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
6 |  CTL |            Seq(List)   |   1.28G| 1 | 10
7 |  M*LIB |          Seq(DPList)   |   1.28G| 3 | 10
8 |  STC |            Seq(List)   |   1.28G| 1 | 10
9 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 9
10 |  POTTERY |            Seq(List)   |   1.28G| 4 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
13 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
16 |  OpenCSTL |           Seq(Array)   |   1.60G| - | -
17 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
18 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 17
19 |  STC |           Seq(Array)   |   1.60G| 17 | 21
20 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
21 |  CTL |           Seq(Array)   |   1.60G| 17 | 20
22 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
23 |  KLIB |           Seq(Array)   |   1.60G| 16 | 21
24 |  STL |           Seq(Array)   |   1.61G| 23 | 23
25 |  OpenCSTL |           Seq(Deque)   |   1.61G| - | -
26 |  STL |           Seq(Deque)   |   1.68G| 24 | 24
27 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 25
28 |  TommyDS |            Seq(List)   |   1.92G| 26 | 26
29 |  OpenCSTL |            Seq(List)   |   1.92G| - | -
30 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 28
31 |  QLIBC |            Seq(List)   |   3.20G| 27 | 28
32 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 29
33 |  GLIB |           Seq(Array)   |   4.81G| 30 | 30

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1204.67 ms | 1 | 1
2 |  STL |                 Sort    |   1228.44 ms | 2 | 2
3 |  POTTERY |                 Sort    |   1325.19 ms | 3 | 3
4 |  STL |          Stable Sort    |   1411.58 ms | 4 | 5
5 |  M*LIB |          Stable Sort    |   1433.11 ms | 4 | 5
6 |  CTL |                 Sort    |   1666.55 ms | 6 | 6
7 |  KLIB |                 Sort    |   1801.94 ms | 7 | 7
8 |  LIBSRT |                 Sort    |   1829.18 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1882.74 ms | 9 | 9
10 |  M*LIB |                 Sort    |   1893.87 ms | 10 | 10
11 |  OpenCSTL |                 Sort    |   1945.43 ms | - | -
12 |  GLIB |                 Sort    |   1960.66 ms | 11 | 11
13 |  CollectionC |                 Sort    |   3273.77 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.16M| 1 | 3
3 |  STC |                 Sort   |   41.68M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.59M| 5 | 5
6 |  OpenCSTL |                 Sort   |   80.54M| - | -
7 |  M*LIB |                 Sort   |   81.16M| 6 | 8
8 |  UT-HASH |                 Sort   |   81.69M| 6 | 8
9 |  M*LIB |          Stable Sort   |   81.96M| 6 | 8
10 |  POTTERY |                 Sort   |   98.98M| 9 | 9
11 |  STL |          Stable Sort   |   100.76M| 10 | 10
12 |  GLIB |                 Sort   |   165.24M| 11 | 11
13 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   966.80 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1030.34 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2336.34 ms | 3 | 5
4 |  OpenCSTL |            SSet(Set)    |   2798.86 ms | - | -
5 |  STL |         SSet(Rbtree)    |   3014.48 ms | 4 | 9
6 |  CTL |            SSet(set)    |   3092.20 ms | 5 | 9
7 |  M*LIB |         SSet(Rbtree)    |   3183.12 ms | 3 | 6
8 |  CollectionC |      SSet(TreeTable)    |   3205.57 ms | 6 | 8
9 |  TommyDS |         SSet(Rbtree)    |   3672.44 ms | 7 | 10
10 |  CMC |           SSet(tree)    |   4023.36 ms | 4 | 9
11 |  GLIB |          SSet(GTree)    |   4230.77 ms | 8 | 10
12 |  QLIBC |         SSet(Rbtree)    |   4917.91 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.57M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.00M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 6
5 |  CTL |            SSet(set)   |   96.08M| 5 | 8
6 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 6
7 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  CMC |           SSet(tree)   |   96.08M| 6 | 8
9 |  OpenCSTL |            SSet(Set)   |   96.47M| - | -
10 |  CollectionC |      SSet(TreeTable)   |   127.93M| 9 | 9
11 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
12 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   418.15 ms | 1 | 1
2 |  M*LIB |        String Concat    |   551.80 ms | 2 | 2
3 |  STL |        String Concat    |   611.57 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1583.62 ms | 4 | 4
5 |  SDS |        String Concat    |   2592.96 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3299.08 ms | 6 | 6
7 |  CTL |        String Concat    |   3881.00 ms | 7 | 7
8 |  GLIB |        String Concat    |   4177.75 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   525.00 ms | 1 | 1
2 |  STL |       String Replace    |   1150.75 ms | 2 | 2
3 |  STC |       String Replace    |   1397.80 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.01M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   416.07M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   1068.68 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   1110.70 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   3316.67 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   8567.34 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   169.93M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.11M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.62M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   905.52 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   973.22 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   1044.46 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1338.13 ms | 4 | 4
5 |  BOOST |  UMap U64(uflat_map)    |   1429.28 ms | 5 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2070.63 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2364.82 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2522.16 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   3076.74 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3843.53 ms | 9 | 11
11 |  TommyDS |       UMap U64(dict)    |   4045.96 ms | 10 | 11
12 |  CollectionC |  UMap U64(HashTable)    |   4349.19 ms | 11 | 12
13 |  OpenCSTL |             UMap U64    |   4767.38 ms | - | -
14 |  CMC |       UMap U64(hmap)    |   7314.22 ms | 12 | 13
15 |  GLIB | UMap U64(GHashTable)    |   8610.58 ms | 13 | 14
16 |  STL |       UMap U64(umap)    |   10691.41 ms | 14 | 16
17 |  UT-HASH |       UMap U64(dict)    |   12204.31 ms | 15 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.28M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   557.78M| 2 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   557.89M| 2 | 4
5 |  M*LIB |       UMap U64(dict)   |   590.16M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  OpenCSTL |             UMap U64   |   872.46M| - | -
8 |  VERSTABLE |             UMap U64   |   906.22M| 6 | 9
9 |  STC |       UMap U64(hmap)   |   906.27M| 6 | 8
10 |  CC |        UMap U64(map)   |   906.34M| 7 | 9
11 |  STL |       UMap U64(umap)   |   933.87M| 9 | 10
12 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 11
13 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 12
14 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 13
15 |  GLIB | UMap U64(GHashTable)   |   1.95G| 13 | 14
16 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 15
17 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 16

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1315.77 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1657.43 ms | 2 | 2
3 |  CC |        UMap Big(map)    |   2052.22 ms | 3 | 4
4 |  VERSTABLE |             UMap Big    |   2173.45 ms | 3 | 4
5 |  TommyDS |       UMap Big(dict)    |   2320.07 ms | 5 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   2530.69 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2539.41 ms | 6 | 10
8 |  STC |       UMap Big(hmap)    |   2559.39 ms | 6 | 9
9 |  POTTERY |  UMap Big(open hash)    |   2631.58 ms | 7 | 10
10 |  GLIB | UMap Big(GHashTable)    |   2673.53 ms | 8 | 10
11 |  CollectionC |  UMap Big(HashTable)    |   3469.39 ms | 11 | 12
12 |  KLIB |     UMap Big(khashl)    |   3572.54 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   4603.23 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4683.59 ms | 13 | 14

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)   |   1.61G| 1 | 1
2 |  STL |       UMap Big(umap)   |   1.68G| 2 | 2
3 |  GLIB | UMap Big(GHashTable)   |   1.72G| 3 | 3
4 |  UT-HASH |       UMap Big(dict)   |   1.80G| 4 | 4
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G| 5 | 5
6 |  KLIB |      UMap Big(khash)   |   2.15G| 6 | 6
7 |  KLIB |     UMap Big(khashl)   |   2.17G| 7 | 7
8 |  BOOST |  UMap Big(uflat_map)   |   3.03G| 7 | 8
9 |  CC |        UMap Big(map)   |   3.23G| 9 | 10
10 |  VERSTABLE |             UMap Big   |   3.23G| 8 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   469.37 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   759.03 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   872.32 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   1061.27 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   1114.25 ms | 3 | 5
6 |  KLIB | USet Longest(khashl)    |   1273.31 ms | 6 | 6
7 |  OpenCSTL |         USet Longest    |   1417.40 ms | - | -
8 |  STC |   USet Longest(hset)    |   1521.76 ms | 6 | 8
9 |  CC |   USet Longest(hset)    |   1599.27 ms | 5 | 7
10 |  CTL |   USet Longest(hset)    |   4152.24 ms | 7 | 9
11 |  STL | USet Longest(dict oa    |   5507.20 ms | 8 | 10

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   117.80M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  OpenCSTL |         USet Longest   |   174.40M| - | -
6 |  CC |   USet Longest(hset)   |   191.24M| 3 | 6
7 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 6
8 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 7
9 |  STC |   USet Longest(hset)   |   219.08M| 6 | 8
10 |  STL | USet Longest(dict oa   |   457.03M| 7 | 9
11 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 10


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : dbedaf9599716c9aa16c6e955fdc3ef76d5c5cca
* OpenCSTL : c02efabbf563b2fedb7dcd4f0581638afe2935cc
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
