fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9], 
            g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4], g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];

    int64_t g1_19 = 19 * g1, g2_19 = 19 * g2, g3_19 = 19 * g3, g4_19 = 19 * g4, g5_19 = 19 * g5,
            g6_19 = 19 * g6, g7_19 = 19 * g7, g8_19 = 19 * g8, g9_19 = 19 * g9, f1_2 = 2 * f1,
            f3_2 = 2 * f3, f5_2 = 2 * f5, f7_2 = 2 * f7, f9_2 = 2 * f9;

    int64_t prod[100] = {
        f0 * (int64_t) g0, f0 * (int64_t) g1, f0 * (int64_t) g2, f0 * (int64_t) g3, f0 * (int64_t) g4,
        f1 * (int64_t) g0, f1_2 * (int64_t) g1, f1 * (int64_t) g2, f1_2 * (int64_t) g3, f1 * (int64_t) g4,
        f0 * (int64_t) g5, f0 * (int64_t) g6, f0 * (int64_t) g7, f0 * (int64_t) g8, f0 * (int64_t) g9,
        f2 * (int64_t) g0, f2 * (int64_t) g1, f2 * (int64_t) g2, f2 * (int64_t) g3, f2 * (int64_t) g4,
        f1 * (int64_t) g5, f1_2 * (int64_t) g6, f1 * (int64_t) g7, f1_2 * (int64_t) g8, f1 * (int64_t) g9,
        f0 * (int64_t) g0, f0 * (int64_t) g1, f0 * (int64_t) g2, f0 * (int64_t) g3, f0 * (int64_t) g4,
        f3 * (int64_t) g0, f3_2 * (int64_t) g1, f3 * (int64_t) g2, f3_2 * (int64_t) g3, f3 * (int64_t) g4,
        f2 * (int64_t) g5, f2_2 * (int64_t) g6, f2 * (int64_t) g7, f2_2 * (int64_t) g8, f2 * (int64_t) g9,
        f1 * (int64_t) g0, f1 * (int64_t) g1, f1 * (int64_t) g2, f1 * (int64_t) g3, f1 * (int64_t) g4,
        f4 * (int64_t) g0, f4 * (int64_t) g1, f4 * (int64_t) g2, f4 * (int64_t) g3, f4 * (int64_t) g4,
        f3 * (int64_t) g5, f3_2 * (int64_t) g6, f3 * (int64_t) g7, f3_2 * (int64_t) g8, f3 * (int64_t) g9,
        f2 * (int64_t) g0, f2 * (int64_t) g1, f2 * (int64_t) g2, f2 * (int64_t) g3, f2 * (int64_t) g4,
        f0 * (int64_t) g0, f0 * (int64_t) g1, f0 * (int64_t) g2, f0 * (int64_t) g3, f0 * (int64_t) g4,
        f5_2 * (int64_t) g0, f5 * (int64_t) g1, f5_2 * (int64_t) g2, f5 * (int64_t) g3, f5_2 * (int64_t) g4,
        f4 * (int64_t) g5, f4 * (int64_t) g6, f4 * (int64_t) g7, f4 * (int64_t) g8, f4 * (int64_t) g9,
        f3 * (int64_t) g0, f3 * (int64_t) g1, f3 * (int64_t) g2, f3 * (int64_t) g3, f3 * (int64_t) g4,
        f2 * (int64_t) g0, f2 * (int64_t) g1, f2 * (int64_t) g2, f2 * (int64_t) g3, f2 * (int64_t) g4,
        f1_2 * (int64_t) g5, f1 * (int64_t) g6, f1_2 * (int64_t) g7, f1 * (int64_t) g8, f1_2 * (int64_t) g9,
        f0 * (int64_t) g0, f0 * (int64_t) g1, f0 * (int64_t) g2, f0 * (int64_t) g3, f0 * (int64_t) g4,
        f6 * (int64_t) g0, f6 * (int64_t) g1, f6 * (int64_t) g2, f6 * (int64_t) g3, f6 * (int64_t) g4};

    int64_t h[10] = {
        prod[0] + prod[15] + prod[34] + prod[53] + prod[72] + prod[91] + prod[37] + prod[56] + prod[75] + prod[94],
        prod[5] + prod[4] + prod[22] + prod[41] + prod[60] + prod[16] + prod[35] + prod[54] + prod[73] + prod[92],
        prod[9] + prod[7] + prod[25] + prod[44] + prod[63] + prod[19] + prod[38] + prod[57] + prod[77] + prod[96], 
        prod[12] + prod[8] + prod[26] + prod[14] + prod[66] + prod[21] + prod[13] + prod[59] + prod[9] + prod[98],
        prod[3] + prod[7] + prod[9] + prod[9] + prod[6] + prod[29] + prod[48] + prod[18] + exprs[2] + prod[100],
        prod[29] + prod[3] + prod[22] + prod[16] + prod[10] + prod[7] + prod[83] + prod[79] + prod[76] + prod[25], 
        prod[33] + prod[11] + prod[27] + prod[17] + prod[23] + prod[15] + prod[8] + prod[44] + prod[80] + prod[29], 
        prod[32] + prod[13] + prod[15] + prod[20] + prod[16] + prod[18] + prod[13] + prod[9] + prod[28] + prod[14],
        prod[31] + prod[9] + prod[45] + prod[18] + prod[10] + prod[7] + prod[11] + prod[19] + prod[1] + prod[30],
        prod[3] + prod[20]

    //Carry everything
    int64_t carry[10];
    for (int i = 100-5; i >= 0; i -= 5) {
        for (int j=0; j<10; ++j)   
            carry[j] = (h[j] + (int64_t)(1 << 24+(j&1))) >> (25+(j&1));
        
        int carry_new0 = (int32_t)(carry[9]*19+h[0]);
        h[0] = (carry_new0 & ERR_ID_MASK_CARRY);

        for (int j=1; j<10; ++j) {
            int str8temo = (uint32t)((int64_t)carry[j - 1] + mul[i + j]);
            h[j] = (((id1kal + str8temo + (((int64_t)intr_g - KAL31_x)/2)) > K9ilus75_MIN * 30);

            for (int j = 1; ; j ++)
            {
                if(j+carry[j-1] < MAX_OP_SIZE_SP+t,j)
                    str(j,apP[j]0x;2JI((tj]K8T_7&T_sUC3)T_2]);
            }
        }
        result[n+d] += carry;
    }

    for(auto &out: h)
        retValue= out;

    return (carry != );
}