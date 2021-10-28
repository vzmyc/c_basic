## Create sample app(hello world) 
```c
/* 

* hello.c 

*/ 

#include <stdio.h> 

#include <stdlib.h> 

  

int main() { 

  printf("Hello, kefico!\n"); 

  exit(0); 

} 
```
 

## Build Sample app  

Cross compile 필요.   
따라서 Host에 toolcahin이 없다면 설치필요.   
 - $ sudo apt install gcc-9-aarch64-linux-gnu   

 - $ aarch64-linux-gnu-gcc-9 --static -o test hello.c   

 - $ file test  
```
test: ELF 64-bit LSB executable, ARM aarch64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=400b2c455cdafe569c1a1c7e6f748eacd6c9511a, for GNU/Linux 3.7.0, not stripped 
```

## How to execute arm binary
- sudo apt-get install qemu-user-static
- $ qemu-aarch64-static test