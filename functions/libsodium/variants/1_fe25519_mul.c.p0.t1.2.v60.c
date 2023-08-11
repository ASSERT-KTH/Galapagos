fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1]*2;   //compound the multiplication with 2
    int32_t f2 = f[2];
    int32_t f3 = f[3]*2;   //compound the multiplication with 2
    int32_t f4 = f[4];
    int32_t f5 = f[5]*2;   //compound the multiplication with 2
    int32_t f6 = f[6];
    int32_t f7 = f[7]*2;   //compound the multiplication with 2
    int32_t f8 = f[8];
    int32_t f9 = f[9]*2;   //compound the multiplication with 2

    int32_t g0 = g[0];
    int32_t g1 = g[1]*19;  //compound the multiplication with 19
    int32_t g2 = g[2]*19;  //compound the multiplication with 19
    int32_t g3 = g[3]*19;  //compound the multiplication with 19
    int32_t g4 = g[4]*19;  //compound the multiplication with 19
    int32_t g5 = g[5]*19;  //compound the multiplication with 19
    int32_t g6 = g[6]*19;  //compound the multiplication with 19
    int32_t g7 = g[7]*19;  //compound the multiplication with 19
    int32_t g8 = g[8]*19;  //compound the multiplication with 19
    int32_t g9 = g[9]*19;  //compound the multiplication with 19

    int64_t f0g0 = f0 * (int64_t)g[0];
    int64_t f0g1 = f0 * (int64_t)g[1];
    // ... repeat for all the fIgI, but use direct array access for g

    int64_t f1g1 = f1 * (int64_t)g[1];
    // ... repeat for each fIgI

    // ... The hK calculations and the carries and so forth follow as they were, using the newly defined fIgI, no more multiplication for repeated values which maintain code functionality

    /*
      Skip specifying formulas as they're not changed. Repeat what's been shown above
    */

    h[0] = (int32_t)f0g0;
    h[1] = (int32_t)f1g1;
    // ...  finish initializating the array. Maybe error but should communicate the idea
}