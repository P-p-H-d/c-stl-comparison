# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   758.14 ms 
2 |  XXHASH |      Hash (xxhash64)    |   822.03 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1266.42 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   33.53 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   69.95 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   163.93 ms 
4 |  M*LIB |          Queue(MPMC)    |   319.74 ms 
5 |  M*LIB |     Queue(Buffer P2)    |   549.76 ms 
6 |  LIBLFDS |          Queue(MPMC)    |   713.12 ms 
7 |  M*LIB |        Queue(Buffer)    |   1477.68 ms 
8 |  M*LIB |    Queue(Shared ptr)    |   1743.54 ms 
9 |  BOOST | Queue MPMC (lockfree    |   2606.54 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       Queue(SPSC P2)   |   262.14K
2 |  M*LIB |       Queue(MPMC P2)   |   393.22K
3 |  M*LIB |     Queue(SPSC Bulk)   |   393.22K
4 |  M*LIB |        Queue(Buffer)   |   524.29K
5 |  BOOST | Queue MPMC (lockfree   |   524.29K
6 |  M*LIB |     Queue(Buffer P2)   |   524.29K
7 |  M*LIB |          Queue(MPMC)   |   528.38K
8 |  LIBLFDS |          Queue(MPMC)   |   655.36K
9 |  M*LIB |    Queue(Shared ptr)   |   2.36M

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)    |   620.15 ms 
2 |  KLIB |           Seq(Array)    |   623.86 ms 
3 |  STC |           Seq(Array)    |   629.25 ms 
4 |  CTL |           Seq(Array)    |   631.83 ms 
5 |  UT-HASH |           Seq(Array)    |   673.85 ms 
6 |  M*LIB |           Seq(Deque)    |   706.94 ms 
7 |  POTTERY |            Seq(List)    |   1050.32 ms 
8 |  UT-HASH |            Seq(List)    |   1061.08 ms 
9 |  CTL |            Seq(List)    |   1079.42 ms 
10 |  M*LIB |            Seq(List)    |   1097.94 ms 
11 |  STC |            Seq(List)    |   1101.26 ms 
12 |  M*LIB |          Seq(DPList)    |   1105.26 ms 
13 |  STL |            Seq(List)    |   1145.76 ms 
14 |  CC |            Seq(List)    |   1196.47 ms 
15 |  STB-DS |        Seq(DynArray)    |   1215.53 ms 
16 |  GLIB |            Seq(List)    |   1219.76 ms 
17 |  CollectionC |            Seq(List)    |   1224.46 ms 
18 |  TommyDS |            Seq(List)    |   1237.99 ms 
19 |  TommyDS |           Seq(Array)    |   1313.79 ms 
20 |  CMC |           Seq(Array)    |   1359.27 ms 
21 |  STL |           Seq(Array)    |   1459.07 ms 
22 |  STL |           Seq(Deque)    |   1546.90 ms 
23 |  KLIB |            Seq(List)    |   1578.78 ms 
24 |  CC |           Seq(Array)    |   1638.32 ms 
25 |  CollectionC |           Seq(Array)    |   2402.94 ms 
26 |  QLIBC |            Seq(List)    |   2552.71 ms 
27 |  POTTERY |           Seq(Array)    |   2671.66 ms 
28 |  GLIB |           Seq(Array)    |   2781.65 ms 
29 |  LIBSRT |           Seq(Array)    |   3899.33 ms 
30 |  QLIBC |           Seq(Array)    |   5165.99 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  POTTERY |            Seq(List)   |   1.28G
2 |  UT-HASH |            Seq(List)   |   1.28G
3 |  CTL |            Seq(List)   |   1.28G
4 |  M*LIB |            Seq(List)   |   1.28G
5 |  STC |            Seq(List)   |   1.28G
6 |  M*LIB |          Seq(DPList)   |   1.28G
7 |  STL |            Seq(List)   |   1.28G
8 |  CC |            Seq(List)   |   1.28G
9 |  GLIB |            Seq(List)   |   1.28G
10 |  CollectionC |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  STB-DS |        Seq(DynArray)   |   1.60G
13 |  CMC |           Seq(Array)   |   1.60G
14 |  CC |           Seq(Array)   |   1.60G
15 |  LIBSRT |           Seq(Array)   |   1.60G
16 |  QLIBC |           Seq(Array)   |   1.60G
17 |  M*LIB |           Seq(Array)   |   1.60G
18 |  KLIB |           Seq(Array)   |   1.60G
19 |  STC |           Seq(Array)   |   1.60G
20 |  CTL |           Seq(Array)   |   1.60G
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
1 |  STL |                 Sort    |   915.43 ms 
2 |  STC |                 Sort    |   934.17 ms 
3 |  STL |          Stable Sort    |   1056.21 ms 
4 |  M*LIB |          Stable Sort    |   1086.29 ms 
5 |  POTTERY |                 Sort    |   1098.23 ms 
6 |  KLIB |                 Sort    |   1288.97 ms 
7 |  CTL |                 Sort    |   1411.50 ms 
8 |  M*LIB |                 Sort    |   1490.82 ms 
9 |  LIBSRT |                 Sort    |   1531.22 ms 
10 |  UT-HASH |                 Sort    |   1554.49 ms 
11 |  GLIB |                 Sort    |   1570.12 ms 
12 |  CollectionC |                 Sort    |   2829.17 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |                 Sort   |   41.29M
2 |  CTL |                 Sort   |   42.10M
3 |  STC |                 Sort   |   42.33M
4 |  STL |                 Sort   |   67.35M
5 |  LIBSRT |                 Sort   |   79.57M
6 |  UT-HASH |                 Sort   |   81.29M
7 |  M*LIB |          Stable Sort   |   82.08M
8 |  M*LIB |                 Sort   |   82.33M
9 |  POTTERY |                 Sort   |   99.11M
10 |  STL |          Stable Sort   |   100.76M
11 |  GLIB |                 Sort   |   162.92M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   901.77 ms 
2 |  KLIB |          SSet(Btree)    |   1326.41 ms 
3 |  STC |           SSet(sset)    |   2824.22 ms 
4 |  M*LIB |         SSet(Rbtree)    |   3096.96 ms 
5 |  STL |         SSet(Rbtree)    |   3127.40 ms 
6 |  CTL |            SSet(set)    |   3205.78 ms 
7 |  CollectionC |      SSet(TreeTable)    |   3304.47 ms 
8 |  CMC |           SSet(tree)    |   3461.24 ms 
9 |  TommyDS |         SSet(Rbtree)    |   3955.38 ms 
10 |  GLIB |          SSet(GTree)    |   4259.28 ms 
11 |  QLIBC |         SSet(Rbtree)    |   5217.26 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.67M
2 |  STC |           SSet(sset)   |   49.57M
3 |  M*LIB |         SSet(B+tree)   |   55.86M
4 |  STL |         SSet(Rbtree)   |   96.08M
5 |  M*LIB |         SSet(Rbtree)   |   96.21M
6 |  CTL |            SSet(set)   |   96.21M
7 |  CMC |           SSet(tree)   |   96.21M
8 |  TommyDS |         SSet(Rbtree)   |   96.21M
9 |  CollectionC |      SSet(TreeTable)   |   128.19M
10 |  GLIB |          SSet(GTree)   |   160.04M
11 |  QLIBC |         SSet(Rbtree)   |   288.10M

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |        String Concat    |   469.63 ms 
2 |  STC |        String Concat    |   476.82 ms 
3 |  STL |        String Concat    |   657.62 ms 
4 |  POTTERY |        String Concat    |   1509.38 ms 
5 |  SDS |        String Concat    |   1956.18 ms 
6 |  BSTRLIB |        String Concat    |   2988.30 ms 
7 |  CTL |        String Concat    |   3617.57 ms 
8 |  GLIB |        String Concat    |   4870.68 ms 

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
1 |  M*LIB |       String Replace    |   418.07 ms 
2 |  STC |       String Replace    |   1303.26 ms 
3 |  STL |       String Replace    |   1798.23 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.31M
2 |  STC |       String Replace   |   382.31M
3 |  STL |       String Replace   |   414.91M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)    |   862.91 ms 
2 |  BOOST |  UMap Str(uflat_map)    |   1165.78 ms 
3 |  STL |       UMap Str(umap)    |   2751.93 ms 
4 |  STL |        UMap Str(map)    |   7858.02 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   169.12M
2 |  STL |        UMap Str(map)   |   336.07M
3 |  STL |       UMap Str(umap)   |   353.44M
4 |  BOOST |  UMap Str(uflat_map)   |   384.03M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap U64(dict)    |   814.93 ms 
2 |  M*LIB | UMap U64 (dict Bulk)    |   837.81 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   906.63 ms 
4 |  BOOST |  UMap U64(uflat_map)    |   1220.37 ms 
5 |  KLIB |      UMap U64(khash)    |   1317.77 ms 
6 |  POTTERY |  UMap U64(open hash)    |   1800.19 ms 
7 |  VERSTABLE |             UMap U64    |   2257.38 ms 
8 |  CC |        UMap U64(map)    |   2653.62 ms 
9 |  STC |       UMap U64(hmap)    |   3409.21 ms 
10 |  TommyDS |       UMap U64(dict)    |   3505.39 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   3655.79 ms 
12 |  CMC |       UMap U64(hmap)    |   6423.50 ms 
13 |  GLIB | UMap U64(GHashTable)    |   6970.35 ms 
14 |  STL |       UMap U64(umap)    |   9253.15 ms 
15 |  UT-HASH |       UMap U64(dict)    |   9858.88 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.77M
2 |  M*LIB | UMap U64 (dict Bulk)   |   556.70M
3 |  M*LIB |    UMap U64(dict OA)   |   557.54M
4 |  M*LIB |       UMap U64(dict)   |   590.03M
5 |  BOOST |  UMap U64(uflat_map)   |   805.55M
6 |  STC |       UMap U64(hmap)   |   906.27M
7 |  VERSTABLE |             UMap U64   |   906.34M
8 |  CC |        UMap U64(map)   |   906.34M
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
1 |  M*LIB |       UMap Big(dict)    |   1284.61 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1901.93 ms 
3 |  TommyDS |       UMap Big(dict)    |   1952.82 ms 
4 |  VERSTABLE |             UMap Big    |   2074.68 ms 
5 |  STC |       UMap Big(hmap)    |   2323.74 ms 
6 |  M*LIB |    UMap Big(dict OA)    |   2380.02 ms 
7 |  GLIB | UMap Big(GHashTable)    |   2554.20 ms 
8 |  CC |        UMap Big(map)    |   2606.83 ms 
9 |  POTTERY |  UMap Big(open hash)    |   2667.90 ms 
10 |  KLIB |      UMap Big(khash)    |   2696.86 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   2893.65 ms 
12 |  STL |       UMap Big(umap)    |   4051.48 ms 
13 |  UT-HASH |       UMap Big(dict)    |   4624.44 ms 

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
1 |  BOOST | USet Longest(uflat_s    |   417.89 ms 
2 |  M*LIB | USet Longest(dict oa    |   711.10 ms 
3 |  M*LIB |   USet Longest(dict)    |   802.04 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   1098.61 ms 
5 |  CC |   USet Longest(hset)    |   1272.23 ms 
6 |  STC |   USet Longest(hset)    |   1801.20 ms 
7 |  CTL |   USet Longest(hset)    |   3569.90 ms 
8 |  STL | USet Longest(dict oa    |   4748.72 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   119.87M
2 |  BOOST | USet Longest(uflat_s   |   159.79M
3 |  VERSTABLE |   USet Longest(hset)   |   191.37M
4 |  CC |   USet Longest(hset)   |   191.37M
5 |  M*LIB |   USet Longest(dict)   |   214.63M
6 |  STC |   USet Longest(hset)   |   219.15M
7 |  STL | USet Longest(dict oa   |   457.03M
8 |  CTL |   USet Longest(hset)   |   480.73M


Model name:                              Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz

* C-Macro-Collections : a7ee017bcd288e0a1521cba5d8aaf83a07a01b58
* CC : 2d62942eb2369b5387e0c4f2aa06f052004d16e0
* Collections-C : 3920f28431ecf82c9e7e78bbcb60fe473d87edf9
* STC : 64fa82de77dd5494abd1adfe4f00d64d60b51188
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
* stb : e6cd9561ea6dae43d41633797745789d142b691e
* tommyds : 1f3727fc89174902c48e3933ac4610cb7fb13f4a
* uthash : 2031adfd8cd6f8f498e0f4a9055648b19496f12e
* xxHash : 82cead715cbfddd9e6093db8df95155077ce6e64
