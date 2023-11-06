
void randombytes_buf(void * const buf, const size_t size)
{
    if (size > 0) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}
