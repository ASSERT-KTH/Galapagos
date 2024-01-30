Here's a slight variant of the function where it now checks if the allocation is successful or unsuccessful. If unsuccessful, it returns NULL.


#include <stdlib.h>

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;
    void *retval;

    if (size_mult(nmemb, size, &result) < 0) {
        return NULL;
    }

    retval = av_mallocz(result);
    if (retval == NULL) {
        /* We could handle memory allocation failure here, doing something relevant, but let's keep things simple*/
        return NULL;
    }

    return retval;
}


Inside this variant, the function contains more lines but begins the same way. It subsequently assigns the result of the function 'av_mallocz()' to 'retval', tests if it's NULL (i.e., if memory has not been allocated properly because of an error or in case of insufficient space), and returns NULL in that case. However, if everything works fine, the same previous functionality of returning a zero'ed array will be maintained by returning 'retval' at the end.