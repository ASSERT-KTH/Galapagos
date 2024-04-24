static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVDictionary **metadata = &in->metadata;
    ASRContext *s = ctx->priv;
    int have_speech;
    const char *speech;

    ps_process_raw(s->ps, (const int16_t *)in->data[0], in->nb_samples, 0, 0);
    have_speech = ps_get_in_speech(s->ps);
    if (have_speech && !s->utt_started)
        s->utt_started = 1;
    if (!have_speech && s->utt_started) {
        ps_end_utt(s->ps);
        speech = ps_get_hyp(s->ps, NULL);
        if (speech != NULL)
            av_dict_set(metadata, "lavfi.asr.text", speech, 0);
        ps_start_utt(s->ps);
        s->utt_started = 0;
    }

    return ff_filter_frame(ctx->outputs[0], in);
}