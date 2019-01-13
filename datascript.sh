#!/bin/bash

./bench_remove 5000000 1 215899614 >	data/remove/llpq215899614.dat
./bench_remove 5000000 1 193948603	> data/remove/llpq193948603.dat
./bench_remove 5000000 1 843574597	> data/remove/llpq843574597.dat
./bench_remove 5000000 1 874432839	> data/remove/llpq874432839.dat
./bench_remove 5000000 1 322625760 > data/remove/llpq322625760.dat
./bench_remove 5000000 1 515409840	> data/remove/llpq515409840.dat
./bench_remove 5000000 1 897288435	> data/remove/llpq897288435.dat
./bench_remove 5000000 1 426677122	> data/remove/llpq426677122.dat
./bench_remove 5000000 1 368758747	> data/remove/llpq368758747.dat
./bench_remove 5000000 1 196253231 > data/remove/llpq196253231.dat

./benchheap_remove 5000000 1 215899614 >	data/remove/heappq215899614.dat
./benchheap_remove 5000000 1 193948603 > data/remove/heappq193948603.dat
./benchheap_remove 5000000 1 843574597	> data/remove/heappq843574597.dat
./benchheap_remove 5000000 1 874432839	> data/remove/heappq874432839.dat
./benchheap_remove 5000000 1 322625760 > data/remove/heappq322625760.dat
./benchheap_remove 5000000 1 515409840	> data/remove/heappq515409840.dat
./benchheap_remove 5000000 1 897288435	> data/remove/heappq897288435.dat
./benchheap_remove 5000000 1 426677122	> data/remove/heappq426677122.dat
./benchheap_remove 5000000 1 368758747	> data/remove/heappq368758747.dat
./benchheap_remove 5000000 1 196253231 > data/remove/heappq196253231.dat


:'
./bench 5000000 1 215899614 >	data/insert/llpq215899614.dat
./bench 5000000 1 193948603	> data/insert/llpq193948603.dat
./bench 5000000 1 843574597	> data/insert/llpq843574597.dat
./bench 5000000 1 874432839	> data/insert/llpq874432839.dat
./bench 5000000 1 322625760 > data/insert/llpq322625760.dat
./bench 5000000 1 515409840	> data/insert/llpq515409840.dat
./bench 5000000 1 897288435	> data/insert/llpq897288435.dat
./bench 5000000 1 426677122	> data/insert/llpq426677122.dat
./bench 5000000 1 368758747	> data/insert/llpq368758747.dat
./bench 5000000 1 196253231 > data/insert/llpq196253231.dat

./benchheap_insert 5000000 1 215899614 >	data/insert/heappq215899614.dat
./benchheap_insert 5000000 1 193948603	> data/insert/heappq193948603.dat
./benchheap_insert 5000000 1 843574597	> data/insert/heappq843574597.dat
./benchheap_insert 5000000 1 874432839	> data/insert/heappq874432839.dat
./benchheap_insert 5000000 1 322625760 > data/insert/heappq322625760.dat
./benchheap_insert 5000000 1 515409840	> data/insert/heappq515409840.dat
./benchheap_insert 5000000 1 897288435	> data/insert/heappq897288435.dat
./benchheap_insert 5000000 1 426677122	> data/insert/heappq426677122.dat
./benchheap_insert 5000000 1 368758747	> data/insert/heappq368758747.dat
./benchheap_insert 5000000 1 196253231 > data/insert/heappq196253231.dat
'
