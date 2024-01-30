Here's an equivalent variant for the given function. An early return is introduced when `fmt` is a null pointer. Although C standard library functions dealing with this type of arguments often handle null pointers gracefully, taking this extra step may prevent undefined behavior depending on how `av_vlog` is implemented.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt == NULL)
           return;

    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
