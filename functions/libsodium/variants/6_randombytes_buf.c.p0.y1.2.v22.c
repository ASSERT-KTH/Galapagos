void randombytes_buf(void * const buf, const size_t size)
{
    if (size_t_init_if_needed()) {
        if(size > 0 ) {
            implementation->buf(buf, size); 
        }
    }
}