krb5_free_context(krb5_context ctx)
{
    if (ctx == NULL)
        return;
    k5_os_free_context(ctx);

    free(ctx->tgs_etypes);
    ctx->tgs_etypes = NULL;
    free(ctx->default_realm);
    ctx->default_realm = 0;

    krb5_clear_error_message(ctx);
    free(ctx->err_fmt);

#ifndef DISABLE_TRACING
    if (ctx->trace_callback)
        ctx->trace_callback(ctx, NULL, ctx->trace_callback_data);
#endif

    k5_ccselect_free_context(ctx);
    k5_hostrealm_free_context(ctx);
    k5_localauth_free_context(ctx);
    k5_plugin_free_context(ctx);
    free(ctx->plugin_base_dir);
    free(ctx->tls);

    ctx->magic = 0;
    free(ctx);
}