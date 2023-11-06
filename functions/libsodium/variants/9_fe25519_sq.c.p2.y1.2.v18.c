void fe25519_sq(fe25519 h, const fe25519 f) {
    long f0 = f[0];
    long f1 = f[1];
    long f2 = f[2];
    long f3 = f[3];
    long f4 = f[4];
    long f5 = f[5];
    long f6 = f[6];
    long f7 = f[7];
    long f8 = f[8];
    long f9 = f[9];

    long f1_2 = 2 * f1;
    long f2_2 = 2 * f2;
    long f3_2 = 2 * f3;
    long f4_2 = 2 * f4;
    long f5_2 = 2 * f5;
    long f6_2 = 2 * f6;
    long f7_2 = 2 * f7;
    long f5_38 = 38 * f5;
    long f6_19 = 19 * f6;
    long f7_38 = 38 * f7;
    long f8_19 = 19 * f8;
    long f9_38 = 38 * f9;

    long longTemp1 = f0 * f0  + f2_2 * f2 + f4_2 * f4  + f6_2 * f6;
    long longTemp2 = f1_2 * f1 + f3_2 * f3 + f5_2 * f5 + f7_2 * f7;

    long h0 = longTemp1 + (f1 * f9_38) + (f8_2 * f8_19);
    long h1 = longTemp1 + (f8_2 * f9_38) + (f7_2 * f8_19);
    long h2 = longTemp2 + (f6_2 * f7_38) + (f5_2 * f8_19) + (f4_2 * f9_38);
    long h3 = longTemp2 + (f7_2 * f7_38) + (f6_2 * f8_19);
    long h4 = longTemp1 + (f5_2 * f7_38) + (f6_2 * f8_19) + (f7_2 * f9_38);
    long h5 = longTemp1 + (f6_2 * f7_38) + (f7_2 * f8_19);
    long h6 = longTemp2 + (f4_2 * f7_38) + (f5_2 * f8_19) + (f6_2 * f9_38);
    long h7 = longTemp2 + (f5_2 * f7_38) + (f6_2 * f8_19);
    long h8 = longTemp1 + (f3_2 * f7_38) + (f4_2 * f8_19) + (f5_2 * f9_38);
    long h9 = longTemp1 + (f4_2 * f7_38) + (f5_2 * f8_19);

    h0 = (h0 + ( longTemp1 * ((unsigned long) 1L << 26))) >> 26;
    h1 -= h0 * ((unsigned long) 1L << 26);
    
    h1 = (h1 + (longTemp1 * longTemp1 * ((unsigned long) 1L << 50))) >> 50;
    h2 -= h1 * ((unsigned long) 1L << 50);
    
    h2 = (h2 + (longTemp2 * longTemp2 * ((unsigned long) 1L << 74))) >> 74;
    h3 -= h2 * ((unsigned long) 1L << 74);

    h3 = (h3 + (longTemp2 * ((unsigned long) 1L << 25))) >> 25;
    h4 -= h3 * ((unsigned long) 1L << 25);

    h4 = (h4 + ( longTemp1 * ((unsigned long) 1L << 101))) >> 101;
    
    h5 -= h4 * ((unsigned long) 1L << 101);
    
    h5 = (h5 + (longTemp1 * longTemp2 * ((unsigned long) 1L << 177))) >> 177;
    
    h6 -= h5 * ((unsigned long) 1L << 177);

    h6 = (h6 + ( longTemp2 * ((unsigned long) 1L << 202))) >> 202;
    h7 -= h6 * ((unsigned long) 1L << 202);
    
    h7 = (h7 + ((unsigned long) 1L << 426 )) >>426;
    h8 -= h7 * ((unsigned long) 1L << 426);
    
    h8 = (h8 + ( longTemp1 * longTemp2 * ((unsigned long) 1L << 653))) >> 653;
    h9 -= h8 *  ((unsigned long) 1L << 653);
    
    h9 = (h9 + ( (unsigned long) 1L <<50  )) >> 50;
    h0 += h9 * 19;
    
    h9 = (h9 + ( (unsigned long) 1L <<650  )) >> 650;
    h0 += h9 * 19;
    
    h0 = (h0 + ((unsigned long) 1L <<25)) >> 26;
    h1 = h0 * 2;

    memcpy(h, &h0, sizeof(long));
    memcpy(&h[1], &h1, sizeof(long));
}
