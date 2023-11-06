void* randombytes_buf(void *buf, const size_t size)
{
    if(size == 0)
    {
        return buf;
    }
    randombytes_init_if_needed();

    if (size > (size_t) 0U) {
        implementation->buf(buf, size);
    }   
    return buf;
}