Variant 1:


void randombytes_buf(void * const buf, const size_t size) {
    if (size == (size_t) 0U)
        return;
    
    randombytes_init_if_needed();
    
    implementation->buf(buf, size);
}


Variant 2:


void randombytes_buf(void * const buf, const size_t size) {
    bool call_implementation = (size > (size_t) 0U) ? true : false;
    
    randombytes_init_if_needed();

    if(call_implementation) {
        implementation->buf(buf, size);
    }
}


Variant 3:


void randombytes_buf(void * const buf, const size_t size) {
    randombytes_init_if_needed();
    
    if(size == 0)
        return;
    
    implementation->buf(buf, size);
}


Variant 4:


void randombytes_buf(void * const buf, const size_t size) {
    randombytes_init_if_needed();

    if (!(size <= (size_t) 0U)) {
        implementation->buf(buf, size);
    }
}
