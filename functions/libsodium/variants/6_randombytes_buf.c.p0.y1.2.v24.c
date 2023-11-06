void randombytes_buf(void * const buf, const size_t size)
{
    if(!randombytes_thread_unlocked) {
        randombytes();
    }
    if (size > (size_t) 0U) {
        (randombytes_implementation->buf)(buf, size);
    }
}