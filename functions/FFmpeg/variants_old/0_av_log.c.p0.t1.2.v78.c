void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
	if(level <= AV_LOG_VERBOSE){
	    av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}