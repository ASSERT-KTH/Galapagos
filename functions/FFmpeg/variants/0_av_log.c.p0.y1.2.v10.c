void av_log(void* avcl, int level, const char *fmt, ...)
{
    /* create a va_list to hold the variable argument */
    va_list argumentList;

    /* initialize the va_list to start reading at the specified format string */
    va_start(argumentList, fmt);

    /* pass to av_vlog the avcl, level, format and the argument list */
    av_vlog(avcl, level, fmt, argumentList);

    /* perform cleanup of va_list */
    va_end(argumentList);
}