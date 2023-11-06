fe25519_sq(fe25519 h, const fe25519 f)
{
    // fetch function values
    int32_t f_values[] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t fp1_cons[] = {19,19,19,19,38,38,19,19,38};
    
    // initialize required variables
    int64_t multiply_values[90];
    int64_t carry[10] = {0};
    int64_t final_values[10] = {0};

    int idx1, idx2;
    // main computations of function
    for (idx1 = 0; idx1 < 10; ++idx1) 
    {
        for (idx2 = 0; idx2 < 10; ++idx2) 
        {
            if(idx1 > idx2) continue;
            if (idx1 == idx2) 
            {
                multiply_values[idx1 * 10 + idx2] = f_values[idx1] * (int64_t)f_values[idx2];
            } 
            else 
            {
                if(idx2 == idx1 + 1) 
                {
                    multiply_values[idx1 * 10 + idx2] = 2 * f_values[idx1] * (int64_t)f_values[idx2];
                } 
                else 
                {
                    const int32_t factor = (idx1 + idx2) & 1 ? 2 * f_values[idx1] : f_values[idx1];
                    multiply_values[idx1 * 10 + idx2] = factor * (int64_t)f_values[idx2];
                }
            }
        }
        final_values[idx1] = multiply_values[idx1 * 10 + ((idx1 * 2) % 10)] + multiply_values[idx1 * 10 + ((idx1 * 7) % 10)];
            if(idx1>0) final_values[idx1] += multiply_values[idx1 * 10 - ((idx1 * 2) % 10)];
            if(idx1<9) final_values[idx1] += multiply_values[(idx1+1) * 10 - ((idx1 * 2) % 10)];
            if(idx1<8) final_values[idx1] += multiply_values[(idx1+2) * 10 - ((idx1 * 2) % 10)];
        final_values[idx1] = multiply_values[idx1* 10 + ((idx1 * 2) % 10)] + multiply_values[idx1 * 10 + ((idx1 * 7) % 10)] 
            - multiply_values[(10 - idx1) * 10 - ((10 - idx1) * 2) % 10] - multiply_values[(9 - idx1) * 10 - ((9 - idx1) * 2) % 10] 
            + multiply_values[(8 - idx1) * 10 - ((8 - idx1) * 7) % 10];
    }

    // carry adjustments
    for(idx1 = 0; idx1 < 10; ++idx1) 
    {
        carry[idx1] = (final_values[idx1] + (int64_t)((idx1 & 1 ? 1 : 1) << 24)) >> 25;
        if (idx1 < 9) 
        {
            final_values[idx1 + 1] += carry[idx1];
        } 
        else 
        {
            final_values[0] += 19 * carry(idx1);
        }
        final_values[idx1] -= carry[idx1] << 25;
    }
    carry[0] = (final_values[0] + (int64_t) (1L << 24)) >> 25;
    final_values[1] += carry[0];
    final_values[0] -= carry[0] * ((uint64_t) 1L << 25);

    // put the result back in h array
    for(idx1 = 0; idx1 < 10; ++idx1) 
    {
        h[idx1] = (int32_t)final_values[idx1];
    }
}
