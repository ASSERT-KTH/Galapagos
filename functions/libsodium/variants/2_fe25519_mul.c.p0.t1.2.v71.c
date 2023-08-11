fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_elements[5];
    uint128_t g_elements[5];
    uint128_t f_mulitone_19[5]; // mulitone: multiplied by nineteen
    uint64_t r_parts[20];
    uint64_t currentCarry;

    for(int i = 0; i < 5; i++) {
        f_elements[i] = (uint128_t)f[i];
        g_elements[i] = (uint128_t)g[i];
    }

    for(int i = 1; i < 5; i++) {
        f_mulitone_19[i]= 19ULL * f[i];
    }

    r0 = f_mulitone_19[0] * g_elements[0] + f_mulitone_19[1] * g_elements[4] + f_mulitone_19[2] * g_elements[3] + f_mulitone_19[3] * g_elements[2] + f_mulitone_19[4] * g_elements[1];
    r1 = f_elements[0] * g_elements[1] + f_elements[1] * g_elements[0] + f_mulitone_19[2] * g_elements[4] + f_mulitone_19[3] * g_elements[3] + f_mulitone_19[4] * g_elements[2];
    r2 = f_elements[0] * g_elements[2] + f_elements[1] * g_elements[1] + f_elements[2] * g_elements[0] + f_mulitone_19[3] * g_elements[4] + f_mulitone_19[4] * g_elements[3];
    r3 = f_elements[0] * g_elements[3] + f_elements[1] * g_elements[2] + f_elements[2] * g_elements[1] + f_elements[3] * g_elements[0] + f_mulitone_19[4] * g_elements[4];
    r4 = f_elements[0] * g_elements[4] + f_elements[1] * g_elements[3] + f_elements[2] * g_elements[2] + f_elements[3] * g_elements[1] + f_elements[4] * g_elements[0];

    for(int i=0; i<20; i++){
        r_parts[i] = (i < 5? ((uint64_t)b[i]) & mask : r_parts[i - 5] );
        currentCarry  = !(i < 4)?  (uint64_t) (b[i - 4] >> 51): 0  ;
        r_parts[i + 5] += currentCarry;
    }

    for(int i=0; i<5; i++){
        h[i] = r_parts[i];
    }

}