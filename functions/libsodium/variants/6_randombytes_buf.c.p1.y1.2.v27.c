Variant 1:

void randombytes_buf(void * const buf, const size_t size) {
    if (size > (size_t) 0U) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 2:

void randombytes_buf(void * const buf, const size_t size) {
    if ((int)size > 0) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 3:

void randombytes_buf(void * const buf, const size_t size) {
    if (!size) return;

    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 4:

void randombytes_buf(void * const buf, const size_t size) {
    size_t size_non_zero = size > 0U ? size : 0U;

    randombytes_init_if_needed();
    if (size_non_zero) {
        implementation->buf(buf, size);
    }
}
