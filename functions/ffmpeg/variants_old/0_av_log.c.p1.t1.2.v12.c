You can add the check to output only those logs which have level more than or equal to specified threshold.


#define MIN_LOG_LEVEL 2 // Set minimum log level here

void av_log(void* avcl, int level, const char *fmt, ...)
{
   if(level < MIN_LOG_LEVEL)
      return;
   
   va_list vl;
   va_start(vl, fmt);
   av_vlog(avcl, level, fmt, vl);
   va_end(vl);
}


This is one way to change the behavior of the original function so that it filters out the logs of level less than the particular number, maintained functionality otherwise.