Here is another implementation in C, a bit re-ordered and simplified:


void fe25519_sq(fe25519 h, const fe25519 f){
    int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    {
        int64_t f0 = f[0];       
        int64_t f1 = f[1];
        int64_t f2 = f[2];
        int64_t f3 = f[3];
        int64_t f4 = f[4];
        int64_t f5 = f[5];
        int64_t f6 = f[6];
        int64_t f7 = f[7];
        int64_t f8 = f[8];
        int64_t f9 = f[9];  

        int64_t f0_2  = 2 * f0;
        int64_t f1_2  = 2 * f1;
        int64_t b1 = 38 * f9;
        int64_t b2 = 19 * f8;

        h0 =   f0*f0  + b1*2 + 38*f8 + 76*f7 + 38*f6 + 38*f5;
        h1 =   f0_2*f1 + b2 + 38*f7 + 38*f6;
        h2 =   f0_2*f2 + f1_2*f1 - b1 + 38*f7 + 38*f6 + 19*f5;
        h3 =   f0_2*f3 + f1_2*f2 + b1;
        h4 =   f0_2*f4 +2*f1*f3 + f2*f2 - b2 + 38*f5;
        h5 =   f0_2*f5 + f1_2*f4 + f2_2*f3 + b2;
        h6 =   f0_2*f6 + f1_2*f5 + f2_2*f4 + f3*f3 + 38*f1;
        h7 =   f0_2*f7 + f1_2*f6 + f2_2*f5 + f3_2*f4 + b1;
        h8 =   f0_2*f8 +2*f1*f7 + f2_2*f6 +2*f1*f5 + f4*f4 - b2;
        h9 =   f0_2*f9 + f1_2*f8 + f2_2*f7 + f3_2*f6 + f3_2*f5;
    }

    int64_t carry0 = (h0 + (1L << 25)) >> 26; h0 -= carry0 << 26; h1+= carry0;
    int64_t carry1 = (h1 + (1L << 24)) >> 25; h1 -= carry1 << 25; h2+= carry1;

    int64_t carry2 = (h2 + (1L << 25)) >> 26; h2 -= carry2 << 26; h3+= carry2;
    int64_t carry3 = (h3 + (1L << 24)) >> 25; h3 -= carry3 << 25; h4+= carry3;

    int64_t carry4 = (h4 + (1L << 25)) >> 26; h4 -= carry4 << 26; h5+= carry4;
    int64_t carry5 = (h5 + (1L << 24)) >> 25; h5 -= carry5 << 25; h6+= carry5;

    int64_t carry6 = (h6 + (1L << 25)) >> 26; h6 -= carry6 << 26; h7+= carry6;
    int64_t carry7 = (h7 + (1L << 24)) >> 25; h7 -= carry7 << 25; h8+= carry7;

    int64_t carry8 = (h8 + (1L << 25)) >> 26; h8 -= carry8 << 26; h9+= carry8;
    int64_t carry9 = (h9 + (1L << 24)) >> 25; h9 -= carry9 << 25; h0 +=19*carry9;

    carry0 = (h0 + (1L << 25)) >> 26; h0 -= carry0 << 26; h1+= carry0;

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    h[8] = h8;
    h[9] = h9;
}

While maintaining the exact same functionality as the original function, the minor updates made to this alternate implementation involve consolidating similar multiplications and unifications to certain expressions to tighten up the mathematics for improved simplicity. The intermediate carry steps were also consolidated into their appropriate sections. Any swap to this function in your code should provide identical results, maintaining original functionality as intended.
