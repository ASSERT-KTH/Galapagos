static int filter_frame(AVFilterLink *inlink, AVFrame *buf)
{
    AVFilterContext *ctx = inlink->dst;
    AudioStatsContext *s = ctx->priv;
    AVDictionary **metadata = &buf->metadata;

    if (s->reset_count > 0) {
        if (s->nb_frames >= s->reset_count) {
            reset_stats(s);
            s->nb_frames = 0;
        }
        s->nb_frames++;
    }

    if (s->used == 0)
        s->used = buf->nb_samples > 0;
    ff_filter_execute(ctx, filter_channel, buf, NULL,
                      FFMIN(inlink->ch_layout.nb_channels, ff_filter_get_nb_threads(ctx)));

    if (s->metadata)
        set_metadata(s, metadata);

    return ff_filter_frame(inlink->dst->outputs[0], buf);
}