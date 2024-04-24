static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    FIREqualizerContext *s = ctx->priv;
    int ch;

    if (!s->min_phase) {
        for (ch = 0; ch + 1 < inlink->ch_layout.nb_channels && s->fft_ctx; ch += 2) {
            fast_convolute2(s, s->kernel_buf, (AVComplexFloat *)(s->conv_buf + 2 * ch * s->rdft_len),
                            s->conv_idx + ch, (float *) frame->extended_data[ch],
                            (float *) frame->extended_data[ch+1], frame->nb_samples);
        }

        for ( ; ch < inlink->ch_layout.nb_channels; ch++) {
            fast_convolute(s, s->kernel_buf + (s->multi ? ch * (s->rdft_len * 2) : 0),
                        s->conv_buf + 2 * ch * s->rdft_len, s->conv_idx + ch,
                        (float *) frame->extended_data[ch], frame->nb_samples);
        }
    } else {
        for (ch = 0; ch < inlink->ch_layout.nb_channels; ch++) {
            fast_convolute_nonlinear(s, s->kernel_buf + (s->multi ? ch * (s->rdft_len * 2) : 0),
                                     s->conv_buf + 2 * ch * s->rdft_len, s->conv_idx + ch,
                                     (float *) frame->extended_data[ch], frame->nb_samples);
        }
    }

    s->next_pts = AV_NOPTS_VALUE;
    if (frame->pts != AV_NOPTS_VALUE) {
        s->next_pts = frame->pts + av_rescale_q(frame->nb_samples, av_make_q(1, inlink->sample_rate), inlink->time_base);
        if (s->zero_phase && !s->min_phase)
            frame->pts -= av_rescale_q(s->fir_len/2, av_make_q(1, inlink->sample_rate), inlink->time_base);
    }
    s->frame_nsamples_max = FFMAX(s->frame_nsamples_max, frame->nb_samples);
    return ff_filter_frame(ctx->outputs[0], frame);
}