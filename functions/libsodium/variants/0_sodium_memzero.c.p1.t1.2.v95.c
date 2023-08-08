A program variant of the provided function could change the method for zeroing memory, to remove all platform-specific behaviors. Only built-in C function memset() is used to accomplish the function's tasks. To maintain its original functionality, the function will be portable to any platform that supports the C standard library. Here is a version:


void sodium_memzero(void * const pnt, const size_t len) {
    volatile unsigned char *pnt_ = (volatile unsigned char*) pnt;
    size_t i;
    for (i = 0; i < len; i++) {
        pnt_[i] = 0;
    }
}

This function also zeroizes the given memory, just like the original function. However, optimizations in terms of platform- and compiler-specific implementations have been discarded.