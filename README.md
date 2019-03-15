# os-basic-programs
Collection of basic programs that I created on Operation Systems course. Most of them are just for educational use (for example Kopiowanko and Kopiowanko2 are very very basic compared to unix cp). 

List of programs:
1. Kopiowanko — program for copying two files. Uses C library's functions. 
2. Kopiowanko2 — same as Kopiowanko, but works on unix functions (very slow for small buffers!). 

Each program is simple to compile e.g. with gcc:
gcc kopiowanko.c -o kopiowanko

Programs usage:
1. ./kopiowanko source_file destination_file buffer_size (e.g.: ./kopiowanko ~/doc/myfoto.png ~/doc/myfotocopy.png 512).
2. ./kopiowanko2 source_file destination_file buffer_size (e.g.: ./kopiowanko2 ~/doc/myfoto.png ~/doc/myfotocopy.png 512).
