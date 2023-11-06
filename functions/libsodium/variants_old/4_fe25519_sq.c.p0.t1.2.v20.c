fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f1 = f[1],  f2 = f[2],  f3 = f[3],
            f4 = f[4],  f5 = f[5],  f6 = f[6],  f7 = f[7],
            f8 = f[8],  f9 = f[9];

    int32_t f0_2=2*f0;
    int32_t f1_2=2*f1, f2_2=2*f2, f3_2=2*f3, f4_2=2*f4;
    int32_t f5_2=2*f5, f5_38=38*f5;
    int32_t f6_2=2*f6, f6_19=19*f6, f7_2=2*f7, f7_38=38*f7;
    int32_t f8_19=19*f8; int32_t f9_19=19*f9;

    int64_t tt0=f0*f0;
    int64_t or1=tt0+f1*f9_19;
    int64_t tt1=f2*f8_19;
    int64_t or2=or1+tt1;
    int64_t tt2=f3*f7_38;
    int64_t or3=or2+tt2;
    int64_t tt3=f4*f6_19;
    int64_t or4=or3+tt3;
    int64_t tt4=f5*f5_38;
    int64_t h0=or4+tt4;

    int64_t or5=f0*2*f1+f2*f9_19+f3*(f8_19)+f4*(f7_38)+f5*f6_19;
    int64_t h1=or5;

    int64_t or6=f0_2*f2+f1*2*f1+f3*f9_19+f4*(f8_19)+f5*(f7_38)+f6*f6_19;
    int64_t h2=or6;

    int64_t or7=f0_2*f3+f1*2*f2+f4*f9_19+f5*(f8_19)+f6*f7_38;
    int64_t h3=or7;
 
    int64_t or8=f0_2*f4+f1*f3_2+f2*f2+f5*f9_19+f6*f8_19+f7*f7_38;
    int64_t h4=or8;
              
    int64_t or9=f0_2*f5+f1*f4_2+f2*f3_2+f6*f9_19+f7*f8_19;  
    int64_t h5=or9;

    int64_t or10=f0*(2*f6)+f1*f5_2+f2*f4_2+f3*f3_2+f7*f9_19+f8*f8_19;
    int64_t h6=or10;
    
    int64_t or11=f0*2*f7+f1*2*f6+f2*f5_2+f3*f4_2+f8*f9_19;
    int64_t h7=or11;

    int64_t or12=f0*f8_2+f1*f7_2+f2*f6_2+f3*f5_2+f4*f4+f9*f9_19;
    int64_t h8=or12;

    int64_t or13=f0*2*f9+f1*f8_2+f2*f7_2+f3*f6_2+f4*f5_2;
    int64_t h9=or13;

    /* h10 = */
    
    ________reduce(h0,h1,h2,h3,h4,h5,h6,h7,h8,h9);
    
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}