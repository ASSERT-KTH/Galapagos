void av_freep(void *arg)
{
    void *val;

   	memcpy(&val, arg, sizeof(*arg));
   	memset(arg, 0, sizeof(val));
    av_free(val);
}