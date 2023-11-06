Option#1: Rename the variables maintaining same functionality,


void av_log(void* arg1, int arg2, const char *arg3, ...)
{
    va_list var_list;
    va_start(var_list, arg3);
    av_vlog(arg1, arg2, arg3, var_list);
    va_end(var_list);
}


Option#2: Comments for more description to others,



void av_log(void* avcl, int level, const char *fmt, ...)
{
    // Creating list
    va_list vaList;

    // Start va_list
    va_start(vaList, fmt);

    // Calling function av_vlog with needed parameters
    av_vlog(avcl, level, fmt, vaList);

    // Cleanup of va_list
    va_end(vaList);
}


Option#3, Arrange va_end after directly av_vlog


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list arguments;
    va_start(arguments, fmt);
    av_vlog(avcl, level, fmt, arguments);
    va_end(arguments);
}
