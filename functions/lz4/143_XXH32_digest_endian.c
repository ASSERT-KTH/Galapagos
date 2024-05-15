XXH32_digest_endian (const XXH32_state_t* state, XXH_endianness endian)
{
    U32 h32;

    if (state->large_len) {
        h32 = XXH_rotl32(state->v1, 1)
            + XXH_rotl32(state->v2, 7)
            + XXH_rotl32(state->v3, 12)
            + XXH_rotl32(state->v4, 18);
    } else {
        h32 = state->v3 /* == seed */ + PRIME32_5;
    }

    h32 += state->total_len_32;

    return XXH32_finalize(h32, state->mem32, state->memsize, endian, XXH_aligned);
}