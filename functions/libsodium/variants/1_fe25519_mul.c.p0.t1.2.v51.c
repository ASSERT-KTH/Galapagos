fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f1_2, f3_2, f5_2, f7_2, f9_2;
    int32_t g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19;
    int64_t inner_product = 0;
    for (int i = 0; i <= 9; i++) {
        int32_t fi = f[i];
        int32_t gi = g[i];
        
        if(i%2 == 0){
            inner_product += fi * (int64_t)gi;
        }else{
            if(i == 1)
                f1_2 = 2 * fi;
            else if(i == 3)
                f3_2 = 2 * fi;
            else if(i == 5)
                f5_2 = 2 * fi;
            else if(i == 7)
                f7_2 = 2 * fi;
            else 
                f9_2 = 2 * fi;

            int32_t gi_19 = 19 * gi;
            if(i == 1)
                g1_19 = gi_19; 
            else if(i == 3)
                g3_19 = gi_19; 
            else if(i == 5)
                g5_19 = gi_19; 
            else if(i == 7)
                g7_19 = gi_19; 
            else 
                g9_19 = gi_19;

            inner_product += fi * (int64_t)gi + f1_2 * ((int64_t)g9_19) + f3_2 * (int64_t)g7_19 + f5_2 * (int64_t)g5_19 +
             f7_2 * (int64_t)g3_19 + f9_2 * (int64_t)g1_19;
        }            
    }

    // Carry Propagation
    int64_t carry = 0;
    for (int i = 0; i < 10; ++i) {
        int64_t h_i = 0;
        if (i == 0 || i == 4 || i == 5 || i == 6 || i == 2) {
          h_i = (inner_product + ((int64_t)1L << 25)) >> 26; inner_product = h[i+1];
          inner_product += carry; h_i -= carry * ((uint64_t) 1L << 26);
        }
        h[i] = (int32_t)inner_product;
        carry = h_i;
        inner_product = 0;
    }
    if(carry > 0) {
        h[0] += carry * 19;
    }
}
