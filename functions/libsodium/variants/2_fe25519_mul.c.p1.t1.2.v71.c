
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_values[5], g_values[5], f_converted[4];
    uint64_t carries[5], final_result[5];
    int i;

    for(i = 0; i<5; i++){
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }

    for(i=0; i<4; i++)
        f_converted[i] = 19ULL * f_values[i+1];

    r[0] = f_values[0] * g_values[0] + f_converted[0] * g_values[4] + f_converted[1] * g_values[3] + f_converted[2] * g_values[2] + f_converted[3] * g_values[1];
    r[1] = f_values[0] * g_values[1] + f_values[1] * g_values[0] + f_converted[1] * g_values[4] + f_converted[2] * g_values[3] + f_converted[3] * g_values[2];
    r[2] = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] + f_converted[2] * g_values[4] + f_converted[3] * g_values[3];
    r[3] = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] + f_values[3] * g_values[0] + f_converted[3] * g_values[4];
    r[4] = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] + f_values[3] * g_values[1] + f_values[4] * g_values[0];

    for(i=0; i<5; i++){
        final_result[i] = ((uint64_t) r[i]) & mask;
        carries[i] = (uint64_t) (r[i] >> 51);
        if(i < 4){
            r[i+1] += carries[i];
            final_result[i+1] = ((uint64_t) r[i+1]) & mask;
            carries[i+1] = (uint64_t) (r[i+1] >> 51);
        } else {
           final_result[0] += 19ULL * carries[i];
           carries[0] = final_result[0] >> 51;
           final_result[0] &= mask;
        }
    }
    final_result[1] += carries[0];
    carries[0] = final_result[1] >> 51;
    final_result[1] &= mask;
    final_result[2] += carries[0];

    for(i=0; i<5; i++)
        h[i] = final_result[i];
}
