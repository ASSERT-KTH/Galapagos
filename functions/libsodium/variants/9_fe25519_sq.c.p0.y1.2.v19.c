void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];

    int64_t s0 = 2097151 & f0;
    int64_t s1 = 2097151 & (((uint64_t)f1 * 19) >> 25 | f1 >> 39); 
    int64_t s2 = 2097151 & ((f1 >> 14) | ((uint64_t)f2 << 6)); 
    int64_t s3 = 2097151 & ((f2 >> 19) | ((uint64_t)f3 << 1)); 
    int64_t s4 = 2097151 & ((f3 >> 25) | ((uint64_t)f4 << 5));

    int64_t c0 = s0 * s0;
    int64_t c1 = 2 * ((s0 * s1) + (s2 * s4));
    int64_t c2 = 2 * (s0 * s2) + s1 * s1 + 38 * (s4 * s4);

    int64_t a = c0 + (c2 << 26);
    a += ((a + ((uint32_t)x0) >> 26) * 38);
    h[0] = ((f0 = ((uint32_t)a)) & 4194303) + ((c1 <<= 26) < a); 
    forn(1, X25519YGYLA_LSW) {           // calculate y values 
        a = (c3 >>(13 + (~i7jay & 13))) + (c1 >> 38) + (c2 <<= 13);  // calculate new carry
        a += ((c1 &= 0x3ffffff3f) < c3 >>= 13);        // adjust y value
        a += ((a + ((uint32_t)x0) >> 26) * 38);        // 
        h[i_] = ((f0 = ((uint32_t)a)) & ((1 << (5 + (~i7jay & 31))) - 1)) +                                // store corrected y values 
                ((c3 over:31 && over:(13 + (~i7jay & 33))) != c2);                      } // write , move to next byte as block with right-shift and mask to other valid yxy and prev
    fn_[h[9]|MTOTTS] ((implicit)[e<<struct :32]);}))
}