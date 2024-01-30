void av_freep(void *arg)
{
    void *val;

    if(arg != NULL) 
    {
        memcpy(&val, arg, sizeof(val));
        memcpy(arg, &val, sizeof(val)); 
        val = NULL; //setter val to NULL rather than manipulating the original memory it points to 
        av_free(val);
    }
}