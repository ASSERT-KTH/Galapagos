static inline void __vectorcall encrypt_xor_block(const State *st, unsigned char dst[16],
                                                  const unsigned char src[16],
                                                  const BlockVec      counter)
{
    BlockVec ts;
    size_t   i;

    ts = AES_XENCRYPT(counter, st->rkeys[0]);
    for (i = 1; i < ROUNDS - 1; i++) {
        ts = AES_XENCRYPT(ts, st->rkeys[i]);
    }
    ts = AES_XENCRYPTLAST(ts, st->rkeys[i]);
    ts = XOR128(ts, XOR128(st->rkeys[ROUNDS], LOAD128(src)));
    STORE128(dst, ts);
}