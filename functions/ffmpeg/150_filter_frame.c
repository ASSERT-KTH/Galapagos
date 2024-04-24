static int filter_frame(AVFilterLink *inlink, AVFrame *insamples)
{
    SilenceDetectContext *s         = inlink->dst->priv;
    const int nb_channels           = inlink->ch_layout.nb_channels;
    const int srate                 = inlink->sample_rate;
    const int nb_samples            = insamples->nb_samples     * nb_channels;
    const int64_t nb_samples_notify = s->duration * (s->mono ? 1 : nb_channels);
    int c;

    // scale number of null samples to the new sample rate
    if (s->last_sample_rate && s->last_sample_rate != srate)
        for (c = 0; c < s->independent_channels; c++) {
            s->nb_null_samples[c] = srate * s->nb_null_samples[c] / s->last_sample_rate;
        }
    s->last_sample_rate = srate;
    s->time_base = inlink->time_base;
    s->frame_end = insamples->pts + av_rescale_q(insamples->nb_samples,
            (AVRational){ 1, s->last_sample_rate }, inlink->time_base);

    s->silencedetect(s, insamples, nb_samples, nb_samples_notify,
                     inlink->time_base);

    return ff_filter_frame(inlink->dst->outputs[0], insamples);
}