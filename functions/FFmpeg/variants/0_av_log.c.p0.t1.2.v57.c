void av_log(void* avcl, int level, const char *fmt, ...)
{
    /*
     * Initialization of the variable argument list has 
     * been shifted to a separate line for better readability
     */ 
    va_list vl;
    va_start(vl, fmt);

    /* Adding a condition to execute av_vlog in case level is not zero */
    if(level != 0) {
        av_vlog(avcl, level, fmt, vl);
    }

    va_end(vl);
}