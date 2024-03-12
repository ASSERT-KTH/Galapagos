#include <stdlib.h>
#include<stddef.h>

int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char d = 0U; // Removing volatile

    for (i = 0U; i < nlen; i++) {
        d |= n[i];
    }

    return !(d != 0); // Simplifying the return statement
}

int main(int argc, char** argv){
    unsigned char* test = (unsigned char*)malloc(sizeof(char*) * 5);
    int x = sodium_is_zero(test, 5);
    return x;
}

