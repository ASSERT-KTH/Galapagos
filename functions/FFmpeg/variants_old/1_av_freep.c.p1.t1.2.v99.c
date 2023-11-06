Sure, here's an alternative implementation:


void av_freep(void *arg)
{
    void **p = (void **)arg;
    void *val = *p;
    *p = NULL;
    av_free(val);
}

This version of the function accomplishes the same task but does so differently. The provided arg is treated as a pointer to a pointer. It then assigns the address that p points to, to the val. It then changes referenced value by original pointer locations to null, using pointer referencing. After that, it frees the space val pointed earlier (which was originally assigned by arg). This preserves the original behavior of the cleanup helper function, where after object reference is freed - replaced with NULL value as a good practice.