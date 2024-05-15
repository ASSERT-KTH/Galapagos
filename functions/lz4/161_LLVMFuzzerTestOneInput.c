int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    uint32_t seed = FUZZ_seed(&data, &size);
    state_t state = state_create((char const*)data, size, seed);
    const int n = sizeof(roundTrips) / sizeof(round_trip_t);
    int i;

    for (i = 0; i < n; ++i) {
        DEBUGLOG(2, "Round trip %d", i);
        state_reset(&state, seed);
        roundTrips[i](&state);
        state_checkRoundTrip(&state);
    }

    state_free(state);

    return 0;
}