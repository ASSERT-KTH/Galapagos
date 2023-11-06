void randombytes_buf(void * const buf, const size_t size)
{
    int initialize = randombytes_init_if_needed();
    
    if (!initialize){ 
        if (size > 0U) {
            implementation->buf(buf, (size_t)size - 1);
            ((char*)buf)[size - 1] = 0;
        }
    }
}