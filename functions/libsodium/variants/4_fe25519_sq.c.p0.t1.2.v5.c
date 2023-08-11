fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t pf[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t pf0_2 = 2*pf[0], pf1_2 = 2*pf[1], pf2_2 = 2*pf[2], pf3_2 = 2*pf[3], pf4_2 = 2*pf[4];
    int32_t pf5_2= 2*pf[5], pf6_2 = 2*pf[6], pf7_2 = 2*pf[7];
    const int c38 = 38, c19 = 19;
    int64_t h_local[10];
    int64_t carry[10];
    const int32_t twoPow25 = (int32_t)1L << 25;
    const int32_t twoPow26 = (int32_t)1L << 26;
    const int32_t twoPow24 = (int32_t)1L << 24;

    {
        int64_t t0 = f[0] * (int64_t) f[0];
        int64_t t2 = pf1_2 * (int64_t) f[1];
        int64_t z2 = t0 + t2;
        h_local[0] = t0 + pf1_2 * (int64_t)pf[8]*c38 + pf2_2 * (int64_t)pf[7]*c38+ f[3] * (int64_t)f[6]*c38*2 + f[4] * (int64_t)f[5]*c38*2;
        carry[0] =(z2 + (int64_t) twoPow25) >> 26; h_local[1] = z2 - carry[0] * (int64_t)twoPow26;
    }
    {
       int64_t t0 = pf0_2 * (int64_t) f[1];
       int64_t t2 = f[2] * (int64_t)f[2];
       int64_t z2 = t0 + t2;
       h_local[1] = z2  + pf0_2 * (int64_t)pf[9] *c38 + f[3] * (int64_t)f[8]*c19*2 + f[4] * (int64_t)f[7]*c19*2 + pf5_2 * (int64_t) f[6]*c19;
       carry[1] = (z2 + (int64_t)twoPow24) >> 25; h_local[2] = z2 - carry[1] * (int64_t)twoPow25;
    }
    {
        int64_t t0 = pf0_2 * (int64_t) f[2] + pf1_2 * (int64_t) f[1];
        int64_t t2 = f[3] * (int64_t)f[3];
        int64_t z2 = t0 + t2;
        h_local[2] = z2 + f[0] * (int64_t)f[9]*c38*2 + f[4] * (int64_t)f[8]*c19*2 + pf5_2 * (int64_t) f[7]*c38 + f[6] * (int64_t)f[6]*c19*2;
        carry[2] = (z2 + (int64_t)twoPow25) >> 26; h_local[3] = z2 - carry[2] * (int64_t)twoPow26;
    }
    
    
    // ... So on until (h9- carry9) ...

    h[0] = h_local[0]; h[1] = h_local[1]; h[7] = h_local[7]; h[8] = h_local[8]; h[9] = h_local[9];
}
The rest of the logic continues to redefine z_i, t_0i, t_2i until all f values and corresponding multipliers are consumed gradually with adjusting shifts (>> 25, >>26, etc.) at the end of calculating each h element.
This shift can be derived from allocating 26 bits making sure coefficient-wise product does not overflow. Then, excessive higher bits are carried to the next limb. Lastly, towards the end of the function h[0] needs to carry from h[9] (after all the overflow resulting from multiplication) to guarantee h[9]*19’s bits are within 25 bits.
This function focuses more heavily on following a certain multiplier schedule. As an example, towards the earlier calculations f2 uses very few multiples of 19 and later within initializing h1 also sees nearly equal treatment. Find and form this multiplier to greatly optimize multiplications within this function.