static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    DNNAsyncStatusType async_state = 0;
    AVFilterContext *ctx  = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    DRContext *dr_context = ctx->priv;
    int dnn_result;
    AVFrame *out;

    out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
    if (!out) {
        av_log(ctx, AV_LOG_ERROR, "could not allocate memory for output frame\n");
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }
    av_frame_copy_props(out, in);

    dnn_result = ff_dnn_execute_model(&dr_context->dnnctx, in, out);
    if (dnn_result != 0){
        av_log(ctx, AV_LOG_ERROR, "failed to execute model\n");
        av_frame_free(&in);
        return dnn_result;
    }
    do {
        async_state = ff_dnn_get_result(&dr_context->dnnctx, &in, &out);
    } while (async_state == DAST_NOT_READY);

    if (async_state != DAST_SUCCESS)
        return AVERROR(EINVAL);

    av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}