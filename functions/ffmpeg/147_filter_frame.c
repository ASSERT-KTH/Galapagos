static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    LV2Context *s = ctx->priv;
    AVFrame *out;

    if (!s->nb_outputs ||
        (av_frame_is_writable(in) && s->nb_inputs == s->nb_outputs)) {
        out = in;
    } else {
        out = ff_get_audio_buffer(ctx->outputs[0], in->nb_samples);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(out, in);
    }

    connect_ports(s, in, out);

    lilv_instance_run(s->instance, in->nb_samples);

    if (out != in)
        av_frame_free(&in);

    return ff_filter_frame(ctx->outputs[0], out);
}