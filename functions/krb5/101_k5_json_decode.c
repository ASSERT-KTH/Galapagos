k5_json_decode(const char *string, k5_json_value *val_out)
{
    struct decode_ctx ctx;
    k5_json_value val;
    int ret;

    *val_out = NULL;
    ctx.p = (unsigned char *)string;
    ctx.depth = MAX_DECODE_DEPTH;
    ret = parse_value(&ctx, &val);
    if (ret)
        return ret;
    if (white_spaces(&ctx) == 0) {
        k5_json_release(val);
        return EINVAL;
    }
    *val_out = val;
    return 0;
}