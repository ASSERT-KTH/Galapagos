void randombytes_buf(void * const buf, const size_t size)
{
    if (implementation == NULL)
    {
        implementation = randombytes_switchimplementation();
    }
    
    if (size > 0U)
    {
        implementation->buf(buf, size);
    }
}