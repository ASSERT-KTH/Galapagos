k5calloc(size_t nmemb, size_t size, krb5_error_code *code)
{
    void *ptr;

    /* Allocate at least one byte since zero-byte allocs may return NULL. */
    ptr = calloc(nmemb ? nmemb : 1, size ? size : 1);
    *code = (ptr == NULL) ? ENOMEM : 0;
    return ptr;
}