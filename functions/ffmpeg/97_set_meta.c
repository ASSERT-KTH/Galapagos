static void set_meta(AVDictionary **metadata, int chan, const char *key,
                     const char *fmt, double val)
{
    uint8_t value[128];
    uint8_t key2[128];

    snprintf(value, sizeof(value), fmt, val);
    if (chan)
        snprintf(key2, sizeof(key2), "lavfi.astats.%d.%s", chan, key);
    else
        snprintf(key2, sizeof(key2), "lavfi.astats.%s", key);
    av_dict_set(metadata, key2, value, 0);
}