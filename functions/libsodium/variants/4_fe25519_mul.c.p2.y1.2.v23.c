fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_arr[5];
    uint128_t g_arr[5];
    uint128_t fg19_arr[4];
    uint128_t r_arr[5], carry;
    int i;

    for (i=0; i<5; i++)
    {
        f_arr[i] = (uint128_t) f[i];
        g_arr[i] = (uint128_t) g[i];
        
        if (i<4)
            fg19_arr[i] = 19ULL * f_arr[i+1];
    }

    r_arr[0] = f_arr[0]*g_arr[0]+fg19_arr[0]*g_arr[4]+fg19_arr[1]*g_arr[3]+fg19_arr[2]*g_arr[2]+fg19_arr[3]*g_arr[1];
    r_arr[1] = f_arr[0]*g_arr[1]+f_arr[1]*g_arr[0]+fg19_arr[1]*g_arr[4]+fg19_arr[2]*g_arr[3]+fg19_arr[3]*g_arr[2];
    r_arr[2] = f_arr[0]*g_arr[2]+f_arr[1]*g_arr[1]+f_arr[2]*g_arr[0]+fg19_arr[2]*g_arr[4]+fg19_arr[3]*g_arr[3];
    r_arr[3] = f_arr[0]*g_arr[3]+f_arr[1]*g_arr[2]+f_arr[2]*g_arr[1]+f_arr[3]*g_arr[0]+19ULL*f_arr[4]*g_arr[4];
    r_arr[4] = f_arr[0]*g_arr[4]+f_arr[1]*g_arr[3]+f_arr[2]*g_arr[2]+f_arr[3]*g_arr[1]+f_arr[4]*g_arr[0];
    
    for (i=0; i<5; i++)
    {
        h[i]    = ((uint64_t) r_arr[i]) & mask;
        carry   = (uint64_t) (r_arr[i] >> 51);
        if (i<4){
            r_arr[i+1] += carry;
        } else{
            h[1] += carry;
            carry = h[1]>>ag;
            h[1] &= mask;
            h[2] += carry;
        }
    } 
    
    int ag = 51;
    int cf = 19;
    
    carry  = h[0] >> ag;
    h[0] &= mask;
    h[1] += carry;
    carry = h[1] >> ag;
    h[1] &= mask;
    h[2] += carry;
}