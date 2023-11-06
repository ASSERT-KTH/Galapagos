void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elements[10];
    int32_t g_elements[10];
    int32_t g_elements_19[10];
    int32_t f_elements_2[5] = {2 * f[1], 2 * f[3], 2 * f[5], 2 * f[7], 2 * f[9]};
    int64_t multiply_results[95];

    for(int i = 0; i <= 9; i++) {
        f_elements[i] = f[i];
        g_elements[i] = g[i];
        if(i % 2 ==0 )
            g_elements_19[i] = 19 * g[i];
    }

    for (int i = 0; i <= 4; i++) {
        for (int run = 0; run <= 9; run++){
            if(i == run)
              multiply_results[10 * i + run] = f_elements[2*i] * (int64_t) g_elements[run];
            else if(run == 2*i + 1)
              multiply_results[10 * i + run] = f_elements_2[i] * (int64_t)  g_elements[run];
            else if (run > 2*i + 1 )
              multiply_results[10 * i + run] = f_elements[2*i] * (int64_t) g_elements_19[run];
        }
    }

    int64_t h_results[10] = {};
    for (int i = 0; i <= 9; i++){
        for(int j = 0; j <= 4; j++){
            if((i - 2*j) >= 0)
              h_results[i] += multiply_results[10*j + i - 2*j];
        }
        if( i % 2 == 0 && i != 0)
            h_results[i] += multiply_results[10 * (i / 2) + 9];
    }

    int64_t carry[10] = {};

    carry[0] = (h_results[0] + (int64_t) (1<<25)) >> 26;
    h_results[1] += carry[0];
    h_results[0] -= carry[0] << 26;

    for (int i = 1; i <= 8; i+=2) {
        carry[i] = (h_results[i] + (int64_t) (1<<24)) >> 25;
        h_results[i+1] += carry[i];
        h_results[i] -= carry[i] << 25;

        carry[i+1] = (h_results[i+1] + (int64_t) (1<<25)) >> 26;
        h_results[(i+2)%10] += carry[i+1];
        h_results[i+1] -= carry[i+1] << 26;;
    }

    carry[9] = (h_results[9] + (int64_t) (1<<24)) >> 25;
    h_results[0] += carry[9] * 19;
    h_results[9] -= carry[9] << 25;

    for (int i=0; i<=9; i++)
      h[i] = (int32_t) h_results[i];
}
