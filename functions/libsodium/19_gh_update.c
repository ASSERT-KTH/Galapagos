static inline void __vectorcall gh_update(I256 *const u, const unsigned char *p, const Precomp hn)
{
    const BlockVec m = REV128(LOAD128(p));
    const I256     t = clmul128(m, hn);
    *u = (I256) { SODIUM_C99(.hi =) XOR128(u->hi, t.hi), SODIUM_C99(.lo =) XOR128(u->lo, t.lo),
                  SODIUM_C99(.mid =) XOR128(u->mid, t.mid) };
}