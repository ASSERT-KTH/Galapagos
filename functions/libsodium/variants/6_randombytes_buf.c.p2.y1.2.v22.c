void randombytes_buf(void * const buf, const size_t size)
{
    // The initialization mechanism can't harm if executed multiple times,
    // relies on randombytes_init_if_needed implementation.
    if (!randombytes_is_initialized()) randombytes_init_if_needed(); 

    // Filter out irrelevant cases immediately and delegate
    // the actual buffer filling to the chosen implementation.
    if (size != (size_t) 0U) { 
        implementation->buf(buf, size); 
    }
    else {
        memset(buf, 0, size);
    }
}