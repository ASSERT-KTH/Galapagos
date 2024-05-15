static size_t state_trimDict(state_t* state)
{
    /* 64 KB is the max dict size, allow slightly beyond that to test trim. */
    uint32_t maxDictSize = MIN(70 * 1024, state->data.size);
    size_t const dictSize = FUZZ_rand32(&state->seed, 0, maxDictSize);
    DEBUGLOG(2, "dictSize = %zu", dictSize);
    FUZZ_ASSERT(state->data.pos == 0);
    FUZZ_ASSERT(state->roundTrip.pos == 0);
    memcpy(state->roundTrip.buf, state->data.buf, dictSize);
    state->data.pos += dictSize;
    state->roundTrip.pos += dictSize;
    return dictSize;
}