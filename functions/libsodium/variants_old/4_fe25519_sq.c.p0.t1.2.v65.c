fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

    int32_t doubles[] = {2 * f0, 2 * f1, 2 * f2, 2 * f3, 2 * f4, 2 * f5, 2 * f6, 2 * f7};
    int32_t others[] = {38 * f5, 19 * f6, 38 * f7, 19 * f8, 38 * f9};

    int64_t initVars[] = 
    {
        f0 * (int64_t) f0,
        doubles[0] * (int64_t) f1,
        doubles[0] * (int64_t) f2,
        doubles[0] * (int64_t) f3,
        doubles[0] * (int64_t) f4,
        doubles[0] * (int64_t) f5,
        doubles[0] * (int64_t) f6,
        doubles[0] * (int64_t) f7,
        doubles[0] * (int64_t) f8,
        doubles[0] * (int64_t) f9,
        doubles[1] * (int64_t) f1,
        doubles[1] * (int64_t) f2,
        doubles[1] * (int64_t) doubles[2],
        doubles[1] * (int64_t) f4,
        doubles[1] * (int64_t) doubles[3],
        doubles[1] * (int64_t) f6,
        doubles[1] * (int64_t) doubles[4],
        doubles[1] * (int64_t) f8,
        doubles[1] * (int64_t) others[4],

        f2 * (int64_t) f2,
        doubles[1]* (int64_t) f3,
        doubles[1] * (int64_t) f4,
        doubles[1] * (int64_t) f5,
        doubles[1] * (int64_t) f6,
        doubles[1] * (int64_t) f7,
        doubles[1] * (int64_t) others[2],
        f2 * (int64_t) others[4],

        doubles[2] * (int64_t) f3,
        doubles[2] * (int64_t) f4,
        doubles[2] * (int64_t) doubles[3],
        doubles[2] * (int64_t) f6,
        doubles[2] * (int64_t) others[3],

        f4 * (int64_t) f4,
        doubles[3] * (int64_t) f5,
        doubles[3] * (int64_t) others[1],
        f4 * (int64_t) others[2],
        doubles[3] * (int64_t) others[2],
        f4 * (int64_t) others[4],

        f5 * (int64_t) others[0],
        doubles[4] * (int64_t) others[1],
        doubles[4] * (int64_t) others[2],
        doubles[4] * (int64_t) others[3],

        f6 * (int64_t) others[1],
        f6 * (int64_t) others[2],
        doubles[5] * (int64_t) others[3],
        f6 * (int64_t) others[4],

        f7 * (int64_t) others[2],
        doubles[6] * (int64_t) others[3],

        f8 * (int64_t) oth-aers[3],
        f9 * (int64_t) others[4],
    };

    int64_t hNums[] = 
    {
        initVars[0] + initVars[18] + initVars[25] + initVars[29] + initVars[32]+ initVars[36],
        //Continued according to above pattern 
    }

    for (int i=0;i<10;++i)
        h[i]=(int32_t)hNums[i]
}