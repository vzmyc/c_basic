# Create docker image for ARM architecture on Host PC

Prerequisites 
```
Docker image 생성시 아래의 소프트웨어가 설치되어 있어야 합니다. 

Install docker. 아래 1번의 블로그 혹은 docker 홈페이지에서 빌드 환경에 맞는 OS를 선택하여 docker를 설치합니다. 

https://www.docker.com/blog/getting-started-with-docker-for-arm-on-linux/ 

https://docs.docker.com/get-docker/ 
```
 

 

## Install buildx for building docker targeting multi-architecture 

Download buildx binary from https://github.com/docker/buildx/releases/tag/v0.2.0 

For linux-amd64:  $wget https://github.com/docker/buildx/releases/download/v0.2.0/buildx-v0.2.0.linux-amd64 

Move the downloaded buildx binary to ~/.docker/cli-plugins 

If cli-plugins directory does’t exsit yet, create it. 

Rename the buildx binary to “docker-buildx” and make it executable 

$ mv buildx-v0.2.0.linux-amd64 docker-buildx 

$ chmod +x docker-buildx 

Run the version command to confirm buildx is now installed 

$ ./docker-buildx version 
github.com/docker/buildx v0.2.0-36-g4e61674 4e61674ac805117794cc55475a62efdef0be9818 

 

## Build docker image with sample app 

Register Arm executables to run on x64 machines 
이 과정을 하지 않으면 x86 HOST pc 에서 arm용으로 생성된 docker image 가 실행될 수 없다.단, 이 과정은 테스트시 원활한 확인을 위한 것이지, ARM 용 docker image 를 만드는데 필요한 과정은 아니다.  

 
```
$ docker run --rm --privileged docker/binfmt:820fdd95a9972a5308930a2bdfb8573dd4447ad3 
Unable to find image 'docker/binfmt:820fdd95a9972a5308930a2bdfb8573dd4447ad3' locally 
820fdd95a9972a5308930a2bdfb8573dd4447ad3: Pulling from docker/binfmt 
2527e2e5bb29: Pull complete 
123e7058f4ec: Pull complete 
e0d3f1463c7a: Pull complete 
Digest: sha256:1a3f78d507c9b2115222924aa1c2b0d9f553e47e86f7518d9cae7567bf290ed1 
Status: Downloaded newer image for docker/binfmt:820fdd95a9972a5308930a2bdfb8573dd4447ad3 
```
```  
$ cat /proc/sys/fs/binfmt_misc/qemu-aarch64 
enabled 
interpreter /usr/bin/qemu-aarch64 
flags: OCF 
offset 0 
magic 7f454c460201010000000000000000000200b7 
mask ffffffffffffff00fffffffffffffffffeffff 
```
 

Create a multi-architecture build instance 
```
$ docker buildx create --name mybuilder 
$ docker buildx use mybuilder 
$ docker buildx inspect --bootstrap 
Name: mybuilder 
Driver: docker-container 
  
Nodes: 
Name: mybuilder0 
Endpoint: unix:///var/run/docker.sock 
Status: running 
Platforms: linux/amd64, linux/arm64, linux/arm/v7, linux/arm/v6  
```
 

## Create sample app & modify DockerFile 

Hello.c 
```c
/* 
* hello.c 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
  
#ifndef ARCH 
#define ARCH "Undefined" 
#endif  
  
int main() { 
  printf("Hello, my architecture is %s\n", ARCH); 
  exit(0); 
} 
```
 
```
# 
# Dockerfile 
# 
FROM alpine AS builder 
RUN apk add build-base 
WORKDIR /home 
COPY hello.c . 
RUN gcc "-DARCH=\"`uname -a`\"" hello.c -o hello 
  
FROM alpine 
WORKDIR /home 
COPY --from=builder /home/hello . 
ENTRYPOINT ["./hello"] 
```
 

## Build docker 
$ docker buildx build --platform linux/arm64 -t <your dockerhub id>/hello . --push 

 

## Create docker image using Yocto recipe   
TBD  

## Running Docker at target hardware 
```
$ docker run docker.io/liveeasily/hello:latest@sha256:26f43ede2c8c324c411559694a8357289972a98d502fa60dae1d0b16073e6ecf 
Unable to find image 'liveeasily/hello:latest@sha256:26f43ede2c8c324c411559694a8357289972a98d502fa60dae1d0b16073e6ecf' locally 
sha256:26f43ede2c8c324c411559694a8357289972a98d502fa60dae1d0b16073e6ecf: Pulling from liveeasily/hello 
58ab47519297: Pull complete 
02222c97cb85: Pull complete 
Digest: sha256:26f43ede2c8c324c411559694a8357289972a98d502fa60dae1d0b16073e6ecf 
Status: Downloaded newer image for liveeasily/hello@sha256:26f43ede2c8c324c411559694a8357289972a98d502fa60dae1d0b16073e6ecf 
Hello, my architecture is Linux buildkitsandbox 5.4.0-77-generic #86-Ubuntu SMP Thu Jun 17 02:35:03 UTC 2021 aarch64 Linux 
```
