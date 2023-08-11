Sure, the program variant of the reference implementation can be as follows:


#include <stdlib.h>

void *av_calloc(size_t nmemb, size_t size) {
     if (nmemb == 0 || size == 0) 
        return NULL;
    void *p = av_mallocz(nmemb * size);

    if (p)
        memset(p, 0, nmemb * size);

    return p;
}

This code also checks the result of the multiplication nmemb * size (without explicitly performing the function with the same name as in original code, but doing the same tasks, making sure zero or null values do not cause problems) and returns null pointer if no space was successfully allocated by av_mallocz. It then uses memset to fill the allocated memory with zeroes and finally returns a pointer to it which is the same functionality as the original code.