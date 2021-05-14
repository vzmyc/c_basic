#include <stdio.h>
/*
 * Visual Studio, 
 * GCC 4.0 이상
 * #pragma pack(push, 정렬크기)
 * #pragma pack(pop)
 * 
 * GCC 4.0 미만
 * __attribute__((aligned(정렬크기), packed))
  struct PacketHeader {
    char flags;    // 1바이트
    int seq;    // 4바이트
  } __attribute__((aligned(1), packed));    // GCC 4.0 미만: 1바이트 크기로 정렬
 */
/**
 * #pragma pack(push, 4)
 * struct MyData {
 *     char a;
 *     char b;
 *     int e;    // 순서 바꿈
 *     char c;
 *     char d;   // 순서 바꿈
 *     double f;
 * };
 * #pragma pack(pop)
 */



#pragma pack(push, 1)    // 1바이트 크기로 정렬
struct PacketHeader {
    char flags;    // 1바이트
    int seq;       // 4바이트
};
#pragma pack(pop)        // 정렬 설정을 이전 상태(기본값)로 되돌림

int main()
{
    struct PacketHeader header;

    printf("%d\n", sizeof(header.flags));    // 1: char는 1바이트
    printf("%d\n", sizeof(header.seq));      // 4: int는 4바이트
    printf("%d\n", sizeof(header));          // 5: 1바이트 단위로 정렬했으므로 
                                             // 구조체 전체 크기는 5바이트

    printf("flags offset: %d\n", offsetof(struct PacketHeader, flags));    // 0
    printf("seq ofset: %d\n", offsetof(struct PacketHeader, seq));      // 1

    return 0;
}
