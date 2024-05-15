void TPOOL_completeJobs(TPOOL_ctx* ctx){
    pthread_mutex_lock(&ctx->queueMutex);
    while(!ctx->queueEmpty || ctx->numThreadsBusy > 0) {
        pthread_cond_wait(&ctx->queuePushCond, &ctx->queueMutex);
    }
    pthread_mutex_unlock(&ctx->queueMutex);
}