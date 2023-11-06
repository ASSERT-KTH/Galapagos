Variant 1:

void randombytes_buf(void * const buf, const size_t size)
{
    if(size == (size_t)0U)
    {
         return;
    }
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}

Variant 2:

void randombytes_buf(void * const buf, const size_t size) 
{
    size > (size_t) 0U ? randombytes_init_if_needed() , implementation->buf(buf, size) : return; 
} 


Variant 3:

void randombytes_buf(void * const buf, const size_t size)
{
    if (size == 0) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


Variant 4:

void randombytes_buf(void * const buf, const size_t size)
{
    if (size <= (size_t)0U) return;
    randombytes_init_if_needed();
    implementation->buf(buf, size);
}
