fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    for (int i = 0; i < 10; i++){
        f_values[i] = f[i];
    }

    int32_t g_values[10];
    for (int i = 0; i < 10; i++){
        g_values[i] = g[i]; 
    }

    int32_t g_19_values[10];
    for (int i = 0; i < 10; i++){
        g_19_values[i] = 19 * g[i];
    }

    int32_t f_2_values[10];
    for (int i = 0; i < 10;  i++){
        f_2_values[i]  = 2 * f[(i*2)%10];
    }

    int64_t fg_values[100];
    for (int i = 0; i < 10; i++){
        for (int j= 0; j< 10; j++){
            fg_values[10*i+j]    = f_values[i] * (int64_t) g_values[j];
        }
    }

    int64_t h_values[10];
    for (int i = 0; i< 10; i++){
        h_values[i] = 0;
        for (int j = 0; j < 10; j++){
            int index = (i+j)%10;
            h_values[i] += (fg_values[10*j+index] + fg_values[10*(j+1)%10+((index+9)%10)] * (int64_t)38 * (((j+1) & 1))) * ((((index & 1)) & ((j & 1))));
        }
    }

    int64_t carry[10];
	util_reduction(h_values, carry, h, 10);
}

static void util_reduction(int64_t *h, int64_t *carry, int32_t *result_h, size_t size) {
    for(size_t i = 0; i < size; i++) {
        carry[i] = (h[i] + (int64_t)(1 << ((i & 1) == 0 ? 25 : 24))) >> ((i & 1) == 0 ? 26 : 25);

        if(i + 1 < size) {
            h[i+1] += carry[i];
        } else {
            h[0] += 19 * carry[i];
        }

        h[i] -= carry[i] << ((i & 1) == 0 ? 26 : 25);
    }

    for(size_t i = 0; i < size; i++) {
        result_h[i] = (int32_t)h[i];
    }
}