void randombytes_buf(void * const buf, const size_t size)
{
    if (size == 0U) {
        return;
    }
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}