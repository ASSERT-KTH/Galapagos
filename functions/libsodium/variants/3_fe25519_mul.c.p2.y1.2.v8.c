void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const int MULTIPLIER_2 = 2, MULTIPLIER_19 = 19;
    int32_t fArray[10], gArray[10];
    
    for(int i = 0; i < 10; i++)
    {
        fArray[i] = f[i];
        gArray[i] = g[i];
    }
   
    gArray[1] *= MULTIPLIER_19; /* 1.959375*2^29 */
    gArray[2] *= MULTIPLIER_19; /* 1.959375*2^30; still ok */
    gArray[3] *= MULTIPLIER_19;
    gArray[4] *= MULTIPLIER_19;
    gArray[5] *= MULTIPLIER_19;
    gArray[6] *= MULTIPLIER_19;
    gArray[7] *= MULTIPLIER_19;
    gArray[8] *= MULTIPLIER_19;
    gArray[9] *= MULTIPLIER_19;
    
    fArray[1] *= MULTIPLIER_2;
    fArray[3] *= MULTIPLIER_2;
    fArray[5] *= MULTIPLIER_2;
    fArray[7] *= MULTIPLIER_2;
    fArray[9] *= MULTIPLIER_2;

    int64_t fgMultiplyArrays[10][10];

    for (int i = 0; i < 10; i++)
        for (int j= 0; j < 10; j++)
            fgMultiplyArrays[i][j] = fArray[i] * (int64_t)gArray[j];

    int64_t hArray[10] {
        fgMultiplyArrays[0][0] + fgMultiplyArrays[1][9] + fgMultiplyArrays[2][8] + fgMultiplyArrays[3][7] + fgMultiplyArrays[4][6] + fgMultiplyArrays[5][5] + fgMultiplyArrays[6][4] + fgMultiplyArrays[7][3] + fgMultiplyArrays[8][2] + fgMultiplyArrays[9][1],
        
        fgMultiplyArrays[0][1] + fgMultiplyArrays[1][0] + fgMultiplyArrays[2][9] + fgMultiplyArrays[3][8] + fgMultiplyArrays[4][7] + fgMultiplyArrays[5][6] + fgMultiplyArrays[6][5] + fgMultiplyArrays[7][4] + fgMultiplyArrays[8][3] + fgMultiplyArrays[9][2],

        fgMultiplyArrays[0][2] + fgMultiplyArrays[1][1] + fgMultiplyArrays[2][0] + fgMultiplyArrays[3][9] + fgMultiplyArrays[4][8] + fgMultiplyArrays[5][7] + fgMultiplyArrays[6][6] + fgMultiplyArrays[7][5] + fgMultiplyArrays[8][4]+ fgMultiplyArrays[9][3],

        fgMultiplyArrays[0][3] + fgMultiplyArrays[1][2] + fgMultiplyArrays[2][1] + fgMultiplyArrays[3][0] + fgMultiplyArrays[4][9] + fgMultiplyArrays[5][8] + fgMultiplyArrays[6][7] + fgMultiplyArrays[7][6] + fgMultiplyArrays[8][5] + fgMultiplyArrays[9][4],
        
        ... Continue with such expressions for hArray[4] through hArray[9] ..., };

    int64_t carry[10];

    for(int i = 0; i < 10; i++)
    {
        if (i % 2 == 0) {
            carry[i] = (hArray[i] + (int64_t)(1L << 24)) >> 25;
            if (i < 8) hArray[i + 1] += carry[i];
            hArray[i] -= carry[i] * ((uint64_t)1L << 25);      
        } else {
            carry[i] = (h[i] + (int64_t) (1L << 25)) >> 26;

            if (i < 8) h[i + 1] += carry[i];
            h[i] -= carry[i] * ((uint64_t) 1L << 26);
        }
    }

    for(int i = 0; i < 10; i++) h[i] = (int32_t) hArray[i];;
}
