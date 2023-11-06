Here is a variant of your function which maintains similar functionality:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level > 5) { 
        level = 5; 
    }
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


In this variant, I have placed a restriction on the 'level' parameter. If this is greater than 5, then it is set to be equal to 5. This modification might be useful for instances where perhaps a higher level of logging detail (higher 'level') generates too much output or is computationally expensive.