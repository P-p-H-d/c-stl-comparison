# Bench for best hash

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)   |   674.57 ms 
2 |  XXHASH |      Hash (xxhash64)   |   700.12 ms 
3 |  M*LIB |        Hash (M_HASH)   |   1317.08 ms 

# Bench for best thread queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)   |   51.35 ms 
2 |  M*LIB |       Queue(SPSC P2)   |   62.72 ms 
3 |  M*LIB |       Queue(MPMC P2)   |   127.76 ms 
4 |  M*LIB |          Queue(MPMC)   |   208.93 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   540.70 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   792.34 ms 
7 |  BOOST | Queue MPMC (lockfree   |   1446.72 ms 
8 |  M*LIB |        Queue(Buffer)   |   2017.28 ms 
9 |  M*LIB |    Queue(Shared ptr)   |   3537.95 ms 

# Bench for best sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)   |   667.78 ms 
2 |  STC |           Seq(Array)   |   671.82 ms 
3 |  KLIB |           Seq(Array)   |   675.38 ms 
4 |  CTL |           Seq(Array)   |   687.01 ms 
5 |  UT-HASH |           Seq(Array)   |   755.43 ms 
6 |  M*LIB |           Seq(Deque)   |   927.37 ms 
7 |  GLIB |            Seq(List)   |   1372.34 ms 
8 |  UT-HASH |            Seq(List)   |   1450.00 ms 
9 |  CTL |            Seq(List)   |   1457.99 ms 
10 |  M*LIB |          Seq(DPList)   |   1467.02 ms 
11 |  M*LIB |            Seq(List)   |   1469.24 ms 
12 |  STC |            Seq(List)   |   1472.30 ms 
13 |  POTTERY |            Seq(List)   |   1479.61 ms 
14 |  CollectionC |            Seq(List)   |   1574.13 ms 
15 |  STL |           Seq(Array)   |   1634.37 ms 
16 |  CC |            Seq(List)   |   1649.22 ms 
17 |  STL |            Seq(List)   |   1704.38 ms 
18 |  TommyDS |            Seq(List)   |   1788.11 ms 
19 |  CMC |           Seq(Array)   |   1794.42 ms 
20 |  STL |           Seq(Deque)   |   1850.95 ms 
21 |  TommyDS |           Seq(Array)   |   1931.39 ms 
22 |  KLIB |            Seq(List)   |   2244.78 ms 
23 |  CC |           Seq(Array)   |   2414.27 ms 
24 |  CollectionC |           Seq(Array)   |   2877.40 ms 
25 |  POTTERY |           Seq(Array)   |   3908.70 ms 
26 |  QLIBC |            Seq(List)   |   4077.96 ms 
27 |  LIBSRT |           Seq(Array)   |   6060.99 ms 
28 |  GLIB |           Seq(Array)   |   7278.17 ms 
29 |  QLIBC |           Seq(Array)   |   7932.05 ms 

Note: Bench for Array based containers works on dataset 10x bigger than size of List based containers.

# Bench for best sort container

Rank|Library|Container|Time
----|-------|---------|----
1 |  STL |                 Sort   |   912.17 ms 
2 |  STC |                 Sort   |   996.43 ms 
3 |  M*LIB |          Stable Sort   |   1165.46 ms 
4 |  POTTERY |                 Sort   |   1169.87 ms 
5 |  STL |          Stable Sort   |   1188.42 ms 
6 |  KLIB |                 Sort   |   1348.08 ms 
7 |  LIBSRT |                 Sort   |   1629.22 ms 
8 |  CTL |                 Sort   |   1638.06 ms 
9 |  M*LIB |                 Sort   |   1661.97 ms 
10 |  UT-HASH |                 Sort   |   1679.28 ms 
11 |  GLIB |                 Sort   |   1844.17 ms 
12 |  CollectionC |                 Sort   |   3937.01 ms 

# Bench for best sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)   |   1185.14 ms 
2 |  KLIB |          SSet(Btree)   |   1743.59 ms 
3 |  STC |           SSet(sset)   |   3340.36 ms 
4 |  M*LIB |         SSet(Rbtree)   |   3344.11 ms 
5 |  STL |         SSet(Rbtree)   |   3579.44 ms 
6 |  CTL |            SSet(set)   |   3603.23 ms 
7 |  CollectionC |      SSet(TreeTable)   |   3685.36 ms 
8 |  CMC |           SSet(tree)   |   3930.71 ms 
9 |  TommyDS |         SSet(Rbtree)   |   4081.29 ms 
10 |  GLIB |          SSet(GTree)   |   5222.53 ms 
11 |  QLIBC |         SSet(Rbtree)   |   5685.38 ms 

# Bench for best string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |        String Concat   |   526.06 ms 
2 |  STC |        String Concat   |   672.44 ms 
3 |  STL |        String Concat   |   929.86 ms 
4 |  POTTERY |        String Concat   |   2328.72 ms 
5 |  SDS |        String Concat   |   3945.38 ms 
6 |  CTL |        String Concat   |   5737.93 ms 
7 |  BSTRLIB |        String Concat   |   5928.81 ms 
8 |  GLIB |        String Concat   |   6556.66 ms 

# Bench for best string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace   |   723.12 ms 
2 |  STC |       String Replace   |   2583.78 ms 
3 |  STL |       String Replace   |   3015.28 ms 
4 |  BSTRLIB |       String Replace   |   3205.98 ms 

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Bench for best unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST |  UMap Str(uflat_map)   |   1038.50 ms 
2 |  M*LIB |       UMap Str(dict)   |   1067.73 ms 
3 |  STL |       UMap Str(umap)   |   3049.62 ms 
4 |  STL |        UMap Str(map)   |   8089.04 ms 

# Bench for best unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)   |   972.69 ms 
2 |  M*LIB |       UMap U64(dict)   |   1062.79 ms 
3 |  M*LIB |    UMap U64(dict OA)   |   1222.98 ms 
4 |  BOOST |  UMap U64(uflat_map)   |   1886.52 ms 
5 |  KLIB |      UMap U64(khash)   |   2179.46 ms 
6 |  POTTERY |  UMap U64(open hash)   |   2750.87 ms 
7 |  CC |        UMap U64(map)   |   2991.51 ms 
8 |  VERSTABLE |             UMap U64   |   3002.97 ms 
9 |  STC |       UMap U64(hmap)   |   3223.65 ms 
10 |  TommyDS |       UMap U64(dict)   |   6376.36 ms 
11 |  CollectionC |  UMap U64(HashTable)   |   10004.82 ms 
12 |  GLIB | UMap U64(GHashTable)   |   10034.69 ms 
13 |  STL |       UMap U64(umap)   |   13496.43 ms 
14 |  CMC |       UMap U64(hmap)   |   14338.24 ms 
15 |  UT-HASH |       UMap U64(dict)   |   15649.82 ms 

# Bench for best unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST |  UMap Big(uflat_map)   |   1761.61 ms 
2 |  M*LIB |       UMap Big(dict)   |   1766.24 ms 
3 |  CC |        UMap Big(map)   |   2401.44 ms 
4 |  VERSTABLE |             UMap Big   |   2406.98 ms 
5 |  M*LIB |    UMap Big(dict OA)   |   2715.63 ms 
6 |  TommyDS |       UMap Big(dict)   |   2908.24 ms 
7 |  STC |       UMap Big(hmap)   |   2932.53 ms 
8 |  KLIB |      UMap Big(khash)   |   3044.01 ms 
9 |  POTTERY |  UMap Big(open hash)   |   3157.21 ms 
10 |  GLIB | UMap Big(GHashTable)   |   3930.90 ms 
11 |  CollectionC |  UMap Big(HashTable)   |   4336.22 ms 
12 |  STL |       UMap Big(umap)   |   5386.81 ms 
13 |  UT-HASH |       UMap Big(dict)   |   5990.57 ms 

# Bench for best unordered set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST | USet Longest(uflat_s   |   911.79 ms 
2 |  M*LIB | USet Longest(dict oa   |   1109.96 ms 
3 |  M*LIB |   USet Longest(dict)   |   1221.61 ms 
4 |  CC |   USet Longest(hset)   |   1582.24 ms 
5 |  VERSTABLE |   USet Longest(hset)   |   1592.06 ms 
6 |  STC |   USet Longest(hset)   |   1894.98 ms 
7 |  STL | USet Longest(dict oa   |   8081.03 ms 
8 |  CTL |   USet Longest(hset)   |   8569.71 ms 


Model name:                              Intel(R) Core(TM) i5-3210M CPU @ 2.50GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 074fbcd92b9e4b72a6ccb20bf91871fb5a02a52e
* Verstable : dd83033fb72736a1d2332e43b84b7794b5d19635
* bstrlib : f0ff1e808102a42cdc7204a4bb6fe231a24c4546
* ctl : f224bdc7361dc8342171e99032e4a1657f8fb02a
* klib : 97a0fcb790b43b9e5da8994f4671021fec036f19
* libdynamic : da348d4234608a1aa3d699f0e16f656d66709fff
* liblfds7.1.1 : d28d20e4750aa9e5b678639b2bb9d5b67a360819
* libsrt : eee28e6dfc23f76c7b8f76f32ef68418619064be
* mlib : e3ae4b514511d7d7f45e2975a742c32e4799b57d
* nedtries : c370fef72146abec435ec805a56f37b912a65774
* pottery : 741bf5fa1ef348c43a86e79322545dc7d6320007
* qlibc : f45c021c59b33bac8eb73510531d0ca743e6f103
* rapidjson : 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
* sds : 5347739b1581fcba74fd5cab1fc21d2aef317d71
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 2031adfd8cd6f8f498e0f4a9055648b19496f12e
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
