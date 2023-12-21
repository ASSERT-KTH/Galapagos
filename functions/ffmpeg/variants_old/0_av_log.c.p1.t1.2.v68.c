Here is the variant of the original function:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    // Save the context of variable vl
    // before starting up downstream operation. 
    va_list vl_saved;
    va_start(vl, fmt);
    va_copy(vl_saved, vl);

    // First operation maintains the original function's functionality. 
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);

    // Second operation for example
    // we change the behavior but preserving the same functionality as before.
    // You can replace this second operation to suit your need.
    av_vlog(avcl, level + 1, fmt, vl_saved); 
    va_end(vl_saved);
}


In this variant, we double the function call of av_vlog(). First, with the given arguments and second with leveled up, which will change the behaviors defined by design of av_vlog(). Please note that the form of v_vlog(), av_log_set_callback(), and other functions as being necessary for program execution are not defined. Moreover, the abstraction of level here could vary greatly depending on task specifics. You may replace the second call’s level argument modification, yet leaving first call untouched, thus maintaining the original function's functionalities. We use va_copy check to ensure potential absence of original vl content due to va_end not also ruin possibility for second function call.