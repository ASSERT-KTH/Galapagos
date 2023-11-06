void randombytes_buf(void * const buf, const size_t size)
{
    if(!(randombytes_initialized_x86(void))) randombytes_init();
    if (size > 0U) {
        implementation->buf(buf, size);
    }
}