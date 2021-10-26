##1: ifcfg-eth0 편집 (영구 적용)

설정 파일을 편집한다. 적용하려면 네트워크 재시작해야 한다.

vi /etc/sysconfig/network-scripts/ifcfg-eth0 (ifconfig 찾아서 변경할 eth 찾아서 해당 ip 변경) 
service network restart   
ifconfig  //명령어 통해 변경 확인  

 

##2: ifconfig 편집 (임시 적용)

실행 즉시 IP가 변경된다. 설정 파일은 기존 그대로이기 때문에 네트워크 재시작 또는 재부팅하면 원래대로 바뀐다.  

ifconfig 장치명 아이피  
 - ifconfig eth0 135.79.246.80    

 

##3: setup 편집 (영구 적용)

저장 후 종료하면 설정파일이 수정되고 적용도 된다.    

setup  
Network configuration --- Device configuration --- eth0 (eth0) - Ethernet --- Static IP 값을 변경  
OK --- Save --- Save&Quit --- Quit  
