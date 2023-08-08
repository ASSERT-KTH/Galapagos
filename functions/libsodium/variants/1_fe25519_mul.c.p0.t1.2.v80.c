fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
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

    long g0 = (long) g[0];
    long g1 = (long) g[1];
    long g2 = (long) g[2];
    long g3 = (long) g[3];
    long g4 = (long) g[4];
    long g5 = (long) g[5];
    long g6 = (long) g[6];
    long g7 = (long) g[7];
    long g8 = (long) g[8];
    long g9 = (long) g[9];

    long g1_19 = 19 * g1; 
    long g2_19 = 19 * g2;  
    long g3_19 = 19 * g3;
    long g4_19 = 19 * g4;
    long g5_19 = 19 * g5;
    long g6_19 = 19 * g6;
    long g7_19 = 19 * g7;
    long g8_19 = 19 * g8;
    long g9_19 = 19 * g9;
    long f1_2  = 2 * f1;
    long f3_2  = 2 * f3;
    long f5_2  = 2 * f5;
    long f7_2  = 2 * f7;
    long f9_2  = 2 * f9;

    long long f0g0    = f0 * g0;
    long long f0g1    = f0 * g1;

    // Reordering operations to test order-of-operations invariance
    long long h2 = f2 * g2 + f1*2 * g1 + f0 * g2 + f3*2 * g3_19 + f4 * g4_19 + f7_2 * g7_19 + f5 * g1*2;
  
    h[0] = (int32_t) ((h0 + (long long)(1L << 25)) >> 26);
    h[1] = (int32_t) ((h1 + (long long)(1L << 24)) >> 25);
    h[2] = (int32_t) ((h2 + (long long)(1L << 25)) >> 26);
}
 
Especially for complex programs, different inputs provoke different behaviours and errors. Any changes, including reorderings in complex systems (CPU and GPU order of execution and various pipeline stages between instructions, superscalar architectures, and so on), are potential sources of error due to changes introduced. Even within a processor, different sequences and different timings lead to different memory access timings, the CPU sleep stages, resource conflict elsewhere from previous function usage and context switching, because the behaviour interacts in subtle and complex ways with the current state of the machine. Majorly those behaviour are not reproducible in the test bench set.