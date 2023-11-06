fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_arr[10];
    int32_t g_arr[10];
    int32_t h_arr[10];
    
    int64_t carry_arr[10];
    
    for(int i = 0; i < 10; i++){
        f_arr[i] = f[i];
        g_arr[i] = g[i];
    }

    for(int i = 1; i < 10; i+=2)
    {
        g_arr[i] *= 19;
        f_arr[i] *= 2;
    }

    int64_t mult_arr[100];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mult_arr[10*i+j] = f_arr[i] * (int64_t) g_arr[j];
        }
    }

    int64_t h_mult[10];

    for(int i = 0; i < 10; i++){
        h_mult[i] = mult_arr[i*10];
    }

    h_mult[0] += mult_arr[1]*38 + mult_arr[2]*19 + mult_arr[4]*19 + mult_arr[5]*38 + mult_arr[6]*19;
    h_mult[0] += mult_arr[8]*19 + mult_arr[10] + mult_arr[20+9]*38 + mult_arr[30+8]*19 + mult_arr[40+7]*19;
    h_mult[0] += mult_arr[50+6]*19 + mult_arr[70+3]*38 + mult_arr[80+2]*19 + mult_arr[90+1]*38;

    int64_t carry;

    for(int i = 0; i < 9; i++) {
      carry_arr[i] = (h_mult[i] + (int64_t)(1<<((i%2)?24:25))) >>((i%2)?25:26);
      h_mult[i+1] += i ==24? 0 :carry_arr[i];
      h_mult[i] -= carry_arr[i] * ((uint64_t) 1L <<((i%2)?24:26));
    }

    carry = (h_mult[9] + (int64_t)(1<<24)) >> 25;
    h_mult[0] += carry * 19;
    h_mult[9] -= carry * ((uint64_t) 1L <<25);
  
    carry = (h_mult[0] + (int64_t)(1<<25)) >>26;
    h_mult[1] += carry;
    h_mult[0] -= carry *((uint64_t) 1<<26);

    for(int i = 0; i < 10; i++)  h[i] = (int32_t) h_mult[i];
}