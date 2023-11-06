Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level >=0 )
        av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(avcl != NULL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(fmt != NULL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


Please note, this transitions involve checks for boundary / normal operation constraints in the specific field. 

In any case outlined, the va_list parameter is defined once only if needed and ever handed off to the av_vlog function as requsted. The responsibility of handling possible NULL or Un-intended values are passed on or done prior to constructing the va_list parameters.