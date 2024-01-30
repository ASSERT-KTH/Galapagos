Here is a variant of the original function which adds a check for null value of "fmt" before proceeding with the function logic. 


void av_log(void* avcl, int level, const char *fmt, ...) {
  if (fmt != NULL) {
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
  }
}


Here is another variant of the function which adds checks for negative value of "level" before proceeding with the function logic. 


void av_log(void* avcl, int level, const char *fmt, ...) {
  if (level >= 0) {
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
  }
}


And here's a variant that combines the above status checks. This function only logs when level is non-negative and fmt isn't NULL.


void av_log(void* avcl, int level, const char *fmt, ...) {
  if(fmt != NULL && level >= 0) {
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
  }
}
