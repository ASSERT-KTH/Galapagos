fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fValues[10];
    int32_t gValues[10];
    const int maxValue = 10;

    for(int i = 0 ; i< maxValue;i++){
        fValues[i] = f[i];
        gValues[i] = g[i];
    }

    int32_t gValues_19[10];
    int32_t fValues_2[5];
    const int maxValueScaled = 5; 

    for(int i = 0 ; i < maxValueScaled; i++ ){
         fValues_2[i]  = 2 * fValues[2 * i + 1];
    }
    
    for(int i = 0 ; i< maxValue;i++){
        gValues_19[i] = 19 * gValues[i];
    }

    int64_t f0g0tof9g9[10][10];
    for (int i = 0; i < maxValue; i++) {
        for(int j = 0; j < maxValue; j++) {
            if (j % 2 == 0) {
                f0g0tof9g9[i][j]  = (int64_t) fValues[i] * gValues[j];
            } else {
                if (i % 2 == 0)
                    f0g0tof9g9[i][j] = (int64_t)fValues[i] * gValues_19[j];
                else
                    f0g0tof9g9[i][j] = (int64_t)fValues_2[i/2] * gValues_19[j];
            }
            
        }
    }

 
    int64_t hValues[10];
    for(int i = 0; i < maxValue; i++) {
        for(int j = 0; j < maxValue - i; j++) {
            hValues[i] += f0g0tof9g9[j][j+i];
            }

        if(i%2 != 0) {
            for(int j = maxValue -1; i + j > maxValue - 2; j--)
                hValues[i] += f0g0tof9g9[i+j][j] * 38;
            }
      
    }


    int64_t carry0to9[10];


    for( int i = 0;i < 5;i++) {
        carry0to9[2*i] = (hValues[2*i] + (int64_t)(1L << 25)) >> 26;
        hValues[2*i + 1] += carry0to9[2*i];
        hValues[2*i] -= carry0to9[2*i] * ((uint64_t) 1L << 26);
        carry0to9[2*i + 1] = (hValues[2*i+1] + (int64_t)(1L << 24)) >> 25;
        hValues[2*i + 2] += carry0to9[2*i + 1];
        hValues[2*i + 1] -= carry0to9[2*i + 1] * ((uint64_t) 1L << 25);
    }

    carry0to9[0]= (hValues[0] + (int64_t)(1L << 25)) >> 26;
    hValues[1] += carry0to9[0];
    hValues[0 ] -= carry0to9[0] * ((uint64_t) 1L << 26);

    for(int i=0;i<maxValue ; i++){
        h[i] = (int32_t)hValues[i];
    }


    
}