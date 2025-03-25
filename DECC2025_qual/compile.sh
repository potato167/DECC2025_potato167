# for MHC
# /usr/local/bin/g++ -std=c++17  -Wall -O2 -I . $1 -D_GLIBCXX_DEBUG -Wl,-stack_size -Wl,20000000 -o ./a.out
/usr/local/bin/g++ -std=c++20  -Wall -O2 -I . $1 -D_GLIBCXX_DEBUG -o ./a.out
# /usr/local/bin/g++ -std=c++20  -Wall -O2 -I . $1 -o ./a.out