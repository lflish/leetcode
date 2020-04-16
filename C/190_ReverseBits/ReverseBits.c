#include <stdio.h>

typedef unsigned int uint32_t;

uint32_t reverseBits(uint32_t n) {

        int i = 0;
        uint32_t ret = 0;
        uint32_t d = 0;

        for(i = 0; i < 32 ; i++){

                ret <<= 1;
                
                d = n & 0x01;
                
                ret |= d;

                n >>= 1; 
        }   
        return ret;
}