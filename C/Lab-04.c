//I used Fibonacci LFSR
// as instructed I created function named “func_lfsr32” which is type of unsigned long and takes number seed which is provided.
//In function first thing we need to get is Bit which will be added to hex number from left, using binary shift.
//In Fibonacci 3 XOR-s are used. To compare all the taps we need to shift them to last bit and use XOR to compare all of them. After XOR is done we need only last bit so we use mask 0x00000001 to only store last bit.
//After that we shift needed bit to right by 31 bit.
//At last we shift seed by one bit to right and user OR statement to add the bit we got earlier.
//In ‘main’ function I used for loop to generate 20 different numbers.
#include<stdio.h>
unsigned long func_lfsr32(unsigned long seed){
    unsigned int bit_To_Add;
    //Only this lines logic was taken from Wikipedia.
    bit_To_Add = ((seed >> 0) ^ (seed >> 2) ^ (seed >> 6) ^ (seed >> 7)) & 0x00000001;
    bit_To_Add = (bit_To_Add<<31);
    seed=((seed>>1) | bit_To_Add);
    return seed;
}

int main()
{
    unsigned long lfsr32=0x5AA5FF00;
    for(int i=0;i<=20;i++){
        lfsr32=func_lfsr32(lfsr32);
        printf("0x%lx\n", lfsr32);
    }
    return 0;
}
