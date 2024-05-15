krb5_klog_syslog(int priority, const char *format, ...)
{
    int         retval;
    va_list     pvar;

    va_start(pvar, format);
    retval = klog_vsyslog(priority, format, pvar);
    va_end(pvar);
    return(retval);
}