static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    Frei0rContext *s = inlink->dst->priv;
    AVFilterLink *outlink = inlink->dst->outputs[0];
    /* align parameter is the line alignment, not the buffer alignment.
     * frei0r expects line size to be width*4 so we want an align of 1
     * to ensure lines aren't padded out. */
    AVFrame *out = ff_default_get_video_buffer2(outlink, outlink->w, outlink->h, 1);
    if (!out)
        goto fail;

    av_frame_copy_props(out, in);

    if (in->linesize[0] != out->linesize[0]) {
        AVFrame *in2 = ff_default_get_video_buffer2(outlink, outlink->w, outlink->h, 1);
        if (!in2)
            goto fail;
        av_frame_copy(in2, in);
        av_frame_free(&in);
        in = in2;
    }

    s->update(s->instance, in->pts * av_q2d(inlink->time_base) * 1000,
                   (const uint32_t *)in->data[0],
                   (uint32_t *)out->data[0]);

    av_frame_free(&in);

    return ff_filter_frame(outlink, out);
fail:
    av_frame_free(&in);
    av_frame_free(&out);
    return AVERROR(ENOMEM);
}