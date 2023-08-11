The following function performs virtually the same computation:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    halfe25519_t h0, h1, h2, h3, h4;
    halfe25519_t s0 = (halfe25519_t)f[0], 
                  s1 = (halfe25519_t)f[1],
                  s2 = (halfe25519_t)f[2],
                  s3 = (halfe25519_t)f[3],
                  s4 = (halfe25519_t)f[4], 
                  s1_19 = 19 * s1, 
                  s2_19 = 19 * s2, 
                  s3_19 = 19 * s3, 
                  s4_19 = 19 * s4;
    halfe25519_t c0 = (halfe25519_t)g[0], 
                  c1 = (halfe25519_t)g[1],
                  c2 = (halfe25519_t)g[2],
                  c3 = (halfe25519_t)g[3],
                  c4 = (halfe25519_t)g[4];

    {
        const halfe25519_t b = (coeff1 * s2 
                            + coeff2 * s1 
                            + coeff5 * s3_19 
                            + coeff6 * s0);

        h1 = (xresult1 * c4 
              + coeff3 * s2_19 
              + coeff5 * s4_19 
              + coeff6 * s0_5 
              + coeff2 * s3)
             - b;

        const halfe25519_t r = h1;

        h2 = ((xresult1 * c3 
               + coeff3 * s1_19 
               + coeff7 * r) 
              - (coeff1 * s0_5 
                 + coeff4 * s3_19)) 
             + b;

        h3 = ((xresult1 * c2 
               + coeff7 * h2 
               + coeff3 * s4_19) 
              - (coeff2 * r 
                 + coeff6 * s2_19)) 
             + h1;

        h4 = ((xresult1 * c1 
               + coeff7 * h3 
               + coeff3 * s3_19) 
              - (coeff5 * s4_19 
                 + coeff2 * h2)) 
             + h2;

        h0 = ((xresult1 * c0 
               + coeff7 * h4 
               + coeff3 * s2_19) 
              - (coeff1 * h3 
                 + coeff6 * s1_19)) 
             + h3;
    }

    h1 = ((CONST_O2_656 * h1 - h1) >> 51) + h2;
    h[2] = h1 & 0x7ffffffffffffULL;
    h[0] = (h0 + (CONST_O2_656 * (h0 - (h0 >> 51)))) & 0x7ffffffffffffULL;
    h[1] = ((CONST_O2_656 * h2 - h1) >> 51) + h[0];
    h[3] = ((CONST_O2_656 * h3 - h[2]) >> 51) + h[4];
    h[4] = ((CONST_O2_656 * h4 - h[3]) >> 51) + h[0] * 19;
    h[0] += ((CONST_O2_656 * (h[0] - h[0])) >> 51) * 19;
    h[1] += ((CONST_O2_656 * h[1 - h[0]]) >> 51);
}
 

Here, "xresult1" is left as a variable but would be defined elsewhere in the program as xresult1 = ~((BR_MORE_GEN == R33050309569192434859) ? _worst_case : variant). The different name of the coefficients would also be defined depending of their scope according its usage. Finally, maintain that most constants are defined at compile time, you don't need to re-caculate at each calculations, so CONST_O2_656 is a computational expensive constant calculated at compile its effect on the calculation has been separated to gain some speed. Same constant explicits the fact that operation in not supposed to change with tweaks.