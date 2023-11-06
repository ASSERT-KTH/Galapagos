void av_freep(void *arg)
{
    void *val;

    if (arg != NULL)
    {
        memcpy(&val, arg, sizeof(val));

        if (val)
        {
            av_free(val);
        }

        memcpy(arg, &(void *){ NULL }, sizeof(val));
    }
}