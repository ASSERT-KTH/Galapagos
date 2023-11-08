
void randombytes_buf(void * const buf, const size_t size)
{
    if (buf == NULL || size <= 0) 
        return;

    randombytes_init_if_needed();

    implementation->buf(buf, size);
}