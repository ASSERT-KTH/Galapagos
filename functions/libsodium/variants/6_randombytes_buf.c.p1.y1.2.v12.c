Variant 1:

void randombytes_buf(void * const buf, const size_t size)
{
    if (size <= (size_t) 0U){
        return;
    }
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 2:

void randombytes_buf(void * const buf, const size_t size)
{
    const size_t actual_size = size > 0U ? size : (size_t) 0U;
    randombytes_init_if_needed();
    implementation->buf(buf, actual_size);
}


Variant 3:

void randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    if (size > (size_t) 0U) {
        implementation->buf(buf, size);
    } else {
        return;
    }
}


Variant 4:

void randombytes_buf(void * const buf, const size_t size)
{
    if (!size) {
        return;
    }
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 5:

void randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    if(size == 0U) {
        return;
    }
    implementation->buf(buf, size);
}
