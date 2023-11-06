void randombytes_buf(void * const buf, const size_t size)
{
    if (!implementation || !implementation->random) {
        randombytes_init();   /* Initialize if needed */
    }
    if(size > 0U) {
        implementation->buf(buf, size);
    }
}