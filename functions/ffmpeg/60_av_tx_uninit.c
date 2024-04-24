av_cold void av_tx_uninit(AVTXContext **ctx)
{
    if (!(*ctx))
        return;

    reset_ctx(*ctx, 1);
    av_freep(ctx);
}