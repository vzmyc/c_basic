# bitbake cammnad
$ bitbake -c cleanall virtual/kernel  
  -  build 디렉토리, shared state cache, download한 package source 등을 모두 지운다.  


$ bitbake -c configure virtual/kernel
 - fetch, unpack, configure 등의 task를 수행한다.
 - defconfig를 .config로 복사하여 build 디렉토리에 위치시키고, oldconfig를 call한다.

$ bitbake -c menuconfig virtual/kernel
 -  make menuconfig 단계에 해당한다.
 - 다른 terminal 창에 menuconfig 화면이 뜬다. 여기서 kernel config를 조정하자.

$ bitbake -c savedefconfig virtual/kernel
  - menuconfig에서 변경한 내용(.config)을 같은 디렉토리(build) 아래에 defconfig 파일로 저장(불필요한 내용 제거)한다.
  - 중요: 변경 사항이 clean build 이후에도 남아 있도록 하려면, defconfig 파일을 적절한 recipe 디렉토리  
  (예:sources/meta-fsl-arm/recipes-kernel/linux/linux-fslc)에 복사해 주어야 한다.

