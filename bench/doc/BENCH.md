# Performance test: hash function

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Hash (Core Hash)    |   730.18 ms | 1 | 1
2 |  XXHASH |      Hash (xxhash64)    |   813.94 ms | 2 | 2
3 |  M*LIB |        Hash (M_HASH)    |   1269.49 ms | 3 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |        Hash (M_HASH)   |   8.00G| 1 | 1
2 |  M*LIB |     Hash (Core Hash)   |   8.00G| 2 | 2
3 |  XXHASH |      Hash (xxhash64)   |   8.00G| 3 | 3

# Performance test: thread communication queue container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |     Queue(SPSC Bulk)    |   30.87 ms | 1 | 3
2 |  M*LIB |       Queue(SPSC P2)    |   66.67 ms | 2 | 3
3 |  M*LIB |       Queue(MPMC P2)    |   161.87 ms | 1 | 3
4 |  M*LIB |          Queue(MPMC)    |   304.97 ms | 4 | 4
5 |  M*LIB |     Queue(Buffer P2)    |   627.52 ms | 5 | 6
6 |  LIBLFDS |          Queue(MPMC)    |   693.87 ms | 5 | 6
7 |  M*LIB |        Queue(Buffer)    |   1687.99 ms | 7 | 8
8 |  M*LIB |    Queue(Shared ptr)    |   1710.61 ms | 7 | 9
9 |  BOOST | Queue MPMC (lockfree    |   2526.55 ms | 7 | 9

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       Queue(SPSC P2)   |   270.34K| 1 | 8
2 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K| 1 | 6
3 |  M*LIB |     Queue(Buffer P2)   |   397.31K| 4 | 9
4 |  M*LIB |        Queue(Buffer)   |   528.38K| 3 | 6
5 |  M*LIB |          Queue(MPMC)   |   528.38K| 5 | 8
6 |  BOOST | Queue MPMC (lockfree   |   565.25K| 1 | 8
7 |  M*LIB |       Queue(MPMC P2)   |   585.73K| 2 | 8
8 |  LIBLFDS |          Queue(MPMC)   |   659.46K| 4 | 8
9 |  M*LIB |    Queue(Shared ptr)   |   8.94M| 5 | 9

# Performance test: sequence container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |           Seq(Array)    |   620.02 ms | 1 | 5
2 |  M*LIB |           Seq(Array)    |   623.75 ms | 1 | 4
3 |  CTL |           Seq(Array)    |   627.36 ms | 1 | 5
4 |  STC |           Seq(Array)    |   628.17 ms | 1 | 4
5 |  UT-HASH |           Seq(Array)    |   669.40 ms | 1 | 5
6 |  M*LIB |           Seq(Deque)    |   710.75 ms | 6 | 14
7 |  POTTERY |            Seq(List)    |   1014.65 ms | 7 | 12
8 |  UT-HASH |            Seq(List)    |   1056.76 ms | 8 | 13
9 |  CTL |            Seq(List)    |   1062.98 ms | 7 | 12
10 |  M*LIB |            Seq(List)    |   1082.04 ms | 9 | 14
11 |  M*LIB |          Seq(DPList)    |   1083.88 ms | 6 | 12
12 |  STC |            Seq(List)    |   1091.10 ms | 6 | 13
13 |  STL |            Seq(List)    |   1164.14 ms | 13 | 18
14 |  CC |            Seq(List)    |   1176.58 ms | 13 | 18
15 |  GLIB |            Seq(List)    |   1195.41 ms | 8 | 18
16 |  CollectionC |            Seq(List)    |   1201.65 ms | 8 | 17
17 |  STB-DS |        Seq(DynArray)    |   1202.65 ms | 7 | 22
18 |  TommyDS |            Seq(List)    |   1212.36 ms | 11 | 19
19 |  CMC |           Seq(Array)    |   1346.50 ms | 19 | 22
20 |  STL |           Seq(Array)    |   1463.92 ms | 16 | 21
21 |  STL |           Seq(Deque)    |   1499.82 ms | 21 | 23
22 |  TommyDS |           Seq(Array)    |   1521.17 ms | 17 | 26
23 |  KLIB |            Seq(List)    |   1586.57 ms | 17 | 24
24 |  CC |           Seq(Array)    |   1634.09 ms | 21 | 24
25 |  QLIBC |            Seq(List)    |   2522.13 ms | 24 | 27
26 |  CollectionC |           Seq(Array)    |   2591.82 ms | 23 | 25
27 |  POTTERY |           Seq(Array)    |   2647.07 ms | 26 | 27
28 |  GLIB |           Seq(Array)    |   2797.64 ms | 27 | 29
29 |  LIBSRT |           Seq(Array)    |   3861.80 ms | 28 | 29
30 |  QLIBC |           Seq(Array)    |   5139.80 ms | 29 | 30

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  POTTERY |            Seq(List)   |   1.28G| 1 | 9
2 |  UT-HASH |            Seq(List)   |   1.28G| 2 | 7
3 |  CTL |            Seq(List)   |   1.28G| 1 | 10
4 |  M*LIB |            Seq(List)   |   1.28G| 4 | 10
5 |  M*LIB |          Seq(DPList)   |   1.28G| 4 | 10
6 |  STC |            Seq(List)   |   1.28G| 3 | 8
7 |  STL |            Seq(List)   |   1.28G| 4 | 9
8 |  CC |            Seq(List)   |   1.28G| 1 | 10
9 |  GLIB |            Seq(List)   |   1.28G| 1 | 10
10 |  CollectionC |            Seq(List)   |   1.28G| 2 | 10
11 |  KLIB |            Seq(List)   |   1.44G| 11 | 11
12 |  STB-DS |        Seq(DynArray)   |   1.60G| 12 | 14
13 |  CMC |           Seq(Array)   |   1.60G| 12 | 13
14 |  CC |           Seq(Array)   |   1.60G| 14 | 15
15 |  LIBSRT |           Seq(Array)   |   1.60G| 15 | 16
16 |  QLIBC |           Seq(Array)   |   1.60G| 14 | 17
17 |  KLIB |           Seq(Array)   |   1.60G| 16 | 22
18 |  M*LIB |           Seq(Array)   |   1.60G| 17 | 20
19 |  CTL |           Seq(Array)   |   1.60G| 17 | 21
20 |  STC |           Seq(Array)   |   1.60G| 18 | 20
21 |  UT-HASH |           Seq(Array)   |   1.60G| 17 | 21
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
1 |  STL |                 Sort    |   916.85 ms | 1 | 2
2 |  STC |                 Sort    |   933.06 ms | 1 | 2
3 |  STL |          Stable Sort    |   1055.11 ms | 3 | 5
4 |  M*LIB |          Stable Sort    |   1088.41 ms | 3 | 5
5 |  POTTERY |                 Sort    |   1096.11 ms | 3 | 5
6 |  KLIB |                 Sort    |   1284.66 ms | 6 | 7
7 |  CTL |                 Sort    |   1404.75 ms | 6 | 8
8 |  LIBSRT |                 Sort    |   1522.27 ms | 7 | 9
9 |  M*LIB |                 Sort    |   1539.10 ms | 8 | 10
10 |  GLIB |                 Sort    |   1564.14 ms | 10 | 11
11 |  UT-HASH |                 Sort    |   1564.63 ms | 9 | 11
12 |  CollectionC |                 Sort    |   2764.60 ms | 12 | 12

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |                 Sort   |   41.82M| 1 | 3
2 |  CTL |                 Sort   |   41.82M| 1 | 3
3 |  STC |                 Sort   |   42.09M| 1 | 3
4 |  STL |                 Sort   |   68.41M| 4 | 4
5 |  LIBSRT |                 Sort   |   79.72M| 5 | 5
6 |  M*LIB |                 Sort   |   81.29M| 6 | 8
7 |  UT-HASH |                 Sort   |   81.29M| 6 | 8
8 |  M*LIB |          Stable Sort   |   81.82M| 6 | 8
9 |  POTTERY |                 Sort   |   99.11M| 9 | 9
10 |  STL |          Stable Sort   |   100.76M| 10 | 10
11 |  GLIB |                 Sort   |   162.79M| 11 | 11
12 |  CollectionC |                 Sort   |   1.12G| 12 | 12

# Performance test: sorted set container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |         SSet(B+tree)    |   847.13 ms | 1 | 1
2 |  KLIB |          SSet(Btree)    |   1218.51 ms | 2 | 2
3 |  STC |           SSet(sset)    |   2585.26 ms | 3 | 5
4 |  CTL |            SSet(set)    |   2823.90 ms | 5 | 6
5 |  M*LIB |         SSet(Rbtree)    |   2995.07 ms | 3 | 9
6 |  CollectionC |      SSet(TreeTable)    |   3048.20 ms | 7 | 8
7 |  CMC |           SSet(tree)    |   3157.58 ms | 6 | 9
8 |  STL |         SSet(Rbtree)    |   3205.30 ms | 4 | 8
9 |  TommyDS |         SSet(Rbtree)    |   3337.22 ms | 5 | 10
10 |  GLIB |          SSet(GTree)    |   3868.72 ms | 9 | 10
11 |  QLIBC |         SSet(Rbtree)    |   4818.40 ms | 11 | 11

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |          SSet(Btree)   |   30.54M| 1 | 1
2 |  STC |           SSet(sset)   |   49.80M| 2 | 2
3 |  M*LIB |         SSet(B+tree)   |   55.80M| 3 | 3
4 |  CTL |            SSet(set)   |   96.08M| 5 | 7
5 |  CMC |           SSet(tree)   |   96.08M| 4 | 8
6 |  STL |         SSet(Rbtree)   |   96.08M| 4 | 8
7 |  M*LIB |         SSet(Rbtree)   |   96.21M| 4 | 7
8 |  TommyDS |         SSet(Rbtree)   |   96.21M| 5 | 8
9 |  CollectionC |      SSet(TreeTable)   |   128.06M| 9 | 9
10 |  GLIB |          SSet(GTree)   |   160.04M| 10 | 10
11 |  QLIBC |         SSet(Rbtree)   |   287.97M| 11 | 11

# Performance test: string concat

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  STC |        String Concat    |   459.96 ms | 1 | 2
2 |  M*LIB |        String Concat    |   483.15 ms | 1 | 2
3 |  STL |        String Concat    |   666.19 ms | 3 | 3
4 |  POTTERY |        String Concat    |   1503.82 ms | 4 | 4
5 |  SDS |        String Concat    |   1982.80 ms | 5 | 5
6 |  BSTRLIB |        String Concat    |   2927.82 ms | 6 | 6
7 |  CTL |        String Concat    |   3560.22 ms | 5 | 7
8 |  GLIB |        String Concat    |   4771.96 ms | 6 | 8

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
1 |  M*LIB |       String Replace    |   410.52 ms | 1 | 1
2 |  STC |       String Replace    |   1288.07 ms | 2 | 3
3 |  STL |       String Replace    |   1722.92 ms | 2 | 3

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       String Replace   |   239.30M| 1 | 1
2 |  STC |       String Replace   |   382.32M| 2 | 2
3 |  STL |       String Replace   |   415.90M| 3 | 3

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)    |   832.01 ms | 1 | 2
2 |  BOOST |  UMap Str(uflat_map)    |   1105.33 ms | 1 | 2
3 |  STL |       UMap Str(umap)    |   2713.48 ms | 3 | 3
4 |  STL |        UMap Str(map)    |   7856.20 ms | 4 | 4

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap Str(dict)   |   169.12M| 1 | 1
2 |  STL |        UMap Str(map)   |   336.07M| 2 | 2
3 |  STL |       UMap Str(umap)   |   353.44M| 3 | 3
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M| 4 | 4

# Performance test: unordered map U64 container

Rank|Library|Container|Time|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB |       UMap U64(dict)    |   737.62 ms | 1 | 2
2 |  M*LIB | UMap U64 (dict Bulk)    |   809.48 ms | 1 | 2
3 |  M*LIB |    UMap U64(dict OA)    |   868.71 ms | 1 | 3
4 |  BOOST |  UMap U64(uflat_map)    |   1206.88 ms | 4 | 5
5 |  KLIB |      UMap U64(khash)    |   1230.28 ms | 3 | 5
6 |  POTTERY |  UMap U64(open hash)    |   1709.01 ms | 5 | 6
7 |  VERSTABLE |             UMap U64    |   2145.20 ms | 6 | 8
8 |  CC |        UMap U64(map)    |   2482.53 ms | 7 | 8
9 |  TommyDS |       UMap U64(dict)    |   3245.57 ms | 9 | 10
10 |  STC |       UMap U64(hmap)    |   3272.78 ms | 8 | 9
11 |  CollectionC |  UMap U64(HashTable)    |   3471.96 ms | 10 | 11
12 |  CMC |       UMap U64(hmap)    |   6241.72 ms | 11 | 14
13 |  GLIB | UMap U64(GHashTable)    |   6663.47 ms | 12 | 13
14 |  STL |       UMap U64(umap)    |   8994.60 ms | 13 | 15
15 |  UT-HASH |       UMap U64(dict)    |   9069.23 ms | 13 | 15

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  KLIB |      UMap U64(khash)   |   552.77M| 1 | 1
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.92M| 2 | 3
3 |  M*LIB |    UMap U64(dict OA)   |   557.70M| 2 | 3
4 |  M*LIB |       UMap U64(dict)   |   589.17M| 4 | 4
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M| 5 | 5
6 |  STC |       UMap U64(hmap)   |   906.27M| 6 | 8
7 |  CC |        UMap U64(map)   |   906.34M| 6 | 8
8 |  VERSTABLE |             UMap U64   |   906.35M| 6 | 8
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
1 |  M*LIB |       UMap Big(dict)    |   1210.40 ms | 1 | 2
2 |  BOOST |  UMap Big(uflat_map)    |   1911.19 ms | 1 | 2
3 |  VERSTABLE |             UMap Big    |   1979.53 ms | 3 | 4
4 |  TommyDS |       UMap Big(dict)    |   2004.77 ms | 3 | 6
5 |  STC |       UMap Big(hmap)    |   2130.64 ms | 5 | 10
6 |  M*LIB |    UMap Big(dict OA)    |   2294.07 ms | 5 | 8
7 |  GLIB | UMap Big(GHashTable)    |   2355.26 ms | 7 | 10
8 |  CC |        UMap Big(map)    |   2420.19 ms | 3 | 8
9 |  KLIB |      UMap Big(khash)    |   2619.00 ms | 5 | 10
10 |  POTTERY |  UMap Big(open hash)    |   2652.22 ms | 7 | 9
11 |  CollectionC |  UMap Big(HashTable)    |   2777.28 ms | 11 | 11
12 |  STL |       UMap Big(umap)    |   4083.81 ms | 12 | 13
13 |  UT-HASH |       UMap Big(dict)    |   4528.81 ms | 12 | 13

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
1 |  BOOST | USet Longest(uflat_s    |   417.20 ms | 1 | 1
2 |  M*LIB | USet Longest(dict oa    |   706.54 ms | 2 | 2
3 |  M*LIB |   USet Longest(dict)    |   759.00 ms | 3 | 3
4 |  VERSTABLE |   USet Longest(hset)    |   1044.31 ms | 4 | 5
5 |  CC |   USet Longest(hset)    |   1182.07 ms | 4 | 5
6 |  STC |   USet Longest(hset)    |   1579.03 ms | 6 | 6
7 |  CTL |   USet Longest(hset)    |   3441.90 ms | 7 | 8
8 |  STL | USet Longest(dict oa    |   4694.38 ms | 7 | 8

Rank|Library|Container|Mem|Best Rank|Worst Rank
----|-------|---------|----|---------|----------
1 |  M*LIB | USet Longest(dict oa   |   118.77M| 1 | 1
2 |  BOOST | USet Longest(uflat_s   |   159.79M| 2 | 2
3 |  VERSTABLE |   USet Longest(hset)   |   191.37M| 3 | 4
4 |  CC |   USet Longest(hset)   |   191.39M| 3 | 4
5 |  M*LIB |   USet Longest(dict)   |   215.00M| 5 | 5
6 |  STC |   USet Longest(hset)   |   219.15M| 6 | 6
7 |  STL | USet Longest(dict oa   |   457.03M| 7 | 7
8 |  CTL |   USet Longest(hset)   |   480.73M| 8 | 8


Model name:                              Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz

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
