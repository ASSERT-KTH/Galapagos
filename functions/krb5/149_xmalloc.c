void *xmalloc (size_t sz)
{
    void *ret = malloc (sz);
    if (ret == 0 && sz != 0) {
        perror (prog_name);
        exit (1);
    }
    return ret;
}