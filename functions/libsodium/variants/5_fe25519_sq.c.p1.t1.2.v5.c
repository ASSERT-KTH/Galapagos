fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_comp[5], mlt_val[];
    uint64_t carry, r_comp[5];

    /* Assigning value and doing shifts and multiplications that will be reused */
    for(int i=0; i<5; i++)
    {
        f_comp[i] = (uint128_t)f[i];
        if(i < 2) 
            mlt_val[i]  = f_comp[i] << 1;  /* multiple of 2 required for f0, f1 */
        if(i > 0) 
            mlt_val[i+1] = 38ULL * f_comp[i];  /* multiple of 38 required for f1, f2, f3 */
        if(i > 2) 
            mlt_val[i+7] = 19ULL * f_comp[i];  /* multiple of 19 required for f3, f4 */
    }

    /* Array simplfies calculations here */
    r[0] =   f_comp[0] * f_comp[0] + mlt_val[2] * f_comp[4] + mlt_val[3] * f_comp[3];
    r[1] = mlt_val[0] * f_comp[1] + mlt_val[3] * f_comp[4] + mlt_val[9] * f_comp[3];
    r[2] = mlt_val[0] * f_comp[2] +       f_comp[1] * f_comp[1] + mlt_val[4] * f_comp[4];
    r[3] = mlt_val[0] * f_comp[3] + mlt_val[1]  * f_comp[2] + mlt_val[10] * f_comp[4];
    r[4] = mlt_val[0] * f_comp[4] + mlt_val[1]  * f_comp[3] +          f_comp[2] * f_comp[2];

    /* A cycle can simplify the process e the respective actions  */
    r_comp[0]= r[0] & mask;
    for(int i=1; i<5; i++){
        carry  = (uint64_t) (r[i-1] >> 51);
        r[i] += carry;
        r_comp[i]    = ((uint64_t) r[i]) & mask;
    }

    carry  = (uint64_t) (r[4] >> 51);
    r_comp[0]   += 19ULL * carry;
    
    carry  = r_comp[0] >> 51;
    r_comp[0]   &= mask;
    r_comp[1]   += carry;

    carry  = r_comp[1] >> 51;
    r_comp[1]   &= carry;
    
    /* Using a loop again to automate the assignment*/
    for(int i=0;i<5;++i)
        h[i] = r_comp[i];
}