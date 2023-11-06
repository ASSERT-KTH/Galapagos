Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...) 
{ 
    va_list vl; 
    va_start(vl, fmt); 
    if (fmt != NULL) { 
        av_vlog(avcl, level, fmt, vl); 
    } 
    va_end(vl); 
}

Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...) 
{ 
    va_list vl; 
    if(fmt){
      va_start(vl, fmt);
      av_vlog(avcl, level, fmt, vl); 
      va_end(vl);
    }
}

Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...) 
{ 
    va_list vl; 
    if (!fmt) {
      return;
    }
    va_start(vl, fmt); 
    av_vlog(avcl, level, fmt, vl); 
    va_end(vl); 
}

Variant 4:

void av_log(void* avcl, int level, const char *fmt, ...) 
{
    va_list vl; 
    va_start(vl, fmt);
    
    vl ? av_vlog(avcl, level, fmt, vl) : NULL;
    
    va_end(vl);
}
