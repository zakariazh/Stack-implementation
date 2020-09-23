#! /bin/bash

gcc -I${PWD} -c stack.c -fpic 
gcc -shared stack.o -o libstack.so
sudo cp ./libstack.so /usr/local/lib/stack_m/
gcc -L/usr/local/lib/stack_m test.c -I${PWD} -o test -lstack
./test