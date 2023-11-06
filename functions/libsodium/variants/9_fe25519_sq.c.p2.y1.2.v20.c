void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fc[10];
    int64_t hc[10];

    for(int i = 0; i < 10; i++){
        fc[i] = f[i];     
    }

    for(int i = 0; i < 5; i++){
        fc[i<<1] = fc[i]<<1; // equal to fc[i*2] = fc[i]*2 
    }
 
    fc[5] = 38 * fc[5];
    fc[6] = 19 * fc[6];
    fc[7] = 38 * fc[7];
    fc[8] = 19 * fc[8];
    fc[9] = 38 * fc[9];

    for(int i = 0, x = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j < i) x = i + j;;
            else x = i + j + 1;
            if(j == i) hc[x] = fc[i] * (int64_t)fc[i];
            else hc[x] += fc[i] * (int64_t)fc[j];
            if(i + j & 1) hc[x + 1] += fc[i] * (int64_t)fc[j];
        }
    }

    int64_t carry[10];
    for(int i = 0; i < 10; i++){
        carry[i] = (hc[i] + (int64_t)(1<<((i&1)?24:25))) >> ((i & 1) ? 25 : 26);
        if(i < 9){
            hc[i+1] += carry[i];
        }
    }

    hc[0] += carry[9] * 19;
    carry[0] = (hc[0] + (int64_t)(1L << 25)) >> 26;
    hc[1] += carry[0];
    hc[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i = 0; i < 10; i++){
        h[i] = (int32_t)hc[i];
    }

}