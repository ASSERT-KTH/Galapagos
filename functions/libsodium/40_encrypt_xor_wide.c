static inline void __vectorcall encrypt_xor_wide(const State        *st,
                                                 unsigned char       dst[16 * PARALLEL_BLOCKS],
                                                 const unsigned char src[16 * PARALLEL_BLOCKS],
                                                 const BlockVec      counters[PARALLEL_BLOCKS])
{
    BlockVec ts[PARALLEL_BLOCKS];
    size_t   i, j;

    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        ts[j] = AES_XENCRYPT(counters[j], st->rkeys[0]);
    }
    for (i = 1; i < ROUNDS - 1; i++) {
        for (j = 0; j < PARALLEL_BLOCKS; j++) {
            ts[j] = AES_XENCRYPT(ts[j], st->rkeys[i]);
        }
    }
    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        ts[j] = AES_XENCRYPTLAST(ts[j], st->rkeys[i]);
        ts[j] = XOR128(ts[j], XOR128(st->rkeys[ROUNDS], LOAD128(&src[16 * j])));
    }
    for (j = 0; j < PARALLEL_BLOCKS; j++) {
        STORE128(&dst[16 * j], ts[j]);
    }
}