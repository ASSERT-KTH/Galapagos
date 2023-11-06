void randombytes_buf(void* buf, size_t size)
{
    if(size <= 0U) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}