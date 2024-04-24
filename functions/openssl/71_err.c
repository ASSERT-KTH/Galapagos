static void err(int eval, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    printf(": %s\n", strerror(errno));
    exit(eval);
}