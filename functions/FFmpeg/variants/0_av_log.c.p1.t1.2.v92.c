Below is a program variant of the "av_log" function. This variant relays the arguments to another function just as in the original, but this modification includes a conditional logic to selectively suppress or adjust the logging level based on the input 'level'. The overall functionality is generalized; not only it relays arguments to 'av_vlog', but also provides basic level control.

`
void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    // Allow logging only for critical error messages
    if (level <= 10) {
        av_vlog(avcl, level, fmt, vl);
    }
    else {
        // for non-critical messages, and informational messages, lower the level
        av_vlog(avcl, level / 2, fmt, vl); 
    }
    va_end(vl);
}


_Do understand that right values and associated functionality for log level suppression & adjustment is subjective and must be devised from empirical data & project requirements, this modification purely for demonstration of how the reference function can modified while retaining the essential behaviour. Actual environment many not have 10 levels, or you might need different handling logic instead of simply suppressing or modifying._