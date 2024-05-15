void TPOOL_free(TPOOL_ctx* ctx) {
    if (!ctx) { return; }
    TPOOL_shutdown(ctx);
    pthread_mutex_destroy(&ctx->queueMutex);
    pthread_cond_destroy(&ctx->queuePushCond);
    pthread_cond_destroy(&ctx->queuePopCond);
    free(ctx->queue);
    free(ctx->threads);
    free(ctx);
}