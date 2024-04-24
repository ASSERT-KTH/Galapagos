static int filter_frame(AVFilterLink *inlink, AVFrame *buf)
{
    DRMeterContext *s = inlink->dst->priv;
    const int channels = s->nb_channels;

    switch (inlink->format) {
    case AV_SAMPLE_FMT_FLTP:
        for (int c = 0; c < channels; c++) {
            ChannelStats *p = &s->chstats[c];
            const float *src = (const float *)buf->extended_data[c];

            for (int i = 0; i < buf->nb_samples; i++, src++)
                update_stat(s, p, *src);
        }
        break;
    case AV_SAMPLE_FMT_FLT: {
        const float *src = (const float *)buf->extended_data[0];

        for (int i = 0; i < buf->nb_samples; i++) {
            for (int c = 0; c < channels; c++, src++)
                update_stat(s, &s->chstats[c], *src);
        }}
        break;
    }

    return ff_filter_frame(inlink->dst->outputs[0], buf);
}