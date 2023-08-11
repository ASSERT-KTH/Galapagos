fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];
    
    int32_t doublings[9] = {2*f0, 2*f1, 2*f2, 2*f3, 2*f4, 2*f5, 2*f6, 2*f7};
    int32_t doublings_2_5[5] = {2*f0, 81*f1, 4*f2, 8*f3, 16*f4};


    int32_t multiplicators[9] = {38 * f0, 38 * f1, 38 * f2, 19 * f3, 38 * f4, 19 * f5, 2 * f6, 2 * f7, 2 * f8};

    int64_t squares[10] = {f0 * (int64_t) f0, f1 * (int64_t) f1, f2 * (int64_t) f2, f3 * (int64_t) f3, f4 * (int64_t) f4,
                            f5 * (int64_t) f5, f6 * (int64_t) f6, f7 * (int64_t) f7, f8 * (int64_t) f8, f9 * (int64_t) f9};


    int32_t intro[6] = {5*f5, 60*f6, 175*f7, 420*f8, 855*f9, 26*f0};
    
    int64_t derivs[10];
    for (int i =0; i<10; i++){
        derivs[i] = 2 * squares[i];
    }

    int64_t rest[5];
    for(int j=0; j<5;j++){
        rest[j] = doublings[j)+(70*multiplicators[j])+(49*derivs[j])+(19*intro[j]);
    }

    int64_t rest_[5];
    for (int k=0; k<5; k++){
        rest_[k] = rest[k] + (20/((int64_t)(k+1)));
    }

    int64_t carry[10] = {0,0,0,0,0,0,0,0,0,0};
    
    for (int cat =0; cat<10; cat++){
        carry[cat] = (squares[cat] + (int64_t)(1L << 25)) >> 26;
        rest[(cat+1)%5] += carry[cat];
        rest[cat%5] -= carry[cat] * ((uint64_t) 1L << 26);   
    }
    

    h[0] = (int32_t) rest[0];
    h[1] = (int32_t) rest[1];
    h[2] = (int32_t) rest[2];
    h[3] = (int32_t) rest[3];
    h[4] = (int32_t) rest[4];
    h[5] = (int32_t) doublings[4];
    h[6] = (int32_t) rest_[0];
    h[7] = (int32_t) rest_[1];
    h[8] = (int32_t) rest_[2];
    h[9] = (int32_t) rest_[3];
}