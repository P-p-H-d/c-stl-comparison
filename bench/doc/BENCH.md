# Performance test: hash function

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)    |   680.50 ms 
2 |  XXHASH |      Hash (xxhash64)    |   695.77 ms 
3 |  M*LIB |        Hash (M_HASH)    |   1330.41 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        Hash (M_HASH)   |   8.00G
2 |  M*LIB |     Hash (Core Hash)   |   8.00G
3 |  XXHASH |      Hash (xxhash64)   |   8.00G

# Performance test: thread communication queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)    |   45.25 ms 
2 |  M*LIB |       Queue(SPSC P2)    |   62.36 ms 
3 |  M*LIB |       Queue(MPMC P2)    |   128.31 ms 
4 |  M*LIB |          Queue(MPMC)    |   201.49 ms 
5 |  LIBLFDS |          Queue(MPMC)    |   541.10 ms 
6 |  M*LIB |     Queue(Buffer P2)    |   791.62 ms 
7 |  BOOST | Queue MPMC (lockfree    |   1400.62 ms 
8 |  M*LIB |        Queue(Buffer)    |   2073.91 ms 
9 |  M*LIB |    Queue(Shared ptr)    |   3375.70 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       Queue(MPMC P2)   |   77.82K
2 |  M*LIB |     Queue(Buffer P2)   |   77.82K
3 |  M*LIB |     Queue(SPSC Bulk)   |   200.70K
4 |  M*LIB |       Queue(SPSC P2)   |   200.70K
5 |  LIBLFDS |          Queue(MPMC)   |   774.14K
6 |  M*LIB |        Queue(Buffer)   |   806.91K
7 |  M*LIB |          Queue(MPMC)   |   892.93K
8 |  BOOST | Queue MPMC (lockfree   |   1.03M
9 |  M*LIB |    Queue(Shared ptr)   |   4.21M

# Performance test: sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)    |   664.26 ms 
2 |  STC |           Seq(Array)    |   679.55 ms 
3 |  CTL |           Seq(Array)    |   695.15 ms 
4 |  UT-HASH |           Seq(Array)    |   725.90 ms 
5 |  KLIB |           Seq(Array)    |   731.27 ms 
6 |  M*LIB |           Seq(Deque)    |   950.96 ms 
7 | STB-DS |           Seq(DynArray) |  1320.01 ms
8 |  GLIB |            Seq(List)    |   1383.70 ms 
9 |  UT-HASH |            Seq(List)    |   1459.38 ms 
10 |  STC |            Seq(List)    |   1478.17 ms 
11 |  M*LIB |          Seq(DPList)    |   1478.85 ms 
12 |  CTL |            Seq(List)    |   1483.12 ms 
13 |  POTTERY |            Seq(List)    |   1486.21 ms 
14 |  CollectionC |            Seq(List)    |   1546.96 ms 
15 |  STL |           Seq(Array)    |   1600.91 ms 
16 |  STL |            Seq(List)    |   1653.76 ms 
17 |  CC |            Seq(List)    |   1708.23 ms 
18 |  CMC |           Seq(Array)    |   1763.53 ms 
19 |  M*LIB |            Seq(List)    |   1779.96 ms 
20 |  TommyDS |            Seq(List)    |   1798.43 ms 
21 |  STL |           Seq(Deque)    |   1820.54 ms 
22 |  TommyDS |           Seq(Array)    |   1848.12 ms 
23 |  CC |           Seq(Array)    |   2442.61 ms 
24 |  KLIB |            Seq(List)    |   2487.40 ms 
25 |  CollectionC |           Seq(Array)    |   2786.02 ms 
26 |  POTTERY |           Seq(Array)    |   3939.73 ms 
27 |  QLIBC |            Seq(List)    |   4155.04 ms 
28 |  LIBSRT |           Seq(Array)    |   6368.50 ms 
29 |  GLIB |           Seq(Array)    |   7386.94 ms 
30 |  QLIBC |           Seq(Array)    |   8403.00 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  GLIB |            Seq(List)   |   788.61M
2 |  UT-HASH |            Seq(List)   |   1.28G
3 |  STC |            Seq(List)   |   1.28G
4 |  M*LIB |          Seq(DPList)   |   1.28G
5 |  CTL |            Seq(List)   |   1.28G
6 |  POTTERY |            Seq(List)   |   1.28G
7 |  CollectionC |            Seq(List)   |   1.28G
8 |  STL |            Seq(List)   |   1.28G
9 |  CC |            Seq(List)   |   1.28G
10 |  M*LIB |            Seq(List)   |   1.28G
11 |  KLIB |            Seq(List)   |   1.44G
12 |  CMC |           Seq(Array)   |   1.60G
13 |  CC |           Seq(Array)   |   1.60G
14 |  LIBSRT |           Seq(Array)   |   1.60G
15 |  M*LIB |           Seq(Array)   |   1.60G
16 |  STC |           Seq(Array)   |   1.60G
17 |  CTL |           Seq(Array)   |   1.60G
18 |  UT-HASH |           Seq(Array)   |   1.60G
19 |  KLIB |           Seq(Array)   |   1.60G
20 |  QLIBC |           Seq(Array)   |   1.60G
21 |  M*LIB |           Seq(Deque)   |   1.60G
22 |  STB-DS |           Seq(DynArray)   |   1.60G
23 |  STL |           Seq(Array)   |   1.62G
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
1 |  STL |                 Sort    |   917.38 ms 
2 |  STC |                 Sort    |   1006.58 ms 
3 |  POTTERY |                 Sort    |   1175.83 ms 
4 |  M*LIB |          Stable Sort    |   1179.00 ms 
5 |  STL |          Stable Sort    |   1194.30 ms 
6 |  KLIB |                 Sort    |   1365.81 ms 
7 |  LIBSRT |                 Sort    |   1660.61 ms 
8 |  CTL |                 Sort    |   1664.95 ms 
9 |  M*LIB |                 Sort    |   1690.65 ms 
10 |  UT-HASH |                 Sort    |   1696.02 ms 
11 |  GLIB |                 Sort    |   1886.51 ms 
12 |  CollectionC |                 Sort    |   3891.49 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |                 Sort   |   40.42M
2 |  STC |                 Sort   |   40.55M
3 |  CTL |                 Sort   |   41.43M
4 |  STL |                 Sort   |   68.78M
5 |  LIBSRT |                 Sort   |   79.84M
6 |  UT-HASH |                 Sort   |   80.87M
7 |  M*LIB |          Stable Sort   |   81.30M
8 |  M*LIB |                 Sort   |   81.90M
9 |  POTTERY |                 Sort   |   98.78M
10 |  STL |          Stable Sort   |   103.37M
11 |  GLIB |                 Sort   |   167.33M
12 |  CollectionC |                 Sort   |   1.12G

# Performance test: sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)    |   1182.39 ms 
2 |  KLIB |          SSet(Btree)    |   1908.74 ms 
3 |  M*LIB |         SSet(Rbtree)    |   3474.88 ms 
4 |  STC |           SSet(sset)    |   3517.52 ms 
5 |  CTL |            SSet(set)    |   3626.58 ms 
6 |  STL |         SSet(Rbtree)    |   3663.67 ms 
7 |  CollectionC |      SSet(TreeTable)    |   3683.10 ms 
8 |  TommyDS |         SSet(Rbtree)    |   4107.66 ms 
9 |  CMC |           SSet(tree)    |   4108.03 ms 
10 |  GLIB |          SSet(GTree)    |   5331.23 ms 
11 |  QLIBC |         SSet(Rbtree)    |   5675.91 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |          SSet(Btree)   |   30.81M
2 |  STC |           SSet(sset)   |   50.17M
3 |  M*LIB |         SSet(B+tree)   |   55.80M
4 |  TommyDS |         SSet(Rbtree)   |   96.22M
5 |  M*LIB |         SSet(Rbtree)   |   96.27M
6 |  CTL |            SSet(set)   |   96.29M
7 |  CMC |           SSet(tree)   |   96.32M
8 |  STL |         SSet(Rbtree)   |   96.74M
9 |  CollectionC |      SSet(TreeTable)   |   128.14M
10 |  GLIB |          SSet(GTree)   |   178.84M
11 |  QLIBC |         SSet(Rbtree)   |   288.33M

# Performance test: string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |        String Concat    |   533.72 ms 
2 |  STC |        String Concat    |   701.70 ms 
3 |  STL |        String Concat    |   963.76 ms 
4 |  POTTERY |        String Concat    |   2513.44 ms 
5 |  SDS |        String Concat    |   3902.28 ms 
6 |  BSTRLIB |        String Concat    |   5521.30 ms 
7 |  CTL |        String Concat    |   5799.15 ms 
8 |  GLIB |        String Concat    |   7087.15 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |        String Concat   |   1.04G
2 |  STC |        String Concat   |   1.36G
3 |  STL |        String Concat   |   1.79G
4 |  SDS |        String Concat   |   2.00G
5 |  POTTERY |        String Concat   |   2.04G
6 |  BSTRLIB |        String Concat   |   3.28G
7 |  CTL |        String Concat   |   4.02G
8 |  GLIB |        String Concat   |   8.01G

# Performance test: string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace    |   727.00 ms 
2 |  STC |       String Replace    |   2618.69 ms 
3 |  STL |       String Replace    |   2983.80 ms 
4 |  BSTRLIB |       String Replace    |   3259.68 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       String Replace   |   239.23M
2 |  STC |       String Replace   |   382.85M
3 |  STL |       String Replace   |   415.41M
4 |  BSTRLIB |       String Replace   |   687.92M

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Performance test: unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST |  UMap Str(uflat_map)    |   1084.37 ms 
2 |  M*LIB |       UMap Str(dict)    |   1111.80 ms 
3 |  STL |       UMap Str(umap)    |   3464.09 ms 
4 |  STL |        UMap Str(map)    |   8067.85 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   170.83M
2 |  STL |        UMap Str(map)   |   336.86M
3 |  STL |       UMap Str(umap)   |   354.06M
4 |  BOOST |  UMap Str(uflat_map)   |   384.76M

# Performance test: unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)    |   977.01 ms 
2 |  M*LIB |       UMap U64(dict)    |   1056.46 ms 
3 |  M*LIB |    UMap U64(dict OA)    |   1217.19 ms 
4 |  BOOST |  UMap U64(uflat_map)    |   1977.90 ms 
5 |  POTTERY |  UMap U64(open hash)    |   2682.76 ms 
6 |  KLIB |      UMap U64(khash)    |   2709.59 ms 
7 |  VERSTABLE |             UMap U64    |   3020.56 ms 
8 |  CC |        UMap U64(map)    |   3045.27 ms 
9 |  STC |       UMap U64(hmap)    |   3217.21 ms 
10 |  TommyDS |       UMap U64(dict)    |   7005.18 ms 
11 |  CollectionC |  UMap U64(HashTable)    |   9560.47 ms 
12 |  GLIB | UMap U64(GHashTable)    |   10118.77 ms 
13 |  STL |       UMap U64(umap)    |   13613.62 ms 
14 |  CMC |       UMap U64(hmap)    |   14164.83 ms 
15 |  UT-HASH |       UMap U64(dict)    |   16144.90 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  KLIB |      UMap U64(khash)   |   552.91M
2 |  M*LIB |    UMap U64(dict OA)   |   557.38M
3 |  M*LIB | UMap U64 (dict Bulk)   |   557.60M
4 |  M*LIB |       UMap U64(dict)   |   590.65M
5 |  BOOST |  UMap U64(uflat_map)   |   806.26M
6 |  CC |        UMap U64(map)   |   906.40M
7 |  VERSTABLE |             UMap U64   |   906.41M
8 |  STC |       UMap U64(hmap)   |   906.53M
9 |  STL |       UMap U64(umap)   |   934.47M
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
1 |  M*LIB |       UMap Big(dict)    |   1777.67 ms 
2 |  BOOST |  UMap Big(uflat_map)    |   1831.40 ms 
3 |  VERSTABLE |             UMap Big    |   2411.29 ms 
4 |  CC |        UMap Big(map)    |   2451.94 ms 
5 |  M*LIB |    UMap Big(dict OA)    |   2813.09 ms 
6 |  TommyDS |       UMap Big(dict)    |   2860.20 ms 
7 |  STC |       UMap Big(hmap)    |   2896.35 ms 
8 |  KLIB |      UMap Big(khash)    |   3095.31 ms 
9 |  POTTERY |  UMap Big(open hash)    |   3124.58 ms 
10 |  GLIB | UMap Big(GHashTable)    |   3950.68 ms 
11 |  CollectionC |  UMap Big(HashTable)    |   4314.07 ms 
12 |  STL |       UMap Big(umap)    |   5289.73 ms 
13 |  UT-HASH |       UMap Big(dict)    |   5954.40 ms 

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
1 |  BOOST | USet Longest(uflat_s    |   899.14 ms 
2 |  M*LIB | USet Longest(dict oa    |   1085.55 ms 
3 |  M*LIB |   USet Longest(dict)    |   1184.60 ms 
4 |  VERSTABLE |   USet Longest(hset)    |   1612.44 ms 
5 |  CC |   USet Longest(hset)    |   1620.60 ms 
6 |  STC |   USet Longest(hset)    |   1883.23 ms 
7 |  STL | USet Longest(dict oa    |   8139.08 ms 
8 |  CTL |   USet Longest(hset)    |   8265.41 ms 

Rank|Library|Container|Mem
----|-------|---------|----
1 |  M*LIB | USet Longest(dict oa   |   116.99M
2 |  BOOST | USet Longest(uflat_s   |   160.47M
3 |  CC |   USet Longest(hset)   |   191.48M
4 |  VERSTABLE |   USet Longest(hset)   |   191.53M
5 |  M*LIB |   USet Longest(dict)   |   216.13M
6 |  STC |   USet Longest(hset)   |   219.30M
7 |  STL | USet Longest(dict oa   |   457.56M
8 |  CTL |   USet Longest(hset)   |   480.89M


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
