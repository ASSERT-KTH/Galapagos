void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t ft[5], gt[5], r[5];
    uint64_t  carry, hr[5];

    for(int i = 0; i < 5; ++i){
        ft[i] = (uint128_t) f[i];
        gt[i] = (uint128_t) g[i];
    }

    for(int i = 0; i < 5; ++i)
    {
        r[i] = ft[0]*gt[i];
        for(int j = 1; j <= i; ++j)
            r[i] += ft[j]*gt[i-j];

        for(int j = i+1, k = 4 ; j <= 4; ++j, --k)
           r[i] += (ft[j]*19)*gt[k];
    }
   
    for(int i = 0; i < 5; ++i)
    {
        hr[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if (i < 4)
            r[i+1] += carry;
        else
            hr[0] += 19 * carry;
    }
 
    carry = hr[0] >> 51;
    hr[0] &= mask;
    hr[1] += carry;
    carry = hr[1] >> 51;
    hr[1] &= mask;
    hr[2] += carry;

    for(int i = 0; i < 5; ++i) h[i] = hr[i];
}