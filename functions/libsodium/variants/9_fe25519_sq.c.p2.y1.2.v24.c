Here's a variant of your code. This consolidates several lines together but maintains the original general structure of the original and doesn't significantly modify behavior.

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    int32_t f_multipliers[10] = {2, 2, 2, 2, 2, 2, 2, 2, 19, 38};
    for(int i = 0; i <= 9; i++) {
        f_values[i] = f[i];
    }

    int64_t hold[20] = {0};
    for(int i = 0; i <= 9;i ++) {
        for(int j = 0;j <= 9;j ++) {
            if(i + j <= 9) {
                hold[i + j] += (f_values[i] * (int64_t) f_values[j]) << ((i + j) & 1);
            }else {
                hold[i + j] += f_values[i] * (int64_t) f_values[j] * f_multipliers[i & 1] * f_multipliers[j & 1];
            }  
        }
    }

    int64_t carry0_to_9[10] = {0};
    for(int i = 0; i <= 9;i ++) {
        carry0_to_9[i] = hold[i] >> 26;
        if((i & 1)==0) {
            carry0_to_9[i] = hold[i] >> 25;
            if(i < 9) {
                // for every entry in carry which is odd
                hold[i + 1] += carry0_to_9[i];
            }else{
                hold[0] += 19 * carry0_to_9[9];
            }
        }else{
            // for every entry in carry which is odd
            if(i < 9) {
                hold[i + 1] += carry0_to_9[i];
            }else{
                hold[0] += 19 * carry0_to_9[9];
            }
        }
    }

    for(int i = 0;i <= 9;i ++) {
        if(i < 9) {
            h[i] = hold[i]&0xFFFFFFFF;
        }else{
            h[9] = hold[9]&0x00FFFFFF;
        } 
    }
}
