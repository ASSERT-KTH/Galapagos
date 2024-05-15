k5_buf_add_fmt(struct k5buf *buf, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    k5_buf_add_vfmt(buf, fmt, ap);
    va_end(ap);
}