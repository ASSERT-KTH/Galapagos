void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result <= 0)
        return NULL;
    else {
        void *val = av_mallocz(result);
        if (!val)
            return NULL;
        else
            return val;
    }
}