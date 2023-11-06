
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elements[10]; // elements of f
    int32_t g_elements[10]; // elements of g
    
    // Load elements of f and g from arrays
    for (int i = 0; i < 10; i++)
    {
        f_elements[i] = f[i];
        g_elements[i] = g[i];
    }

    // Precomputations
    int32_t fg1[10], fg2[10];
    for (int i = 0; i < 10; i++)
    {
        fg1[i] = f_elements[i] * (int64_t) g_elements[i];
        fg2[i] = f_elements[i] * (int64_t) (19 * g_elements[i]);
    }
    int32_t f_double[5] = {2 * f_elements[1],
                            2 * f_elements[3],
                            2 * f_elements[5],
                            2 * f_elements[7],
                            2 * f_elements[9]};

    int64_t temp[10] = {0};

    // Order of computing is based off which elements are required in subsequent computations
    for (int index: {5, 7, 9})
    {
        starting_temp[index - 5] += f_elements[index - 4] * fg1[index -
                                            5] + f_elements[index -
                                            3] * fg1[index -
                                            3] + f_elements[index -
                                            1] * fg1[index -
                                            1] + f_elements[index -
                                            2] * fg1[index -
                                            2] + f_elements[index -
                                            4] * fg2[index -
                                            4];
                                            
    }
    for (int index: {3, 2, 6, 8, 1, 0, 4})
    {
        temp[index] += f_elements[index + 1] * fg1[index +
                        1] + f_elements[index +
                        2] * fg1[index +
                        2] + f_elements[index +
                        3] * fg1[index +
                        3] + f_elements[index +
                        4] * fg2[index +
                        4] + f_double[index] * hg2[10 - index];
    }

    int64_t adjustment_factors [10];
    for (int i = 9; i >= 0; i--)
    {
        adjustment_factors[i] = (temp[i] + (int64_t)(1L << ((i == 4 || i == 6) ? 25 : 24))) 
                                  >> ((i == 1 || i == 5 || i == 7) ? 25 : 26);
        if (i != 0) temp[i - 1] += (i <= 4) ? adjustment_factors[i] : 19 * adjustment_factors[i];
    }

    int64_t final[10];
    for (int i = 0; i <= 9; i++) 
    {
        final[i] = temp[i] - ((uint64_t)1L << ((i == 4 || i == 6) ? 25 : 24)) *
                                      (adjustment_factors[i ? (i - 1) : 9]);
        h[i] = (int32_t) final[i];
    }

    memcpy(h, final, sizeof(final));

}
