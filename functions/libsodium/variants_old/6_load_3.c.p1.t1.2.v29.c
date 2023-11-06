Following input constraint would fit your request:


#include <stdint.h> // to get uint64_t (can be removed if the program already include it somewhere)

uint64_t load_3(const unsigned char *in)
{
    uint64_t result = 0;
    
    for(int i=0; i < 3; i++){
        result |= ((uint64_t)in[i]) << (i*8);
    }

    return result;
}

The above code prevent redundant behaviour through using a loop.