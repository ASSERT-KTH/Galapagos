static uint64_t BitInterleave(uint64_t Ai)
{
    if (BIT_INTERLEAVE) {
        uint32_t hi = (uint32_t)(Ai >> 32), lo = (uint32_t)Ai;
        uint32_t t0, t1;

        t0 = lo & 0x55555555;
        t0 |= t0 >> 1;  t0 &= 0x33333333;
        t0 |= t0 >> 2;  t0 &= 0x0f0f0f0f;
        t0 |= t0 >> 4;  t0 &= 0x00ff00ff;
        t0 |= t0 >> 8;  t0 &= 0x0000ffff;

        t1 = hi & 0x55555555;
        t1 |= t1 >> 1;  t1 &= 0x33333333;
        t1 |= t1 >> 2;  t1 &= 0x0f0f0f0f;
        t1 |= t1 >> 4;  t1 &= 0x00ff00ff;
        t1 |= t1 >> 8;  t1 <<= 16;

        lo &= 0xaaaaaaaa;
        lo |= lo << 1;  lo &= 0xcccccccc;
        lo |= lo << 2;  lo &= 0xf0f0f0f0;
        lo |= lo << 4;  lo &= 0xff00ff00;
        lo |= lo << 8;  lo >>= 16;

        hi &= 0xaaaaaaaa;
        hi |= hi << 1;  hi &= 0xcccccccc;
        hi |= hi << 2;  hi &= 0xf0f0f0f0;
        hi |= hi << 4;  hi &= 0xff00ff00;
        hi |= hi << 8;  hi &= 0xffff0000;

        Ai = ((uint64_t)(hi | lo) << 32) | (t1 | t0);
    }

    return Ai;
}