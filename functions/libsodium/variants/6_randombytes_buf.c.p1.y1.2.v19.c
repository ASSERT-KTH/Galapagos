Variant 1:

void randombytes_buf(void * const buf, const size_t size) {
    if (size) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 2:

void randombytes_buf(void * const buf, const size_t size) {
    if (!size) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 3:

void randombytes_buf(void * const buf, const size_t size) {
    randombytes_init_if_needed();
    if (size <= (size_t) 0U) return;
    implementation->buf(buf, size);
}

Variant 4:

void randombytes_buf(void * const buf, const size_t size) {
    if (size == 0) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}

Variant 5:

void randombytes_buf(void * const buf, const size_t size) {
    if (size > 0) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}