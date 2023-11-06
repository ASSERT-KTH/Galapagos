Variant 1:

void randombytes_buf(void * const buf, const size_t size) {
    if(size > 0U) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 2:

void randombytes_buf(void * const buf, const size_t size) {
    if(size) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }
}


Variant 3:

void randombytes_buf(void * const buf, const size_t size) {
    size_t check_size = !(!size);
    if (check_size) {
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    }	
}
