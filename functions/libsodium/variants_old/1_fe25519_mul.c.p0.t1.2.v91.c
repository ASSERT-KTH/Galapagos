fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t ftmp[10], gtmp[10];
    for(int i=0; i<10; i++) {
        ftmp[i] = f[i];
        gtmp[i] = g[i];
    }

    int32_t f1_2  = 2 * ftmp[1];
    int32_t f3_2  = 2 * ftmp[3];
    int32_t f5_2  = 2 * ftmp[5];
    int32_t f7_2  = 2 * ftmp[7];
    int32_t f9_2  = 2 * ftmp[9];

    int32_t g1_19 = 19 * gtmp[1]; 
    int32_t g2_19 = 19 * gtmp[2]; 
    int32_t g3_19 = 19 * gtmp[3];
    int32_t g4_19 = 19 * gtmp[4];
    int32_t g5_19 = 19 * gtmp[5]; 
    int32_t g6_19 = 19 * gtmp[6]; 
    int32_t g7_19 = 19 * gtmp[7]; 
    int32_t g8_19 = 19 * gtmp[8]; 
    int32_t g9_19 = 19 * gtmp[9]; 

    int64_t hvals[33];
    for(int i=0; i<10; i+=2) {
        for(int j=0; j<10; j+=2) {
            hvals[i*2+j*2] = ftmp[i] * (int64_t) gtmp[j];
        }
        
        for(int j=0; j<10; j+=2) {
            if(j>2)
                hvals[i*2+j*2+1] = ftmp[i] * (int64_t) gtmp[4*j];
            else
                hvals[i*2+j*2+1] = ftmp[i] * (int64_t) gtmp[j+1];
        }
            
    }

    int64_t carryvals[33];
    for(int i=0; i<10; i+=2) {
        carryvals[i] = (hvals[i] + (int64_t)(1L << 25)) >> 26; 
        hvals[i+2] += carryvals[i];
        hvals[i] -= carryvals[i] * ((uint64_t) 1L << 26);
    }

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) hvals[i*2+i];
    }
}