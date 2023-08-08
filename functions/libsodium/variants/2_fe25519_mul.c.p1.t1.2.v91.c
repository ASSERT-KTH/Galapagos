fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = ~(uint64_t)0 >> 13;
    uint128_t temp, carry;
    uint128_t f0 = f[0];
    uint128_t g0 = g[0];
    uint64_t hr0, hr1, hr2, hr3, hr4;

    uint128_t f1234[4] = {f[1], f[2], f[3], f[4]};
    uint128_t g1234[4] = {g[1], g[2], g[3], g[4]};
    uint128_t hr[5] = {0, 0, 0, 0,};
    
    for(int i = 0; i < 4; i++){
        f1234[i] = 19 * f1234[i];
    }

    for(int i = 0; i< 5; i++){
        temp =  f0 * ( i == 4? g0: g1234[4 - i]);
        for(int j =0; j< i; j++){
            temp += f1234[j] * g1234[i-j-1];
        }
        hr[i] = temp;
        if(i != 0){
            hr[i] += hr[i - 1] >> 51;
            hr[i - 1] &= mask;
        }
    }

    hr[0] += 19 * (hr[4] >> 51);
    hr[4] &= mask;

    carry = hr[0] >> 51;
    hr[0] &= mask;
    hr[1] += carry;
    
    carry = hr[1] >> 51;
    hr[1] &= mask;
    hr[2] += carry;

    h[0] = hr[0];
    h[1] = hr[1];
    h[2] = hr[2];
    h[3] = hr[3];
    h[4] = hr[4];
}