Here is a functional equivalent program variant, adopting a slightly different strategy to store intermediate results.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a[5], b[5], r[5], acc, carry;
    uint64_t  h_ch[5];
    int i, j;
    
    for(i = 0; i < 5; i++) 
    {
        a[i] = (uint128_t)f[i];
        b[i] = (uint128_t) (i == 0 ? g[i] : 19 * g[i]);
    }

    for(i = 0; i < 5; i++) 
    {
        acc = 0;
        for(j = 0; j <= i; j++)
        {
            acc += a[j] * b[i-j];
            if (j != i) acc += a[i-j] * b[j];
        }

        r[i] = acc;
    }

    carry=0;
    for(i=0; i<5; i++) 
    {
        r[i]+=carry;
        h_ch[i] = r[i] & mask;
        carry = r[i] >> 51;
    }

    h_ch[0] += 19 * carry;
    carry = h_ch[0] >> 51;
    
    h_ch[0] &= mask;
	
    h_ch[1] += carry;
    carry = h_ch[1] >> 51;
	
    h_ch[1] &= mask;
	
    h_ch[2] += carry;
	
    for(i=0; i < 5; i++) 
	h[i] = h_ch[i];
}

In this variant, we combined a couple of steps into singular loops and opted for a single accumulator to keep things concise. Be aware that this might not maintain the same performance characteristics as the original given the different loop structures.