void randombytes_buf(void * const buf, const size_t size)
{
    if (size != (size_t) 0U) {
        if(!randombytes_initialized()) {
            randombytes_initialize();
        }
        implementation->buf(buf, size);
    }
}