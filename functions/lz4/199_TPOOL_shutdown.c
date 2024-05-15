static void TPOOL_shutdown(TPOOL_ctx* ctx) {
    /* Shut down the queue */
    pthread_mutex_lock(&ctx->queueMutex);
    ctx->shutdown = 1;
    pthread_mutex_unlock(&ctx->queueMutex);
    /* Wake up sleeping threads */
    pthread_cond_broadcast(&ctx->queuePushCond);
    pthread_cond_broadcast(&ctx->queuePopCond);
    /* Join all of the threads */
    {   size_t i;
        for (i = 0; i < ctx->threadCapacity; ++i) {
            pthread_join(ctx->threads[i], NULL);  /* note : could fail */
    }   }
}