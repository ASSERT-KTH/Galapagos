void randombytes_buf(void *buf, size_t size)
{
    if (implementation == NULL) {     
        randombytes_init();
    }
    if (size > 0){
        implementation->buf(buf, size);
    }
}