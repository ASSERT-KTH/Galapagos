/* variant #1 */
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = {0}, f_[5] = {0}, g_[5] = {0};
    uint64_t  r__[5] = {0};
    uint64_t  carry;

    for (int i = 0; i < 5; i++)
    {
        f_[i] = (uint128_t) f[i];
        g_[i] = (uint128_t) g[i];
    }
    for (int i = 0; i < 5; i++)
    {
        uint128_t adj = ((i == 1) || (i == 2) || (i == 3) || (i == 4)) ? 19ULL * f_[i] : f_[i];
        for (int j = 0; j < 5; j++) 
        {
            int gj = (j - i < 0) ? j - i + 5 : j - i;
            r[j] += adj * g_[gj];
        }
    }

    for (int i = 0; i < 5; i++) 
    {
        uint64_t rr = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >>= 51);
        if (++i < 5) r[i] += carry;
        r__[i % 5] = rr;
    }
    carry  = r__[0] >> 51;
    r__[0] &= mask;
    r__[1] += carry;
    carry  = r__[1] >> 51;
    r__[1] &= mask;
    r__[2] += carry;
    
    memcpy(h, r__, 5 * sizeof(uint64_t));
}
/* variant #2 */ 
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fi[5], gi[5];
    uint64_t carry;
    
    for(int i=0; i<5; ++i)
    {
        fi[i] = f[i];
        gi[i] = g[i];
    }
    
    for(int i=0; i<5; ++i)
        r[i] = fi[0] * gi[i] + 19ull * (
                                     ((uint128_t)fi[(i+1)%5]) * gi[(i+5-1)%5]
                                   + ((uint128_t)fi[(i+2)%5]) * gi[(i+5-2)%5]
                                   + ((uint128_t)fi[(i+3)%5]) * gi[(i+5-3)%5]
                                   + ((uint128_t)fi[(i+4)%5]) * gi[(i+5-4)%5]);

    for(int i=0; i<5; ++i)
    {
        h[i] = r[i] & mask;
        carry = r[i] >> 51;      
        r[(i+1)%5] += carry;  

        /* Last round requires special handling */
        i == 4 && (h[0] += carry * 19ull, h[1] += h[0] >> 51, h[0] &= mask, h[1] &= mask); 
    }
} 
