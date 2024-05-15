gssalloc_malloc(size_t size)
{
    char *p = calloc(size + 8, 1);

    memcpy(p, "gssalloc", 8);
    return p + 8;
}