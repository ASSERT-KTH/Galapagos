void randombytes_buf(void * const buf, const size_t size)
{
    if (!(size > (size_t) 0U)) {
        return;
    }
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}