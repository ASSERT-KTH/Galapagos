fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    int32_t g_values[10];
    for (int i = 0; i < 10; i++) {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }

    int64_t gg_values[10];
    for (int i = 1; i < 10; i++) {
        gg_values[i] = 19 * f[i];
    }

    int64_t f_values_multiplied[10];
    for (int i = 1; i < 10; i += 2) {
        f_values_multiplied[i] = 2 * f_values[i];
    }

    int64_t fg_values_combined[100];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fg_values_combined[10*i + j] = f_values[i] * (int64_t)g_values[j];
        }
    }

    int64_t h_values[10] = {0};

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j <= i; j++) {
            h_values[i] += fg_values_combined[10*j + (i-j)];
            if(j < i){
                h_values[i] += fg_values_combined[10*(i-j) + j] * ((i-j) == 1 ? 2 : 1);
            }
        }
        h_values[i] += (i==0) ? 38*fg_values_combined[9] : ((i!=9)?19:0)*fg_values_combined[(9-i+1)*10];
    }

    int64_t carry_values[10];
    for(int i = 0 ; i < 10 ; i++) {
        carry_values[i] = (h_values[i] + (int64_t)(1L << (25 + (i%2)))) >> (26 - (i%2));
        h_values[(i+1)%10] += carry_values[i];
        h_values[i] -= carry_values[i] << (26 - (i%2));
    }

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) h_values[i];
    }
}
