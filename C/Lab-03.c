int swap_endian(int x){
    int a=(x >> 24) & 0x000000FF;
    int b=(x >> 8)  & 0x0000FF00;
    int c=(x << 8)  & 0x00FF0000;
    int d=(x << 24) & 0xFF000000;
     return a | b | c | d;
}
#include <stdio.h>

int main(){
    int x=0x01234567;
    int y=swap_endian(x);
    printf("0x%x", y);

    return 0;
}
