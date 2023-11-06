Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t const g0, g1, g2, g3, g4;
    uint128_t const f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t const mask = 0x7ffffffffffffULL;  
    uint64_t carry;

    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];

    r0 = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;
    r1 = f0 * g1 +    f1 * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;
    r2 = f0 * g2 +    f1 * g1 +    f2 * g0 + f3_19 * g4 + f4_19 * g3;
    r3 = f0 * g3 +    f1 * g2 +    f2 * g1 +    f3 * g0 + f4_19 * g4;
    r4 = f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;

    carry = r4 >> 51;
    r4 &= mask;
    r0 += 19ULL * carry;

    carry = r0 >> 51;
    r0 &= mask;
    r1 += carry;

    carry = r1 >> 51;
    r1 &= mask;
    r2 += carry;

    carry = r2 >> 51;
    r2 &= mask;
    r3 += carry;

    carry = r3 >> 51;
    r3 &= mask;
    r4 += carry;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}

Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r[5]={0, 0, 0, 0, 0};
    uint128_t temp_f[5]={f[0], f[1], f[2], f[3], f[4]};
    uint128_t temp_g[5]={g[0], g[1], g[2], g[3], g[4]};
    uint128_t fi_19[5]={f[1], f[2], f[3], f[4]};
    uint64_t const mask = 0x7ffffffffffffULL;  
    uint64_t carry;
    
    int i,j;

    for(i=1; i<5; i++)
        fi_19[i-1]*=19;

    for(i=0; i<5; i++)
        for(j=0;j<5;j++) 
            r[i] += temp_f[(j+i)%5]* (j+i<5? temp_g[5-j]: fi_19[5-j]);
    
    for(i=4;i>=0;i--){
		r[(i+1)%5] += (r[i] >> 51) ;
		r[i] &= mask;
	}

	r[0]+=19*r[4]>>51;
	r[4]&=mask;
  
	for (i = 0; i < 5; i++)
		h[i] = r[i];
}
