static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    APadContext *s = ctx->priv;

    if (s->whole_len >= 0) {
        s->whole_len_left = FFMAX(s->whole_len_left - frame->nb_samples, 0);
        av_log(ctx, AV_LOG_DEBUG,
               "n_out:%d whole_len_left:%"PRId64"\n", frame->nb_samples, s->whole_len_left);
    }

    s->next_pts = frame->pts + av_rescale_q(frame->nb_samples, (AVRational){1, inlink->sample_rate}, inlink->time_base);
    return ff_filter_frame(ctx->outputs[0], frame);
}