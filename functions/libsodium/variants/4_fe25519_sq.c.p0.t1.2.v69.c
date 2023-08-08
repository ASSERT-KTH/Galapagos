fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f00f00 = f[0] * f[0];
    int32_t f01f01 = f[1] * f[1];
    int32_t f02f02 = f[2] * f[2];
    int32_t f03f03 = f[3] * f[3];
    int32_t f04f04 = f[4] * f[4];
    int32_t f05f05 = f[5] * f[5];
    int32_t f06f06 = f[6] * f[6];
    int32_t f07f07 = f[7] * f[7];
    int32_t f08f08 = f[8] * f[8];
    int32_t f09f09 = f[9] * f[9];

    int32_t f0f1 = 2 * f[0] * f[1];
    int32_t f0f2 = 2 * f[0] * f[2];
    int32_t f0f3 = 2 * f[0] * f[3];
    int32_t f1f2 = 2 * f[1] * f[2];
    int32_t f1f3 = 2 * f[1] * f[3];
    int32_t f1f4 = 2 * f[1] * f[4];
    int32_t f2f3 = 2 * f[2] * f[3];
    int32_t f2f4 = 38 * f[2] * f[4];
    int32_t f3f4 = 38 * f[3] * f[4];
    int32_t f3f5 = 38 * f[3] * f[5];

    int32_t f0f5 = 2 * f[0] * f[5];
    int32_t f0f6 = 2 * f[0] * f[6];
    int32_t f1f5 = 19 * f[1] * f[5];
    int32_t f1f6 = 19 * f[1] * f[6];
    int32_t f2f5 = 38 * f[2] * f[5];
    int32_t f2f6 = 38 * f[2] * f[6];
    int32_t f3f6 = 38 * f[3] * f[6];
    int32_t f3f7 = 38 * f[3] * f[7];
    int32_t f4f6 = 38 * f[4] * f[6];

    int32_t f0f7 = 2 * f[0] * f[7];
    int32_t f1f7 = 19 * f[1] * f[7];
    int32_t f2f7 = 38 * f[2] * f[7];
    int32_t f4f7 = 19 * f[4] * f[7];
    int32_t f5f6 = 38 * f[5] * f[6];
    int32_t f5f7 = 38 * f[5] * f[7];
    int32_t f6f7 = 38 * f[6] * f[7];

    int32_t f0f8 = 2 * f[0] * f[8];
    int32_t f1f8 = 2 * f[1] * f[8];
    int32_t f2f8 = 19 * f[2] * f[8];
    int32_t f4f8 = 19 * f[4] * f[8];
    int32_t f5f8 = 38 * f[5] * f[8];
    int32_t f6f8 = 19 * f[6] * f[8];
    int32_t f7f8 = 38 * f[7] * f[8];

    int32_t f0f9 = 2 * f[0] * f[9];
    int32_t f1f9 = 2 * f[1] * f[9];
    int32_t f2f9 = 38 * f[2] * f[9];
    int32_t f4f9 = 38 * f[4] * f[9];
    int32_t f5f9 = 38 * f[5] * f[9];
    int32_t f6f9 = 38 * f[6] * f[9];
    int32_t f7f9 = 38 * f[7] * f[9];
    int32_t f8f9 = 38 * f[8] * f[9];

    int64_t res[10] = { f00f00 + f01f01,  f02f02 + f03f03,  f04f04 + f05f05,  f06f06 + f07f07,  f08f08 + f09f09,
                        f0f1 + f2f3 + f4f5 + f6f7 + f8f9,   f0f2 + f1f3 + f4f6 + f7f8 + f5f6,
                        f0f3 + f1f4 + f2f5 + f6f7 + f4f7,   f0f5 + f1f6 + f2f7 + f3f4 + f5f7 + f6f8,
                        f0f7 + f1f8 + f2f9 + f3f5 + f4f8 + f5f9 + f6f9};

    for(int i=0; i<10; i++){
        int64_t carry = (res[i] + (1L << 25)) >> 26;
        if(i < 9){
            res[i+1] += carry;
            res[i] -= carry * (1L << 26);
        }else{
            res[0] += carry * 19;
            res[i] -= carry * (1L << 25);
            carry = (res[0] + (1L << 25)) >> 26;
            res[1] += carry;
            res[0] -= carry * (1L << 26);
        }
        h[i] = res[i];
    }
}