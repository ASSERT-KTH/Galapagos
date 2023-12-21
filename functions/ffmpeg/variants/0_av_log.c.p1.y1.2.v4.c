Sure. Here are three variants of the code that works the same as the original function.

Function Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list theArgs;
    va_start(theArgs, fmt);
    av_vlog(avcl, level, fmt, theArgs);
    va_end(theArgs);
}

Function Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    format_check:
    if(fmt==NULL){
	return;
    }
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Function Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
   va_list arg;
   va_start(arg, fmt);
   if (fmt == NULL){
       return;
   }
   av_vlog(avcl, level, fmt, arg);
   va_end(arg);
}

Remember the va_list is only valid until va_end() is called. If you intend to pass va_list to a function that uses va_arg(), and that function does not call va_end(), then the calling function must call va_end() instead.