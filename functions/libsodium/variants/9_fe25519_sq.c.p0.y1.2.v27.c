In a similar manner, a different solution performing the same computations can be:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t temp[10];
    int32_t f_array[20];
    
    for(int i = 0; i < 10; ++i) {
        f_array[i] = f_array[i + 10] = f[i];
    }
         
    for(int i = 0; i < 10; ++i) {
        temp[i] = 0;
        for(int j = 0 ; j < 10 ; ++j) {
            if(j + i < 10) {
                temp[i] += (j == i ? f_array[j] * (int64_t)f_array[i] : f_array[j] * (int64_t)f_array[i + 10] * 2);
            } else if(j == i) {
                temp[i] +=  38 * (f_array[j] * (int64_t)f_array[i + 10]);
            } else {
                temp[i] += 19 * (f_array[j] * (int64_t)f_array[i + 10] * 2);
            }
        }
    }

   for (int i = 0; i < 9; ++i)
    {
        int64_t carry = (temp[i] + ((i == 0?2:1) << 24)) >> 25;
        temp[i] = temp[i] - carry * ((i == 0 ? 1l : 1l << 25));
        temp[i + 1] = temp[i + 1] + carry;
    }

    int64_t carry_out = temp[9] >> 24;
    temp[9] = temp[9] - (carry_out << 24);
    temp[0] = temp[0] + carry_out * 19;
    carry_out = temp[0] >> 26;
    temp[0] = temp[0] - (carry_out << 26);
    temp[1] = temp[1] + carry_out;
    
    for(int i = 0; i < 10; ++i) {
        h[i] = temp[i];
    }

}
