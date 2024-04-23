static inline void __vectorcall encrypt_xor_block(const State *st, unsigned char dst[16],
                                                  const unsigned char src[16],
                                                  const BlockVec      counter)
{
    BlockVec ts;
    size_t   i;

    ts = XOR128(counter, st->rkeys[0]);
    for (i = 1; i < ROUNDS; i++) {
        ts = AES_ENCRYPT(ts, st->rkeys[i]);
    }
    ts = AES_ENCRYPTLAST(ts, st->rkeys[i]);
    ts = XOR128(ts, LOAD128(src));
    STORE128(dst, ts);
}