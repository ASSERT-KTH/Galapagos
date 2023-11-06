Variant #1

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g){
    uint128_t a[5], b[5], r[5], s[5];
    uint64_t  mask = 0x7ffffffffffffULL, carry;

    for (int i=0; i<5; i++){
        a[i] = (uint128_t) f[i];
        b[i] = (uint128_t) g[i];
    }

    for (int i=1; i<5; i++){
        s[i] = 19ULL * a[i];
    }

    r[0] = a[0]*b[0] + s[1]*b[4] + s[2]*b[3] + s[3]*b[2] + s[4]*b[1];
    r[1] = a[0]*b[1] +  a[1]*b[0] + s[2]*b[4] + s[3]*b[3] + s[4]*b[2];
    r[2] = a[0]*b[2] +  a[1]*b[1] +  a[2]*b[0] + s[3]*b[4] + s[4]*b[3];
    r[3] = a[0]*b[3] +  a[1]*b[2] +  a[2]*b[1] +  a[3]*b[0] + s[4]*b[4];
    r[4] = a[0]*b[4] +  a[1]*b[3] +  a[2]*b[2] +  a[3]*b[1] +  a[4]*b[0];

    for (int i=0; i<5; i++){
        h[i] =  (uint64_t) (r[i] & mask);
        carry   = (r[i] >> 51);
        r[(i+1)%5]   += carry;  
        h[i] =  h[i] & mask;
    }
    h[0] += (19ULL*(r[4] >> 51));
    h[1]   += (h[0] >> 51);
    h[0]   &= mask;
}

Variant #2

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t fvals[5], gvals[5], rvals[5], f19vals[2];
    uint64_t hvals[5], carry, mask = 0x7FFFFFFFFFFFFULL;

    for (int i = 0; i < 5; i++) {
        fvals[i] = (-(uint128_t)f[i]);
        gvals[i] = (uint128_t)g[i];
        if (i > 0) 
            f19vals[i] = 19ull*fvals[i];
    }

    for (int i = 0; i < 5; i++)
    {
        rvals[i] = fvals[0]*gvals[i] + fvals[i]*gvals[0];
        for (int j = 1; j < 5; j++)
            rvals[i] += f19vals[(i+j)%5]*gvals[(5-j)%5];
    }

    for (int i = 0; i < 5; i++)
    {
        rvals[i] += (-mask) & (uint64_t)rvals[i];
        carry = rvals[i] >> 51;
        rvals[(i+1)%5] += carry;
    }

    hvals[0] = rvals[0] + (-mask) & (19ull*(rvals[4] >> 51));
    hvals[1] = rvals[1]+(hvals[0]>>51);
    for (int i = 2; i < 5; i++)
        hvals[i] += (hvals[(i-1)%5]>>51);
    for (int i = 0; i < 5; i++)
        h[i] = hvals[i];
  }
