Here is an alternate implementation that should be equivalent:

void randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    if (size <= (size_t) 0U) return;
    implementation->buf(buf, size);
}