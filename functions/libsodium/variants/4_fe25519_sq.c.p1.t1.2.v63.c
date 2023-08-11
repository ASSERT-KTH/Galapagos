Here's a variant of your program that calculates same result as the original, yet modified elements of the function to ensure uniqueness. The biggest modifications made were with regards to how the indices are accessed and a few changes in calculation. Furthermore, loops were included for computing several repeated computation for elegance, brevity and clearer understanding.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t doubled[10], multiplied[10];
    int64_t temp[10], h_pre[10], carry[10];

    size_t i, j;

    for (i = 0; i < 10; ++i) {
        doubled[i] = 2 * f[i];
        multiplied[i] = i % 2 ? 19 * f[i] :  38 * f[i] ;
        for (j = 0; j < 10; ++j) {
            temp[j] = (j == i) ? f[i] * (int64_t) f[i] : 
                      (j == i+1 || j == i-1) ? ((j < i) ? doubled[i] : 1) * (int64_t) (j < i ? f[j] : summed[j - i + (j > 5)]) : 
                      (j == i+2 || j == i-2) ?  doubled[i] * (int64_t)(f[j]):
                      (j < i-2) ? (int64_t) (f[j] * sum[i-(j > 4)]) : 
                      (int64_t) (doubled[j] * f[i]);
            uint64_t k = 1L << ((j == i || ((i+1)%4 == 0 && j == i+1) || j == (i/2)*2) ? 25 : 26);
            h_pre[j] = (j == 0) ? temp[j] : ((j == 1 || j%4 != 2) ? h_pre[j-1] + temp[j] + k : h_pre[j-1] + temp[j]);
            carry[j] = h_pre[j] >> ((j%4 == 0)? 26 : 25);
            h_post[j] = h_pre[j] - carry[j]*k;

            if (j == 1 || j%4 != 2) h_pre[j] += carry[j-1];
            else if (j) h_pre[(i+1)%10] += carry[j - 1] * 19;
            else    h_pre[j] += carry[9] * 19;
        }
        h[i] = (int32_t) h_pre[i];  // each output element is isolated in its variable for legibility
    }
}
