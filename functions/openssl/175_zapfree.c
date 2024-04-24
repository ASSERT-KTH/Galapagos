zapfree(void *ptr, size_t len)
{
    if (ptr != NULL) {
        zap(ptr, len);
        free(ptr);
    }
}