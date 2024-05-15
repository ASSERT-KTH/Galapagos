k5memdup(const void *in, size_t len, krb5_error_code *code)
{
    void *ptr = k5alloc(len, code);

    if (ptr != NULL && len > 0)
        memcpy(ptr, in, len);
    return ptr;
}