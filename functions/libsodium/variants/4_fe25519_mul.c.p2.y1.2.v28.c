void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t f1_19, f2_19, f3_19, f4_19;
    uint128_t r[5];
    uint128_t f_elem[5], g_elem[5];
    uint64_t r_elem[5], carry;

    for(int i=0; i<5; i++) {
        f_elem[i] = (uint128_t)f[i];
        g_elem[i] = (uint128_t)g[i];
    }

    f1_19 = 19ULL * f_elem[1];
    f2_19 = 19ULL * f_elem[2];
    f3_19 = 19ULL * f_elem[3];
    f4_19 = 19ULL * f_elem[4];

    r[0] = f_elem[0]*g_elem[0] + f1_19*g_elem[4] + f2_19*g_elem[3] + f3_19*g_elem[2] + f4_19*g_elem[1];
    r[1] = f_elem[0]*g_elem[1] + f_elem[1]*g_elem[0] + f2_19*g_elem[4] + f3_19*g_elem[3] + f4_19*g_elem[2];
    r[2] = f_elem[0]*g_elem[2] + f_elem[1]*g_elem[1] + f_elem[2]*g_elem[0] + f3_19*g_elem[4] + f4_19*g_elem[3];
    r[3] = f_elem[0]*g_elem[3] + f_elem[1]*g_elem[2] + f_elem[2]*g_elem[1] + f_elem[3]*g_elem[0] + f4_19*g_elem[4];
    r[4] = f_elem[0]*g_elem[4] + f_elem[1]*g_elem[3] + f_elem[2]*g_elem[2] + f_elem[3]*g_elem[1] + f_elem[4]*g_elem[0];

    for(int j=0; j<5; j++) {
        r_elem[j] = ((uint64_t) r[j]) & mask;
        carry  = (uint64_t) (r[j] >> 51);
        if (j < 4) {
            r[j+1] += carry;
        } 
        
        if(j == 4) {
            for(int k=0; k<2; k++) {
                r_elem[0] += 19ULL * carry;
                carry = r_elem[0] >> 51;
                r_elem[0] &= mask;
                r_elem[k+1] += carry;
                carry = r_elem[k+1] >> 51;
                r_elem[k+1] &= mask;
            }
            break;
        }
    }

    for(int l=0; l<5; l++) {
        h[l] = r_elem[l];
    }
}