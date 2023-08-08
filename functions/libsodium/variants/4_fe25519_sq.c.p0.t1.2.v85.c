fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fb[10];

    for(int i=0; i<10; i++){
        fb[i] = f[i];
    }

    int32_t fb_2[10];
    for(int i=0; i<10; i++){
        fb_2[i] = 2*fb[i];
    }

    int32_t fb_38[10];
    int32_t fb_19[10];
    fb_38[0] = fb_19[0] = fb[0];
    fb_19[1] = 19*fb[1];
    fb_38[1] = 38 * fb[1];
    fb_38[2] = 38 * fb[2];
    fb_19[3] = 19 * fb[3];
    fb_38[5] = 38 * fb[5];
    fb_19[6] = 19 * fb[6];
    fb_38[7] = 38 * fb[7];
    fb_19[8] = 19 * fb[8];
    fb_38[9] = 38 * fb[9];


    int64_t fbf[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
           fbf[i][j] = fb[i]*fb[j];
        }
    }

    int64_t h0 = fbf[0][0] + fbf[1][9] + fbf[2][8] + fbf[3][7] + fbf[4][6] + fbf[5][5];
    int64_t h1 = fbf[0][1] + fbf[2][9] + fbf[3][8] + fbf[4][7] + fbf[5][6];
    int64_t h2 = fbf[0][2] + fbf[1][1] + fbf[3][9] + fbf[4][8] + fbf[5][7] + fbf[6][6];
    int64_t h3 = fbf[0][3] + fbf[1][2] + fbf[4][9] + fbf[5][8] + fbf[6][7];
    int64_t h4 = fbf[0][4] + fbf[1][3] + fbf[2][2] + fbf[5][9] + fbf[6][8] + fbf[7][7];
    int64_t h5 = fbf[0][5] + fbf[1][4] + fbf[2][3] + fbf[6][9] + fbf[7][8];
    int64_t h6 = fbf[0][6] + fbf[1][5] + fbf[2][4] + fbf[3][3] + fbf[7][9] + fbf[8][8];
    int64_t h7 = fbf[0][7] + fbf[1][6] + fbf[2][5] + fbf[3][4] + fbf[8][9];
    int64_t h8 = fbf[0][8] + fbf[1][7] + fbf[2][6] + fbf[3][5] + fbf[4][4] + fbf[9][9];
    int64_t h9 = fbf[0][9] + fbf[1][8] + fbf[2][7] + fbf[3][6] + fbf[4][5];

    h[0] = shiftAndMask(h0, 26);
    h[1] = shiftAndMask(h1, 24);
    h[2] = shiftAndMask(h2, 26);
    h[3] = shiftAndMask(h3, 25);
    h[4] = shiftAndMask(h4, 26);
    h[5] = shiftAndMask(h5, 25);
    h[6] = shiftAndMask(h6, 26);
    h[7] = shiftAndMask(h7, 25);
    h[8] = shiftAndMask(h8, 26);
    h[9] = shiftAndMask(h9, 25);

    h[0] += 19 * ((h[9] + (int64_t)(1L << 24)) >> 25);
    h[9] -= ((h[9] + (int64_t)(1L << 24)) >> 25) * ((uint64_t) 1L << 25);
    h[1] += (h[0] + (int64_t) (1L << 25)) >> 26;
    h[0] -= ((h[0] + (int64_t) (1L << 25)) >> 26) * ((uint64_t) 1L << 26);
}

inline
int64_t shiftAndMask(int64_t &hs, int shift){
    int64_t carry = (hs + (int64_t)(1L << (shift-1))) >> shift;
    if(&hs!=&carry){
      hs += carry;
      hs -= carry * ((uint64_t) (1L<<shift));
    }
    return hs;
}
