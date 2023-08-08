fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_val[5], g_val[5];
    uint128_t carry, f_times_19[4];

    for(int i=0; i<5; i++) {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
    }
    
    for(int i=1; i<5; i++) {
        f_times_19[i-1] = 19ULL * f_val[i];
    }

    r[0] = f_val[0] * g_val[0] + f_times_19[3] * g_val[4] + f_times_19[1] * g_val[3] + f_times_19[2] * g_val[2] + f_times_19[0] * g_val[1];
    r[1] = f_val[0] * g_val[1] + f_val[1] * g_val[0] + f_times_19[1] * g_val[4] + f_times_19[2] * g_val[3] + f_times_19[0] * g_val[2];
    r[2] = f_val[0] * g_val[2] + f_val[1] * g_val[1] + f_val[2] * g_val[0] + f_times_19[2] * g_val[4] + f_times_19[0] * g_val[3];
    r[3] = f_val[0] * g_val[3] + f_val[1] * g_val[2] + f_val[2] * g_val[1] + f_val[3] * g_val[0] + f_times_19[0] * g_val[4];
    r[4] = f_val[0] * g_val[4] + f_val[1] * g_val[3] + f_val[2] * g_val[2] + f_val[3] * g_val[1] + f_val[4] * g_val[0];
    
    for(int i=0; i<5; i++) {
        carry = (r[i] >> 51);
        r[i] = r[i] & mask;
        r[i+1] += carry;

        if(i==4)
        {
            r[0] += 19ULL * carry;
            carry = r[0] >> 51;
            r[0] &= mask;

            r[1] += carry;
            carry = r[1] >> 51;
            r[1] &= mask;
            
            r[2] += carry;
        }
    }

    for(int i=0; i<5; i++)
    {
        h[i] = r[i];
    }
}