void *av_calloc(size_t nmemb, size_t size)
{
    size_t product_size;
    
    // Perform the multiplication and check for overflow
    if (size_mult(nmemb, size, &product_size) >= 0) 
        return av_mallocz(product_size);

    // If overflow occurred
    return NULL;
}