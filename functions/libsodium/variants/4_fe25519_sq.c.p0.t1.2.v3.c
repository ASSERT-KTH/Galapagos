fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fVals[10];
    int32_t fDoubles[8];
    int32_t fSpecs[5];
    int64_t ff[45];
    int64_t hVals[10];
    int64_t carry[10];
    
    for (int i=0; i<10; ++i){
        fVals[i] = f[i];
    }

    for (int i=0; i<10; ++i){
        if(i<8) fDoubles[i] = 2 * fVals[i];
        if(i<5){
            if(fVals[i]==f[5]||fVals[i]==f[7]||fVals[i]==f[9]) fSpecs[i] = 38 * fVals[i];
            else if (fVals[i]==f[6]||fVals[i]==f[8]) fSpecs[i] = 19 * fVals[i];
        }
    }

    # Taking squares of 10 integers including cross product within 2 loop
    int pos = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = i; j < 10; ++j){
            if(i == j) ff[pos] = fVals[i] * (int64_t) fVals[j];
            else if(j == 9 && i!=9) ff[pos] = fDoubles[i] * (int64_t)fSpecs[j-i-1];
            else ff[pos] = fDoubles[i] * (int64_t) fVals[j];
            pos++;
        }
    }

    hVals[0] = ff[0] + ff[9] + ff[17] + ff[24] + ff[30] + ff[34];
    hVals[1] = ff[1] + ff[11] + ff[18] + ff[25] + ff[31];
    hVals[2] = ff[2] + ff[5] + ff[15] + ff[22] + ff[28] + ff[33];
    hVals[3] = ff[3] + ff[7] + ff[16] + ff[23] + ff[29];
    hVals[4] = ff[4] + ff[8] + ff[13] + ff[27] + ff[32] + ff[36];
    hVals[5] = ff[6] + ff[12] + ff[20] + ff[26] + ff[35];
    hVals[6] = ff[10] + ff[14] + ff[21] + ff[19] + ff[37] + ff[41];
    hVals[7] = ff[42] + ff[14] +ff[20] + ff[39];
    hVals[8] = ff[43] + ff[21] + ff[40] + ff[12] + fVals[4] * (int64_t)fSpecs[4];
    hVals[9] = ff[38] + ff[44];
    
    for(int i=0; i<10; ++i) {
        int j = (i+4)%10;
        if(i<5){
            carry[i] = (hVals[i] + (int64_t)(1L << 25)) >> 26;
            hVals[i+1] += carry[i];
            hVals[i] -= carry[i] * ((uint64_t) 1L << 26);
            carry[j] = (hVals[j] + (int64_t)(1L << 24)) >> 25;
            hVals[j+1] += carry[j];
            hVals[j] -= carry[j] * ((uint64_t) 1L << 25);
        }
        else if (i > 4 && i < 9){
            int k = (i + 2) % 10;
            int l = (i + 7) % 10;
            carry[k] = (hVals[k] + (int64_t)(1L << 25)) >> 26;
            hVals[(k+1)%10] += carry[k];
            hVals[k] -= carry[k] * ((uint64_t) 1L << 26);
            carry[l] = (hVals[l] + (int64_t)(1L << 24)) >> 25;
            hVals[l+1] += carry[l];
            hVals[l] -= carry[l] * ((uint64_t) 1L << 25);
        }
    }
    
    carry[9] = (hVals[9] + (int64_t)(1L << 24)) >> 25;
    hVals[0] += carry[9] * 19;
    hVals[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0] = (hVals[0] + (int64_t)(1L << 25)) >> 26;
    hVals[1] += carry[0];
    hVals[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int i=0; i<10; ++i) h[i] = (int32_t) hVals[i];
    
}