You can add extra functionality to the original function by checking the level before calling `av_vlog`. Here is a potential need that maybe arise. For instance, you may want to add an error or specific handling mechanism when the level is too high (let's say 5 for the case of this example), while maintaining the original functionality with other levels:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    if(level > 5)
    {
        //Add your own behavior here e.g. logging the error, returning or any other.
        ...
    }
    else
    {
        av_vlog(avcl, level, fmt, vl);
    }

    va_end(vl);
}


Note that despite these changes in behavior, the function's signature remains exactly the same. Also, always ensure that `va_end` is called before the function returns, or else we'll have a memory leak. You could run up against undefined behaviour if you attempt to re-use that `va_list` without cleaning it up by first calling `va_end`. So even if you would for example return on the if-clause, make sure you would've called `va_end`, needed to clean up.