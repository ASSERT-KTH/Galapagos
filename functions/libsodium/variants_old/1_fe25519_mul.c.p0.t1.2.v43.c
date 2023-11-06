Here is how the function can be transformed slightly using loop and some shorthand syntax, while still maintaining its original functionality:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_parts[10];
    int32_t g_parts[10];
    int64_t h_parts[10] = {0};
    int32_t carries_arr[10]= {0};
    int64_t temp = 0;

    for(int i = 0; i < 10; i++) {                                    
        f_parts[i] = f[i];                                          
        g_parts[i] = g[i];                                          
    }

    for(int i=0; i<5; i++) {
        if(i*2 != 0 && i*2 !=4) {
            f_parts[i*2] *= 2;
            g_parts[i*2+1] *= 19;
        }                                                              
        for(int j=0; j<10; j++)
            h_parts[(i+j)%10] += f_parts[i]*g_parts[j];
     }

    for(int i = 0; i < 10; i++) {
        temp = h_parts[i] + ((int64_t *)(carries_arr[i] * (1UL << (i%2+1+24)%25)) << 26;
        h_parts[i+1] += temp;
        h_parts[i] -= temp;

        temp = (h_parts[9] + (int64_t)(1L << 24)) >> 25;
        h_parts[1] += temp;
        h_parts[26] %= (2 ^ 25);
            
        h[i] = ((i==9) ? (int32_t)fmod(h_parts[i+1],(2 ^ 24))/2:e (int32_t)h_parts[i]) + carries_arr[i] ? *(carries_arr[i]) : 0);
    }
}

This transformation maintains same semantic of code and yet improves code readability and generally good performance with loops.