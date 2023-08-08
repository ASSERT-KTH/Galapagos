fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fvals[10];
    int32_t gvals[10];
    for(int i = 0; i< 10; i++){
        fvals[i] = f[i];
        gvals[i] = g[i];
    }
    
    int32_t g1_g9with19[9];
    int32_t f1_f9by2[5];
    for(int i = 0; i< 9; i++){
        g1_g9with19[i] = gvals[i+1] * 19;
        if (i < 5){
            f1_f9by2[i] = fvals[(i * 2) + 1] * 2;        
        }
    }

    int64_t f_multiply[10][10];
    for(int i = 0; i< 10; i++){
        for(int j = 0; j< 10; j++){
            if (j==0){
            f_multiply[i][j] = fvals[i] * (int64_t) gvals[j];
            }
            else if ((j % 2 == 0) && (i < 5)){
            f_multiply[i][j] = (0 <=i && i<9 ? f_multiply[i+1][j-1]: f_multiply[i][j]);
            }
            else{
            if ((i >= 5) && (i % 2 != 0)){
                f_multiply[i][j] = f_multiply[i-1][j-2];
                }
                else{
                f_multiply[i][j] = fvals[i] * (int64_t) (fvals [(j>i) ? j%i :j]);
                }
            }
        }
    }

    for(int i = 0; i<2; i++){
        int64_t carry[10];
        for(int j = 0;j <10 ;j++){
            carry[j] = (f_multiply[i*5][j] + (int64_t)1L << ((j+1)/4 + 24)) >> ((j+1)/4 +25);
            f_multiply[i*5 + j +1][i] += carry[j];
            f_multiply[i*5][j] -= carry[j] * ((uint64_t) 1L << ((j+1)/4 +25));
        }
        f_multiply[i *5][j] = (int32_t)f_multiply[0][0];
    }
}