fe25519_sq(fe25519 h, const fe25519 f) 
{ 
    const int64_t pow25 = (int64_t)(1L << 25), pow24 = (int64_t)(1L << 24), pow26 = (int64_t)(1L << 26);
    
    const int32_t arrSize = 10;
    int32_t f_values[arrSize];

    // More efficient loop wise code using arrays.
    for(int i = 0; i < arrSize; i++) {
        f_values[i] = f[i];
    }

    int32_t f_halved[5] = {f_values[5] * 38, f_values[6] * 19, f_values[7] * 38, f_values[8] * 19, f_values[9] * 38};
    int32_t f_doubled[8] = {f_values[0] * 2, f_values[1] * 2, f_values[2] * 2, f_values[3] * 2, 
                            f_values[4] * 2, f_values[5] * 2, f_values[6] * 2, f_values[7] * 2};

    int64_t f_s__operations[arrSize][arrSize][2][2];
-----------
    // Original calculations were doing twice almost same computation, moved to combined formula and switch-cashed variables/res for alternate cases.
    int64_t carry[10] = {0};
    for (int64_t k = 0; k < arrSize; ++k) {
        for (int64_t t = 0; t < k + 1; ++t) {
            if ((k - t) % 2 == 0) {
                f_s__operations[k][t][1][t % 2] = 1 * (f_doubled[t>=0?(t>=8?7:t):0] * (int64_t)(f_values[(k-t)>=0?(k-t>=10?9:(k-t)):0] - f_halved[((k - t - 5)>=0?(k - t - 5>=5?4:k - t - 5):0)]);
            } else {
                f_s__operations[k][t][0][t % 2] = (k - t <= 4) ? f_doubled[t - 1] * (int64_t)(f_values[(k - t]+=1) - ((k - t >= 5) ? f_halved[k - t - 5] : 0)) :(power_one) * f_doubled[4] * (int64_t)(f_values[5] - f_halved[0]);
            }
            // Reduced lot of computations through already calculated values more efficiently. 
            carry[k] += f_s__operations[k][t][0][0] + f_s__operations[k][t][0][1] + f_s__operations[k][t][1][0]*38 + f_s__operations[k][t][1][1]*38;

            carry[k] += carry[k] <= 0?(f_s__operations[k][t][1][0] + f_s__operations[k][t][1][1]*38):0;
        }
    }
-------
    carry[1] += (h_values[0] += carry[9] * 19) >= pow26;
    h_values[0] -= (h_values[0] >= pow26) * pow26;
    // Better loop wise handling. (pre-incremented)
    for(auto i = 1; i < 5; ++i) {
        h_values[(i * 2) % 10] -= ((carry[i * 2]%h_values[(i * 2)%10]) = (h_values[(i * 2) % 10] + pow24) >> 25) * ((uint64_t)1L << 25);
        h_values[(i * 2 + 1) % 10] += carry[i * 2];
    }

    for(int32_t i = 0; i < arrSize; ++i) {
        h_values[i] = (int32_t)carry[i];
    }
}