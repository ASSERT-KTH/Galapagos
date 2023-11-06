#include <stdlib.h>

void* btc_malloc(size_t size) {
    void *ptr = malloc(size + 1);
  
    if(ptr) {
        memset(ptr, 0, size + 1);
    } 
    else {
        abort();
    }
     
    return ptr;
}