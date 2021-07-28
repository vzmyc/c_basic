#include <stdio.h>  
int main(void)

{
    printf("선행처리가 수행된 날짜는 %s입니다.\n", __DATE__);
    printf("선행처리가 수행된 시간은 %s입니다.\n", __TIME__);
    printf("현재 소스 파일에서 처리중인 라인 번호는 %d입니다.\n", __LINE__);
    printf("__STDC__ : %d\n", __STDC__);
    printf("__STDC_HOSTED__ : %d\n", __STDC_HOSTED__);

    return 0;

}
