Here's a variant of your function where i have used fewer variables:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0[10];
    int i,j;

    for(i = 0; i < 10 ; i++){
        f0[i] = f[i];
        if(i < 5){
            f0[i] *= 2;
        } else {
            f0[i] *= 38;
        }
    }
    
    int64_t x[10][10];
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            x[i][j] = f0[i] * (int64_t)f[j];
            if(((i < 5) && ( j > i)) || ((i > 4) && (j >= i))) {
                x[i][j] *=2;
            }
        }
    }
    
    int64_t h0[10];
    h0[0] = x[0][0]+x[1][9]+x[2][8]+x[3][7]+x[4][6]+x[5][5];
    h0[1] = x[0][1]+x[2][9]+x[3][8]+x[4][7]+x[5][6];
    h0[2] = x[0][2]+x[1][1]+x[3][9]+x[4][8]+x[5][7]+x[6][6];
    h0[3] = x[0][3]+x[1][2]+x[4][9]+x[5][8]+x[6][7];
    h0[4] = x[0][4]+x[1][3]+x[2][2]+x[5][9]+x[6][8]+x[7][7];
    h0[5] = x[0][5]+x[1][4]+x[2][3]+x[6][9]+x[7][8];
    h0[6] = x[0][6]+x[1][5]+x[2][4]+x[3][3]+x[7][9]+x[8][8];
    h0[7] = x[0][7]+x[1][6]+x[2][5]+x[3][4]+x[8][9];
    h0[8] = x[0][8]+x[1][7]+x[2][6]+x[3][5]+x[4][4]+x[9][9];
    h0[9] = x[0][9]+x[1][8]+x[2][7]+x[3][6]+x[4][5];

    int carry;

    for (int i=0;i<10;i++)
    {
        carry = (h0[i] + (int64_t)(1L << (i&1 ? 24 : 25)))
                >> (i&1 ? 25 : 26);
        if(i == 9){
            h0[0] += 19 * carry;
        } else {
            h0[i+1] += carry;
        }
        h0[i] -= carry * ((uint64_t) 1L << (i&1 ? 25 : 26));
    }

    for(i=0; i<10; i++){
    	h[i] = (int32_t)h0[i];
    }
}

Bear in mind using 6 bitshift operations is computationally expensive based on your device, so the initial implementation may be more effective in most scenarios. My modification has taken O(n^2) space in more cases, which could also slow the script.