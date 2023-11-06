void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t results[5], fieldValue[5];
    uint128_t fieldValue_twice_0, fieldValue_twice_1;
    uint128_t fieldValue_38_times_1, fieldValue_38_times_2, fieldValue_38_times_3;
    uint128_t fieldValue_19_times_3, fieldValue_19_times_4;
    uint64_t  individualResults[5];
    uint64_t  carry;

    for(int i=0 ; i<5 ; i++)
        fieldValue[i] = (uint128_t) f[i];

    fieldValue_twice_0 = fieldValue[0] << 1;
    fieldValue_twice_1 = fieldValue[1] << 1;

    fieldValue_38_times_1 = 38ULL * fieldValue[1];
    fieldValue_38_times_2 = 38ULL * fieldValue[2];
    fieldValue_38_times_3 = 38ULL * fieldValue[3];

    fieldValue_19_times_3 = 19ULL * fieldValue[3];
    fieldValue_19_times_4 = 19ULL * fieldValue[4];

    results[0] = fieldValue[0] * fieldValue[0] + fieldValue_38_times_1 * fieldValue[4] + fieldValue_38_times_2 * fieldValue[3];
    results[1] = fieldValue_twice_0 * fieldValue[1] + fieldValue_38_times_2 * fieldValue[4] + fieldValue_19_times_3 * fieldValue[3];
    results[2] = fieldValue_twice_0 * fieldValue[2] + fieldValue[1] * fieldValue[1] + fieldValue_38_times_3 * fieldValue[4];
    results[3] = fieldValue_twice_0 * fieldValue[3] +  fieldValue_twice_1 * fieldValue[2] + fieldValue_19_times_4 * fieldValue[4];
    results[4] = fieldValue_twice_0 * fieldValue[4] +  fieldValue_twice_1 * fieldValue[3] +     fieldValue[2] * fieldValue[2];

    for(int i=0 ; i<5 ; i++)
    {
        individualResults[i] = ((uint64_t) results[i]) & mask;
        carry  = (uint64_t) (results[i] >> 51);
        results[(i+1)%5] += carry;
        individualResults[i] = ((uint64_t) results[i]) & mask;

        if(i > 0)
        {
            carry  = individualResults[i] >> 51;
            individualResults[i] &= mask;
            results[(i+2)%5] += carry;
        }  
    }

    individualResults[0] += 19ULL * carry;
    carry  = individualResults[0] >> 51;
    individualResults[0] &= mask;
    sliceValue_Result[1] += carry;
    carry  = sliceValue_Result[1] >> 51;
    sliceValue_Result[1] &= mask;
    sliceValue_Result[2] += carry;

    for(int i=0 ; i<5 ; i++)
        h[i] = sliceValue_Result[i];
}