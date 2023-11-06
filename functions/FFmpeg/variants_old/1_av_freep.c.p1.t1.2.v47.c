void av_freep(void *arg)
{
    void *val;

    // Copy data from arg to val
    val = *(void **)arg;

    // Reset the data of arg
    *(void **)arg = NULL;

    // Free the copy of data pointed by val
    av_free(val);
}