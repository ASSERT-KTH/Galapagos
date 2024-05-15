krb5_gss_init_context (krb5_context *ctxp)
{
    krb5_error_code err;
#ifndef _WIN32
    int is_kdc;
#endif

    err = gss_krb5int_initialize_library();
    if (err)
        return err;
#ifndef _WIN32
    k5_mutex_lock(&kg_kdc_flag_mutex);
    is_kdc = kdc_flag;
    k5_mutex_unlock(&kg_kdc_flag_mutex);

    if (is_kdc)
        return krb5int_init_context_kdc(ctxp);
#endif

    return krb5_init_context(ctxp);
}