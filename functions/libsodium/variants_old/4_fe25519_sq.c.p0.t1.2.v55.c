fe25519_sq(fe25519 h, const fe25519 f)
{
    __int64_t coefficients[159] = {
        2 * f[0], 2 * f[1], 2 * f[2], 2 * f[3], 
        2 * f[4], 2 * f[5], 2 * f[6], 2 * f[7], 
        38 * f[5], 19 * f[6], 38 * f[7], 19 * f[8], 38 * f[9],

        f[0] * (__int64_t) f[0], 2 * f[0] * (__int64_t) f[1],
        2 * f[0] * (__int64_t) f[2], 2 * f[0] * (__int64_t) f[3], 
        2 * f[0] * (__int64_t) f[4], 2 * f[0] * (__int64_t) f[5], 
        2 * f[0] * (__int64_t) f[6], 2 * f[0] * (__int64_t) f[7], 
        2 * f[0] * (__int64_t) f[8], 2 * f[0] * (__int64_t) f[9],  

        2 * f[1] * (__int64_t) f[1], 2 * f[1] * (__int64_t) f[2],
        2 * f[1] * (__int64_t) f[3], 2 * f[1] * (__int64_t) f[4],
        2 * f[1] * (__int64_t) f[5], 2 * f[1] * (__int64_t) f[6],
        2 * f[1] * (__int64_t) f[7], 2 * f[1] * (__int64_t) f[8],
        8 * f[1] * (__int64_t) f[9], f[2] * (__int64_t) f[2],

        2 * f[2] * (__int64_t) f[3], 2 * f[2] * (__int64_t) f[4], 
        2 * f[2] * (__int64_t) f[5], 2 * f[2] * (__int64_t) f[6], 
        2 * f[2] * (__int64_t) f[7], 2 * f[2] * (__int64_t) f[8], 
        f[2] * (__int64_t) f[9], /* rest of symmetrical multiplications divided amongst 3 arrays */

        4 * f[1] * (__int64_t) f[8],
        2 * f[2] * (__int64_t) f[7], 4 * f[2] * (__int64_t) f[8],
        2 * f[2] * (__int64_t) f[9], 2 * f[1] * (__int64_t) f[6],
        4 * f[2] * (__int64_t) f[7], 4 * f[1] * (__int64_t) f[7],

        2 * f[1] * (__int64_t) f[9],
        4 * f[1] * (__int64_t) f[6], 4 * f[2] * (__int64_t) f[6],
        2 * f[3] * (__int64_t) f[8], f[4] * (__int64_t) f[7], 
        2 * f[3] * (__int64_t) f[6], 2 * f[2] * (__int64_t) f[5], 
       
        4 * f[5] * (__int64_t) f[9], 
        f[4] * (__int64_t) f[8],
        2 * f[5] * (__int64_t) f[7],
        4 * f[1] * (__int64_t) f[5],
        2 * f[3] * (__int64_t) f[7],
        4 * f[1] * (__int64_t) f[4],
        4 * f[2] * (__int64_t) f[5],

        2 * f[3] * (__int64_t) f[6],
        2 * f[4] * (__int64_t) f[5],
        4 * f[3] * (__int64_t) f[7],
        2 * f[3] * (__int64_t) f[5],
        2 * f[4] * (__int64_t) f[6], 
        2 * f[1] * (__int64_t) f[3],
        2 * f[2] * (__int64_t) f[4],

        f[5] * (__int64_t) f[5],
        2 * f[5] * (__int64_t) f[6],
        4 * f[3] * (__int64_t) f[8],
        f[4] * (__int64_t) f[6],
        f[3] * (__int64_t) f[3],
        2 * f[4] * (__int64_t) f[7],
        4 * f[3] * (__int64_t) f[9],

        f[6] * (__int64_t) f[6],
        2 * f[1] * (__int64_t) f[2],
        2 * f[5] * (__int64_t) f[8], 
        f[2] * (__int64_t) f[3],
        38 * f[0] * (__int64_t) f[9],
        f[0] * (__int64_t) f[1],

        38 * f[3] * (__int64_t) f[6],
        4 * f[5] * (__int64_t) f[7],
        f[8] * (__int64_t) f[8], 
        38 * f[0] * (__int64_t) f[8],
        f[7] * (__int64_t) f[7],
        38 * f[1] * (__int64_t) f[7], 

        2 * f[4] * (__int64_t) f[9], 
        76 * f[6] * (__int64_t) f[9], 
        19 * f[6] * (__int64_t) f[6],
        76 * f[8] * (__int64_t) f[9], 
        19 * f[6] * (__int64_t) f[7],
        2 * f[8] * (__int64_t) f[9], 
        2 * f[7] * (__int64_t) f[6],

        38 * f[1] * (__int64_t) f[6],
        38 * f[0] * (__int64_t) f[7],
        18 * f[5] * (__int64_t) f[6], 
        38 * f[1] * (__int64_t) f[8], 
        2 * f[6] * (__int64_t) f[7], 
        36 * f[4] * (__int64_t) f[7],
        2 * f[5] * (__int64_t) f[9],

        36 * f[7] * (__int64_t) f[8], 
        36 * f[5] * (__int64_t) f[8],
        
    };

    
    __int64_t h0 = coefficients[159]+coefficients[248]+coefficients[240]+coefficients[235]+coefficients[234]+coefficients[100];

    __int64_t h1 = (coefficients[130]+coefficients[242]+coefficients[72]+coefficients[232]+coefficients[92]);
    __int64_t h2 = (coefficients[79]+coefficients[138]+coefficients[231]+coefficients[226]+coefficients[198]+coefficients[133]);
    __int64_t h3 = coefficients[129]+coefficients[105]+coefficients[17]+coefficients[197]+coefficients[208];
   
    __int64_t h4 = coefficients[117]+coefficients[93]+coefficients[167]+coefficients[19]+coefficients[119]+coefficients[198];
    __int64_t h5 = (coefficients[112]+coefficients[126]+coefficients[97]+coefficients[194]+coefficients[184]);

    __int64_t h6 = (coefficients[109]+coefficients[156]+coefficients[125]+coefficients[98]+coefficients[185]+coefficients[106]);
    __int64_t h7 = (coefficients[108]+coefficients[92]+coefficients[118]+coefficients[124]+coefficients[180]);
   
    __int64_t h8 = coefficients[107]+coefficients[69]+coefficients[118]+coefficients[180]+coefficients[199]+coefficients[91];
    __int64_t h9 = (coefficients[99]+coefficients[102]+coefficients[68]+coefficients[195]+coefficients[208]);

    __int64_t carry0;
    __int64_t carry1;
    __int64_t carry2;
    __int64_t carry3;
    __int64_t carry4;
    __int64_t carry5;
    __int64_t carry6;
    __int64_t carry7;
    __int64_t carry8;
    __int64_t carry9;

    carry0 = (h0 + (__int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((__uint64_t) 1L << 26);
    carry4 = (h4 + (__int64_t)(1L << 25)) >> 26;
    h5 += carry4;
    h4 -= carry4 * ((__uint64_t) 1L << 26);

    carry1 = (h1 + (__int64_t)(1L << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * ((__uint64_t) 1L << 25);
    carry5 = (h5 + (__int64_t)(1L << 24)) >> 25;
    h6 += carry5;
    h5 -= carry5 * ((__uint64_t) 1L << 25);

    carry2 = (h2 + (__int64_t)(1L << 25)) >> 26;
    h3 += carry2;
    h2 -= carry2 * ((__uint64_t) 1L << 26);
    carry6 = (h6 + (__int64_t)(1L << 25)) >> 26;
    h7 += carry6;
    h6 -= carry6 * ((__uint64_t) 1L << 26);

    carry3 = (h3 + (__int64_t)(1L << 24)) >> 25;
    h4 += carry3;
    h3 -= carry3 * ((__uint64_t) 1L << 25);
    carry7 = (h7 + (__int64_t)(1L << 24)) >> 25;
    h8 += carry7;
    h7 -= carry7 * ((__uint64_t) 1L << 25);

    carry4 = (h4 + (__int64_t)(1L << 25)) >> 26;
    h5 += carry4;
    h4 -= carry4 * ((__uint64_t) 1L << 26);
    carry8 = (h8 + (__int64_t)(1L << 25)) >> 26;
    h9 += carry8;
    h8 -= carry8 * ((__uint64_t) 1L << 26);

    carry9 = (h9 + (__int64_t)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    h9 -= carry9 * ((__uint64_t) 1L << 25);

    carry0 = (h0 + (__int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((__uint64_t) 1L << 26);

    h[0] = (__int32_t) h0;

    h[1] = (__int32_t) h1;
    h[2] = (__int32_t) h2;
    h[3] = (__int32_t) h3;
    h[4] = (__int32_t) h4;
    h[5] = (__int32_t) h5;
    h[6] = (__int32_t) h6;
    h[7] = (__int32_t) h7;
    h[8] = (__int32_t) h8;
    h[9] = (__int32_t) h9;
}
