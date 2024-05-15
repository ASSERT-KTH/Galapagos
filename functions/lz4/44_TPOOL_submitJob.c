void TPOOL_submitJob(TPOOL_ctx* ctx, void (*job_function)(void*), void* arg)
{
    assert(ctx != NULL);
    pthread_mutex_lock(&ctx->queueMutex);
    /* Wait until there is space in the queue for the new job */
    while (isQueueFull(ctx) && (!ctx->shutdown)) {
        pthread_cond_wait(&ctx->queuePushCond, &ctx->queueMutex);
    }
    TPOOL_submitJob_internal(ctx, job_function, arg);
    pthread_mutex_unlock(&ctx->queueMutex);
}