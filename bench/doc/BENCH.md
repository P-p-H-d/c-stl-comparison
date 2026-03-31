# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   642.52 ms 
2 |  XXHASH |      Hash (xxhash64)    |   865.85 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1251.93 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   30.72 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   45.14 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   50.53 ms 
4 |  M*LIB |          Queue(MPMC)    |   76.47 ms 
5 |  LIBLFDS |          Queue(MPMC)    |   454.39 ms 
6 |  M*LIB |     Queue(Buffer P2)    |   817.57 ms 
7 |  M*LIB |    Queue(Shared ptr)    |   1159.95 ms 
8 |  M*LIB |        Queue(Buffer)    |   1356.33 ms 
9 |  BOOST | Queue MPMC (lockfree    |   1901.14 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  BOOST | Queue MPMC (lockfree   |   393.22K
2 |  M*LIB |     Queue(SPSC Bulk)   |   397.31K
3 |  M*LIB |       Queue(SPSC P2)   |   397.31K
4 |  M*LIB |       Queue(MPMC P2)   |   397.31K
5 |  M*LIB |    Queue(Shared ptr)   |   528.38K
6 |  M*LIB |        Queue(Buffer)   |   528.38K
7 |  LIBLFDS |          Queue(MPMC)   |   528.38K
8 |  M*LIB |          Queue(MPMC)   |   528.38K
9 |  M*LIB |     Queue(Buffer P2)   |   528.38K

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  KLIB |           Seq(Array)    |   648.93 ms 
2 |  UT-HASH |           Seq(Array)    |   656.68 ms 
3 |  M*LIB |           Seq(Array)    |   722.99 ms 
4 |  STC |           Seq(Array)    |   727.12 ms 
5 |  CTL |           Seq(Array)    |   740.20 ms 
6 |  M*LIB |           Seq(Deque)    |   878.16 ms 
7 |  CTL |            Seq(List)    |   923.39 ms 
8 |  UT-HASH |            Seq(List)    |   924.30 ms 
9 |  M*LIB |          Seq(DPList)    |   956.85 ms 
10 |  STC |            Seq(List)    |   959.44 ms 
11 |  POTTERY |            Seq(List)    |   977.57 ms 
12 |  M*LIB |            Seq(List)    |   979.68 ms 
13 |  TommyDS |            Seq(List)    |   1021.85 ms 
14 |  CC |            Seq(List)    |   1031.84 ms 
15 |  GLIB |            Seq(List)    |   1119.07 ms 
16 |  CollectionC |            Seq(List)    |   1144.25 ms 
17 |  STL |            Seq(List)    |   1168.20 ms 
18 |  KLIB |            Seq(List)    |   1334.67 ms 
19 |  STB-DS |        Seq(DynArray)    |   1476.86 ms 
20 |  STL |           Seq(Array)    |   1603.29 ms 
21 |  CMC |           Seq(Array)    |   1622.83 ms 
22 |  STL |           Seq(Deque)    |   1787.62 ms 
23 |  CC |           Seq(Array)    |   2054.39 ms 
24 |  CollectionC |           Seq(Array)    |   2153.87 ms 
25 |  QLIBC |            Seq(List)    |   2556.72 ms 
26 |  TommyDS |           Seq(Array)    |   2768.12 ms 
27 |  POTTERY |           Seq(Array)    |   2960.66 ms 
28 |  GLIB |           Seq(Array)    |   3266.88 ms 
29 |  LIBSRT |           Seq(Array)    |   4347.28 ms 
30 |  QLIBC |           Seq(Array)    |   6556.36 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  CC |            Seq(List)   |   1.28G
2 |  GLIB |            Seq(List)   |   1.28G
3 |  CollectionC |            Seq(List)   |   1.28G
4 |  STL |            Seq(List)   |   1.28G
5 |  CTL |            Seq(List)   |   1.28G
6 |  UT-HASH |            Seq(List)   |   1.28G
7 |  M*LIB |          Seq(DPList)   |   1.28G
8 |  STC |            Seq(List)   |   1.28G
9 |  POTTERY |            Seq(List)   |   1.28G
10 |  M*LIB |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  STB-DS |        Seq(DynArray)   |   1.60G
13 |  CMC |           Seq(Array)   |   1.60G
14 |  CC |           Seq(Array)   |   1.60G
15 |  LIBSRT |           Seq(Array)   |   1.60G
16 |  KLIB |           Seq(Array)   |   1.60G
17 |  QLIBC |           Seq(Array)   |   1.60G
18 |  UT-HASH |           Seq(Array)   |   1.60G
19 |  M*LIB |           Seq(Array)   |   1.60G
20 |  STC |           Seq(Array)   |   1.60G
21 |  CTL |           Seq(Array)   |   1.60G
22 |  M*LIB |           Seq(Deque)   |   1.60G
23 |  STL |           Seq(Array)   |   1.61G
24 |  STL |           Seq(Deque)   |   1.68G
25 |  POTTERY |           Seq(Array)   |   1.70G
26 |  TommyDS |            Seq(List)   |   1.92G
27 |  QLIBC |            Seq(List)   |   3.20G
28 |  TommyDS |           Seq(Array)   |   3.20G
29 |  CollectionC |           Seq(Array)   |   3.22G
30 |  GLIB |           Seq(Array)   |   4.80G

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |                 Sort    |   1040.15 ms 
2 |  STL |                 Sort    |   1108.95 ms 
3 |  POTTERY |                 Sort    |   1156.74 ms 
4 |  STL |          Stable Sort    |   1283.62 ms 
5 |  M*LIB |          Stable Sort    |   1314.77 ms 
6 |  CTL |                 Sort    |   1497.86 ms 
7 |  KLIB |                 Sort    |   1577.74 ms 
8 |  LIBSRT |                 Sort    |   1662.45 ms 
9 |  M*LIB |                 Sort    |   1670.00 ms 
10 |  UT-HASH |                 Sort    |   1692.00 ms 
11 |  GLIB |                 Sort    |   1753.88 ms 
12 |  CollectionC |                 Sort    |   2900.14 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |                 Sort   |   41.68M
2 |  STC |                 Sort   |   41.82M
3 |  CTL |                 Sort   |   42.20M
4 |  STL |                 Sort   |   67.35M
5 |  LIBSRT |                 Sort   |   79.10M
6 |  M*LIB |          Stable Sort   |   81.16M
7 |  M*LIB |                 Sort   |   81.16M
8 |  UT-HASH |                 Sort   |   81.69M
9 |  POTTERY |                 Sort   |   98.98M
10 |  STL |          Stable Sort   |   100.76M
11 |  GLIB |                 Sort   |   163.58M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   727.91 ms 
2 |  KLIB |          SSet(Btree)    |   919.17 ms 
3 |  STC |           SSet(sset)    |   2025.80 ms 
4 |  M*LIB |         SSet(Rbtree)    |   2239.71 ms 
5 |  CTL |            SSet(set)    |   2420.23 ms 
6 |  STL |         SSet(Rbtree)    |   2510.94 ms 
7 |  CMC |           SSet(tree)    |   2626.67 ms 
8 |  CollectionC |      SSet(TreeTable)    |   2714.76 ms 
9 |  TommyDS |         SSet(Rbtree)    |   2868.18 ms 
10 |  GLIB |          SSet(GTree)    |   3274.46 ms 
11 |  QLIBC |         SSet(Rbtree)    |   4115.09 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.67M
2 |  STC |           SSet(sset)   |   49.73M
3 |  M*LIB |         SSet(B+tree)   |   55.73M
4 |  M*LIB |         SSet(Rbtree)   |   96.08M
5 |  CTL |            SSet(set)   |   96.08M
6 |  STL |         SSet(Rbtree)   |   96.08M
7 |  CMC |           SSet(tree)   |   96.08M
8 |  TommyDS |         SSet(Rbtree)   |   96.08M
9 |  CollectionC |      SSet(TreeTable)   |   128.06M
10 |  GLIB |          SSet(GTree)   |   160.04M
11 |  QLIBC |         SSet(Rbtree)   |   288.23M

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |        String Concat    |   392.53 ms 
2 |  M*LIB |        String Concat    |   547.37 ms 
3 |  STL |        String Concat    |   616.69 ms 
4 |  POTTERY |        String Concat    |   1564.45 ms 
5 |  SDS |        String Concat    |   2412.60 ms 
6 |  BSTRLIB |        String Concat    |   3304.67 ms 
7 |  CTL |        String Concat    |   3844.07 ms 
8 |  GLIB |        String Concat    |   4134.47 ms 

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
1 |  M*LIB |       String Replace    |   495.63 ms 
2 |  STL |       String Replace    |   1294.68 ms 
3 |  STC |       String Replace    |   1512.80 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.01M
2 |  STC |       String Replace   |   382.60M
3 |  STL |       String Replace   |   415.09M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)    |   735.05 ms 
2 |  BOOST |  UMap Str(uflat_map)    |   784.01 ms 
3 |  STL |       UMap Str(umap)    |   2585.87 ms 
4 |  STL |        UMap Str(map)    |   6943.99 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   168.99M
2 |  STL |        UMap Str(map)   |   336.25M
3 |  STL |       UMap Str(umap)   |   353.63M
4 |  BOOST |  UMap Str(uflat_map)   |   384.20M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)    |   691.68 ms 
2 |  M*LIB |       UMap U64(dict)    |   839.18 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   861.10 ms 
4 |  KLIB |      UMap U64(khash)    |   1196.06 ms 
5 |  BOOST |  UMap U64(uflat_map)    |   1333.38 ms 
6 |  POTTERY |  UMap U64(open hash)    |   1837.04 ms 
7 |  VERSTABLE |             UMap U64    |   2064.89 ms 
8 |  CC |        UMap U64(map)    |   2625.27 ms 
9 |  STC |       UMap U64(hmap)    |   2969.42 ms 
10 |  TommyDS |       UMap U64(dict)    |   4437.69 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   4907.79 ms 
12 |  CMC |       UMap U64(hmap)    |   7973.71 ms 
13 |  GLIB | UMap U64(GHashTable)    |   8439.33 ms 
14 |  UT-HASH |       UMap U64(dict)    |   10171.90 ms 
15 |  STL |       UMap U64(umap)    |   10324.07 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.77M
2 |  M*LIB |    UMap U64(dict OA)   |   557.46M
3 |  M*LIB | UMap U64 (dict Bulk)   |   557.75M
4 |  M*LIB |       UMap U64(dict)   |   589.75M
5 |  BOOST |  UMap U64(uflat_map)   |   805.56M
6 |  STC |       UMap U64(hmap)   |   906.13M
7 |  CC |        UMap U64(map)   |   906.21M
8 |  VERSTABLE |             UMap U64   |   906.34M
9 |  STL |       UMap U64(umap)   |   933.81M
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
1 |  M*LIB |       UMap Big(dict)    |   991.41 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1239.66 ms 
3 |  VERSTABLE |             UMap Big    |   1559.71 ms 
4 |  CC |        UMap Big(map)    |   1569.44 ms 
5 |  TommyDS |       UMap Big(dict)    |   1822.93 ms 
6 |  M*LIB |    UMap Big(dict OA)    |   1896.02 ms 
7 |  KLIB |      UMap Big(khash)    |   1910.40 ms 
8 |  STC |       UMap Big(hmap)    |   2024.68 ms 
9 |  POTTERY |  UMap Big(open hash)    |   2042.03 ms 
10 |  GLIB | UMap Big(GHashTable)    |   2404.08 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   2872.44 ms 
12 |  STL |       UMap Big(umap)    |   3635.03 ms 
13 |  UT-HASH |       UMap Big(dict)    |   4033.99 ms 

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
1 |  BOOST | USet Longest(uflat_s    |   437.85 ms 
2 |  M*LIB | USet Longest(dict oa    |   736.88 ms 
3 |  M*LIB |   USet Longest(dict)    |   887.54 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   935.96 ms 
5 |  CC |   USet Longest(hset)    |   1218.42 ms 
6 |  STC |   USet Longest(hset)    |   1294.80 ms 
7 |  CTL |   USet Longest(hset)    |   4276.34 ms 
8 |  STL | USet Longest(dict oa    |   5448.47 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   117.06M
2 |  BOOST | USet Longest(uflat_s   |   159.79M
3 |  CC |   USet Longest(hset)   |   191.23M
4 |  VERSTABLE |   USet Longest(hset)   |   191.23M
5 |  M*LIB |   USet Longest(dict)   |   216.49M
6 |  STC |   USet Longest(hset)   |   219.02M
7 |  STL | USet Longest(dict oa   |   457.03M
8 |  CTL |   USet Longest(hset)   |   480.60M


Model name:                              AMD EPYC 7763 64-Core Processor

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : d4f8be5a58557c6d66e865b60ce746dab5f6af06
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : 479ea00b0b7540b8b88cfd1b6d36ee8042994d6a
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 28d546d5eb77d4585506a20480f4de2e706dff4c
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 6d8573997c21f24c7e4ec9e48734b44f384170a1
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
