static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    ReplayGainContext *s = ctx->priv;
    int64_t level;
    AVFrame *out;

    out = ff_get_audio_buffer(outlink, in->nb_samples);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }

    calc_stereo_peak((float *)in->data[0],
                              in->nb_samples, &s->peak);
    yule_filter_stereo_samples(s, (const float *)in->data[0],
                                        (float *)out->data[0],
                                                 out->nb_samples);
    butter_filter_stereo_samples(s, (float *)out->data[0],
                                             out->nb_samples);
    level = lrint(floor(100 * calc_stereo_rms((float *)out->data[0],
                                                           out->nb_samples)));
    level = av_clip64(level, 0, HISTOGRAM_SLOTS - 1);

    s->histogram[level]++;

    av_frame_free(&out);
    return ff_filter_frame(outlink, in);
}