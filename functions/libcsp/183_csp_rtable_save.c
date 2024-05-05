int csp_rtable_save(char * buffer, size_t maxlen)
{
    csp_rtable_save_ctx_t ctx = {.len = 0, .buffer = buffer, .maxlen = maxlen, .error = CSP_ERR_NONE};
    buffer[0] = 0;
    csp_rtable_iterate(csp_rtable_save_route, &ctx);
    return ctx.error;
}