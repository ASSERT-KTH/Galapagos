void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    uint128_t f_prop[5], g_prop[5];
    uint128_t r[5];
    uint128_t product, carry = 0;
    uint64_t constant = 19, mask = 0x7ffffffffffffULL;

    for (int i = 0; i < 5; i++) {
        f_prop[i] = f[i];
        g_prop[i] = g[i];
    }

    for (int i = 1; i < 5; i++)
        f_prop[i] *= constant;

    for (int i = 0; i < 5; i++) {
        product = 0;
        for (int j = 0; j <= i; j++)
            product += f_prop[j % 5] * g_prop[(i - j + 5) % 5] ;
        
        r[i] = product;
    }

    for(int i=0; i<5; i++) {
        r[i] += carry;
        h[i] = r[i] & mask;
        carry = r[i] >> 51;
    }


    h[0] += constant*carry;
    for(int i=0; i<2; i++) {
        carry = h[i] >> 51;
        h[i] & mask;
        h[i+1]+=carry;
    }
}