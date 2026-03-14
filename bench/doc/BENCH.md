# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   734.76 ms 
2 |  XXHASH |      Hash (xxhash64)    |   796.44 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1266.04 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   32.43 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   67.17 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   168.80 ms 
4 |  M*LIB |          Queue(MPMC)    |   310.04 ms 
5 |  M*LIB |     Queue(Buffer P2)    |   454.87 ms 
6 |  LIBLFDS |          Queue(MPMC)    |   869.25 ms 
7 |  M*LIB |        Queue(Buffer)    |   1475.60 ms 
8 |  M*LIB |    Queue(Shared ptr)    |   1610.76 ms 
9 |  BOOST | Queue MPMC (lockfree    |   2607.95 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       Queue(SPSC P2)   |   393.22K
2 |  M*LIB |       Queue(MPMC P2)   |   397.31K
3 |  M*LIB |        Queue(Buffer)   |   524.29K
4 |  BOOST | Queue MPMC (lockfree   |   524.29K
5 |  M*LIB |          Queue(MPMC)   |   524.29K
6 |  M*LIB |     Queue(SPSC Bulk)   |   524.29K
7 |  M*LIB |     Queue(Buffer P2)   |   524.29K
8 |  LIBLFDS |          Queue(MPMC)   |   655.36K
9 |  M*LIB |    Queue(Shared ptr)   |   20.43M

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)    |   610.91 ms 
2 |  CTL |           Seq(Array)    |   618.48 ms 
3 |  KLIB |           Seq(Array)    |   624.67 ms 
4 |  STC |           Seq(Array)    |   631.57 ms 
5 |  UT-HASH |           Seq(Array)    |   664.76 ms 
6 |  M*LIB |           Seq(Deque)    |   708.84 ms 
7 |  POTTERY |            Seq(List)    |   1056.78 ms 
8 |  CTL |            Seq(List)    |   1059.23 ms 
9 |  STC |            Seq(List)    |   1080.55 ms 
10 |  M*LIB |          Seq(DPList)    |   1081.24 ms 
11 |  UT-HASH |            Seq(List)    |   1081.58 ms 
12 |  M*LIB |            Seq(List)    |   1100.25 ms 
13 |  STL |            Seq(List)    |   1105.98 ms 
14 |  CC |            Seq(List)    |   1155.36 ms 
15 |  TommyDS |            Seq(List)    |   1187.95 ms 
16 |  CollectionC |            Seq(List)    |   1197.96 ms 
17 |  GLIB |            Seq(List)    |   1198.14 ms 
18 |  STB-DS |        Seq(DynArray)    |   1317.74 ms 
19 |  CMC |           Seq(Array)    |   1354.13 ms 
20 |  STL |           Seq(Array)    |   1464.84 ms 
21 |  STL |           Seq(Deque)    |   1513.60 ms 
22 |  KLIB |            Seq(List)    |   1553.75 ms 
23 |  TommyDS |           Seq(Array)    |   1579.39 ms 
24 |  CC |           Seq(Array)    |   1636.58 ms 
25 |  CollectionC |           Seq(Array)    |   2488.78 ms 
26 |  QLIBC |            Seq(List)    |   2574.93 ms 
27 |  POTTERY |           Seq(Array)    |   2653.08 ms 
28 |  GLIB |           Seq(Array)    |   2777.54 ms 
29 |  LIBSRT |           Seq(Array)    |   3881.14 ms 
30 |  QLIBC |           Seq(Array)    |   5181.02 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  POTTERY |            Seq(List)   |   1.28G
2 |  CTL |            Seq(List)   |   1.28G
3 |  STC |            Seq(List)   |   1.28G
4 |  M*LIB |          Seq(DPList)   |   1.28G
5 |  UT-HASH |            Seq(List)   |   1.28G
6 |  M*LIB |            Seq(List)   |   1.28G
7 |  STL |            Seq(List)   |   1.28G
8 |  CC |            Seq(List)   |   1.28G
9 |  CollectionC |            Seq(List)   |   1.28G
10 |  GLIB |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  STB-DS |        Seq(DynArray)   |   1.60G
13 |  CMC |           Seq(Array)   |   1.60G
14 |  CC |           Seq(Array)   |   1.60G
15 |  LIBSRT |           Seq(Array)   |   1.60G
16 |  QLIBC |           Seq(Array)   |   1.60G
17 |  M*LIB |           Seq(Array)   |   1.60G
18 |  CTL |           Seq(Array)   |   1.60G
19 |  KLIB |           Seq(Array)   |   1.60G
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
30 |  GLIB |           Seq(Array)   |   4.81G

Note: Performance test: Array based containers work on dataset 10x bigger than the ones used by List based containers.

# Performance test: sort algorithm

Rank|Library|Container|Time
----|-------|---------|----
1 |  STL |                 Sort    |   917.41 ms 
2 |  STC |                 Sort    |   932.24 ms 
3 |  STL |          Stable Sort    |   1056.99 ms 
4 |  POTTERY |                 Sort    |   1085.28 ms 
5 |  M*LIB |          Stable Sort    |   1086.03 ms 
6 |  KLIB |                 Sort    |   1289.14 ms 
7 |  CTL |                 Sort    |   1417.08 ms 
8 |  M*LIB |                 Sort    |   1483.83 ms 
9 |  LIBSRT |                 Sort    |   1517.24 ms 
10 |  UT-HASH |                 Sort    |   1559.86 ms 
11 |  GLIB |                 Sort    |   1565.01 ms 
12 |  CollectionC |                 Sort    |   2786.02 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |                 Sort   |   41.29M
2 |  CTL |                 Sort   |   41.29M
3 |  STC |                 Sort   |   41.29M
4 |  STL |                 Sort   |   68.40M
5 |  LIBSRT |                 Sort   |   79.15M
6 |  M*LIB |          Stable Sort   |   81.82M
7 |  M*LIB |                 Sort   |   81.82M
8 |  UT-HASH |                 Sort   |   82.09M
9 |  POTTERY |                 Sort   |   99.11M
10 |  STL |          Stable Sort   |   100.76M
11 |  GLIB |                 Sort   |   161.72M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   810.52 ms 
2 |  KLIB |          SSet(Btree)    |   1291.56 ms 
3 |  STC |           SSet(sset)    |   2356.48 ms 
4 |  STL |         SSet(Rbtree)    |   2592.83 ms 
5 |  M*LIB |         SSet(Rbtree)    |   2634.20 ms 
6 |  CTL |            SSet(set)    |   3075.27 ms 
7 |  CollectionC |      SSet(TreeTable)    |   3076.17 ms 
8 |  CMC |           SSet(tree)    |   3250.87 ms 
9 |  TommyDS |         SSet(Rbtree)    |   3655.02 ms 
10 |  GLIB |          SSet(GTree)    |   3912.61 ms 
11 |  QLIBC |         SSet(Rbtree)    |   4956.61 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.67M
2 |  STC |           SSet(sset)   |   49.73M
3 |  M*LIB |         SSet(B+tree)   |   55.84M
4 |  STL |         SSet(Rbtree)   |   96.08M
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
1 |  M*LIB |        String Concat    |   465.39 ms 
2 |  STC |        String Concat    |   485.74 ms 
3 |  STL |        String Concat    |   646.53 ms 
4 |  POTTERY |        String Concat    |   1479.18 ms 
5 |  SDS |        String Concat    |   2013.77 ms 
6 |  BSTRLIB |        String Concat    |   2912.44 ms 
7 |  CTL |        String Concat    |   3606.50 ms 
8 |  GLIB |        String Concat    |   4786.51 ms 

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
1 |  M*LIB |       String Replace    |   402.07 ms 
2 |  STC |       String Replace    |   1286.38 ms 
3 |  STL |       String Replace    |   1497.74 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.30M
2 |  STC |       String Replace   |   382.31M
3 |  STL |       String Replace   |   415.90M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)    |   843.28 ms 
2 |  BOOST |  UMap Str(uflat_map)    |   999.47 ms 
3 |  STL |       UMap Str(umap)    |   2639.04 ms 
4 |  STL |        UMap Str(map)    |   7440.55 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   170.22M
2 |  STL |        UMap Str(map)   |   335.94M
3 |  STL |       UMap Str(umap)   |   353.44M
4 |  BOOST |  UMap Str(uflat_map)   |   384.02M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap U64(dict)    |   803.49 ms 
2 |  M*LIB | UMap U64 (dict Bulk)    |   830.04 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   896.69 ms 
4 |  BOOST |  UMap U64(uflat_map)    |   1085.19 ms 
5 |  KLIB |      UMap U64(khash)    |   1283.33 ms 
6 |  POTTERY |  UMap U64(open hash)    |   1702.66 ms 
7 |  VERSTABLE |             UMap U64    |   2178.28 ms 
8 |  CC |        UMap U64(map)    |   2582.13 ms 
9 |  STC |       UMap U64(hmap)    |   3279.65 ms 
10 |  TommyDS |       UMap U64(dict)    |   3331.59 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   3572.05 ms 
12 |  CMC |       UMap U64(hmap)    |   6255.50 ms 
13 |  GLIB | UMap U64(GHashTable)    |   6919.94 ms 
14 |  STL |       UMap U64(umap)    |   8820.80 ms 
15 |  UT-HASH |       UMap U64(dict)    |   9323.03 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.77M
2 |  M*LIB |    UMap U64(dict OA)   |   556.48M
3 |  M*LIB | UMap U64 (dict Bulk)   |   557.07M
4 |  M*LIB |       UMap U64(dict)   |   590.03M
5 |  BOOST |  UMap U64(uflat_map)   |   805.56M
6 |  STC |       UMap U64(hmap)   |   906.28M
7 |  VERSTABLE |             UMap U64   |   906.34M
8 |  CC |        UMap U64(map)   |   906.34M
9 |  STL |       UMap U64(umap)   |   933.75M
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
1 |  M*LIB |       UMap Big(dict)    |   1226.33 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1819.62 ms 
3 |  TommyDS |       UMap Big(dict)    |   1926.51 ms 
4 |  VERSTABLE |             UMap Big    |   1936.54 ms 
5 |  STC |       UMap Big(hmap)    |   2185.58 ms 
6 |  M*LIB |    UMap Big(dict OA)    |   2346.56 ms 
7 |  GLIB | UMap Big(GHashTable)    |   2467.09 ms 
8 |  CC |        UMap Big(map)    |   2517.88 ms 
9 |  POTTERY |  UMap Big(open hash)    |   2581.18 ms 
10 |  KLIB |      UMap Big(khash)    |   2600.45 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   2820.52 ms 
12 |  STL |       UMap Big(umap)    |   3698.46 ms 
13 |  UT-HASH |       UMap Big(dict)    |   4502.23 ms 

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
1 |  BOOST | USet Longest(uflat_s    |   395.08 ms 
2 |  M*LIB | USet Longest(dict oa    |   676.59 ms 
3 |  M*LIB |   USet Longest(dict)    |   776.66 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   1009.04 ms 
5 |  CC |   USet Longest(hset)    |   1208.37 ms 
6 |  STC |   USet Longest(hset)    |   1585.01 ms 
7 |  CTL |   USet Longest(hset)    |   3515.94 ms 
8 |  STL | USet Longest(dict oa    |   4564.43 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   117.35M
2 |  BOOST | USet Longest(uflat_s   |   159.80M
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
