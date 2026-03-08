# Bench for best hash

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)   |   642.94 ms 
2 |  XXHASH |      Hash (xxhash64)   |   863.32 ms 
3 |  M*LIB |        Hash (M_HASH)   |   1249.76 ms 

# Bench for best thread queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       Queue(MPMC P2)   |   35.06 ms 
2 |  M*LIB |     Queue(SPSC Bulk)   |   43.31 ms 
3 |  M*LIB |       Queue(SPSC P2)   |   56.31 ms 
4 |  M*LIB |          Queue(MPMC)   |   71.36 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   428.84 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   739.37 ms 
7 |  M*LIB |        Queue(Buffer)   |   1233.39 ms 
8 |  M*LIB |    Queue(Shared ptr)   |   1337.83 ms 
9 |  BOOST | Queue MPMC (lockfree   |   1972.08 ms 

# Bench for best sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  UT-HASH |           Seq(Array)   |   657.60 ms 
2 |  KLIB |           Seq(Array)   |   732.43 ms 
3 |  M*LIB |           Seq(Array)   |   732.57 ms 
4 |  STC |           Seq(Array)   |   740.20 ms 
5 |  CTL |           Seq(Array)   |   748.35 ms 
6 |  M*LIB |           Seq(Deque)   |   898.38 ms 
7 |  POTTERY |            Seq(List)   |   989.56 ms 
8 |  UT-HASH |            Seq(List)   |   1007.43 ms 
9 |  STC |            Seq(List)   |   1008.58 ms 
10 |  M*LIB |          Seq(DPList)   |   1020.22 ms 
11 |  CTL |            Seq(List)   |   1028.23 ms 
12 |  M*LIB |            Seq(List)   |   1054.80 ms 
13 |  CC |            Seq(List)   |   1126.18 ms 
14 |  TommyDS |            Seq(List)   |   1143.59 ms 
15 |  CollectionC |            Seq(List)   |   1172.90 ms 
16 |  GLIB |            Seq(List)   |   1202.70 ms 
17 |  STL |            Seq(List)   |   1215.70 ms 
18 |  KLIB |            Seq(List)   |   1370.78 ms 
19 |  STL |           Seq(Array)   |   1550.13 ms 
20 |  CMC |           Seq(Array)   |   1627.21 ms 
21 |  STL |           Seq(Deque)   |   1863.40 ms 
22 |  CC |           Seq(Array)   |   1963.14 ms 
23 |  CollectionC |           Seq(Array)   |   2189.58 ms 
24 |  QLIBC |            Seq(List)   |   2691.73 ms 
25 |  TommyDS |           Seq(Array)   |   2757.46 ms 
26 |  POTTERY |           Seq(Array)   |   2943.51 ms 
27 |  GLIB |           Seq(Array)   |   3256.14 ms 
28 |  LIBSRT |           Seq(Array)   |   4502.22 ms 
29 |  QLIBC |           Seq(Array)   |   6310.88 ms 

Note: Bench for Array based containers works on dataset 10x bigger than size of List based containers.

# Bench for best sort container

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |                 Sort   |   1058.70 ms 
2 |  STL |                 Sort   |   1081.24 ms 
3 |  POTTERY |                 Sort   |   1157.26 ms 
4 |  STL |          Stable Sort   |   1297.71 ms 
5 |  M*LIB |          Stable Sort   |   1314.74 ms 
6 |  CTL |                 Sort   |   1505.57 ms 
7 |  KLIB |                 Sort   |   1614.86 ms 
8 |  LIBSRT |                 Sort   |   1664.59 ms 
9 |  M*LIB |                 Sort   |   1670.39 ms 
10 |  UT-HASH |                 Sort   |   1694.67 ms 
11 |  GLIB |                 Sort   |   1751.32 ms 
12 |  CollectionC |                 Sort   |   2970.76 ms 

# Bench for best sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)   |   924.63 ms 
2 |  KLIB |          SSet(Btree)   |   1015.33 ms 
3 |  STC |           SSet(sset)   |   2520.44 ms 
4 |  STL |         SSet(Rbtree)   |   2522.56 ms 
5 |  CTL |            SSet(set)   |   2697.61 ms 
6 |  CMC |           SSet(tree)   |   2892.47 ms 
7 |  TommyDS |         SSet(Rbtree)   |   3028.83 ms 
8 |  CollectionC |      SSet(TreeTable)   |   3073.20 ms 
9 |  M*LIB |         SSet(Rbtree)   |   3315.83 ms 
10 |  GLIB |          SSet(GTree)   |   3403.36 ms 
11 |  QLIBC |         SSet(Rbtree)   |   4094.25 ms 

# Bench for best string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  STC |        String Concat   |   399.49 ms 
2 |  M*LIB |        String Concat   |   552.04 ms 
3 |  STL |        String Concat   |   651.87 ms 
4 |  POTTERY |        String Concat   |   1662.43 ms 
5 |  CTL |        String Concat   |   3908.16 ms 
6 |  GLIB |        String Concat   |   4097.18 ms 

# Bench for best string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace   |   522.67 ms 
2 |  STL |       String Replace   |   1311.76 ms 
3 |  STC |       String Replace   |   1543.70 ms 

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Bench for best unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  BOOST |  UMap Str(uflat_map)   |   767.00 ms 
2 |  M*LIB |       UMap Str(dict)   |   879.96 ms 
3 |  STL |       UMap Str(umap)   |   2634.82 ms 
4 |  STL |        UMap Str(map)   |   7242.62 ms 

# Bench for best unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |    UMap U64(dict OA)   |   893.01 ms 
2 |  M*LIB |       UMap U64(dict)   |   907.15 ms 
3 |  KLIB |      UMap U64(khash)   |   1225.49 ms 
4 |  BOOST |  UMap U64(uflat_map)   |   1332.47 ms 
5 |  POTTERY |  UMap U64(open hash)   |   1935.42 ms 
6 |  VERSTABLE |             UMap U64   |   2259.39 ms 
7 |  CC |        UMap U64(map)   |   2741.35 ms 
8 |  STC |       UMap U64(hmap)   |   3120.32 ms 
9 |  TommyDS |       UMap U64(dict)   |   4482.70 ms 
10 |  CollectionC |  UMap U64(HashTable)   |   5127.35 ms 
11 |  CMC |       UMap U64(hmap)   |   8330.78 ms 
12 |  GLIB | UMap U64(GHashTable)   |   8729.45 ms 
13 |  UT-HASH |       UMap U64(dict)   |   10370.44 ms 
14 |  STL |       UMap U64(umap)   |   10590.58 ms 

# Bench for best unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)   |   1164.04 ms 
2 |  BOOST |  UMap Big(uflat_map)   |   1251.42 ms 
3 |  CC |        UMap Big(map)   |   1599.05 ms 
4 |  VERSTABLE |             UMap Big   |   1675.56 ms 
5 |  KLIB |      UMap Big(khash)   |   1943.24 ms 
6 |  TommyDS |       UMap Big(dict)   |   1984.99 ms 
7 |  POTTERY |  UMap Big(open hash)   |   2038.27 ms 
8 |  M*LIB |    UMap Big(dict OA)   |   2061.25 ms 
9 |  STC |       UMap Big(hmap)   |   2262.47 ms 
10 |  GLIB | UMap Big(GHashTable)   |   2669.68 ms 
11 |  CollectionC |  UMap Big(HashTable)   |   3042.40 ms 
12 |  STL |       UMap Big(umap)   |   3795.36 ms 
13 |  UT-HASH |       UMap Big(dict)   |   4193.67 ms 


Model name:                              AMD EPYC 7763 64-Core Processor

C-Macro-Collections commit a7ee017bcd288e0a1521cba5d8aaf83a07a01b58

CC commit 2d62942eb2369b5387e0c4f2aa06f052004d16e0

Collections-C commit 3920f28431ecf82c9e7e78bbcb60fe473d87edf9

STC commit 078fecf619ebd9af26d9a2fb81992db40a33f8f5

Verstable commit dd83033fb72736a1d2332e43b84b7794b5d19635

ctl commit 4c9157369d36d33722f479de3663368ab6ab1ea9

klib commit 97a0fcb790b43b9e5da8994f4671021fec036f19

liblfds7.1.1 commit d28d20e4750aa9e5b678639b2bb9d5b67a360819

libsrt commit eee28e6dfc23f76c7b8f76f32ef68418619064be

mlib commit d0fd65a8695218ffabf2aa543ce51ca3af69536f

pottery commit 741bf5fa1ef348c43a86e79322545dc7d6320007

qlibc commit f45c021c59b33bac8eb73510531d0ca743e6f103

rapidjson commit 24b5e7a8b27f42fa16b96fc70aade9106cf7102f

tommyds commit 1f3727fc89174902c48e3933ac4610cb7fb13f4a

uthash commit 2031adfd8cd6f8f498e0f4a9055648b19496f12e

xxHash commit 82cead715cbfddd9e6093db8df95155077ce6e64

