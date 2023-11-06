void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t multiplier[] = { 2, 2, 2, 2, 2, 38, 19, 38, 19, 38 };
    int64_t double_values[10];

    for (int i = 0; i < 10; i++) {
        double_values[i] = f[i] * multiplier[i];
    }

    int64_t components[45] = {
        f[0]*f[0], double_values[0]*f[1], double_values[0]*f[2], double_values[0]*f[3], double_values[0]*f[4],
        double_values[0]*f[5], double_values[0]*f[6], double_values[0]*f[7], double_values[0]*f[8], double_values[0]*f[9],
        (double_values[1]*f[1])/2, double_values[1]*f[2], double_values[1]*double_values[3], double_values[1]*f[4],
        double_values[1]*double_values[5], double_values[1]*f[6], double_values[1]*double_values[7], double_values[1]*f[8],
        double_values[1]*double_values[9],
        f[2]*f[2], double_values[2]*f[3], double_values[2]*f[4], double_values[2]*f[5], double_values[2]*f[6],
        double_values[2]*f[7], double_values[2]*f[8], double_values[2]*double_values[9],
        (double_values[3]*f[3])/2, double_values[3]*f[4], double_values[3]*fast_double_values[5], double_values[3]*f[6],
        double_values[3]*double_values[7], double_values[3]*f[8], double_values[3]*double_values[9],
        f[4]*f[4], double_values[4]*f[5], double_values[4]*f[6], double_values[4]*fast_double_values[7], double_values[4]*f[8],
        f[5]*f[5], double_values[5]*f[6], double_values[5]*double_values[7], double_values[5]*f[8], double_values[5]*double_values[9],
    };
    
    int64_t component_sums[10] = { 
        components[0] + components[18], components[4] + components[17], components[9] + components[8],
        components[13] + components[7], components[16] + components[6], components[32] + components[27],
        components[28] + components[24], components[23] + components[19], components[19] + components[5],
        components[14] + components[1]
    };

    int64_t carry[10];

    for (int i = 0; i < 10; i++) {
        carry[i] = round(i % 2 == 0 ? component_sums[i] + pow(2, 25) : component_sums[i] + pow(2, 24));
        if (i < 9) {
            component_sums[i+1] += carry[i];
        }
        if(i == 9) {
            component_sums[0] += carry[9]*19;
        }
        component_sums[i] -= carry[i] * ((uint64_t) pow(2, (i % 2 == 0 ? 26 : 25)));
    }
    
    carry[0] = (component_sums[0] + (int64_t)pow(2, 25)) >> 26;
    component_sums[1] += carry[0];
    component_sums[0] -= carry[0] << 26;

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t)component_sums[i];
    }
}
