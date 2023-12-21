1. First Variant:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;

    result = nmemb * size;
    if (result / size != nmemb)  // overflow check
        return NULL;

    return av_mallocz(result);
}

2. Second Variant:

void *av_calloc(size_t nmemb, size_t size) {
    if ((nmemb >= INT_MAX || size >= INT_MAX) || (size && nmemb > SIZE_MAX / size))
        return NULL;
        
    return av_mallocz(nmemb * size);
}

3. Third Variant:

void *av_calloc(size_t nmemb, size_t size) {
    if (!nmemb || !size)
        return NULL;
    
    size_t result = nmemb * size;

    // Overflow check
    if (result != 0 && (result < nmemb || result < size))
        return NULL;

    return av_mallocz(result);
}

4. Fourth Variant:

void *av_calloc(size_t nmemb, size_t size) {
    // Check for possible overflow in multiplication, by dividing max possible size by 'size'
    if (nmemb > 0 && size > 0 && ((SIZE_MAX / size) < nmemb))
        return NULL;

    return av_mallocz(nmemb * size);
}

**Note**: These code transformations assume that av_mallocz function calls are handling all other cases such as zero callocing size, maximum sizeof size etc. In each transformed function we have emphasis on checking for overflow(s) because it is mostly forgot when dealing with such calls.