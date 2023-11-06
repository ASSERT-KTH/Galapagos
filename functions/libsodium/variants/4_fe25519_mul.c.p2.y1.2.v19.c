void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask  = 0x7ffffffffffffULL;
    const uint64_t mask19 =  19;
    uint128_t h0, h1, h2, h3, h4;
    uint64_t  h00, h01, h02, h03, h04;
    uint64_t  r;

    h0 = (uint128_t) f[0];
    h1 = (uint128_t) f[1];
    h2 = (uint128_t) f[2];
    h3 = (uint128_t) f[3];
    h4 = (uint128_t) f[4];

    h0 = ((h0 * mask19) * g[4]) 
       + ((h2 * mask19) * g[2]) 
       + ((h3 * mask19) * g[1]) 
       + ((h1 * mask19) * g[3]) 
       + (f[0] * g[0]);

    h1 = ((h2 * mask19) * g[3]) 
       + ((h3 * mask19) * g[2]) 
       + ((h4 * mask19) * g[1])
       + (f[0] * g[1]) 
       + (f[1] * g[0]);

    h2 = ((h3 * mask19) * g[1]) 
       + ((h4 * mask19) * g[0])
       + (f[0] * g[2]) 
       + (f[1] * g[1]) 
       + (f[2] * g[0]);

    h3 = ((h4 * mask19) * g[0])
       + (f[0] * g[3]) 
       + (f[1] * g[2]) 
       + (f[2] * g[1]) 
       + (f[3] * g[0]);

    h4 =  (f[0] * g[4]) 
        + (f[1] * g[3]) 
        + (f[2] * g[2]) 
        + (f[3] * g[1]) 
        + (f[4] * g[0]);
   
    h00    = ((uint64_t)h0) & mask; 
    r      = h0 >> 51;
    h1    += r;
    h01    = ((uint64_t)h1) & mask;
    r      = h1 >> 51;
    h2    += r;
    h02    = ((uint64_t)h2) & mask;
    r      = h2 >> 51;
    h3    += r;
    h03    = ((uint64_t)h3) & mask;
    r      = h3 >> 51;
    h4    += r;
    h04    = ((uint64_t)h4) & mask;
    r      = h4 >> 51;
    h00   += r * 19;
    r      = h00 >> 51;
    h00   &= mask;
    h01   += r;
    r      = h01 >> 51;
    h01   &= mask;
    h02   += r;

    h[0] = h00;
    h[1] = h01;
    h[2] = h02;
    h[3] = h03;
    h[4] = h04;
}