# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)   |   707.06 ms 
2 |  XXHASH |      Hash (xxhash64)   |   971.62 ms 
3 |  M*LIB |        Hash (M_HASH)   |   1411.31 ms 

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       Queue(MPMC P2)   |   39.08 ms 
2 |  M*LIB |       Queue(SPSC P2)   |   57.62 ms 
3 |  M*LIB |     Queue(SPSC Bulk)   |   58.14 ms 
4 |  M*LIB |          Queue(MPMC)   |   82.67 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   489.45 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   775.62 ms 
7 |  M*LIB |    Queue(Shared ptr)   |   1159.82 ms 
8 |  M*LIB |        Queue(Buffer)   |   1672.78 ms 
9 |  BOOST | Queue MPMC (lockfree   |   2108.21 ms 

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)   |   807.55 ms 
2 |  CTL |           Seq(Array)   |   828.34 ms 
3 |  KLIB |           Seq(Array)   |   834.01 ms 
4 |  STC |           Seq(Array)   |   835.30 ms 
5 |  UT-HASH |           Seq(Array)   |   872.94 ms 
6 |  M*LIB |          Seq(DPList)   |   969.61 ms 
7 |  POTTERY |            Seq(List)   |   977.68 ms 
8 |  CTL |            Seq(List)   |   980.76 ms 
9 |  UT-HASH |            Seq(List)   |   986.37 ms 
10 |  M*LIB |            Seq(List)   |   988.48 ms 
11 |  CollectionC |            Seq(List)   |   1000.34 ms 
12 |  STC |            Seq(List)   |   1000.62 ms 
13 |  M*LIB |           Seq(Deque)   |   1032.42 ms 
14 |  CC |            Seq(List)   |   1054.45 ms 
15 |  TommyDS |            Seq(List)   |   1068.63 ms 
16 |  GLIB |            Seq(List)   |   1119.01 ms 
17 |  KLIB |            Seq(List)   |   1207.37 ms 
18 |  STL |            Seq(List)   |   1226.84 ms 
19 |  CMC |           Seq(Array)   |   1825.71 ms 
20 |  TommyDS |           Seq(Array)   |   1833.79 ms 
21 |  STL |           Seq(Array)   |   1836.64 ms 
22 |  STL |           Seq(Deque)   |   2041.68 ms 
23 |  CC |           Seq(Array)   |   2087.06 ms 
24 |  CollectionC |           Seq(Array)   |   2499.57 ms 
25 |  QLIBC |            Seq(List)   |   2598.75 ms 
26 |  POTTERY |           Seq(Array)   |   2724.91 ms 
27 |  GLIB |           Seq(Array)   |   3337.35 ms 
28 |  LIBSRT |           Seq(Array)   |   4583.50 ms 
29 |  QLIBC |           Seq(Array)   |   6342.63 ms 

Note: Performance test: Array based containers works on dataset 10x bigger than size of List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |                 Sort   |   1210.87 ms 
2 |  STL |                 Sort   |   1228.93 ms 
3 |  POTTERY |                 Sort   |   1326.02 ms 
4 |  STL |          Stable Sort   |   1411.62 ms 
5 |  M*LIB |          Stable Sort   |   1467.68 ms 
6 |  CTL |                 Sort   |   1665.35 ms 
7 |  KLIB |                 Sort   |   1805.36 ms 
8 |  LIBSRT |                 Sort   |   1829.36 ms 
9 |  M*LIB |                 Sort   |   1858.63 ms 
10 |  UT-HASH |                 Sort   |   1889.15 ms 
11 |  GLIB |                 Sort   |   1957.51 ms 
12 |  CollectionC |                 Sort   |   3191.76 ms 

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)   |   817.76 ms 
2 |  KLIB |          SSet(Btree)   |   1033.56 ms 
3 |  STC |           SSet(sset)   |   2253.48 ms 
4 |  M*LIB |         SSet(Rbtree)   |   2522.57 ms 
5 |  STL |         SSet(Rbtree)   |   2604.51 ms 
6 |  CTL |            SSet(set)   |   2953.72 ms 
7 |  CMC |           SSet(tree)   |   3068.65 ms 
8 |  CollectionC |      SSet(TreeTable)   |   3192.94 ms 
9 |  TommyDS |         SSet(Rbtree)   |   3324.50 ms 
10 |  GLIB |          SSet(GTree)   |   3671.41 ms 
11 |  QLIBC |         SSet(Rbtree)   |   4767.66 ms 

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |        String Concat   |   379.00 ms 
2 |  M*LIB |        String Concat   |   531.32 ms 
3 |  STL |        String Concat   |   617.88 ms 
4 |  POTTERY |        String Concat   |   1661.37 ms 
5 |  SDS |        String Concat   |   2487.97 ms 
6 |  BSTRLIB |        String Concat   |   3412.52 ms 
7 |  CTL |        String Concat   |   3934.41 ms 
8 |  GLIB |        String Concat   |   4162.56 ms 

# Performance test: string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace   |   499.70 ms 
2 |  STL |       String Replace   |   1068.09 ms 
3 |  STC |       String Replace   |   1414.62 ms 

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   838.79 ms 
2 |  BOOST |  UMap Str(uflat_map)   |   985.05 ms 
3 |  STL |       UMap Str(umap)   |   3057.88 ms 
4 |  STL |        UMap Str(map)   |   7682.88 ms 

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)   |   855.00 ms 
2 |  M*LIB |       UMap U64(dict)   |   870.77 ms 
3 |  M*LIB |    UMap U64(dict OA)   |   955.29 ms 
4 |  KLIB |      UMap U64(khash)   |   1250.78 ms 
5 |  BOOST |  UMap U64(uflat_map)   |   1315.02 ms 
6 |  POTTERY |  UMap U64(open hash)   |   1909.32 ms 
7 |  VERSTABLE |             UMap U64   |   2222.55 ms 
8 |  CC |        UMap U64(map)   |   2928.16 ms 
9 |  STC |       UMap U64(hmap)   |   3719.78 ms 
10 |  TommyDS |       UMap U64(dict)   |   3852.99 ms 
11 |  CollectionC |  UMap U64(HashTable)   |   4222.99 ms 
12 |  CMC |       UMap U64(hmap)   |   6893.32 ms 
13 |  GLIB | UMap U64(GHashTable)   |   8120.99 ms 
14 |  STL |       UMap U64(umap)   |   9920.40 ms 
15 |  UT-HASH |       UMap U64(dict)   |   11719.22 ms 

# Performance test: unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)   |   1155.69 ms 
2 |  BOOST |  UMap Big(uflat_map)   |   1576.60 ms 
3 |  VERSTABLE |             UMap Big   |   1919.38 ms 
4 |  CC |        UMap Big(map)   |   1965.38 ms 
5 |  TommyDS |       UMap Big(dict)   |   2296.05 ms 
6 |  M*LIB |    UMap Big(dict OA)   |   2301.90 ms 
7 |  KLIB |      UMap Big(khash)   |   2361.94 ms 
8 |  POTTERY |  UMap Big(open hash)   |   2424.00 ms 
9 |  STC |       UMap Big(hmap)   |   2451.36 ms 
10 |  GLIB | UMap Big(GHashTable)   |   2602.26 ms 
11 |  CollectionC |  UMap Big(HashTable)   |   3544.03 ms 
12 |  STL |       UMap Big(umap)   |   4279.98 ms 
13 |  UT-HASH |       UMap Big(dict)   |   4915.85 ms 

# Performance test: unordered set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST | USet Longest(uflat_s   |   464.03 ms 
2 |  M*LIB | USet Longest(dict oa   |   825.03 ms 
3 |  M*LIB |   USet Longest(dict)   |   921.95 ms 
4 |  VERSTABLE |   USet Longest(hset)   |   1015.53 ms 
5 |  CC |   USet Longest(hset)   |   1322.93 ms 
6 |  STC |   USet Longest(hset)   |   1455.77 ms 
7 |  CTL |   USet Longest(hset)   |   3945.72 ms 
8 |  STL | USet Longest(dict oa   |   5241.47 ms 


Model name:                              AMD EPYC 9V74 80-Core Processor

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
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 2031adfd8cd6f8f498e0f4a9055648b19496f12e
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
