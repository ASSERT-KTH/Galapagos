Here's a variant of the function that swaps out the preprocessor directives for a runtime detection of endianness. The runtime checks for system endianness and performs appropriate action based on it.


#include <stdint.h>
#include <string.h>

uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t z = 0;
    unsigned char endianness_check[2] = { 1, 0 };
    
    if (*(short *)endianness_check == 1) {  // little-endian
        memcpy(&z, xp, sizeof(z));
    } else {  // big-endian
        z = ((uint32_t)xp[0] <<  0) | ((uint32_t)xp[1] <<  8) | ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24);
    }

    return z;
}


In this version of the function, we can see that it finds endianness dynamically and changes behavior depending on system it's running at. This way despite small changes in structure the functionality remains as it was in your original sample. It first checks if the system it's current running is little endian or not by creating an array of two bytes, with the lowest byte set to 1 and the other byte set to 0. Then it checks the integer representation of these two bytes, if it is equal to 1 system is little endian else if it equals to 256 system is big endian. Based on that, the function either directly copies the 4 bytes into the final result or performing the shift and bitwise or operation. This eliminates need for conditional compile time debugging checks and ensures that function behaves the same way as it was intended in original line by line.