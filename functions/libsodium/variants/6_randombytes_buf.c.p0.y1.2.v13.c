Here's an alternative but equivalent C code:


void randombytes_buf(void * const dest, const size_t len)
{
    if (!len) 
        return;

    randombytes_init_if_needed();

    implementation->buf(dest, len);
}
