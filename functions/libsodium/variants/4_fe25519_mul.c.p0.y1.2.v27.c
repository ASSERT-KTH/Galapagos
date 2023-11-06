void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int i, j;
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  carry;

    uint128_t t[5];
    uint128_t r[5];
    for(i=0; i<5; i++)
    {
         uint64_t gtemp = (uint128_t) g[i];
         uint64_t ftemp = (uint128_t) f[i];
         uint64_t by_19 = 19ULL * ftemp;
         t[i] = gtemp;
         if(i > 0)
             r[i] = ((i==4) ? gtemp*ftemp : by_19 * g[(5-i)%5] + ftemp * t[0]);
         else
             r[i] = ftemp * gtemp + by_19 * t[4] + 19ULL*f[(i+2)%5] * t[(5-i)%5] + 19ULL*f[(i+3)%5] * t[(6-i)%5] + 19ULL*f[(i+4)%5] * t[(7-i)%5];
    }

    for(i=0; i<4; i++) {
        carry = (uint64_t) (r[i] >> 51);
        r[i] = (uint64_t) r1 & mask;
        r[i+1] += carry;
    }
    r00 = r[0] + 19ULL * ((uint64_t) (r[4] >> 51));
    carry = (uint64_t) (r[0] >> 51);
    h[0] = r[0] & mask;
    r[1] += carry;
    carry = (uint64_t) (r[1] >> 51);
    h[1] = r[1] & mask;
    h[2] = r[2] + carry;
    h[3] = r[3];
    h[4] = r[4] & mask;
}
