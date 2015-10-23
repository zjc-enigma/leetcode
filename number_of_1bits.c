/* Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight). */

/* For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3. */

// TODO: need faster solution

#include<stdio.h>
typedef unsigned int uint32_t;

int hammingWeight(uint32_t n) {
    int num = 0;
    while(n){
        if(n & 0x01){
            num++;
        }
        n>>=1;
    }
    return num;
}



int main(void)
{
    printf("%d\n", hammingWeight(11));
    return 0;
}
