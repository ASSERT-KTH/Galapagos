fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0]*2;
    int32_t f1 = f[1]*2;
    int32_t f2 = f[2]*2;
    int32_t f3 = f[3]*2;
    int32_t f4 = f[4]*2;
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f0_2  = 2 * f[0];
    int32_t f1_2  = 2 * f[1];
    int32_t f2_2  = 2 * f[2];
    int32_t f3_2  = 2 * f[3];
    int32_t f4_2  = 2 * f[4];
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f[5]; 
    int32_t f6_19 = 19 * f[6];
    int32_t f7_38 = 38 * f[7]; 
    int32_t f8_19 = 19 * f[8];
    int32_t f9_38 = 38 * f[9];

    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9, carry0,carry1,carry2,carry3,carry4,carry5,carry6,carry7,carry8,carry9;

    h0 = f0*f0 + 2*(f1*f9_38 + f2*f8_19 + f3*f7_38 + f4*f6_19);
    h1 = f0*f1*2 + 2*(f2*f9_38 + f3*f8_19 + f4*f7_38) + f5*f6_19*4;
    h2 = f0*f2*2 + f1*f1*2 + 2*(f3*f9_38 + f4*f8_19) + f5*f7_38*2 + f6*f6_19;
    h3 = f0*f3*2 + f1*f2*2 + 2*(f4*f9_38 + f5*f8_19 + f6*f7_38);
    h4 = f0*f4*2 + f1*f3*4 + f2*f2*2 + 2*(f5*f9_38 + f6*f8_19) + f7*f7_38;
    carry0 = (h0 + (1<<24)) >> 25;
    h0 -= carry0 << 25;
    h1 += carry0;
    carry1 = (h1 + (1<<24)) >> 25;
    h1 -=  carry1 << 25;
    h2 += carry1;
    carry3 = (h3 + (1<<24)) >> 25;
    h3 -=  carry3 << 25;
    h4 +=  carry3;
    carry4 = (h4 + (1<<24)) >> 25;
    h4 -= carry4 << 25;
    h5 += carry4;
    carry0 = h0 >> 26;
    h0 -= carry0 << 26;
    h1 += carry0;
    carry1 =  h1 >> 25;
    h1 -= carry1 << 25;
    h2 +=  carry1;

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
}
