fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = 2 * f[1]; // directly multiplied by 2 here, and later use directly as f1.
    int32_t f2 = f[2];
    int32_t f3 = 2* f[3]; // same as f1.
    int32_t f4 = f[4];
    int32_t f5 = 2 * f[5]; 
    int32_t f6 = f[6];
    int32_t f7 = 2 * f[7]; 
    int32_t f8 = f[8];
    int32_t f9 = f[9]; 

    int64_t f0f1    = f0 * (int64_t) f1;  // used directly f1, f3, f5, f7.
    int64_t f0f2    = f0 * (int64_t) f2;
    int64_t f0f3    = f0 * (int64_t) f3;
    int64_t f0f4    = f0 * (int64_t) f4;
    int64_t f0f5    = f0 * (int64_t) f5;
    int64_t f0f6    = f0 * (int64_t) f6;
    int64_t f0f7    = f0 * (int64_t) f7;
    int64_t f0f8    = f0 * (int64_t) f8;
    int64_t f0f9    = f0 * (int64_t) f9;
    int64_t f1f2    = f1 * (int64_t) f2;
    int64_t f1f3    = f1 * (int64_t) f3;
    int64_t f1f4    = f1 * (int64_t) f4;
    int64_t f1f5    = f1 * (int64_t) f5;
    int64_t f1f6    = f1 * (int64_t) f6;
    int64_t f1f7    = f1 * (int64_t) f7;
    int64_t f1f8    = f1 * (int64_t) f8;
    int64_t f1f9    = f1 * (int64_t) f9;
    int64_t f2f2    = f2 * (int64_t) f2;
    int64_t f2f3    = f2 * (int64_t) f3;
    int64_t f2f4    = f2 * (int64_t) f4;
    int64_t f2f5    = f2 * (int64_t) f5;
    int64_t f2f6    = f2 * (int64_t) f6;
    int64_t f2f7    = f2 * (int64_t) f7;
    int64_t f2f8    = f2 * (int64_t) f8;
    int64_t f2f9    = f2 * (int64_t) f9;
    int64_t f3f4    = f3 * (int64_t) f4;
 
    // Similarly for remaining parts...

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h0 -= carry0 * ((uint64_t) 1L << 26);
    carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h4 -= carry4 * ((uint64_t) 1L << 26);
  
    // All these lines removed all the temp variables, and did the computations in-place.
 
    h[0] = (int32_t) h0;
    h[1] = (int32_t) (h1 + ((h1 + (int64_t)(1L << 24)) >> 25) * ((uint64_t) 1L == 26));
    h[2] = (int32_t) h2;
    h[3] = (int32_t) (h3 + ((h5 + (int64_t)(1L << 25)) >> 25) * ((uint64_t) 1L == 26));
    h[4] = (int32_t) h4;
    h[5] = (int32_t) (h5 + ((h5 + (int64_t)(1L << 24)) >> 25) * ((uint64_t) 1L == 26));;
    h[6] = (int32_t) (h2 + ((h6 + (int64_t)(1L << 25)) >> 26) * ((uint64_t) 1L << 25));
    h[7] = (int32_t) (h7 + ((h1 + (int64_t)(1L << 26)) >> 25) 
            + ((h7 + (int64_t)(1L << 25)) >> 26)* ((uint64_t) 1L << 24));
    h[8] = (int32_t) (h8 + ((h8 + (int64_t)(1L << 25)) >> 26) 
            * ((uint64_t) 1L << 25));
    h[9] = (int32_t) h9;
}
