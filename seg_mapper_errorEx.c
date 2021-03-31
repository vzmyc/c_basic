#include <stdio.h>

int main() {

	//  signal 11 (SIGSEGV), code 1 (SEGV_MAPERR) 
	int *p = 0;
	*p = 1; // null을 역참조하기 떄문에 SIGEGV 발생

        return 0;
}       

