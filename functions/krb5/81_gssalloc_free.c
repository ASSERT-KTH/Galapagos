gssalloc_free(void *value)
{
    char *p = (char *)value - 8;

    if (value == NULL)
        return;
    if (memcmp(p, "gssalloc", 8) != 0)
        abort();
    free(p);
}