static int filter_frame(AVFilterLink *inlink, AVFrame *inbuf)
{
    AudioPhaserContext *s = inlink->dst->priv;
    AVFilterLink *outlink = inlink->dst->outputs[0];
    AVFrame *outbuf;

    if (av_frame_is_writable(inbuf)) {
        outbuf = inbuf;
    } else {
        outbuf = ff_get_audio_buffer(outlink, inbuf->nb_samples);
        if (!outbuf) {
            av_frame_free(&inbuf);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(outbuf, inbuf);
    }

    s->phaser(s, inbuf->extended_data, outbuf->extended_data,
              outbuf->nb_samples, outbuf->ch_layout.nb_channels);

    if (inbuf != outbuf)
        av_frame_free(&inbuf);

    return ff_filter_frame(outlink, outbuf);
}