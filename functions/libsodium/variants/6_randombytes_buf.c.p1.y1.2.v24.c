Variant 1:

void randombytes_buf(void * const buf, const size_t size){
    if (size > (size_t) 0U) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 2:

void randombytes_buf(void * const buf, const size_t size){
    size_t modSize = size > (size_t) 0U ? size : (size_t) 0U;
    randombytes_init_if_needed();
    implementation->buf(buf, modSize);
}


Variant 3:

void randombytes_buf(void * const buf, const size_t size){
    if (!size) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 4:

void randombytes_buf(void * const buf, const size_t size){
    randombytes_init_if_needed();
    implementation->buf(buf, size > 0U ? size : 0U);
}
