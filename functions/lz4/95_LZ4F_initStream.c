static void LZ4F_initStream(void* ctx,
                            const LZ4F_CDict* cdict,
                            int level,
                            LZ4F_blockMode_t blockMode) {
    if (level < LZ4HC_CLEVEL_MIN) {
        if (cdict || blockMode == LZ4F_blockLinked) {
            /* In these cases, we will call LZ4_compress_fast_continue(),
             * which needs an already reset context. Otherwise, we'll call a
             * one-shot API. The non-continued APIs internally perform their own
             * resets at the beginning of their calls, where they know what
             * tableType they need the context to be in. So in that case this
             * would be misguided / wasted work. */
            LZ4_resetStream_fast((LZ4_stream_t*)ctx);
            if (cdict)
                LZ4_attach_dictionary((LZ4_stream_t*)ctx, cdict->fastCtx);
        }
        /* In these cases, we'll call a one-shot API.
         * The non-continued APIs internally perform their own resets
         * at the beginning of their calls, where they know
         * which tableType they need the context to be in.
         * Therefore, a reset here would be wasted work. */
    } else {
        LZ4_resetStreamHC_fast((LZ4_streamHC_t*)ctx, level);
        if (cdict)
            LZ4_attach_HC_dictionary((LZ4_streamHC_t*)ctx, cdict->HCCtx);
    }
}