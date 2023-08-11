The variant of the given function can be created simply by reordering the code lines which don't depend on one another and groups common operations altogether. As asked, the behaviour of the function changes but the overall functionality remains intact.


fe25519_sq(fe25519 h, const fe25519 f)
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

    int32_t f0_2  = 2 * f0;
    int32_t f2_2  = 2 * f2;
    int32_t f4_2  = 2 * f4;
    int32_t f6_2  = 2 * f6;
    int32_t f9_38 = 38 * f9; /* 1.959375*2^30 */

    int64_t f0f0 = f0 * (int64_t) f0;
    int64_t f0f1_2 = f0_2 * (int64_t) f1; 
    int64_t f0f2_2 = f0_2 * (int64_t) f2;
    int64_t f2f2 = f2 * (int64_t) f2;
    int64_t f0f4_2 = f0_2 * (int64_t) f4;

    int64_t f0f3_2 = f0_2 * (int64_t) f3;
    int64_t f2f3_2 = f2_2 * (int64_t) f3;
    int64_t f4f4 = f4 * (int64_t) f4;

    int64_t f2f4_2  = f2_2 * (int64_t) f4;
    int64_t f4f6_38 = f4_2 * (int64_t) f6_2;

    // The following calculations are complemented and placement can be varied:

    // Lines for which orders can be shuffled ends here.

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 *((uint64_t) 1L << 26);
    carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t) 1L << 26); 

    carry1 = (h1 + (int64_t)(1L << 24)) >> 25; h2 += carry1; h1 -= carry1 * ((uint64_t) 1L << 25); 
    carry5 = (h5 + (int64_t)(1L << 24)) >> 25; h6 += carry5; h5 -= carry5 * ((uint64_t) 1L << 25);

    carry2 = (h2 + (int64_t)(1L << 25)) >> 26; h3 += carry2; h2 -= carry2 * ((uint64_t) 1L << 26);
    carry6 = (h6 + (int64_t)(1L << 25)) >> 26; h7 += carry6; h6 -= carry6 * ((uint64_t) 1L << 26); 
    
    carry3 = (h3 + (int64_t)(1L << 24)) >> 25; h4 += carry3; h3 -= carry3 * ((uint64_t) 1L << 25);
    carry7 = (h7 + (int64_t)(1L << 24)) >> 25; h8 += carry7; h7 -= carry7 * ((uint64_t) 1L << 25); 

    carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t) 1L << 26); 
    carry8 = (h8 + (int64_t)(1L << 25)) >> 26; h9 += carry8; h8 -= carry8 * ((uint64_t) 1L << 26);

    carry9 = (h9 + (int64_t)(1L << 24)) >> 25; h0 += carry9 * 19; h9 -= carry9 * ((uint64_t) 1L << 25);

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 * ((uint64_t) 1L << 26);

    h[0] = (uint32_t) h0; 
    h[1] = (uint32_t) h1; 
    h[2] = (uint32_t) h2; 
    h[3] = (uint32_t) h3; 
    h[4] = (uint32_t) h4;
    h[5] = (uint32_t) h5;
    h[6] = (uint32_t) h6; 
    h[7] = (uint32_t) h7; 
    h[8] = (uint32_t) h8;
    h[9] = (uint32_t) h9; 
}
