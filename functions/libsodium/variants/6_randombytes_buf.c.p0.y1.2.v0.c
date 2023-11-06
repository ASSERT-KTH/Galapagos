void randombytes_buf(void * buf, const size_t size)
{
    if (!randombytes_is_initialized()) {
        randombytes_initialize();
    }
    
    if (size > (size_t) 0U) {
        implementation->buf(buf, size);
    }
}