void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(fmt == NULL) return;

    va_list vl;
    va_start(vl, fmt);
    
    char *new_fmt = (char *)malloc((strlen(fmt)+1)*sizeof(char));
    strcpy(new_fmt, fmt);

    av_vlog(avcl, level, new_fmt, vl);

    free(new_fmt);
    va_end(vl);
}