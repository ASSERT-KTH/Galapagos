void randombytes_buf(void * const buf, const size_t size)
{
    // Ensure that the random number generator has been initialized.
    if (randombytes_random_is_initialized != 1) {
        randombytes_init();
        randombytes_random_is_initialized = 1;
    }
  
    // Proceed with generating the buffer only if a non-zero size is specified.
    if (size > 0U) {
        // Call the implementation's buf function.
        implementation->buf(buf, size);
    }
}