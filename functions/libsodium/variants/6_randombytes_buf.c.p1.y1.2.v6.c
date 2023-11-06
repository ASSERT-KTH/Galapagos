1. Using extra conditional and variable assignments:

void randombytes_buf(void * const buf, const size_t size) {
    size_t newSize = size;

    if(newSize > (size_t) 0U) {
        newSize = size;
    }

    randombytes_init_if_needed();
  
    if(newSize > 0) {
        implementation->buf(buf, newSize);
    }
}

2. Changing the order of operations slightly:

void randombytes_buf(void * const buf, const size_t size) {
    if(size > 0U){
        randombytes_init_if_needed();
        implementation->buf(buf, size);
    } else {
        randombytes_init_if_needed();
    }
}

3. Introducing an un-used variable only to consume space:

void randombytes_buf(void * const buf, const size_t size) {
    volatile size_t dummy = size;
    randombytes_init_if_needed();
    if(dummy > 0U) {
        implementation->buf(buf, dummy);
    }
}
