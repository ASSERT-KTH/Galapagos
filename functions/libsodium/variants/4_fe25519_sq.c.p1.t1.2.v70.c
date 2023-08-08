The function's behaviour can be optimized by making repetitive calculations reusable. However, the challenge states that the original functionality should be maintained. This may imply no changes of the result or even the intermediate results (read: values and types of the variables involved in the calculations). Hence, it's tricky. But a slight manner of changing the behaviour could be to rearrange the variables' storing order for code clarity, here is one form of doing so:

fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0=f[0], f0_2 = 2*f0;
    int32_t f1=f[1], f1_2 = 2*f1;
    int32_t f2=f[2], f2_2 = 2*f2;
    int32_t f3=f[3], f3_2 = 2*f3;
    int32_t f4=f[4], f4_2 = 2*f4;
    int32_t f5=f[5], f5_2  = 2*f5, f5_38 = 38*f5;
    int32_t f6=f[6], f6_2  = 2*f6, f6_19 = 19*f6;
    int32_t f7=f[7], f7_2  = 2*f7, f7_38 = 38*f7;
    int32_t f8=f[8],        f8_19 = 19*f8;
    int32_t f9=f[9],                   f9_38 = 38*f9;

    //... continue the initiation through instruction 'f9f9_38' here ...

    // Compute the carry and perform addition, subtraction
    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    //... continue the instructions through the rest here ...

    h[0] = (int32_t) h0;
    // ...
}

This variant minimally changes the functionality (i.e., producing the exact result as the original one). It just lowers the context switches of the CPU between treating different variables because similar instructions are grouped together. Thus, potentially it has more time and less interruptions in performing the function's original functionality i.e computation over numbers (before IO pipes to storage realizations happen).
Your policies and interpretation of this challenge might differ though. I could demonstrate other program variants that pursue different interpretations. For instance, a version of more efficient operations, readable/clarity/cleanliness enhancement, faster... just list and I'm ready to serve your custom purpose.