Version 1:

void randombytes_buf(void * const buf, const size_t size)
{
    if (size > 0U) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}

Version 2:

void randombytes_buf(void * const buf, const size_t size) 
{
    randombytes_init_if_needed();
    if (size) {
        implementation->buf(buf, size);
    }
}

Version 3:

void randombytes_buf(void * const buf, const size_t size) 
{
    if (!size) {
        return;
    }
    
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}

Version 4:

void randombytes_buf(void * const buf, const size_t size) 
{
    if (size > (size_t)0U) {
        randombytes_init_if_needed();
        if(implementation != NULL) {
            implementation->buf(buf, size);
        }
    }
}
