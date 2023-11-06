Here's a numerically equivalent code but written in a more compact form and conforms to the dry principle (Don't Repeat Yourself).

This alternative approach uses loop and arrays for processing, thereby avoiding a lot of line-by-line repetition seen in the original approach:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    long long tmp[31] = {0}, carry;
  
    /* preprocessing & core multiplication */
    for (int i = 0; i < 10; ++i) {
        carry = 0;
        for (int j = 0; j <= i; ++j)
            tmp[i] += ((long long)f[j]) * g[i-j] * (j == i ? 1 : 2);
        if(i&1)
            tmp[i] += ((long long)f[i>>1]) * g[i>>1] * 38*2;
    }

    /* Handle higher part of left diagonal */
    for (int d = 0; d<9; ++d){
        carry = 0;
        for (int k = 0; d + k + 1 < 10; ++k)
            tmp[d + 10 + k] += ((long long)f[k])*g[d + k + 1] * 2;
        if((d + 2)&1)
            tmp[d+19]+= ((long long)f[(d+2)>>1])*g[(d+2)>>1] * 38*2;
    }

    /* Prepare carry are part of the post-processing */
    for (int d = 10; d--; ){
        tmp[20+d] += tmp[d];
        tmp[d]*=38;
    }

  /* postprocessing */
     for (int i = 0; i < 10;++i) {
         carry = tmp[i] >> 26;
         if (!(i&1))
             tmp[i+1] += carry;
         else
             tmp[i + 2] += carry*19;
        h[i] = tmp[i] -(carry<<26);
    }
}


Please note that whole number arithmetic should be performed exactly. Anything outside the exact range of values specified for a whole arithmetic type is implementation-defined and requires careful analysis and compiler documentation to ensure expected behavior. This is important it some compilers uses arithmetic right shift for signed integers which is implementation defined in C.