static inline void __vectorcall encrypt_xor_wide(const State        *st,
                                                 unsigned char       dst[16 * PARALLEL_BLOCKS],
                                                 const unsigned char src[16 * PARALLEL_BLOCKS],
                                                 const BlockVec      counters[PARALLEL_BLOCKS])
{
    BlockVec ts[PARALLEL_BLOCKS];
    size_t   i, j;

    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        ts[j] = XOR128(counters[j], st->rkeys[0]);
    }
    for (i = 1; i < ROUNDS; i++) {
        for (j = 0; j < PARALLEL_BLOCKS; j++) {
            ts[j] = AES_ENCRYPT(ts[j], st->rkeys[i]);
        }
    }
    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        ts[j] = AES_ENCRYPTLAST(ts[j], st->rkeys[i]);
        ts[j] = XOR128(ts[j], LOAD128(&src[16 * j]));
    }
    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        STORE128(&dst[16 * j], ts[j]);
    }
}