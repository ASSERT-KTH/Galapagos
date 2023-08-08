The revised function works the same way as the original, but has an additional step where it checks if both the size and number of elements are more than 0 before doing multiplication. This way we can avoid unnecessary calculations when dealing with null or zero sizes.


void* av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t total;
    if (size_mult(nmemb, size, &total) < 0)
        return NULL;
    return av_mallocz(total);
}
