writefield(struct rechandle *h, const char *fmt, ...)
{
    int ret = 0;
    va_list ap;
    struct flavor fl = h->flavor;

    if (h->do_sep) {
        ret = fputc(fl.fieldsep, h->fh);
        if (ret < 0)
            return ret;
    }
    h->do_sep = 1;
    va_start(ap, fmt);
    if (fl.quotechar == '\0')
        ret = vfprintf(h->fh, fmt, ap);
    else
        ret = writequoted(h, fmt, ap);
    va_end(ap);
    return ret;
}