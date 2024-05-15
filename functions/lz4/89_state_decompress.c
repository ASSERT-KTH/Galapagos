static void state_decompress(state_t* state, char const* src, int srcSize)
{
    char* dst = state->roundTrip.buf + state->roundTrip.pos;
    int const dstCapacity = state->roundTrip.size - state->roundTrip.pos;
    int const dSize = LZ4_decompress_safe_continue(state->dstream, src, dst,
                                                   srcSize, dstCapacity);
    FUZZ_ASSERT(dSize >= 0);
    state->roundTrip.pos += dSize;
}