# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   798.18 ms 
2 |  XXHASH |      Hash (xxhash64)    |   886.18 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1283.54 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   30.62 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   69.73 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   164.13 ms 
4 |  M*LIB |          Queue(MPMC)    |   339.06 ms 
5 |  LIBLFDS |          Queue(MPMC)    |   591.78 ms 
6 |  M*LIB |     Queue(Buffer P2)    |   624.30 ms 
7 |  M*LIB |        Queue(Buffer)    |   1458.62 ms 
8 |  M*LIB |    Queue(Shared ptr)    |   1767.34 ms 
9 |  BOOST | Queue MPMC (lockfree    |   2706.04 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)   |   262.14K
2 |  M*LIB |       Queue(MPMC P2)   |   393.22K
3 |  M*LIB |       Queue(SPSC P2)   |   393.22K
4 |  M*LIB |        Queue(Buffer)   |   524.29K
5 |  BOOST | Queue MPMC (lockfree   |   524.29K
6 |  M*LIB |          Queue(MPMC)   |   524.29K
7 |  M*LIB |     Queue(Buffer P2)   |   524.29K
8 |  LIBLFDS |          Queue(MPMC)   |   655.36K
9 |  M*LIB |    Queue(Shared ptr)   |   6.21M

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  KLIB |           Seq(Array)    |   618.53 ms 
2 |  M*LIB |           Seq(Array)    |   621.32 ms 
3 |  CTL |           Seq(Array)    |   633.51 ms 
4 |  STC |           Seq(Array)    |   633.78 ms 
5 |  UT-HASH |           Seq(Array)    |   661.33 ms 
6 |  M*LIB |           Seq(Deque)    |   789.62 ms 
7 |  CTL |            Seq(List)    |   1072.96 ms 
8 |  POTTERY |            Seq(List)    |   1077.60 ms 
9 |  STC |            Seq(List)    |   1096.29 ms 
10 |  M*LIB |            Seq(List)    |   1103.35 ms 
11 |  UT-HASH |            Seq(List)    |   1107.87 ms 
12 |  M*LIB |          Seq(DPList)    |   1113.34 ms 
13 |  CC |            Seq(List)    |   1200.45 ms 
14 |  CollectionC |            Seq(List)    |   1220.90 ms 
15 |  STL |            Seq(List)    |   1220.95 ms 
16 |  STB-DS |        Seq(DynArray)    |   1228.81 ms 
17 |  TommyDS |           Seq(Array)    |   1232.42 ms 
18 |  GLIB |            Seq(List)    |   1232.96 ms 
19 |  TommyDS |            Seq(List)    |   1252.62 ms 
20 |  CMC |           Seq(Array)    |   1360.86 ms 
21 |  STL |           Seq(Array)    |   1475.04 ms 
22 |  STL |           Seq(Deque)    |   1553.72 ms 
23 |  CC |           Seq(Array)    |   1646.66 ms 
24 |  KLIB |            Seq(List)    |   1654.01 ms 
25 |  CollectionC |           Seq(Array)    |   2314.49 ms 
26 |  POTTERY |           Seq(Array)    |   2669.59 ms 
27 |  QLIBC |            Seq(List)    |   2671.00 ms 
28 |  GLIB |           Seq(Array)    |   2799.74 ms 
29 |  LIBSRT |           Seq(Array)    |   3845.51 ms 
30 |  QLIBC |           Seq(Array)    |   5178.98 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  CTL |            Seq(List)   |   1.28G
2 |  POTTERY |            Seq(List)   |   1.28G
3 |  STC |            Seq(List)   |   1.28G
4 |  M*LIB |            Seq(List)   |   1.28G
5 |  UT-HASH |            Seq(List)   |   1.28G
6 |  M*LIB |          Seq(DPList)   |   1.28G
7 |  CC |            Seq(List)   |   1.28G
8 |  CollectionC |            Seq(List)   |   1.28G
9 |  STL |            Seq(List)   |   1.28G
10 |  GLIB |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  STB-DS |        Seq(DynArray)   |   1.60G
13 |  CMC |           Seq(Array)   |   1.60G
14 |  CC |           Seq(Array)   |   1.60G
15 |  LIBSRT |           Seq(Array)   |   1.60G
16 |  QLIBC |           Seq(Array)   |   1.60G
17 |  KLIB |           Seq(Array)   |   1.60G
18 |  M*LIB |           Seq(Array)   |   1.60G
19 |  CTL |           Seq(Array)   |   1.60G
20 |  STC |           Seq(Array)   |   1.60G
21 |  UT-HASH |           Seq(Array)   |   1.60G
22 |  M*LIB |           Seq(Deque)   |   1.60G
23 |  STL |           Seq(Array)   |   1.61G
24 |  STL |           Seq(Deque)   |   1.68G
25 |  POTTERY |           Seq(Array)   |   1.70G
26 |  TommyDS |            Seq(List)   |   1.92G
27 |  TommyDS |           Seq(Array)   |   3.20G
28 |  QLIBC |            Seq(List)   |   3.20G
29 |  CollectionC |           Seq(Array)   |   3.22G
30 |  GLIB |           Seq(Array)   |   4.80G

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time
----|-------|---------|----
1 |  STL |                 Sort    |   915.90 ms 
2 |  STC |                 Sort    |   936.39 ms 
3 |  STL |          Stable Sort    |   1062.78 ms 
4 |  POTTERY |                 Sort    |   1086.91 ms 
5 |  M*LIB |          Stable Sort    |   1091.56 ms 
6 |  KLIB |                 Sort    |   1285.41 ms 
7 |  CTL |                 Sort    |   1410.58 ms 
8 |  M*LIB |                 Sort    |   1492.53 ms 
9 |  LIBSRT |                 Sort    |   1530.56 ms 
10 |  GLIB |                 Sort    |   1557.44 ms 
11 |  UT-HASH |                 Sort    |   1577.24 ms 
12 |  CollectionC |                 Sort    |   2882.31 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  STC |                 Sort   |   41.29M
2 |  KLIB |                 Sort   |   41.82M
3 |  CTL |                 Sort   |   41.82M
4 |  STL |                 Sort   |   68.40M
5 |  LIBSRT |                 Sort   |   79.72M
6 |  M*LIB |          Stable Sort   |   81.29M
7 |  M*LIB |                 Sort   |   81.29M
8 |  UT-HASH |                 Sort   |   82.08M
9 |  POTTERY |                 Sort   |   99.11M
10 |  STL |          Stable Sort   |   100.76M
11 |  GLIB |                 Sort   |   162.91M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   857.82 ms 
2 |  KLIB |          SSet(Btree)    |   1261.08 ms 
3 |  STC |           SSet(sset)    |   2732.38 ms 
4 |  M*LIB |         SSet(Rbtree)    |   2997.27 ms 
5 |  CTL |            SSet(set)    |   3238.64 ms 
6 |  STL |         SSet(Rbtree)    |   3493.42 ms 
7 |  CollectionC |      SSet(TreeTable)    |   3654.65 ms 
8 |  CMC |           SSet(tree)    |   3678.72 ms 
9 |  GLIB |          SSet(GTree)    |   3954.06 ms 
10 |  TommyDS |         SSet(Rbtree)    |   4041.32 ms 
11 |  QLIBC |         SSet(Rbtree)    |   5524.18 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.67M
2 |  STC |           SSet(sset)   |   49.57M
3 |  M*LIB |         SSet(B+tree)   |   55.84M
4 |  STL |         SSet(Rbtree)   |   95.94M
5 |  TommyDS |         SSet(Rbtree)   |   96.08M
6 |  M*LIB |         SSet(Rbtree)   |   96.21M
7 |  CTL |            SSet(set)   |   96.21M
8 |  CMC |           SSet(tree)   |   96.21M
9 |  CollectionC |      SSet(TreeTable)   |   128.19M
10 |  GLIB |          SSet(GTree)   |   160.04M
11 |  QLIBC |         SSet(Rbtree)   |   288.10M

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |        String Concat    |   469.73 ms 
2 |  STC |        String Concat    |   481.92 ms 
3 |  STL |        String Concat    |   678.56 ms 
4 |  POTTERY |        String Concat    |   1490.92 ms 
5 |  SDS |        String Concat    |   2018.38 ms 
6 |  BSTRLIB |        String Concat    |   2969.37 ms 
7 |  CTL |        String Concat    |   3607.57 ms 
8 |  GLIB |        String Concat    |   4972.91 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        String Concat   |   1.04G
2 |  STC |        String Concat   |   1.36G
3 |  STL |        String Concat   |   1.79G
4 |  SDS |        String Concat   |   2.00G
5 |  POTTERY |        String Concat   |   2.04G
6 |  BSTRLIB |        String Concat   |   3.28G
7 |  CTL |        String Concat   |   4.02G
8 |  GLIB |        String Concat   |   7.76G

# Performance test: string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace    |   429.66 ms 
2 |  STC |       String Replace    |   1310.95 ms 
3 |  STL |       String Replace    |   1897.37 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.14M
2 |  STC |       String Replace   |   382.32M
3 |  STL |       String Replace   |   414.91M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)    |   855.48 ms 
2 |  BOOST |  UMap Str(uflat_map)    |   1166.19 ms 
3 |  STL |       UMap Str(umap)    |   3188.04 ms 
4 |  STL |        UMap Str(map)    |   9160.94 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   169.12M
2 |  STL |        UMap Str(map)   |   336.07M
3 |  STL |       UMap Str(umap)   |   353.45M
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap U64(dict)    |   814.44 ms 
2 |  M*LIB | UMap U64 (dict Bulk)    |   847.72 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   923.91 ms 
4 |  BOOST |  UMap U64(uflat_map)    |   1277.97 ms 
5 |  KLIB |      UMap U64(khash)    |   1307.02 ms 
6 |  POTTERY |  UMap U64(open hash)    |   1873.70 ms 
7 |  VERSTABLE |             UMap U64    |   2374.47 ms 
8 |  CC |        UMap U64(map)    |   2641.19 ms 
9 |  STC |       UMap U64(hmap)    |   3505.62 ms 
10 |  TommyDS |       UMap U64(dict)    |   3736.16 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   3839.51 ms 
12 |  CMC |       UMap U64(hmap)    |   6500.93 ms 
13 |  GLIB | UMap U64(GHashTable)    |   6945.71 ms 
14 |  STL |       UMap U64(umap)    |   9634.75 ms 
15 |  UT-HASH |       UMap U64(dict)    |   10231.47 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.77M
2 |  M*LIB | UMap U64 (dict Bulk)   |   557.04M
3 |  M*LIB |    UMap U64(dict OA)   |   557.23M
4 |  M*LIB |       UMap U64(dict)   |   590.66M
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M
6 |  STC |       UMap U64(hmap)   |   906.28M
7 |  CC |        UMap U64(map)   |   906.34M
8 |  VERSTABLE |             UMap U64   |   906.35M
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
1 |  M*LIB |       UMap Big(dict)    |   1278.63 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1969.05 ms 
3 |  TommyDS |       UMap Big(dict)    |   2082.14 ms 
4 |  VERSTABLE |             UMap Big    |   2119.69 ms 
5 |  STC |       UMap Big(hmap)    |   2299.60 ms 
6 |  M*LIB |    UMap Big(dict OA)    |   2355.69 ms 
7 |  GLIB | UMap Big(GHashTable)    |   2512.22 ms 
8 |  CC |        UMap Big(map)    |   2551.65 ms 
9 |  POTTERY |  UMap Big(open hash)    |   2686.08 ms 
10 |  KLIB |      UMap Big(khash)    |   2762.00 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   3046.27 ms 
12 |  STL |       UMap Big(umap)    |   4354.76 ms 
13 |  UT-HASH |       UMap Big(dict)    |   4800.40 ms 

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
1 |  BOOST | USet Longest(uflat_s    |   470.25 ms 
2 |  M*LIB | USet Longest(dict oa    |   729.43 ms 
3 |  M*LIB |   USet Longest(dict)    |   798.82 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   1163.48 ms 
5 |  CC |   USet Longest(hset)    |   1274.87 ms 
6 |  STC |   USet Longest(hset)    |   1742.17 ms 
7 |  CTL |   USet Longest(hset)    |   3704.68 ms 
8 |  STL | USet Longest(dict oa    |   4991.24 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   117.01M
2 |  BOOST | USet Longest(uflat_s   |   159.79M
3 |  VERSTABLE |   USet Longest(hset)   |   191.37M
4 |  CC |   USet Longest(hset)   |   191.37M
5 |  M*LIB |   USet Longest(dict)   |   214.63M
6 |  STC |   USet Longest(hset)   |   219.15M
7 |  STL | USet Longest(dict oa   |   457.02M
8 |  CTL |   USet Longest(hset)   |   480.73M


Model name:                              Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 3d78b1db995b27b7964b88c5d0806e0c3f8a2105
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : 4c9157369d36d33722f479de3663368ab6ab1ea9
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : d0fd65a8695218ffabf2aa543ce51ca3af69536f
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* stb : 904aa67e1e2d1dec92959df63e700b166d5c1022
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 2031adfd8cd6f8f498e0f4a9055648b19496f12e
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
