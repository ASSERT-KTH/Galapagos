info(const char *fmt, ...)
{
    va_list ap;

    if (script_mode)
        return;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}