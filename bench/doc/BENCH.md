# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   642.27 ms | 1 | 2
2 |  XXHASH |      Hash (xxhash64)    |   867.08 ms | 1 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1255.09 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 3
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 2 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   23.37 ms | 1 | 2
2 |  M*LIB |       Queue(MPMC P2)    |   36.94 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   45.28 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   83.06 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   432.48 ms | 5 | 5
6 |  M*LIB |     Queue(Buffer P2)    |   843.36 ms | 6 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1156.72 ms | 7 | 7
8 |  M*LIB |        Queue(Buffer)    |   1313.59 ms | 8 | 8
9 |  BOOST | Queue MPMC (lockfree    |   1774.22 ms | 9 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)   |   397.31K| 1 | 7
2 |  M*LIB |       Queue(SPSC P2)   |   454.66K| 1 | 5
3 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 7
4 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 9
5 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 3 | 8
7 |  BOOST | Queue MPMC (lockfree   |   569.34K| 1 | 9
8 |  M*LIB |     Queue(SPSC Bulk)   |   585.73K| 1 | 7
9 |  M*LIB |    Queue(Shared ptr)   |   1.03M| 4 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |           Seq(Array)    |   681.49 ms | 1 | 4
2 |  KLIB |           Seq(Array)    |   682.01 ms | 1 | 5
3 |  STC |           Seq(Array)    |   733.22 ms | 1 | 5
4 |  CTL |           Seq(Array)    |   736.53 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   738.80 ms | 2 | 5
6 |  M*LIB |           Seq(Deque)    |   910.03 ms | 6 | 16
7 |  POTTERY |            Seq(List)    |   941.38 ms | 7 | 11
8 |  UT-HASH |            Seq(List)    |   964.44 ms | 6 | 10
9 |  CTL |            Seq(List)    |   970.44 ms | 6 | 12
10 |  M*LIB |            Seq(List)    |   970.48 ms | 6 | 11
11 |  M*LIB |          Seq(DPList)    |   980.37 ms | 8 | 12
12 |  STC |            Seq(List)    |   981.70 ms | 6 | 12
13 |  TommyDS |            Seq(List)    |   1042.92 ms | 8 | 16
14 |  CC |            Seq(List)    |   1073.17 ms | 11 | 14
15 |  GLIB |            Seq(List)    |   1133.22 ms | 14 | 17
16 |  CollectionC |            Seq(List)    |   1137.36 ms | 13 | 16
17 |  STL |            Seq(List)    |   1163.20 ms | 16 | 18
18 |  KLIB |            Seq(List)    |   1274.48 ms | 17 | 18
19 |  STB-DS |        Seq(DynArray)    |   1493.35 ms | 19 | 24
20 |  STL |           Seq(Array)    |   1552.43 ms | 19 | 22
21 |  CMC |           Seq(Array)    |   1605.82 ms | 19 | 24
22 |  OpenCSTL |            Seq(List)    |   1671.88 ms | 19 | 19
23 |  STL |           Seq(Deque)    |   1769.72 ms | 22 | 25
24 |  CC |           Seq(Array)    |   2053.35 ms | 19 | 24
25 |  CollectionC |           Seq(Array)    |   2140.89 ms | 23 | 26
26 |  OpenCSTL |           Seq(Array)    |   2530.70 ms | 29 | 29
27 |  QLIBC |            Seq(List)    |   2551.17 ms | 25 | 27
28 |  TommyDS |           Seq(Array)    |   2760.06 ms | 20 | 26
29 |  POTTERY |           Seq(Array)    |   2958.66 ms | 27 | 28
30 |  GLIB |           Seq(Array)    |   3268.24 ms | 28 | 30
31 |  OpenCSTL |           Seq(Deque)    |   3675.92 ms | 32 | 32
32 |  LIBSRT |           Seq(Array)    |   4346.32 ms | 29 | 31
33 |  QLIBC |           Seq(Array)    |   6186.53 ms | 30 | 33

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  GLIB |            Seq(List)   |   1.28G| 1 | 9
3 |  CollectionC |            Seq(List)   |   1.28G| 1 | 10
4 |  STL |            Seq(List)   |   1.28G| 2 | 10
5 |  POTTERY |            Seq(List)   |   1.28G| 4 | 10
6 |  UT-HASH |            Seq(List)   |   1.28G| 1 | 9
7 |  CTL |            Seq(List)   |   1.28G| 1 | 8
8 |  M*LIB |            Seq(List)   |   1.28G| 2 | 9
9 |  M*LIB |          Seq(DPList)   |   1.28G| 3 | 10
10 |  STC |            Seq(List)   |   1.28G| 1 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 15
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 15
14 |  CC |           Seq(Array)   |   1.60G| 12 | 15
15 |  OpenCSTL |           Seq(Array)   |   1.60G| 16 | 16
16 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 17
17 |  QLIBC |           Seq(Array)   |   1.60G| 16 | 18
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 21
19 |  KLIB |           Seq(Array)   |   1.60G| 17 | 23
20 |  STC |           Seq(Array)   |   1.60G| 17 | 21
21 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
22 |  UT-HASH |           Seq(Array)   |   1.60G| 18 | 22
23 |  M*LIB |           Seq(Deque)   |   1.60G| 12 | 22
24 |  STL |           Seq(Array)   |   1.61G| 23 | 24
25 |  OpenCSTL |           Seq(Deque)   |   1.61G| 25 | 25
26 |  STL |           Seq(Deque)   |   1.68G| 24 | 26
27 |  POTTERY |           Seq(Array)   |   1.70G| 25 | 27
28 |  TommyDS |            Seq(List)   |   1.92G| 26 | 28
29 |  OpenCSTL |            Seq(List)   |   1.92G| 29 | 29
30 |  QLIBC |            Seq(List)   |   3.20G| 27 | 31
31 |  TommyDS |           Seq(Array)   |   3.20G| 27 | 30
32 |  CollectionC |           Seq(Array)   |   3.22G| 29 | 32
33 |  GLIB |           Seq(Array)   |   4.81G| 30 | 33

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort    |   1047.27 ms | 1 | 1
2 |  STL |                 Sort    |   1106.73 ms | 2 | 2
3 |  POTTERY |                 Sort    |   1159.08 ms | 3 | 3
4 |  M*LIB |          Stable Sort    |   1239.34 ms | 4 | 5
5 |  STL |          Stable Sort    |   1279.58 ms | 4 | 5
6 |  CTL |                 Sort    |   1499.55 ms | 6 | 6
7 |  KLIB |                 Sort    |   1573.84 ms | 7 | 7
8 |  LIBSRT |                 Sort    |   1660.20 ms | 8 | 8
9 |  UT-HASH |                 Sort    |   1696.75 ms | 9 | 9
10 |  M*LIB |                 Sort    |   1700.89 ms | 10 | 10
11 |  GLIB |                 Sort    |   1756.78 ms | 11 | 12
12 |  OpenCSTL |                 Sort    |   1764.56 ms | 11 | 11
13 |  CollectionC |                 Sort    |   3034.71 ms | 12 | 13

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CTL |                 Sort   |   41.16M| 1 | 3
2 |  STC |                 Sort   |   41.95M| 1 | 3
3 |  KLIB |                 Sort   |   42.34M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.02M| 5 | 5
6 |  OpenCSTL |                 Sort   |   80.41M| 6 | 6
7 |  UT-HASH |                 Sort   |   81.29M| 6 | 8
8 |  M*LIB |          Stable Sort   |   81.69M| 6 | 9
9 |  M*LIB |                 Sort   |   81.82M| 6 | 8
10 |  POTTERY |                 Sort   |   98.98M| 9 | 10
11 |  STL |          Stable Sort   |   100.76M| 10 | 11
12 |  GLIB |                 Sort   |   161.72M| 11 | 12
13 |  CollectionC |                 Sort   |   1.12G| 12 | 13

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   771.93 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1098.69 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2280.56 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2411.88 ms | 3 | 7
5 |  OpenCSTL |            SSet(Set)    |   2554.11 ms | 4 | 4
6 |  STL |         SSet(Rbtree)    |   2556.00 ms | 4 | 9
7 |  CollectionC |      SSet(TreeTable)    |   2920.39 ms | 6 | 8
8 |  CTL |            SSet(set)    |   2989.50 ms | 5 | 9
9 |  TommyDS |         SSet(Rbtree)    |   3023.08 ms | 7 | 10
10 |  CMC |           SSet(tree)    |   3313.66 ms | 4 | 10
11 |  GLIB |          SSet(GTree)    |   3584.74 ms | 8 | 11
12 |  QLIBC |         SSet(Rbtree)    |   4717.09 ms | 11 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.44M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   58.06M| 3 | 3
4 |  STL |         SSet(Rbtree)   |   95.94M| 4 | 5
5 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 6
6 |  CTL |            SSet(set)   |   96.08M| 5 | 8
7 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  CMC |           SSet(tree)   |   96.08M| 6 | 8
9 |  OpenCSTL |            SSet(Set)   |   96.60M| 9 | 9
10 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 10
11 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 11
12 |  QLIBC |         SSet(Rbtree)   |   288.23M| 11 | 12

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   424.84 ms | 1 | 1
2 |  M*LIB |        String Concat    |   526.76 ms | 2 | 2
3 |  STL |        String Concat    |   623.46 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1534.73 ms | 4 | 4
5 |  SDS |        String Concat    |   2402.03 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3227.96 ms | 6 | 6
7 |  CTL |        String Concat    |   3865.05 ms | 7 | 7
8 |  GLIB |        String Concat    |   4072.45 ms | 8 | 8

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
1 |  M*LIB |       String Replace    |   530.73 ms | 1 | 1
2 |  STL |       String Replace    |   1357.85 ms | 2 | 2
3 |  STC |       String Replace    |   1536.03 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.18M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   416.07M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   789.04 ms | 1 | 1
2 |  BOOST |  UMap Str(uflat_map)    |   820.51 ms | 2 | 2
3 |  STL |       UMap Str(umap)    |   2808.27 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   7495.79 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.99M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.24M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.62M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   731.91 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   920.96 ms | 1 | 3
3 |  M*LIB |    UMap U64(dict OA)    |   928.74 ms | 2 | 3
4 |  KLIB |      UMap U64(khash)    |   1272.76 ms | 4 | 4
5 |  BOOST |  UMap U64(uflat_map)    |   1444.16 ms | 5 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1985.81 ms | 6 | 6
7 |  VERSTABLE |             UMap U64    |   2176.94 ms | 7 | 8
8 |  KLIB |     UMap U64(khashl)    |   2459.12 ms | 7 | 8
9 |  CC |        UMap U64(map)    |   2850.46 ms | 8 | 9
10 |  STC |       UMap U64(hmap)    |   3203.20 ms | 9 | 11
11 |  OpenCSTL |             UMap U64    |   4210.01 ms | 13 | 13
12 |  TommyDS |       UMap U64(dict)    |   4663.94 ms | 10 | 11
13 |  CollectionC |  UMap U64(HashTable)    |   4948.99 ms | 11 | 12
14 |  CMC |       UMap U64(hmap)    |   8642.78 ms | 12 | 14
15 |  GLIB | UMap U64(GHashTable)    |   9082.44 ms | 13 | 15
16 |  UT-HASH |       UMap U64(dict)    |   11013.62 ms | 15 | 17
17 |  STL |       UMap U64(umap)    |   11033.34 ms | 14 | 16

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |     UMap U64(khashl)   |   545.17M| 1 | 1
2 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 2
3 |  M*LIB | UMap U64 (dict Bulk)   |   556.42M| 2 | 4
4 |  M*LIB |    UMap U64(dict OA)   |   557.28M| 3 | 4
5 |  M*LIB |       UMap U64(dict)   |   589.74M| 4 | 5
6 |  BOOST |  UMap U64(uflat_map)   |   805.56M| 5 | 6
7 |  OpenCSTL |             UMap U64   |   872.46M| 7 | 7
8 |  STC |       UMap U64(hmap)   |   906.14M| 7 | 9
9 |  VERSTABLE |             UMap U64   |   906.21M| 6 | 9
10 |  CC |        UMap U64(map)   |   906.22M| 7 | 10
11 |  STL |       UMap U64(umap)   |   933.87M| 9 | 11
12 |  CollectionC |  UMap U64(HashTable)   |   1.36G| 10 | 12
13 |  POTTERY |  UMap U64(open hash)   |   1.71G| 11 | 13
14 |  UT-HASH |       UMap U64(dict)   |   1.87G| 12 | 14
15 |  GLIB | UMap U64(GHashTable)   |   1.95G| 13 | 15
16 |  CMC |       UMap U64(hmap)   |   2.42G| 14 | 16
17 |  TommyDS |       UMap U64(dict)   |   4.16G| 15 | 17

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Big(dict)    |   1104.17 ms | 1 | 1
2 |  BOOST |  UMap Big(uflat_map)    |   1318.00 ms | 2 | 2
3 |  VERSTABLE |             UMap Big    |   1562.56 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   1692.06 ms | 3 | 4
5 |  TommyDS |       UMap Big(dict)    |   1950.82 ms | 5 | 6
6 |  M*LIB |    UMap Big(dict OA)    |   1981.32 ms | 5 | 7
7 |  KLIB |      UMap Big(khash)    |   2072.50 ms | 7 | 10
8 |  POTTERY |  UMap Big(open hash)    |   2141.38 ms | 7 | 10
9 |  STC |       UMap Big(hmap)    |   2215.27 ms | 6 | 9
10 |  GLIB | UMap Big(GHashTable)    |   2447.08 ms | 8 | 10
11 |  KLIB |     UMap Big(khashl)    |   2912.86 ms | 11 | 12
12 |  CollectionC |  UMap Big(HashTable)    |   3032.03 ms | 11 | 12
13 |  STL |       UMap Big(umap)    |   3905.88 ms | 12 | 13
14 |  UT-HASH |       UMap Big(dict)    |   4375.08 ms | 13 | 14

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
10 |  CC |        UMap Big(map)   |   3.23G| 9 | 10
11 |  STC |       UMap Big(hmap)   |   3.26G| 10 | 11
12 |  M*LIB |    UMap Big(dict OA)   |   4.56G| 11 | 12
13 |  TommyDS |       UMap Big(dict)   |   5.09G| 12 | 13
14 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 14

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   452.81 ms | 1 | 1
2 |  KLIB |  USet Longest(khash)    |   723.54 ms | 2 | 2
3 |  M*LIB | USet Longest(dict oa    |   758.77 ms | 2 | 3
4 |  M*LIB |   USet Longest(dict)    |   933.83 ms | 3 | 4
5 |  VERSTABLE |   USet Longest(hset)    |   990.87 ms | 4 | 5
6 |  OpenCSTL |         USet Longest    |   1215.26 ms | 7 | 7
7 |  KLIB | USet Longest(khashl)    |   1260.53 ms | 6 | 6
8 |  CC |   USet Longest(hset)    |   1348.31 ms | 5 | 9
9 |  STC |   USet Longest(hset)    |   1596.12 ms | 6 | 8
10 |  CTL |   USet Longest(hset)    |   4608.11 ms | 7 | 10
11 |  STL | USet Longest(dict oa    |   5942.31 ms | 8 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB | USet Longest(khashl)   |   111.23M| 1 | 1
2 |  KLIB |  USet Longest(khash)   |   115.25M| 2 | 2
3 |  M*LIB | USet Longest(dict oa   |   117.91M| 1 | 3
4 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 4
5 |  OpenCSTL |         USet Longest   |   174.37M| 5 | 5
6 |  CC |   USet Longest(hset)   |   191.24M| 4 | 6
7 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 7
8 |  M*LIB |   USet Longest(dict)   |   216.39M| 5 | 8
9 |  STC |   USet Longest(hset)   |   219.02M| 6 | 9
10 |  STL | USet Longest(dict oa   |   457.03M| 7 | 10
11 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 11


Model name:                              AMD EPYC 7763 64-Core Processor

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
