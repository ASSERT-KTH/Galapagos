static inline BlockVec __vectorcall gcm_reduce(const I256 x)
{
    const BlockVec hi = XOR128(x.hi, BYTESHR128(x.mid, 8));
    const BlockVec lo = XOR128(x.lo, BYTESHL128(x.mid, 8));

    const BlockVec p64 = SET64x2(0, 0xc200000000000000);
    const BlockVec a   = CLMULLO128(lo, p64);
    const BlockVec b   = XOR128(SHUFFLE32x4(lo, 2, 3, 0, 1), a);
    const BlockVec c   = CLMULLO128(b, p64);
    const BlockVec d   = XOR128(SHUFFLE32x4(b, 2, 3, 0, 1), c);

    return XOR128(d, hi);
}