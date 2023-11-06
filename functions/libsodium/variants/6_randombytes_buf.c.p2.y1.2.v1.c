void randombytes_buf(void * const buf, const size_t size)
{
    size_t i = size;
    randombytes_init_if_needed();
    
    if (i > (size_t)0U) {
        --i;

        char *b = (char*)buf;
        b += i;
        implementation->buf((void*)b, (size_t)1U);

        while (i > (size_t)0U) {
            --i;

            b = (char*)buf;
            b += i;
            implementation->buf((void*)b, (size_t)1U);
        }
    }
}