fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fi[10];
    
    for(int i=0; i<10; i++) {
        fi[i] = f[i];
    }

    int32_t fi_2[10];
    for(int i=0; i<10; i++) {
        fi_2[i] = 2 * fi[i];
    }
    
    fi_2[5] = 38 * fi[5]; /* 1.959375*2^30 */
    fi_2[6] = 19 * fi[6]; /* 1.959375*2^30 */
    fi_2[7] = 38 * fi[7]; /* 1.959375*2^30 */
    fi_2[8] = 19 * fi[8]; /* 1.959375*2^30 */
    fi_2[9] = 38 * fi[9]; /* 1.959375*2^30 */
    
    int64_t fifi[45];

    int k=0;
    for(int i=0; i<10; i++) {
        for(int j=i; j<10;j++) {
            if(j==i) {
                fifi[k] = fi[j] * (int64_t) fi[j];
            } else {
                fifi[k] = fi_2[j] * (int64_t) fi_2[i];
            }
            k++;
        }
    }
    
    int64_t h_temp[10] = {fifi[0] + fifi[9] + fifi[17] + fifi[24] + fifi[30] + fifi[35],
                          fifi[1] + fifi[10] + fifi[18] + fifi[25] + fifi[31],
                          fifi[2] + fifi[4] + fifi[11] + fifi[19] + fifi[26] + fifi[32],
                          fifi[3] + fifi[5] + fifi[12] + fifi[20] + fifi[27],
                          fifi[6] + fifi[7] + fifi[8] + fifi[13] + fifi[21] + fifi[28],
                          fifi[14] + fifi[15] + fifi[16] + fifi[22] + fifi[29],
                          fifi[23] + fifi[33] + fifi[34] + fifi[36],
                          fifi[37] + fifi[38] + fifi[39] + fifi[40],
                          fifi[41] + fifi[42] + fifi[43] + fifi[44] + fifi[20],
                          fifi[21] + fifi[22] + fifi[23] + fifi[24] + fifi[25]};

    int64_t carry[10];
    
    for(int i=0; i<10; i++) {
        carry[i] = (h_temp[i] + (int64_t)(1L << Sel[i])) >> Sel[i+1];
        h_temp[(i+1)%10] += carry[i];
        h_temp[i] -= carry[i] * ((uint64_t) 1L << Sel[i+1]);
    }

    for(int i=0; i<10; i++) {
        h[i] = (int32_t) h_temp[i];
    }
}
Where Sel[e] is an array defining shift and subtract operations: int Sel[11] = {25,26,25,26,25,26,24,25,26,25,26};