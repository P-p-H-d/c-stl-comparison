# Bench for best hash

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)   |   706.85 ms 
2 |  XXHASH |      Hash (xxhash64)   |   971.59 ms 
3 |  M*LIB |        Hash (M_HASH)   |   1410.82 ms 

# Bench for best thread queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       Queue(MPMC P2)   |   38.91 ms 
2 |  M*LIB |     Queue(SPSC Bulk)   |   62.38 ms 
3 |  M*LIB |       Queue(SPSC P2)   |   67.31 ms 
4 |  M*LIB |          Queue(MPMC)   |   74.45 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   488.48 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   721.98 ms 
7 |  M*LIB |    Queue(Shared ptr)   |   1293.76 ms 
8 |  M*LIB |        Queue(Buffer)   |   1497.23 ms 
9 |  BOOST | Queue MPMC (lockfree   |   2080.98 ms 

# Bench for best sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |           Seq(Array)   |   808.54 ms 
2 |  STC |           Seq(Array)   |   829.76 ms 
3 |  CTL |           Seq(Array)   |   842.29 ms 
4 |  KLIB |           Seq(Array)   |   842.36 ms 
5 |  UT-HASH |           Seq(Array)   |   880.96 ms 
6 |  M*LIB |          Seq(DPList)   |   982.95 ms 
7 |  STC |            Seq(List)   |   998.43 ms 
8 |  CollectionC |            Seq(List)   |   1003.27 ms 
9 |  M*LIB |            Seq(List)   |   1003.85 ms 
10 |  POTTERY |            Seq(List)   |   1027.10 ms 
11 |  CTL |            Seq(List)   |   1028.61 ms 
12 |  M*LIB |           Seq(Deque)   |   1039.70 ms 
13 |  UT-HASH |            Seq(List)   |   1042.50 ms 
14 |  CC |            Seq(List)   |   1058.60 ms 
15 |  GLIB |            Seq(List)   |   1110.98 ms 
16 |  TommyDS |            Seq(List)   |   1112.50 ms 
17 |  KLIB |            Seq(List)   |   1213.33 ms 
18 |  STL |            Seq(List)   |   1234.95 ms 
19 |  STL |           Seq(Array)   |   1781.52 ms 
20 |  TommyDS |           Seq(Array)   |   1844.22 ms 
21 |  CC |           Seq(Array)   |   1865.59 ms 
22 |  CMC |           Seq(Array)   |   1873.23 ms 
23 |  STL |           Seq(Deque)   |   2081.85 ms 
24 |  CollectionC |           Seq(Array)   |   2458.95 ms 
25 |  QLIBC |            Seq(List)   |   2629.71 ms 
26 |  POTTERY |           Seq(Array)   |   2775.32 ms 
27 |  GLIB |           Seq(Array)   |   3345.41 ms 
28 |  LIBSRT |           Seq(Array)   |   4618.01 ms 
29 |  QLIBC |           Seq(Array)   |   6304.21 ms 

Note: Bench for Array based containers works on dataset 10x bigger than size of List based containers.

# Bench for best sort container

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |                 Sort   |   1201.59 ms 
2 |  STL |                 Sort   |   1229.44 ms 
3 |  POTTERY |                 Sort   |   1325.84 ms 
4 |  STL |          Stable Sort   |   1410.84 ms 
5 |  M*LIB |          Stable Sort   |   1471.49 ms 
6 |  CTL |                 Sort   |   1667.85 ms 
7 |  KLIB |                 Sort   |   1803.99 ms 
8 |  LIBSRT |                 Sort   |   1833.31 ms 
9 |  M*LIB |                 Sort   |   1862.61 ms 
10 |  UT-HASH |                 Sort   |   1886.59 ms 
11 |  GLIB |                 Sort   |   1958.15 ms 
12 |  CollectionC |                 Sort   |   3278.98 ms 

# Bench for best sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)   |   1106.15 ms 
2 |  KLIB |          SSet(Btree)   |   1121.62 ms 
3 |  STC |           SSet(sset)   |   2573.60 ms 
4 |  STL |         SSet(Rbtree)   |   3113.29 ms 
5 |  TommyDS |         SSet(Rbtree)   |   3477.94 ms 
6 |  CTL |            SSet(set)   |   3529.47 ms 
7 |  M*LIB |         SSet(Rbtree)   |   3586.68 ms 
8 |  CollectionC |      SSet(TreeTable)   |   3978.81 ms 
9 |  CMC |           SSet(tree)   |   4108.93 ms 
10 |  GLIB |          SSet(GTree)   |   4152.73 ms 
11 |  QLIBC |         SSet(Rbtree)   |   5331.88 ms 

# Bench for best string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |        String Concat   |   385.24 ms 
2 |  M*LIB |        String Concat   |   535.67 ms 
3 |  STL |        String Concat   |   603.76 ms 
4 |  POTTERY |        String Concat   |   1658.25 ms 
5 |  SDS |        String Concat   |   2413.68 ms 
6 |  BSTRLIB |        String Concat   |   3390.03 ms 
7 |  CTL |        String Concat   |   3919.20 ms 
8 |  GLIB |        String Concat   |   4169.71 ms 

# Bench for best string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace   |   510.18 ms 
2 |  STL |       String Replace   |   1118.74 ms 
3 |  STC |       String Replace   |   1434.18 ms 

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Bench for best unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   930.77 ms 
2 |  BOOST |  UMap Str(uflat_map)   |   1113.91 ms 
3 |  STL |       UMap Str(umap)   |   3480.69 ms 
4 |  STL |        UMap Str(map)   |   9575.71 ms 

# Bench for best unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB | UMap U64 (dict Bulk)   |   886.74 ms 
2 |  M*LIB |       UMap U64(dict)   |   913.60 ms 
3 |  M*LIB |    UMap U64(dict OA)   |   990.56 ms 
4 |  KLIB |      UMap U64(khash)   |   1287.19 ms 
5 |  BOOST |  UMap U64(uflat_map)   |   1399.81 ms 
6 |  POTTERY |  UMap U64(open hash)   |   2012.77 ms 
7 |  VERSTABLE |             UMap U64   |   2361.52 ms 
8 |  CC |        UMap U64(map)   |   3255.82 ms 
9 |  STC |       UMap U64(hmap)   |   3781.98 ms 
10 |  TommyDS |       UMap U64(dict)   |   3923.51 ms 
11 |  CollectionC |  UMap U64(HashTable)   |   4330.89 ms 
12 |  CMC |       UMap U64(hmap)   |   7213.12 ms 
13 |  GLIB | UMap U64(GHashTable)   |   8351.81 ms 
14 |  STL |       UMap U64(umap)   |   10344.52 ms 
15 |  UT-HASH |       UMap U64(dict)   |   11874.41 ms 

# Bench for best unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)   |   1316.39 ms 
2 |  BOOST |  UMap Big(uflat_map)   |   1696.76 ms 
3 |  VERSTABLE |             UMap Big   |   2011.11 ms 
4 |  CC |        UMap Big(map)   |   2106.15 ms 
5 |  M*LIB |    UMap Big(dict OA)   |   2337.34 ms 
6 |  TommyDS |       UMap Big(dict)   |   2358.62 ms 
7 |  KLIB |      UMap Big(khash)   |   2388.18 ms 
8 |  STC |       UMap Big(hmap)   |   2458.78 ms 
9 |  POTTERY |  UMap Big(open hash)   |   2548.65 ms 
10 |  GLIB | UMap Big(GHashTable)   |   2739.15 ms 
11 |  CollectionC |  UMap Big(HashTable)   |   3823.60 ms 
12 |  UT-HASH |       UMap Big(dict)   |   4892.39 ms 
13 |  STL |       UMap Big(umap)   |   4996.94 ms 


Model name:                              AMD EPYC 9V74 80-Core Processor

C-Macro-Collections commit a7ee017bcd288e0a1521cba5d8aaf83a07a01b58

CC commit 2d62942eb2369b5387e0c4f2aa06f052004d16e0

Collections-C commit 3920f28431ecf82c9e7e78bbcb60fe473d87edf9

STC commit 078fecf619ebd9af26d9a2fb81992db40a33f8f5

Verstable commit dd83033fb72736a1d2332e43b84b7794b5d19635

bstrlib commit f0ff1e808102a42cdc7204a4bb6fe231a24c4546 -committed to Unicode representation of its string data, and therefore cannot

ctl commit 4c9157369d36d33722f479de3663368ab6ab1ea9

klib commit 97a0fcb790b43b9e5da8994f4671021fec036f19

liblfds7.1.1 commit d28d20e4750aa9e5b678639b2bb9d5b67a360819

libsrt commit eee28e6dfc23f76c7b8f76f32ef68418619064be

mlib commit d0fd65a8695218ffabf2aa543ce51ca3af69536f

pottery commit 741bf5fa1ef348c43a86e79322545dc7d6320007

qlibc commit f45c021c59b33bac8eb73510531d0ca743e6f103

rapidjson commit 24b5e7a8b27f42fa16b96fc70aade9106cf7102f

sds commit 5347739b1581fcba74fd5cab1fc21d2aef317d71

tommyds commit 1f3727fc89174902c48e3933ac4610cb7fb13f4a

uthash commit 2031adfd8cd6f8f498e0f4a9055648b19496f12e

xxHash commit 82cead715cbfddd9e6093db8df95155077ce6e64

