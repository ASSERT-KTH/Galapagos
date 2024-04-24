static void set_meta(AVFilterContext *ctx,
                     AVDictionary **metadata, const char *key, char comp, float d)
{
    char value[128];
    snprintf(value, sizeof(value), "%f", d);
    if (comp) {
        char key2[128];
        snprintf(key2, sizeof(key2), "lavfi.%s.%s%s%c",
                 ctx->filter->name, ctx->filter->name, key, comp);
        av_dict_set(metadata, key2, value, 0);
    } else {
        char key2[128];
        snprintf(key2, sizeof(key2), "lavfi.%s.%s%s",
                 ctx->filter->name, ctx->filter->name, key);
        av_dict_set(metadata, key2, value, 0);
    }
}