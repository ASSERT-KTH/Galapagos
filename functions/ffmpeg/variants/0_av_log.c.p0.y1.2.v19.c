Sure, here is an equivalent substitute of the original function that should work in the same way:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    char buf[500];

    va_start(vl, fmt);
    vsnprintf(buf, sizeof buf, fmt, vl);
    va_end(vl);

    av_vlog(avcl, level, "%s", buf);
}


Note: This version would not work properly if the length of the formatted string is more than 500 characters. A more robust version might dynamically allocate just enough memory to hold the formatted string, using a technique such as that used by the `asprintf` and `vasprintf` functions in GNU libc. Nevertheless, without the specs of av_vlog function it is not clear and my assumption can vary its functionality in this case. Making arbitrary string allocation could deplete memory resources unnecessarily hence by keeping the array (with reasonable size) brings some light efficiency.