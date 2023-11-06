fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t tmp[64] = {0};
    int32_t g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19, temp;
    fe25519 fg;
    for(int i = 0; i < 10; i++) {
        temp = 2 * f[i];
        for(int j = 0; j < 10; j++) {
            if((i+j) % 2 == 0)
                fg[i+j] += (f[2*i] * g[2*j]);
            else
                fg[i+j] += (f[2*i+1] * g[(2*j)+1]);
        }
    }

    g1_19 = 19 * g[1]; 
    g2_19 = 19 * g[2]; 
    g3_19 = 19 * g[3];
    g4_19 = 19 * g[4];
    g5_19 = 19 * g[5];
    g6_19 = 19 * g[6];
    g7_19 = 19 * g[7];
    g8_19 = 19 * g[8];
    g9_19 = 19 * g[9];
    
    for(int i = 0; i < 19; i++){
        if(i%2!=0) {
            fg[i] += g1_19 * f[i-1] + g3_19 * f[i-3] + g5_19 * f[i-5] + g7_19 * 
                    f[i-7] + g9_19 * f[(18) - (i+8>18 ? 18 : i+8)];
        }
    }

    for(int i = 0; i < 19; i++) {
        int64_t carry = (fg[i] + (1<<(25-1))) >> 25;
        fg[i+1] += carry;
        fg[i] -= carry * (1L<<25);
    }

    int64_t carry = (fg[0] + (1L<<25)) >> 26;
    fg[1] += 19*carry;
    fg[0] -= carry*(1L<<26);

    for(int i = 0; i < 10; i++)
        h[i] = fg[i];
}
