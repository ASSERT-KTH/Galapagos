krb5_timeofday(krb5_context context, krb5_timestamp *timeret)
{
    krb5_os_context os_ctx;
    time_t tval;

    if (context == NULL)
        return EINVAL;

    os_ctx = &context->os_context;
    if (os_ctx->os_flags & KRB5_OS_TOFFSET_TIME) {
        *timeret = os_ctx->time_offset;
        return 0;
    }
    tval = time(0);
    if (tval == (time_t) -1)
        return (krb5_error_code) errno;
    if (os_ctx->os_flags & KRB5_OS_TOFFSET_VALID)
        tval += os_ctx->time_offset;
    *timeret = tval;
    return 0;
}