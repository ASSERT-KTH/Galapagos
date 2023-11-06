// Variant 1
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    for (int i = 0; i <= 9; ++i) {
        int64_t acc = 0;
        for(int j = 0; j <= i; ++j) {
            acc += ((j & 1) && j != i ? 2 : 1) * f[j] * (int64_t) g[i-j] * ((j==i ? 1 : 1 << i-j & 1 ? 19 : 1));
        }

        h[i] = acc * ((i & 1 ? 38 : 1));
    }
}

// Variant 2
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elems[10] = {f[0], f[1], f[2],               f[3], f[4], 
                           f[5], f[6], 19 * f[7], 2 * f[8], f[9]};
    int32_t g_elems[10] = {g[0], g[1], 19 * g[2], g[3], 19 * g[4], 
                           g[5], g[6], 2 * g[7], 19 * g[8], g[9]};
    int64_t tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j <= i; ++j) {
            tmp[i] += (int64_t) f_elems[j] * g_elems[i - j];
        }
        
        // Carry
        if (i % 2 == 0){
            const int64_t carry = tmp[i] >> 26;
            tmp[i] -= carry << 26;
            if (i < 9)
                tmp[i + 1] += carry;
            else
                tmp[0] += 19 * carry;
        }
        else {
            const int64_t carry = tmp[i] >> 25;
            tmp[i] -= carry << 25;
            tmp[i + 1] += carry;
        }

        // Put into result
        h[i] = (int32_t) tmp[i];
    }
} 

// Variant 3
void fe25519_mul(fe25519 hd, const fe25519 fd, const fe25519 gd)
{
    int64_t f[10], g[10], h[10];
    for (int i = 0; i <= 9; ++i){
        f[i] = fd[i];
        g[i] = gd[i];
    }

    int64_t g1_19 = 19 * g[1], g2_19 = 19 * g[2], g3_19 = 19 * g[3];
    int64_t g4_19 = 19 * g[4], g5_19 = 19 * g[5], g6_19 = 19 * g[6];
    int64_t g7_19 = 19 * g[7], g8_19 = 19 * g[8], g9_19 = 19 * g[9];

    for(int i=0; i<=9; ++i){
        h[i] = f[0]*(g[i]*19*(i&1?1:2));
        h[i] += g[0]*(f[i]*19*(i&1?1:2));
    
        for(int j=1;j<=(i/2);++j){
            h[i] += 2*(f[j]*g[i-j] + g[j]*f[i-j])*19*((j+i)%2/* accounts for g_19 terms */);
            h[i]  = h[i]<<26>>26;
        }
    
        if(i>0 &&  !(i&1))
            h[i] += 38*(f[i/2]*g[i/2]); /*  '38' hides an implicit '2*'  */
        
        /* propagate carries starting from the most significant terms */
        int64_t c31= h[i]>>31&1;  
        int64_t c30= h[i]>>30&1;  
        h[i-2]+=c31;
        h[i-2]+=c30;
        h[i-5]+=19*c30<<(31&1);
    }
    
    for(int carry, i = 9; i > 0; --i){
    /* add: 668 bytes */
        carry = h[i] >> 25; h[i-1] += carry; h[i] -= carry * 33554432; /* 33554432 = 2^25 */
    }

   /* same, without aliasing. pay attention of hhh[0] and h[0] AND 'inplace' computation of 'x' */
    hd[1] = h[1];
    hd[2] = h[2]; 
    hd[3] = h[3];
    hd[4] = h[4]; 
    hd[5] = h[5]; 
    hd[6] = h[6];
    hd[7] = h[7]; 
    hd[8] = h[8]; 
    hd[9] = h[9];
}
