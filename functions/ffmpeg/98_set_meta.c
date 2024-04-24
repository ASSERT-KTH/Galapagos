static void set_meta(AVFrame *insamples, int channel, const char *key, char *value)
{
    char key2[128];

    if (channel)
        snprintf(key2, sizeof(key2), "lavfi.%s.%d", key, channel);
    else
        snprintf(key2, sizeof(key2), "lavfi.%s", key);
    av_dict_set(&insamples->metadata, key2, value, 0);
}