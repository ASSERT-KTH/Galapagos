Here is one possible variant. This variant ensures proper handling and inspection of potential error messages with higher log levels (if for instance, level equals value 1). There wouldn't be any behavioral difference if the log level is not equal to 1.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level == 1) { // Error log level
       printf("Error: ");
    }
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
