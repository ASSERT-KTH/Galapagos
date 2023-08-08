void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    if (level > 100){
        level = 100; //Increase the level to highest if any number greater than 100 is inputed.
    } 
    else if(level < 0) {
        level = 0; //Set level to lowest if negative is inputed.
    }

    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}