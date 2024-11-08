CC=       	gcc
CFLAGS= 	-std=gnu99 -Wall -lmemalloc -pedantic -ansi --std=c99
CLFLAGS= 	-std=gnu99 -Wall -pedantic -ansi
LDFLAGS=
LIBRARIES=      lib/libmemalloc.a lib/libmemalloc_tracy.a

all:   unit_test benchmark1 benchmark2 benchmark3 benchmark4 benchmark5 benchmark1_tracy benchmark2_tracy benchmark3_tracy benchmark4_tracy benchmark5_tracy

debug: CFLAGS += -g -gdwarf-2
debug: all

release: CFLAGS += -O2 -march=native
release: all

release_debug: CFLAGS += -O2 -march=native -g
release_debug: all

benchmark1: benchmark1.o libmemalloc.a
	gcc -o benchmark1 benchmark1.o -L. -lmemalloc $(CFLAGS)

benchmark2: benchmark2.o libmemalloc.a
	gcc -o benchmark2 benchmark2.o -L. -lmemalloc $(CFLAGS)

benchmark3: benchmark3.o libmemalloc.a
	gcc -o benchmark3 benchmark3.o -L. -lmemalloc $(CFLAGS)

benchmark4: benchmark4.o libmemalloc.a
	gcc -o benchmark4 benchmark4.o -L. -lmemalloc $(CFLAGS)

benchmark5: benchmark5.o libmemalloc.a
	gcc -o benchmark5 benchmark5.o -L. -lmemalloc $(CFLAGS)

benchmark1_tracy: benchmark1.o libmemalloc_tracy.a
	gcc -o benchmark1_tracy benchmark1.o -L. -lmemalloc_tracy -lTracyClient $(CFLAGS)

benchmark2_tracy: benchmark2.o libmemalloc_tracy.a
	gcc -o benchmark2_tracy benchmark2.o -L. -lmemalloc_tracy -lTracyClient $(CFLAGS)

benchmark3_tracy: benchmark3.o libmemalloc_tracy.a
	gcc -o benchmark3_tracy benchmark3.o -L. -lmemalloc_tracy -lTracyClient $(CFLAGS)

benchmark4_tracy: benchmark4.o libmemalloc_tracy.a
	gcc -o benchmark4_tracy benchmark4.o -L. -lmemalloc_tracy -lTracyClient $(CFLAGS)

benchmark5_tracy: benchmark5.o libmemalloc_tracy.a
	gcc -o benchmark5_tracy benchmark5.o -L. -lmemalloc_tracy -lTracyClient $(CFLAGS)

unit_test: main.o libmemalloc.a
	gcc -o unit_test main.o -L. -lmemalloc $(CFLAGS)

main.o: src/main.c
	gcc  -c  -Wall -Wno-self-assign -Wno-nonnull src/main.c $(CFLAGS) -Isrc/memalloc -Iext/tinytest

benchmark1.o: benchmarks/benchmark1.c
	gcc  -c -Wall benchmarks/benchmark1.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

benchmark2.o: benchmarks/benchmark2.c
	gcc  -c -Wall benchmarks/benchmark2.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

benchmark3.o: benchmarks/benchmark3.c
	gcc  -c -Wall benchmarks/benchmark3.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

benchmark4.o: benchmarks/benchmark4.c
	gcc  -c -Wall benchmarks/benchmark4.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

benchmark5.o: benchmarks/benchmark5.c
	gcc  -c -Wall benchmarks/benchmark5.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

memalloc.o: src/memalloc/memalloc.c
	gcc  -c  -Wall src/memalloc/memalloc.c $(CFLAGS) -Isrc/memalloc -Iext/tracy-0.10

memalloc_tracy.o: src/memalloc/memalloc.c
	gcc  -c  -Wall src/memalloc/memalloc.c $(CFLAGS) -o memalloc_tracy.o -Isrc/memalloc -Iext/tracy-0.10 -DTRACY_ENABLE -L. -lTracyClient

libmemalloc.a: memalloc.o
	ar rcs libmemalloc.a memalloc.o

libmemalloc_tracy.a: memalloc_tracy.o
	ar rcs libmemalloc_tracy.a memalloc_tracy.o 

clean:
	rm -f *.o *.a unit_test main benchmark1 benchmark2 benchmark3 benchmark4 benchmark5 benchmark1_tracy benchmark2_tracy benchmark3_tracy benchmark4_tracy benchmark5_tracy

.PHONY: all clean
