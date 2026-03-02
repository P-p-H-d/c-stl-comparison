Bench for best thread queue container

Rank|Library|Container|Time
----|-------|---------|----
1 |  M*LIB |       Queue(MPMC P2)   |   6.07 ms 
2 |  M*LIB |     Queue(SPSC Bulk)   |   11.06 ms 
3 |  M*LIB |       Queue(SPSC P2)   |   11.33 ms 
4 |  M*LIB |          Queue(MPMC)   |   15.74 ms 
5 |  LIBLFDS |          Queue(MPMC)   |   81.43 ms 
6 |  M*LIB |     Queue(Buffer P2)   |   151.56 ms 
7 |  M*LIB |        Queue(Buffer)   |   240.26 ms 
8 |  M*LIB |    Queue(Shared ptr)   |   258.85 ms 
9 |  BOOST | Queue MPMC (lockfree   |   368.82 ms 

Model name:                              AMD EPYC 7763 64-Core Processor
