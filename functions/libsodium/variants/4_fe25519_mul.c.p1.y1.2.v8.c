variant 1:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rm[5], fm[5], f19[5 - 1], gm[5];
    uint64_t carry;
    int i, j;
  
    for (i = 0; i < 5; i++) {
        fm[i] = (uint128_t)f[i];
        gm[i] = (uint128_t)g[i];
        if (i != 0) f19[i - 1] = 19ULL * fm[i];
    }

    for (i = 0; i < 5; i++) {
        rm[i] = fm[0] * gm[i];
        for (j = 1; j <= i && j <= 4; j++) {
            if (j <= i - j)
                rm[i] += fm[j] * gm[i-j];
            else
                rm[i] += f19[j - 1] * gm[i-j];
        }
        if (i < 4)
            rm[i] += f19[i];
    }

    for (i = 0; i < 5; i++) {
        h[i] = ((uint64_t)rm[i]) & mask;
        if (i != 4) {
            carry = (uint64_t)(rm[i] >> 51);
            rm[i + 1] += carry;
        }
    }

    h[0] += 19ULL * (((uint64_t)rm[4]) >> 51);
}


variant 2:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rf[5][5];
    uint64_t  carry;

    for (int i = 0; i < 5; ++i) {
        uint128_t fi = f[i]; 
        for (int j = 0; j < 5; ++j)  rf[j][i] = fi * g[j]; })      
    }

    uint128_t r[5] = {
      rf[0][0] +    rf[1][4] * 19ULL +    rf[2][3] * 19ULL +    rf[3][2] * 19ULL +    rf[4][1] * 19ULL,
      rf[0][1] + rf[1][0]        +    rf[2][4] * 19ULL +    rf[3][3] * 19ULL +    rf[4][2] * 19ULL,
      rf[0][2] + rf[1][1]        + rf[2][0]        +    rf[3][4] * 19ULL +    rf[4][3] * 19ULL,
      rf[0][3] + rf[1][2]        + rf[2][1]        + rf[3][0]        +    rf[4][4] * 19ULL,
      rf[0][4] + rf[1][3]        + rf[2][2]        + rf[3][1]        + rf[4][0] 
    };

    h[0] = (uint64_t) r[0] & mask;  r[1] += (uint64_t) (r[0]>>51);
    h[1] = (uint64_t) r[1] & mask;  r[2] += (uint64_t) (r[1]>>51);
    h[2] = (uint64_t) r[2] & mask;  r[3] += (uint64_t) (r[2]>>51);
    h[3] = (uint64_t) r[3] & mask;
    h[4] = (uint64_t) r[4] & mask;

    carry = (uint64_t) (r[4]>>51);
    h[0] =(uint64_t) r[0] + 19ULL * carry;
    carry = h[0] >> 51; 
    h[0] = h[0] & mask;
    h[1] += carry;
}
