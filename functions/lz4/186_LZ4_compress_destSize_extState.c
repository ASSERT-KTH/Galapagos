int LZ4_compress_destSize_extState(void* state, const char* src, char* dst, int* srcSizePtr, int targetDstSize, int acceleration)
{
    int const r = LZ4_compress_destSize_extState_internal((LZ4_stream_t*)state, src, dst, srcSizePtr, targetDstSize, acceleration);
    /* clean the state on exit */
    LZ4_initStream(state, sizeof (LZ4_stream_t));
    return r;
}