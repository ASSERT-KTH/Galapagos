static void state_randomRoundTrip(state_t* state, round_trip_t rt0,
                                  round_trip_t rt1)
{
    if (FUZZ_rand32(&state->seed, 0, 1)) {
      rt0(state);
    } else {
      rt1(state);
    }
}