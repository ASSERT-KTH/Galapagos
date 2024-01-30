void av_log(void* avcl, int level, const char *fmt, ...)
{   
    // check if level and *fmt is not NULL
    if(level >= 0 && fmt != NULL){
        va_list vl;
        va_start(vl, fmt);
        // Checking if avcl is not NULL before calling av_vlog() function
        if ( avcl != NULL){
            av_vlog(avcl, level, fmt, vl);
        }
        va_end(vl);
    }
    // originally functionality maintains even when level is negative or avcl and fmt is NULL by not calling av_vlog().
}