int diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  int res = vfprintf(stderr, fmt, ap);
  fprintf(stderr,"\n");
  va_end (ap);

  if(0< progress_len){
      progress_len = 0;
  }

  return res;  
}