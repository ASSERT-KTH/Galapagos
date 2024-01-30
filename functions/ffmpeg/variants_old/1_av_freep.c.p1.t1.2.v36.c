Here's a variant of the original function that maintains its functionality:


void av_freep(void *arg)
{
    void *vpointer = NULL;
    if(arg) {
        memcpy(&vpointer, arg, sizeof(vpointer));
        memset(arg, 0, sizeof(vpointer));
        av_free(vpointer);
    }
}

The main difference here is the usage of `memset` instead of `memcpy` to set the value at `arg` to NULL. This doesn't change functionality, as in both cases it ends with `arg` being NULL.