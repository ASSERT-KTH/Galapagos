The given function is already a simple wrapper function with very performing a self-contained task - so the only variable we could change 'while maintaining its original functionality' would be the storage of `va_list vl` (instead of normal variable, we may declare it static), without effect the functionality. Here is the below code,


void av_log(void* avcl, int level, const char *fmt, ...)
{
    static va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


However, keep in mind that it's rarely appropriate to give `va_list vl` static storage duration - as variable argument list `vl` could be uninitialized or in otherwise observable forms depending on function calls. So, take precaution when use this variant and have control on function calls.