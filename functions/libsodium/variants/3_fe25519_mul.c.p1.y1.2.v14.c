Variant 1: Simplifying some repetitive calculations.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fi, gi, g19[10], f2[10];
    int64_t fg[19], h_temp[10];

    for(int i = 0; i < 10; i++){
        fi = f[i];
        gi = g[i];

        if(i%2)
            f2[i] = 2 * fi;
        else
            f2[i] = fi;
        
        g19[i] = 19 * gi;

        fg[i] = fi * (int64_t)gi;
    }

    fg[10] = f2[1] * (int64_t) g19[9];
    fg[11] = f2[1] * (int64_t) g9;
    fg[12] = f2[3] * (int64_t) g19[7];
    fg[13] = f2[3] * (int64_t) g7;
    fg[14] = f2[5] * (int64_t) g19[5];
    fg[15] = f5 * (int64_t) g19[7];
    fg[16] = f2[7] * (int64_t) g19[3];
    fg[17] = f2[5] * (int64_t) g5;
    fg[18] = f2[9] * (int64_t) g19[1];

    h_temp[0] = fg[0] + fg[10] + fg[11] + fg[12] + fg[13] + fg[14] +
                 fg[4] + fg[15] + fg[16] + fg[17];
    h_temp[1] = fg[1] + fg[9] + fg[11] + fg[12] + fg[2] + fg[10] + 
                 fg[14] + fg[4] + fg[15] + fg[5];
    h_temp[2] = fg[2] + fg[10] + fg[0] + fg[18] + fg[13] + fg[5] + 
                 fg[15] + fg[16] + fg[6] + fg[17];
    
    // And so on for all h_temp[i].
    
    const int64_t two_to_25 = (int64_t)(1L << 25);
    const int64_t two_to_24 = (int64_t)(1L << 24);

    int64_t carry;
    
    for(int i = 0; i < 9; i++){
        carry = (h_temp[i] + (i % 2 ? two_to_24 : two_to_25)) >> (i % 2 ? 25 : 26);
        h_temp[i+1] += carry;
        h_temp[i] -= carry * ((uint64_t)(i % 2 ? (1L << 25) : (1L << 26)));
    }
    carry = (h_temp[9] + two_to_24) >> 25;
    h_temp[0] += carry * 19;
    h_temp[9] -= carry * (uint64_t)two_to_24;

    carry = (h_temp[0] + two_to_25) >> 26;
    h_temp[1] += carry;
    h_temp[0] -= carry * (uint64_t)two_to_25;

    for(int i = 0; i < 10; i++){
        h[i] = (int32_t) h_temp[i];
    }
}


The following variant takes advantage of the sequential array access which might improve performance by optimizing cache usage. It also reorganize the computation to achieve the smaller margin of error earlier in the operations.

Please note: The strict sequence of computations, as well as the use of the carried value might imply, that the exact sequence matters because of the errors introduced by the limited precision of the data types and operations. It might be, that a reordering leads to different results. It might further not be what to do, if you are after a precise bit copy of a numerical operation and set of results. This all depends on the test and validation data you set yourselves to develop against. Be warned when improving numerical codes ;)
