# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   709.17 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   971.55 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1410.21 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(MPMC P2)    |   40.50 ms | 1 | 3
2 |  M*LIB |     Queue(SPSC Bulk)    |   43.47 ms | 1 | 3
3 |  M*LIB |       Queue(SPSC P2)    |   46.95 ms | 2 | 3
4 |  M*LIB |          Queue(MPMC)    |   79.44 ms | 4 | 4
5 |  LIBLFDS |          Queue(MPMC)    |   461.32 ms | 5 | 6
6 |  M*LIB |     Queue(Buffer P2)    |   607.28 ms | 5 | 6
7 |  M*LIB |    Queue(Shared ptr)    |   1070.80 ms | 7 | 9
8 |  M*LIB |        Queue(Buffer)    |   1468.40 ms | 7 | 8
9 |  BOOST | Queue MPMC (lockfree    |   2169.93 ms | 7 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)   |   266.24K| 1 | 6
2 |  M*LIB |       Queue(SPSC P2)   |   266.24K| 1 | 8
3 |  BOOST | Queue MPMC (lockfree   |   393.22K| 1 | 8
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
5 |  LIBLFDS |          Queue(MPMC)   |   528.38K| 4 | 8
6 |  M*LIB |     Queue(Buffer P2)   |   528.38K| 2 | 9
7 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
8 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 1 | 7
9 |  M*LIB |    Queue(Shared ptr)   |   4.59M| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |           Seq(Array)    |   831.08 ms | 2 | 4
2 |  CTL |           Seq(Array)    |   835.15 ms | 1 | 5
3 |  M*LIB |           Seq(Array)    |   837.96 ms | 1 | 4
4 |  UT-HASH |           Seq(Array)    |   841.78 ms | 1 | 5
5 |  KLIB |           Seq(Array)    |   855.95 ms | 1 | 5
6 |  STC |            Seq(List)    |   894.20 ms | 7 | 13
7 |  CTL |            Seq(List)    |   925.78 ms | 7 | 12
8 |  UT-HASH |            Seq(List)    |   927.15 ms | 8 | 13
9 |  M*LIB |            Seq(List)    |   942.74 ms | 9 | 19
10 |  POTTERY |            Seq(List)    |   946.54 ms | 7 | 13
11 |  TommyDS |            Seq(List)    |   952.32 ms | 13 | 20
12 |  M*LIB |          Seq(DPList)    |   954.87 ms | 6 | 12
13 |  CC |            Seq(List)    |   1005.93 ms | 13 | 18
14 |  M*LIB |           Seq(Deque)    |   1028.14 ms | 6 | 13
15 |  CollectionC |            Seq(List)    |   1047.37 ms | 8 | 17
16 |  GLIB |            Seq(List)    |   1085.72 ms | 8 | 18
17 |  STL |            Seq(List)    |   1119.86 ms | 13 | 18
18 |  KLIB |            Seq(List)    |   1177.49 ms | 17 | 24
19 |  TommyDS |           Seq(Array)    |   1842.03 ms | 17 | 26
20 |  CMC |           Seq(Array)    |   1866.28 ms | 18 | 22
21 |  STL |           Seq(Array)    |   1873.23 ms | 15 | 21
22 |  STB-DS |        Seq(DynArray)    |   1968.55 ms | 7 | 21
23 |  STL |           Seq(Deque)    |   1985.71 ms | 21 | 23
24 |  CC |           Seq(Array)    |   2124.21 ms | 21 | 24
25 |  CollectionC |           Seq(Array)    |   2328.85 ms | 23 | 25
26 |  QLIBC |            Seq(List)    |   2511.28 ms | 24 | 27
27 |  POTTERY |           Seq(Array)    |   2768.30 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   3393.16 ms | 27 | 29
29 |  LIBSRT |           Seq(Array)    |   4317.83 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   6877.35 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  CC |            Seq(List)   |   1.28G| 1 | 10
2 |  CollectionC |            Seq(List)   |   1.28G| 3 | 10
3 |  GLIB |            Seq(List)   |   1.28G| 1 | 10
4 |  STL |            Seq(List)   |   1.28G| 4 | 9
5 |  STC |            Seq(List)   |   1.28G| 3 | 8
6 |  CTL |            Seq(List)   |   1.28G| 1 | 10
7 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 6
8 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
9 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
10 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 8
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  M*LIB |           Seq(Deque)   |   1.60G| 21 | 22
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
14 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 22
15 |  CC |           Seq(Array)   |   1.60G| 13 | 15
16 |  LIBSRT |           Seq(Array)   |   1.60G| 14 | 16
17 |  QLIBC |           Seq(Array)   |   1.60G| 14 | 20
18 |  STC |           Seq(Array)   |   1.60G| 16 | 20
19 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
20 |  M*LIB |           Seq(Array)   |   1.60G| 15 | 20
21 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 21
22 |  KLIB |           Seq(Array)   |   1.60G| 16 | 21
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
1 |  STC |                 Sort    |   1204.57 ms | 1 | 2
2 |  STL |                 Sort    |   1231.59 ms | 1 | 2
3 |  POTTERY |                 Sort    |   1327.01 ms | 3 | 5
4 |  STL |          Stable Sort    |   1416.33 ms | 3 | 5
5 |  M*LIB |          Stable Sort    |   1434.62 ms | 3 | 5
6 |  CTL |                 Sort    |   1668.27 ms | 6 | 8
7 |  KLIB |                 Sort    |   1803.93 ms | 6 | 7
8 |  LIBSRT |                 Sort    |   1835.39 ms | 7 | 9
9 |  UT-HASH |                 Sort    |   1887.70 ms | 9 | 11
10 |  M*LIB |                 Sort    |   1900.94 ms | 8 | 10
11 |  GLIB |                 Sort    |   1962.79 ms | 10 | 11
12 |  CollectionC |                 Sort    |   3238.66 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |                 Sort   |   41.16M| 1 | 3
2 |  KLIB |                 Sort   |   41.95M| 1 | 3
3 |  CTL |                 Sort   |   41.96M| 1 | 3
4 |  STL |                 Sort   |   67.35M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.10M| 5 | 5
6 |  M*LIB |          Stable Sort   |   81.16M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.16M| 6 | 8
8 |  M*LIB |                 Sort   |   81.69M| 6 | 8
9 |  POTTERY |                 Sort   |   98.98M| 9 | 9
10 |  STL |          Stable Sort   |   100.75M| 10 | 10
11 |  GLIB |                 Sort   |   161.12M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   905.01 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1047.15 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2267.69 ms | 3 | 5
4 |  M*LIB |         SSet(Rbtree)    |   2892.46 ms | 3 | 9
5 |  CTL |            SSet(set)    |   3065.66 ms | 5 | 6
6 |  CMC |           SSet(tree)    |   3144.27 ms | 6 | 9
7 |  CollectionC |      SSet(TreeTable)    |   3148.65 ms | 7 | 8
8 |  STL |         SSet(Rbtree)    |   3198.13 ms | 4 | 6
9 |  TommyDS |         SSet(Rbtree)    |   3878.48 ms | 5 | 10
10 |  GLIB |          SSet(GTree)    |   4163.08 ms | 9 | 10
11 |  QLIBC |         SSet(Rbtree)    |   5220.02 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.80M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   55.73M| 3 | 3
4 |  M*LIB |         SSet(Rbtree)   |   96.08M| 4 | 7
5 |  CTL |            SSet(set)   |   96.08M| 5 | 7
6 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
7 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
8 |  TommyDS |         SSet(Rbtree)   |   96.08M| 4 | 8
9 |  CollectionC |      SSet(TreeTable)   |   127.93M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   159.91M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   288.10M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   366.91 ms | 1 | 2
2 |  M*LIB |        String Concat    |   532.54 ms | 1 | 2
3 |  STL |        String Concat    |   619.42 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1593.80 ms | 4 | 4
5 |  SDS |        String Concat    |   2443.91 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   3309.98 ms | 6 | 6
7 |  CTL |        String Concat    |   3979.65 ms | 5 | 7
8 |  GLIB |        String Concat    |   4209.94 ms | 6 | 8

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
1 |  M*LIB |       String Replace    |   545.82 ms | 1 | 1
2 |  STL |       String Replace    |   1178.65 ms | 2 | 3
3 |  STC |       String Replace    |   1467.39 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.01M| 1 | 1
2 |  STC |       String Replace   |   382.31M| 2 | 2
3 |  STL |       String Replace   |   415.10M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   938.64 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1133.45 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   3371.01 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   9098.36 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   168.99M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.25M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.63M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | UMap U64 (dict Bulk)    |   918.15 ms | 1 | 2
2 |  M*LIB |       UMap U64(dict)    |   992.70 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   1059.68 ms | 1 | 3
4 |  KLIB |      UMap U64(khash)    |   1385.21 ms | 3 | 6
5 |  BOOST |  UMap U64(uflat_map)    |   1476.14 ms | 4 | 5
6 |  POTTERY |  UMap U64(open hash)    |   2082.41 ms | 5 | 6
7 |  VERSTABLE |             UMap U64    |   2477.49 ms | 6 | 8
8 |  CC |        UMap U64(map)    |   3143.99 ms | 7 | 8
9 |  STC |       UMap U64(hmap)    |   4131.88 ms | 8 | 9
10 |  TommyDS |       UMap U64(dict)    |   4240.99 ms | 9 | 10
11 |  CollectionC |  UMap U64(HashTable)    |   4639.26 ms | 10 | 11
12 |  CMC |       UMap U64(hmap)    |   7481.12 ms | 11 | 14
13 |  GLIB | UMap U64(GHashTable)    |   9072.37 ms | 12 | 13
14 |  STL |       UMap U64(umap)    |   10934.48 ms | 13 | 15
15 |  UT-HASH |       UMap U64(dict)    |   12814.69 ms | 13 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.64M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   555.95M| 2 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   557.07M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.90M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 5
6 |  CC |        UMap U64(map)   |   906.21M| 6 | 8
7 |  STC |       UMap U64(hmap)   |   906.21M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.22M| 6 | 8
9 |  STL |       UMap U64(umap)   |   933.87M| 9 | 9
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
1 |  M*LIB |       UMap Big(dict)    |   1267.86 ms | 1 | 2
2 |  BOOST |  UMap Big(uflat_map)    |   1705.38 ms | 1 | 2
3 |  VERSTABLE |             UMap Big    |   2080.62 ms | 3 | 4
4 |  CC |        UMap Big(map)    |   2111.53 ms | 3 | 8
5 |  M*LIB |    UMap Big(dict OA)    |   2439.46 ms | 5 | 8
6 |  TommyDS |       UMap Big(dict)    |   2459.40 ms | 3 | 6
7 |  KLIB |      UMap Big(khash)    |   2581.14 ms | 5 | 10
8 |  GLIB | UMap Big(GHashTable)    |   2694.76 ms | 7 | 10
9 |  POTTERY |  UMap Big(open hash)    |   2732.05 ms | 7 | 9
10 |  STC |       UMap Big(hmap)    |   2732.61 ms | 5 | 9
11 |  CollectionC |  UMap Big(HashTable)    |   3584.28 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   4648.54 ms | 12 | 13
13 |  UT-HASH |       UMap Big(dict)    |   5259.54 ms | 12 | 13

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
13 |  POTTERY |  UMap Big(open hash)   |   6.48G| 13 | 13

# Performance test: unordered set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  BOOST | USet Longest(uflat_s    |   493.27 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   871.67 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   1014.60 ms | 3 | 3
4 |  VERSTABLE |   USet Longest(hset)    |   1094.90 ms | 4 | 5
5 |  CC |   USet Longest(hset)    |   1377.64 ms | 4 | 5
6 |  STC |   USet Longest(hset)    |   1553.70 ms | 6 | 6
7 |  CTL |   USet Longest(hset)    |   4308.62 ms | 7 | 8
8 |  STL | USet Longest(dict oa    |   6184.82 ms | 7 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   116.86M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 2
3 |  VERSTABLE |   USet Longest(hset)   |   191.24M| 3 | 4
4 |  CC |   USet Longest(hset)   |   191.24M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   214.50M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.22M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.01M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.60M| 8 | 8


Model name:                              AMD EPYC 9V74 80-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : e9d3bcab70db85a7a5225aacb53eb5595216b638
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : 41a5e3ea2703dbf7cb3713c67930add3bb64e0d1
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 28d546d5eb77d4585506a20480f4de2e706dff4c
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : 668362bb89b7ca00bc37a58a10d37cb811dbe6a9
