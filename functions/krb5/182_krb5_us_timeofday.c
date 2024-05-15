krb5_us_timeofday(krb5_context context, krb5_timestamp *seconds,
                  krb5_int32 *microseconds)
{
    krb5_os_context os_ctx = &context->os_context;

    if (os_ctx->os_flags & KRB5_OS_TOFFSET_TIME) {
        *seconds = os_ctx->time_offset;
        *microseconds = os_ctx->usec_offset;
        return 0;
    } else if (os_ctx->os_flags & KRB5_OS_TOFFSET_VALID) {
        return k5_time_with_offset(os_ctx->time_offset, os_ctx->usec_offset,
                                   seconds, microseconds);
    } else {
        return krb5_crypto_us_timeofday(seconds, microseconds);
    }
}