# Bench for best hash

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Hash (Core Hash)   |   674.57 ms 
2 |  XXHASH |      Hash (xxhash64)   |   700.12 ms 
3 |  M*LIB |        Hash (M_HASH)   |   1317.08 ms 

# Bench for best thread queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |     Queue(SPSC Bulk)   |   50.78 ms 
2 |  M*LIB |       Queue(SPSC P2)   |   61.99 ms 
3 |  M*LIB |       Queue(MPMC P2)   |   127.17 ms 
4 |  M*LIB |          Queue(MPMC)   |   204.40 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   562.26 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   817.78 ms 
7 |  M*LIB |        Queue(Buffer)   |   1992.97 ms 
8 |  M*LIB |    Queue(Shared ptr)   |   3353.88 ms 

# Bench for best sequence container

Rank|Library|Container|Time
----|-------|---------|----
1 |  KLIB |           Seq(Array)   |   674.44 ms 
2 |  STC |           Seq(Array)   |   676.27 ms 
3 |  CTL |           Seq(Array)   |   679.44 ms 
4 |  M*LIB |           Seq(Array)   |   685.42 ms 
5 |  UT-HASH |           Seq(Array)   |   745.38 ms 
6 |  M*LIB |           Seq(Deque)   |   942.04 ms 
7 |  GLIB |            Seq(List)   |   1377.95 ms 
8 |  M*LIB |            Seq(List)   |   1445.12 ms 
9 |  STC |            Seq(List)   |   1455.81 ms 
10 |  CTL |            Seq(List)   |   1459.09 ms 
11 |  UT-HASH |            Seq(List)   |   1460.60 ms 
12 |  M*LIB |          Seq(DPList)   |   1463.27 ms 
13 |  POTTERY |            Seq(List)   |   1485.15 ms 
14 |  CollectionC |            Seq(List)   |   1545.36 ms 
15 |  STL |            Seq(List)   |   1616.33 ms 
16 |  STL |           Seq(Array)   |   1637.12 ms 
17 |  CC |            Seq(List)   |   1667.24 ms 
18 |  TommyDS |            Seq(List)   |   1746.66 ms 
19 |  CMC |           Seq(Array)   |   1791.72 ms 
20 |  STL |           Seq(Deque)   |   1867.24 ms 
21 |  TommyDS |           Seq(Array)   |   1925.63 ms 
22 |  KLIB |            Seq(List)   |   2191.36 ms 
23 |  CC |           Seq(Array)   |   2355.61 ms 
24 |  CollectionC |           Seq(Array)   |   2853.15 ms 
25 |  POTTERY |           Seq(Array)   |   3875.26 ms 
26 |  QLIBC |            Seq(List)   |   4545.92 ms 
27 |  LIBSRT |           Seq(Array)   |   6021.74 ms 
28 |  GLIB |           Seq(Array)   |   7280.67 ms 
29 |  QLIBC |           Seq(Array)   |   7925.11 ms 

Note: Bench for Array based containers works on dataset 10x bigger than size of List based containers.

# Bench for best sort container

Rank|Library|Container|Time
----|-------|---------|----
1 |  STL |                 Sort   |   915.87 ms 
2 |  STC |                 Sort   |   998.41 ms 
3 |  POTTERY |                 Sort   |   1165.56 ms 
4 |  M*LIB |          Stable Sort   |   1167.02 ms 
5 |  STL |          Stable Sort   |   1193.03 ms 
6 |  KLIB |                 Sort   |   1353.23 ms 
7 |  LIBSRT |                 Sort   |   1629.26 ms 
8 |  CTL |                 Sort   |   1650.94 ms 
9 |  UT-HASH |                 Sort   |   1677.82 ms 
10 |  M*LIB |                 Sort   |   1677.93 ms 
11 |  GLIB |                 Sort   |   1842.57 ms 
12 |  CollectionC |                 Sort   |   3926.93 ms 

# Bench for best sorted set container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |         SSet(B+tree)   |   1151.89 ms 
2 |  KLIB |          SSet(Btree)   |   1613.41 ms 
3 |  STC |           SSet(sset)   |   3322.73 ms 
4 |  STL |         SSet(Rbtree)   |   3348.05 ms 
5 |  M*LIB |         SSet(Rbtree)   |   3353.56 ms 
6 |  CTL |            SSet(set)   |   3596.24 ms 
7 |  CMC |           SSet(tree)   |   3780.70 ms 
8 |  CollectionC |      SSet(TreeTable)   |   3914.51 ms 
9 |  TommyDS |         SSet(Rbtree)   |   4166.35 ms 
10 |  GLIB |          SSet(GTree)   |   5216.31 ms 
11 |  QLIBC |         SSet(Rbtree)   |   5491.33 ms 

# Bench for best string concat

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |        String Concat   |   535.28 ms 
2 |  STC |        String Concat   |   671.92 ms 
3 |  STL |        String Concat   |   956.34 ms 
4 |  POTTERY |        String Concat   |   2336.52 ms 
5 |  CTL |        String Concat   |   5775.37 ms 
6 |  GLIB |        String Concat   |   6587.31 ms 

# Bench for best string replacement

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       String Replace   |   693.37 ms 
2 |  STC |       String Replace   |   2550.48 ms 
3 |  STL |       String Replace   |   2971.55 ms 

GLIB2, POTTERY, CTL & SDS benchs are not included due to being too slow

# Bench for best unordered map string container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Str(dict)   |   1079.26 ms 
2 |  STL |       UMap Str(umap)   |   2910.99 ms 
3 |  STL |        UMap Str(map)   |   7676.80 ms 

# Bench for best unordered map U64 container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap U64(dict)   |   1054.35 ms 
2 |  M*LIB |    UMap U64(dict OA)   |   1217.98 ms 
3 |  KLIB |      UMap U64(khash)   |   2093.15 ms 
4 |  POTTERY |  UMap U64(open hash)   |   2747.16 ms 
5 |  VERSTABLE |             UMap U64   |   2927.57 ms 
6 |  CC |        UMap U64(map)   |   2936.31 ms 
7 |  STC |       UMap U64(hmap)   |   3059.69 ms 
8 |  TommyDS |       UMap U64(dict)   |   6798.47 ms 
9 |  CollectionC |  UMap U64(HashTable)   |   9223.23 ms 
10 |  GLIB | UMap U64(GHashTable)   |   9436.08 ms 
11 |  STL |       UMap U64(umap)   |   12546.81 ms 
12 |  CMC |       UMap U64(hmap)   |   14264.28 ms 
13 |  UT-HASH |       UMap U64(dict)   |   15529.51 ms 

# Bench for best unordered map BIG container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       UMap Big(dict)   |   1834.60 ms 
2 |  CC |        UMap Big(map)   |   2338.62 ms 
3 |  VERSTABLE |             UMap Big   |   2382.33 ms 
4 |  M*LIB |    UMap Big(dict OA)   |   2713.07 ms 
5 |  STC |       UMap Big(hmap)   |   2797.48 ms 
6 |  TommyDS |       UMap Big(dict)   |   2912.90 ms 
7 |  KLIB |      UMap Big(khash)   |   2921.57 ms 
8 |  POTTERY |  UMap Big(open hash)   |   3224.26 ms 
9 |  GLIB | UMap Big(GHashTable)   |   3765.81 ms 
10 |  CollectionC |  UMap Big(HashTable)   |   4257.19 ms 
11 |  STL |       UMap Big(umap)   |   5036.28 ms 
12 |  UT-HASH |       UMap Big(dict)   |   6043.83 ms 


Model name:                              Intel(R) Core(TM) i5-3210M CPU @ 2.50GHz

C-Macro-Collections commit a7ee017bcd288e0a1521cba5d8aaf83a07a01b58

CC commit 2d62942eb2369b5387e0c4f2aa06f052004d16e0

Collections-C commit 3920f28431ecf82c9e7e78bbcb60fe473d87edf9

STC commit 074fbcd92b9e4b72a6ccb20bf91871fb5a02a52e

Verstable commit dd83033fb72736a1d2332e43b84b7794b5d19635

bstrlib commit f0ff1e808102a42cdc7204a4bb6fe231a24c4546 -committed to Unicode representation of its string data, and therefore cannot

ctl commit f224bdc7361dc8342171e99032e4a1657f8fb02a

klib commit 97a0fcb790b43b9e5da8994f4671021fec036f19

libdynamic commit da348d4234608a1aa3d699f0e16f656d66709fff

liblfds7.1.1 commit d28d20e4750aa9e5b678639b2bb9d5b67a360819

libsrt commit eee28e6dfc23f76c7b8f76f32ef68418619064be

mlib commit e3ae4b514511d7d7f45e2975a742c32e4799b57d

nedtries commit c370fef72146abec435ec805a56f37b912a65774

pottery commit 741bf5fa1ef348c43a86e79322545dc7d6320007

qlibc commit f45c021c59b33bac8eb73510531d0ca743e6f103

rapidjson commit 24b5e7a8b27f42fa16b96fc70aade9106cf7102f

sds commit 5347739b1581fcba74fd5cab1fc21d2aef317d71

tommyds commit 1f3727fc89174902c48e3933ac4610cb7fb13f4a

uthash commit 2031adfd8cd6f8f498e0f4a9055648b19496f12e

xxHash commit 82cead715cbfddd9e6093db8df95155077ce6e64

