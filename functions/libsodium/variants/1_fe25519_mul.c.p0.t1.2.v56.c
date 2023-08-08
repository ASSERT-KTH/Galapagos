fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t nf[10];
    for(int i=0; i<10; i++) nf[i] = f[i];
    
    int32_t ng[10];
    for(int i=0; i<10; i++) if(i % 2 != 0) ng[i] = 19*g[i]; else ng[i] = g[i];
        
    nf[1] *= 2;
    nf[3] *= 2;
    nf[5] *= 2;
    nf[7] *= 2;
    nf[9] *= 2;

    
    int64_t hMap[10][10];
    
    for (int i = 0; i < 10; ++i) {
        int j = 0;
        for (; j < i+1; ++j) {
            hMap[i][j] = nf[(10-i+j)%10]*(int64_t) ng[j];
        }
        for (; j < 10; ++j) {
            hMap[i][j] = nf[(10-i+j)%10]*2*(int64_t) ng[j];   
        }
    }
    
    int64_t resultat[10] = {0};

    resultat[0] = hMap[0][0] + hMap[1][3] + hMap[2][2] + hMap[3][5] + hMap[4][4] + hMap[5][7] +
                  hMap[6][6] + hMap[7][9] + hMap[8][8] + hMap[9][0];
    
    for (int i = 1; i < 9; ++i) {
        resultat[i] = hMap[0][i] + hMap[1][i-1] + hMap[2][i+1] + hMap[3][i-2] + hMap[4][i+2] + hMap[5][i-3] + 
                      hMap[6][i+3] + hMap[7][i-4] + hMap[8][i+4] + hMap[9][i-5];
    }
    
    resultat[9] = hMap[0][9] + hMap[1][8] + hMap[2][0] + hMap[3][9] + hMap[4][1] + 
                  hMap[5][8] + hMap[6][2] + hMap[7][7] + hMap[8][3] + hMap[9][6];

    int64_t carry[10] = {0};
    
    for (int64_t i = 0; i < 10; ++i) {
        if(i%2==0)
            carry[i] = (resultat[i] + (int64_t)(1L << 25)) >> 26;
        else 
            carry[i] = (resultat[i]+(int64_t)(1L << 24)) >> 25;
        
        resultat[(i+1)%10] += carry[i];
        
        resultat[i] = resultat[i] - carry[i]*((uint64_t) 1L<<(26-(i%2)));
    }
        
    carry[9] = (resultat[9]+(int64_t)(1L<<24)) >> 25;
    resultat[0] += carry[9]*19;
    resultat[9] -= carry[9]*((uint64_t) 1L << 25);
    
    /* |h9| <= 2^24; from now on fits into int32 unchanged */
    /* |h0| <= 1.1*2^39 */

    carry[0] = (resultat[0]+(int64_t)(1L << 25)) >> 26;
    resultat[1] += carry[0];
    resultat[0] -= carry[0]*((uint64_t) 1L << 26);
    /* |h0| <= 2^25; from now on fits into int32 unchanged */
    /* |h1| <= 1.01*2^24 */
          
    for(int i = 0; i < 10; i++) h[i] = resultat[i];
}