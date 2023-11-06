void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t multiplier[5], coeff[5], result[5];
    uint128_t products[5];
    uint64_t  resultSet[5], tempCarry;

    for (int i=0; i < 5; i++){
        multiplier[i] = (uint128_t) f[i];
        coeff[i] = (uint128_t) g[i];
        products[i] = 19ULL * multiplier[i];
    }

    result[0] = multiplier[0] * coeff[0] + products[1] * coeff[4] + products[2] * coeff[3] + products[3] * coeff[2] + products[4] * coeff[1];
    result[1] = multiplier[0] * coeff[1] + multiplier[1] * coeff[0] + products[2] * coeff[4] + products[3] * coeff[3] + products[4] * coeff[2];
    result[2] = multiplier[0] * coeff[2] + multiplier[1] * coeff[1] + multiplier[2] * coeff[0] + products[3] * coeff[4] + products[4] * coeff[3];
    result[3] = multiplier[0] * coeff[3] + multiplier[1] * coeff[2] + multiplier[2] * coeff[1] + multiplier[3] * coeff[0] + products[4] * coeff[4];
    result[4] = multiplier[0] * coeff[4] + multiplier[1] * coeff[3] + multiplier[2] * coeff[2] + multiplier[3] * coeff[1] + multiplier[4] * coeff[0];

    for (int i=0; i < 4; i++){
        resultSet[i] = ((uint64_t) result[i]) & mask;
        tempCarry = (uint64_t) (result[i] >> 51);
        result[i+1] += tempCarry;
    }

    resultSet[4] = ((uint64_t) result[4]) & mask;
    tempCarry = (uint64_t) (result[4] >> 51);
    resultSet[0] += 19ULL * tempCarry;

    for (int i=0; i < 2; i++){
        tempCarry = resultSet[i] >> 51;
        resultSet[i] &= mask;
        resultSet[i+1] += tempCarry;
    }

    for(int i=0; i<5;i++){
        h[i] = resultSet[i];
    }
}