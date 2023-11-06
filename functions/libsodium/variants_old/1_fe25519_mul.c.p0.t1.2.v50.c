fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_arr[10];
    int32_t g_arr[10];
    for(int i=0; i<10; i++) {
        f_arr[i] = f[i];
        g_arr[i] = g[i];
    }
    
    int32_t g1_19_to_g9_19[9], f1_2_to_f9_2[5];
    for(int i=0; i<9; i++) {
        g1_19_to_g9_19[i] = 19 * g_arr[i+1]; /* 1.959375*2^29 */
    }
    
    for(int i=1; i<10; i+=2) {
        f1_2_to_f9_2[i/2]  = 2 * f_arr[i];
    }
    
    int64_t f0g0_to_f9g9_38[100];
    for(int fi=0; fi<10; fi++) {
        for(int gi=0; gi<10; gi++) {
            if(fi%2==1 && gi==19) {
                f0g0_to_f9g9_38[fi*10+gi] = f1_2_to_f9g9_38[fi / 2] * (int64_t) g1_19_to_g9_19[gi - 1];
            } else if(fi*10+gi <= 80){ // i.e., up till f8 * g0
                f0g0_to_f9g9_38[fi*10+gi] = f_arr[fi] * (int64_t) g_arr[gi];
            } else { // i.e., for f9 * g0 to f9 * g9
                f0g0_to_f9g9_38[fi*10+gi] = f_arr[fi] * (int64_t) g1_19_to_g9_19[gi - 1];
            }   
        }
    }

    int64_t h_elements[10];
    for (int i=0; i < 10; i++) {
        h_elements[i] = 0;
        for (int offset=0; offset < 10-offset; offset++) {
            h_elements[i] += f0g0_to_f9g9_38[offset*10 + (i - offset)];
            if (i != offset) {
                h_elements[i] += f0g0_to_f9g9_38[offset*10 + (i - offset)];
            }
        }
    }
    /*printf("\n");
    for(int i=0; i<10; i++){
        printf("%lli. ",h_elements[i]);
    }*/
    
    int64_t carry[10];
    carry[0] = (h_elements[0] + (int64_t)(1L << 25)) >> 26; 
    h_elements[1] += carry[0]; 
    h_elements[0] -= carry[0] * ((uint64_t)1L << 26);
    carry[4] = (h_elements[4] + (int64_t)(1L << 25)) >> 26;
    h_elements[5] += carry[4];
    h_elements[4] -= carry[4] * ((uint64_t)1L << 26);

    carry[1] = (h_elements[1] + (int64_t)(1L << 24)) >> 25;
    h_elements[2] += carry[1]; 
    h_elements[1] -= carry[1] * ((uint64_t) 1L << 25);
    carry[5] = (h_elements[5] + (int64_t)(1L << 24)) >> 25;
    h_elements[6] += carry[5]; 
    h_elements[5] -= carry[5] * ((uint64_t) 1L << 25);

    carry[2] = (h_elements[2] + (int64_t)(1L << 25)) >> 26; 
    h_elements[3] += carry[2]; 
    h_elements[2] -= carry[2] * ((uint64_t) 1L << 26);
    carry[6] = (h_elements[6] + (int64_t)(1L << 25)) >> 26;
    h_elements[7] += carry[6];
    h_elements[6] -= carry[6] * ((uint64_t) 1L << 26);

    carry[3] = (h_elements[3] + (int64_t)(1L << 24)) >> 25; 
    h_elements[4] += carry[3];
    h_elements[3] -= carry[3] * ((uint64_t) 1L << 25);  
    carry[7] = (h_elements[7] + (int64_t)(1L << 24)) >> 25; 
    h_elements[8] += carry[7];
    h_elements[7] -= carry[7] * ((uint64_t) 1L << 25);

    carry[4] = (h_elements[4] + (int64_t)(1L << 25)) >> 26;
    h_elements[5] += carry[4]; 
    h_elements[4] -= carry[4] * ((uint64_t) 1L << 26);
    carry[8] = (h_elements[8] + (int64_t)(1L << 25)) >> 26;
    h_elements[9] += carry[8];
    h_elements[8] -= carry[8 * ((uint64_t) 1L << 26)];

    carry[9] = (h_elements[9] + (int64_t)(1L << 24)) >> 25;
    h_elements[0] += carry[9] * 19; 
    h_elements[9] -= carry[9] * ((uint64_t) 1L << 25);
    
    carry[0] = (h_elements[0] + (int64_t)(1L << 25)) >> 26;
    h_elements[1] += carry[0];
    h_elements[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i=0; i < 10; i++) {
        h[i] = (int32_t) h_elements[i];
    }
}