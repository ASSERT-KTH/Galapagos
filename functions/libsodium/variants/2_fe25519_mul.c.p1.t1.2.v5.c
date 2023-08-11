fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t total[10];
    uint64_t carries, tmp, i;
 
    for(i = 0; i < 5; ++i)
    {
        total[i] = f[i] * g[i];
        total[5 + i] = 19 * f[i] * ((i < 4) ? g[i + 1] : g[0]);
    }
 
    for(i = 1; i < 5; ++i) 
    {
        total[i] += total[i-1]>>51;
        total[i-1] &= mask;
    }
    
    total[0] += total[4]>>51;
    total[4] &= mask;
    
    carries  = total[0] >> 51;
    total[0] &= mask;
    total[1] += carries;

    /*propagating the rest of the carries*/
    for(i = 1; i < 5; ++i)
    {
        tmp = total[i];
        total[i] = (tmp & mask) + carries;
        carries = tmp >> 51;
    }

    total[0] += carries * 19;// final reduction

    for(i = 0; i < 5; ++i) 
        h[i] = total[i];
}