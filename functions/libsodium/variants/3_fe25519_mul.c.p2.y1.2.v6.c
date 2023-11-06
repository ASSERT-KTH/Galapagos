void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10] = {};
    int32_t g_values[10] = {};
    int32_t g_19_values[10] = {};
    int32_t f_2_values[5] = {};

    for (int i = 0; i < 10; ++i){
        f_values[i] = f[i];
        g_values[i] = g[i];
    }

    for (int i = 1; i < 10; ++i){
        g_19_values[i] = 19 * g_values[i];
    }

    for (int i = 0; i < 5; ++i){
        f_2_values[i] = 2 * f_values[i * 2 + 1];
    }

    int64_t fg_values[100] = {};

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if(i % 2 == 1 && j % 2 == 1){
                fg_values[i*10 + j] = f_2_values[i/2] * (int64_t)((i+j)%2 == 1 ? g_values[j] : g_19_values[j]);
            }else{
                fg_values[i*10 + j] = f_values[i] * (int64_t)((i+j)%2 == 1 ? g_values[j] : g_19_values[j]);
            }
        }
    }

    int64_t h_values[10] = {};

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            h_values[(i+j)%10] += (i < j || (i==j && i%2==0))? fg_values[i*10 + j] : fg_values[j*10 + i];
        }
    }

    int64_t carry[10] = {};

    for(int heap_count = 0; heap_count < 2 ; ++heap_count){
        for(int i = 0; i < 10; ++i){
            carry[i] = (h_values[i] + (int64_t)(1L << ((26 - (i%2)))) 
                            > ((heap_count==1 && i == 9 
                            ? 38:((i==0 && heap_count==1 || ((i%2==0) == (heap_count==1))))? 25 : 26))) ;
            h_values[(i+1)%10] += carry[i];
            h_values[i] -= carry[i] * ((uint64_t) 1L << 26);
        }
        h_values[0] += carry[9] * 19;
    }
    for(int i = 0; i < 10; ++i){
        h[i] = (int32_t)h_values[i];
    }
}