In this variant, I included an if statement that checks for a certain log level. For example, it could ignore logs with a log level less than 10 and allow logs with levels 10 or higher. Please customize this number with the value you want.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (level >= 10) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


Note: The functionality would not change as long as level is 10 or higher. If levels are typically lower than 10 then the functionality could hypothetically change for your program.