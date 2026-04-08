# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   645.04 ms 
2 |  XXHASH |      Hash (xxhash64)    |   870.47 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1255.19 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   24.01 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   45.55 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   54.38 ms 
4 |  M*LIB |          Queue(MPMC)    |   76.13 ms 
5 |  LIBLFDS |          Queue(MPMC)    |   439.94 ms 
6 |  M*LIB |     Queue(Buffer P2)    |   805.79 ms 
7 |  M*LIB |    Queue(Shared ptr)    |   1126.19 ms 
8 |  M*LIB |        Queue(Buffer)    |   1285.89 ms 
9 |  BOOST | Queue MPMC (lockfree    |   1699.23 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  BOOST | Queue MPMC (lockfree   |   393.22K
2 |  M*LIB |       Queue(MPMC P2)   |   397.31K
3 |  M*LIB |     Queue(SPSC Bulk)   |   454.66K
4 |  M*LIB |       Queue(SPSC P2)   |   454.66K
5 |  M*LIB |        Queue(Buffer)   |   528.38K
6 |  LIBLFDS |          Queue(MPMC)   |   528.38K
7 |  M*LIB |          Queue(MPMC)   |   528.38K
8 |  M*LIB |     Queue(Buffer P2)   |   528.38K
9 |  M*LIB |    Queue(Shared ptr)   |   532.48K

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)    |   694.61 ms 
2 |  STC |           Seq(Array)    |   708.95 ms 
3 |  CTL |           Seq(Array)    |   728.16 ms 
4 |  KLIB |           Seq(Array)    |   744.41 ms 
5 |  UT-HASH |           Seq(Array)    |   751.18 ms 
6 |  M*LIB |           Seq(Deque)    |   883.89 ms 
7 |  STC |            Seq(List)    |   944.33 ms 
8 |  UT-HASH |            Seq(List)    |   969.89 ms 
9 |  M*LIB |            Seq(List)    |   972.69 ms 
10 |  M*LIB |          Seq(DPList)    |   977.96 ms 
11 |  POTTERY |            Seq(List)    |   980.39 ms 
12 |  CTL |            Seq(List)    |   981.90 ms 
13 |  CC |            Seq(List)    |   1054.89 ms 
14 |  TommyDS |            Seq(List)    |   1088.76 ms 
15 |  GLIB |            Seq(List)    |   1133.99 ms 
16 |  CollectionC |            Seq(List)    |   1157.17 ms 
17 |  STL |            Seq(List)    |   1161.55 ms 
18 |  KLIB |            Seq(List)    |   1314.51 ms 
19 |  STL |           Seq(Array)    |   1567.37 ms 
20 |  CMC |           Seq(Array)    |   1613.28 ms 
21 |  STB-DS |        Seq(DynArray)    |   1675.25 ms 
22 |  STL |           Seq(Deque)    |   1817.46 ms 
23 |  CC |           Seq(Array)    |   2021.68 ms 
24 |  CollectionC |           Seq(Array)    |   2147.71 ms 
25 |  QLIBC |            Seq(List)    |   2521.70 ms 
26 |  TommyDS |           Seq(Array)    |   2765.23 ms 
27 |  POTTERY |           Seq(Array)    |   2976.39 ms 
28 |  GLIB |           Seq(Array)    |   3257.64 ms 
29 |  LIBSRT |           Seq(Array)    |   4355.61 ms 
30 |  QLIBC |           Seq(Array)    |   6569.43 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  CC |            Seq(List)   |   1.28G
2 |  GLIB |            Seq(List)   |   1.28G
3 |  CollectionC |            Seq(List)   |   1.28G
4 |  STL |            Seq(List)   |   1.28G
5 |  STC |            Seq(List)   |   1.28G
6 |  UT-HASH |            Seq(List)   |   1.28G
7 |  M*LIB |            Seq(List)   |   1.28G
8 |  M*LIB |          Seq(DPList)   |   1.28G
9 |  POTTERY |            Seq(List)   |   1.28G
10 |  CTL |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  CMC |           Seq(Array)   |   1.60G
13 |  STB-DS |        Seq(DynArray)   |   1.60G
14 |  CC |           Seq(Array)   |   1.60G
15 |  LIBSRT |           Seq(Array)   |   1.60G
16 |  QLIBC |           Seq(Array)   |   1.60G
17 |  M*LIB |           Seq(Array)   |   1.60G
18 |  STC |           Seq(Array)   |   1.60G
19 |  CTL |           Seq(Array)   |   1.60G
20 |  KLIB |           Seq(Array)   |   1.60G
21 |  UT-HASH |           Seq(Array)   |   1.60G
22 |  M*LIB |           Seq(Deque)   |   1.60G
23 |  STL |           Seq(Array)   |   1.61G
24 |  STL |           Seq(Deque)   |   1.68G
25 |  POTTERY |           Seq(Array)   |   1.70G
26 |  TommyDS |            Seq(List)   |   1.92G
27 |  QLIBC |            Seq(List)   |   3.20G
28 |  TommyDS |           Seq(Array)   |   3.20G
29 |  CollectionC |           Seq(Array)   |   3.22G
30 |  GLIB |           Seq(Array)   |   4.81G

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |                 Sort    |   1048.17 ms 
2 |  STL |                 Sort    |   1108.12 ms 
3 |  POTTERY |                 Sort    |   1156.19 ms 
4 |  M*LIB |          Stable Sort    |   1238.38 ms 
5 |  STL |          Stable Sort    |   1286.81 ms 
6 |  CTL |                 Sort    |   1505.55 ms 
7 |  KLIB |                 Sort    |   1573.11 ms 
8 |  LIBSRT |                 Sort    |   1663.28 ms 
9 |  UT-HASH |                 Sort    |   1697.89 ms 
10 |  M*LIB |                 Sort    |   1700.80 ms 
11 |  GLIB |                 Sort    |   1755.25 ms 
12 |  CollectionC |                 Sort    |   3131.87 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  CTL |                 Sort   |   41.68M
2 |  STC |                 Sort   |   41.97M
3 |  KLIB |                 Sort   |   42.21M
4 |  STL |                 Sort   |   67.35M
5 |  LIBSRT |                 Sort   |   79.52M
6 |  M*LIB |                 Sort   |   81.16M
7 |  UT-HASH |                 Sort   |   81.69M
8 |  M*LIB |          Stable Sort   |   82.20M
9 |  POTTERY |                 Sort   |   98.98M
10 |  STL |          Stable Sort   |   100.76M
11 |  GLIB |                 Sort   |   161.71M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   942.59 ms 
2 |  KLIB |          SSet(Btree)    |   1121.46 ms 
3 |  STC |           SSet(sset)    |   2851.68 ms 
4 |  STL |         SSet(Rbtree)    |   3379.84 ms 
5 |  M*LIB |         SSet(Rbtree)    |   3445.16 ms 
6 |  CTL |            SSet(set)    |   3536.12 ms 
7 |  CollectionC |      SSet(TreeTable)    |   3634.41 ms 
8 |  CMC |           SSet(tree)    |   3786.07 ms 
9 |  GLIB |          SSet(GTree)    |   3851.57 ms 
10 |  TommyDS |         SSet(Rbtree)    |   4182.96 ms 
11 |  QLIBC |         SSet(Rbtree)    |   4797.56 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.54M
2 |  STC |           SSet(sset)   |   48.57M
3 |  M*LIB |         SSet(B+tree)   |   55.71M
4 |  CMC |           SSet(tree)   |   95.94M
5 |  STL |         SSet(Rbtree)   |   96.08M
6 |  M*LIB |         SSet(Rbtree)   |   96.08M
7 |  CTL |            SSet(set)   |   96.08M
8 |  TommyDS |         SSet(Rbtree)   |   96.08M
9 |  CollectionC |      SSet(TreeTable)   |   128.06M
10 |  GLIB |          SSet(GTree)   |   160.04M
11 |  QLIBC |         SSet(Rbtree)   |   288.23M

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |        String Concat    |   401.35 ms 
2 |  M*LIB |        String Concat    |   538.79 ms 
3 |  STL |        String Concat    |   621.18 ms 
4 |  POTTERY |        String Concat    |   1545.68 ms 
5 |  SDS |        String Concat    |   2374.65 ms 
6 |  BSTRLIB |        String Concat    |   3230.61 ms 
7 |  CTL |        String Concat    |   3902.29 ms 
8 |  GLIB |        String Concat    |   4103.92 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        String Concat   |   1.04G
2 |  STC |        String Concat   |   1.36G
3 |  STL |        String Concat   |   1.78G
4 |  SDS |        String Concat   |   2.00G
5 |  POTTERY |        String Concat   |   2.04G
6 |  BSTRLIB |        String Concat   |   3.28G
7 |  CTL |        String Concat   |   4.02G
8 |  GLIB |        String Concat   |   7.76G

# Performance test: string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace    |   527.85 ms 
2 |  STL |       String Replace    |   1405.67 ms 
3 |  STC |       String Replace    |   1565.11 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.01M
2 |  STC |       String Replace   |   382.31M
3 |  STL |       String Replace   |   415.09M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST |  UMap Str(uflat_map)    |   887.48 ms 
2 |  M*LIB |       UMap Str(dict)    |   887.93 ms 
3 |  STL |       UMap Str(umap)    |   2835.45 ms 
4 |  STL |        UMap Str(map)    |   8424.54 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   170.19M
2 |  STL |        UMap Str(map)   |   336.25M
3 |  STL |       UMap Str(umap)   |   353.57M
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)    |   718.40 ms 
2 |  M*LIB |       UMap U64(dict)    |   904.83 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   905.65 ms 
4 |  KLIB |      UMap U64(khash)    |   1277.69 ms 
5 |  BOOST |  UMap U64(uflat_map)    |   1484.13 ms 
6 |  POTTERY |  UMap U64(open hash)    |   1960.59 ms 
7 |  VERSTABLE |             UMap U64    |   2238.34 ms 
8 |  CC |        UMap U64(map)    |   2910.11 ms 
9 |  STC |       UMap U64(hmap)    |   3262.09 ms 
10 |  TommyDS |       UMap U64(dict)    |   4842.26 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   5446.61 ms 
12 |  CMC |       UMap U64(hmap)    |   8550.85 ms 
13 |  GLIB | UMap U64(GHashTable)    |   9273.77 ms 
14 |  UT-HASH |       UMap U64(dict)    |   11235.94 ms 
15 |  STL |       UMap U64(umap)    |   11503.82 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.64M
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.31M
3 |  M*LIB |    UMap U64(dict OA)   |   556.53M
4 |  M*LIB |       UMap U64(dict)   |   590.03M
5 |  BOOST |  UMap U64(uflat_map)   |   805.56M
6 |  STC |       UMap U64(hmap)   |   906.15M
7 |  VERSTABLE |             UMap U64   |   906.21M
8 |  CC |        UMap U64(map)   |   906.21M
9 |  STL |       UMap U64(umap)   |   933.87M
10 |  CollectionC |  UMap U64(HashTable)   |   1.36G
11 |  POTTERY |  UMap U64(open hash)   |   1.71G
12 |  UT-HASH |       UMap U64(dict)   |   1.87G
13 |  GLIB | UMap U64(GHashTable)   |   1.95G
14 |  CMC |       UMap U64(hmap)   |   2.42G
15 |  TommyDS |       UMap U64(dict)   |   4.16G

STB-DS bench is not included due to an incorrect result being reported

# Performance test: unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)    |   1204.79 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1383.40 ms 
3 |  VERSTABLE |             UMap Big    |   1712.01 ms 
4 |  CC |        UMap Big(map)    |   1836.98 ms 
5 |  KLIB |      UMap Big(khash)    |   2070.25 ms 
6 |  TommyDS |       UMap Big(dict)    |   2096.83 ms 
7 |  M*LIB |    UMap Big(dict OA)    |   2118.61 ms 
8 |  POTTERY |  UMap Big(open hash)    |   2227.94 ms 
9 |  STC |       UMap Big(hmap)    |   2301.81 ms 
10 |  GLIB | UMap Big(GHashTable)    |   2838.30 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   3420.15 ms 
12 |  STL |       UMap Big(umap)    |   4251.10 ms 
13 |  UT-HASH |       UMap Big(dict)    |   4705.28 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)   |   1.61G
2 |  STL |       UMap Big(umap)   |   1.68G
3 |  GLIB | UMap Big(GHashTable)   |   1.72G
4 |  UT-HASH |       UMap Big(dict)   |   1.76G
5 |  CollectionC |  UMap Big(HashTable)   |   2.05G
6 |  KLIB |      UMap Big(khash)   |   2.15G
7 |  BOOST |  UMap Big(uflat_map)   |   3.03G
8 |  VERSTABLE |             UMap Big   |   3.23G
9 |  CC |        UMap Big(map)   |   3.23G
10 |  STC |       UMap Big(hmap)   |   3.26G
11 |  M*LIB |    UMap Big(dict OA)   |   4.56G
12 |  TommyDS |       UMap Big(dict)   |   5.09G
13 |  POTTERY |  UMap Big(open hash)   |   6.48G

# Performance test: unordered set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST | USet Longest(uflat_s    |   532.61 ms 
2 |  M*LIB | USet Longest(dict oa    |   795.03 ms 
3 |  M*LIB |   USet Longest(dict)    |   927.12 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   1103.18 ms 
5 |  CC |   USet Longest(hset)    |   1430.62 ms 
6 |  STC |   USet Longest(hset)    |   1738.69 ms 
7 |  CTL |   USet Longest(hset)    |   4754.98 ms 
8 |  STL | USet Longest(dict oa    |   6147.57 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   118.14M
2 |  BOOST | USet Longest(uflat_s   |   159.80M
3 |  VERSTABLE |   USet Longest(hset)   |   191.37M
4 |  CC |   USet Longest(hset)   |   191.37M
5 |  M*LIB |   USet Longest(dict)   |   216.39M
6 |  STC |   USet Longest(hset)   |   219.02M
7 |  STL | USet Longest(dict oa   |   457.03M
8 |  CTL |   USet Longest(hset)   |   480.60M


Model name:                              AMD EPYC 7763 64-Core Processor

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
* mlib : 332e5e0238e54e2b88f6462194f08851e5606777
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 28d546d5eb77d4585506a20480f4de2e706dff4c
* tommyds : 228535758bf6806f6ea1e1f3368a80860133acd1
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : 668362bb89b7ca00bc37a58a10d37cb811dbe6a9
