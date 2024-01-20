void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if(level >= 0 && fmt != nullptr){
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }else{
        printf("logging can't proceed, Kindly provide right input.");
    }
}