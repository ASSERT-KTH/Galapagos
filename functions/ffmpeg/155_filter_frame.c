static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    BenchContext *s = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];
    const int64_t t = av_gettime();

    if (t < 0)
        return ff_filter_frame(outlink, in);

    if (s->action == ACTION_START) {
        av_dict_set_int(&in->metadata, START_TIME_KEY, t, 0);
    } else if (s->action == ACTION_STOP) {
        AVDictionaryEntry *e = av_dict_get(in->metadata, START_TIME_KEY, NULL, 0);
        if (e) {
            const int64_t start = strtoll(e->value, NULL, 0);
            const int64_t diff = t - start;
            s->sum += diff;
            s->n++;
            s->min = FFMIN(s->min, diff);
            s->max = FFMAX(s->max, diff);
            av_log(s, AV_LOG_INFO, "t:%f avg:%f max:%f min:%f\n",
                   T2F(diff), T2F(s->sum / s->n), T2F(s->max), T2F(s->min));
        }
        av_dict_set(&in->metadata, START_TIME_KEY, NULL, 0);
    }

    return ff_filter_frame(outlink, in);
}