static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    ShowFreqsContext *s = ctx->priv;
    const int offset = s->win_size - s->hop_size;
    int64_t pts = in->pts;

    for (int ch = 0; ch < in->ch_layout.nb_channels; ch++) {
        float *dst = (float *)s->window->extended_data[ch];

        memmove(dst, &dst[s->hop_size], offset * sizeof(float));
        memcpy(&dst[offset], in->extended_data[ch], in->nb_samples * sizeof(float));
        memset(&dst[offset + in->nb_samples], 0, (s->hop_size - in->nb_samples) * sizeof(float));
    }

    av_frame_free(&in);

    return plot_freqs(inlink, pts);
}