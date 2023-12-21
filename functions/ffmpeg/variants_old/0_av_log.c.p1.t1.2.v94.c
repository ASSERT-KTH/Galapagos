You might consider adding a simple condition in the function like below, it slightly changes the behavior of given function while still mainlining its original functionality.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if (level > 0) { // condition that changes the behaviour
        av_vlog(avcl, level, fmt, vl);
    }

    va_end(vl);
}


In this variant, we add a condition to call `av_vlog` only if the level is greater than 0. This condition does not produce additional output or add auxiliary functions, and it preserves the original function's signature. It merely omits the log action for negative or zero levels.