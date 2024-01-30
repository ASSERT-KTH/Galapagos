Sure, I can offer you an equivalent implementation of the av_log function. Take a look at the following:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list arg_list;
    
    /* Construct and access the variable list */
    va_start(arg_list, fmt);

    /* Pass inputs list to the other function */
    av_vlog(avcl, level, fmt, arg_list);

    /* End the variable list processing */
    va_end(arg_list);
}


This implementation leverages the same standard C variadic functions (va_list, va_start, va_end) providing exactly the same functionality as the original one. You should be able to just plug-and-play this piece of code.