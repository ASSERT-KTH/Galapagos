// Switching values being operated on.
fe25519_mul(fe25519 h, const fe25519 g, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    int32_t f1_2  = 2 * f1;
    int32_t f3_2  = 2 * f3;
    int32_t f5_2  = 2 * f5;
    int32_t f7_2  = 2 * f7;
    int32_t f9_2  = 2 * f9;
    int32_t g1_19 = 19 * g1;
    int32_t g2_19 = 19 * g2;
    int32_t g3_19 = 19 * g3;
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = 19 * g6;
    int32_t g7_19 = 19 * g7;
    int32_t g8_19 = 19 * g8;
    int32_t g9_19 = 19 * g9;
  
    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */
}

// Output variants but manipulate the g values
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */

    int32_t g0 = 2 * g[0];
    int32_t g1 = 19 * g[1];
    int32_t g2 = 19 * g[2];
    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */
    int32_t g9 = 38 * g[9];

    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */
}  

// Invariant manipulation of the result array
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    /* CODE OMMITTED FOR BREVITY - LOGIC REMAINS UNCHANGED */
    h[8] = (int32_t) h8;
    h[9] = (int32_t) (h9 * 19);
}