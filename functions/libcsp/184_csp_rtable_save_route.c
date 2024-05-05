static bool csp_rtable_save_route(void * vctx, uint8_t address, uint8_t mask, const csp_route_t * route)
{
    csp_rtable_save_ctx_t * ctx = vctx;

    // Do not save loop back interface
    if (strcasecmp(route->iface->name, CSP_IF_LOOPBACK_NAME) == 0) {
        return true;
    }

    const char * sep = (ctx->len == 0) ? "" : ",";

    char mask_str[10];
    if (mask != CSP_ID_HOST_SIZE) {
        snprintf(mask_str, sizeof(mask_str), "/%u", mask);
    } else {
        mask_str[0] = 0;
    }
    char via_str[10];
    if (route->via != CSP_NO_VIA_ADDRESS) {
        snprintf(via_str, sizeof(via_str), " %u", route->via);
    } else {
        via_str[0] = 0;
    }
    size_t remain_buf_size = ctx->maxlen - ctx->len;
    int res = snprintf(ctx->buffer + ctx->len, remain_buf_size,
                       "%s%u%s %s%s", sep, address, mask_str, route->iface->name, via_str);
    if ((res < 0) || (res >= (int)(remain_buf_size))) {
        ctx->error = CSP_ERR_NOMEM;
        return false;
    }
    ctx->len += res;
    return true;
}