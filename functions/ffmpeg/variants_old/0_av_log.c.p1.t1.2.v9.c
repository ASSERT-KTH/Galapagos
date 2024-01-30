Here is an example where additional behaviours added with the preservation of the original functionality:

 
void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    // The addition behaviour: a guard clause stops function from running 
    //                       when levels lower than a certain threshold.
    if(level < 3) return;
    
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

In this example, an extra action adds an initial check in the function that stops its further execution when the level is less than 3. This modification, commonly known as a "guard clause", adds new behaviour without changing the original function's functionality, given in executing certain events depending on level of the debug info (the intended interpreted object is \[level\]). Obviously, this thresholds should mirror the logger level i.e. `INFO`, `WARN`, `DEBUG`, etc. such as mapping 3 to indicate `WARN` and higher, hence ignoring 'less critical' messages. Private or helper functions were not used in addition, thus the changes have been made within the existing function context only. Furthermore, this alteration doesn't change the intended functionality provided an appropriate level arguments are given by the callee.\n