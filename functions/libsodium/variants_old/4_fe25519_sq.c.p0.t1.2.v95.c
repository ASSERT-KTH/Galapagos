fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t h_arr[10]; 

    for (int i = 0; i < 10; i++){
        h_arr[i] = f[i] * f[i];
    }

    int32_t carry_arr[10];

    for (int i = 0; i < 9; i++){
        carry_arr[i] = (h_arr[i] + (int64_t)(1<< ((i % 2 == 0) ? 25 : 24))) >> ((i % 2 == 0) ? 26 : 25);
        h_arr[i+1] += carry_arr[i];
        h_arr[i] -= carry_arr[i] * ((uint64_t) 1<< ((i % 2 == 0) ? 26 : 25));
    }

    carry_arr[9] = (h_arr[9] + (int64_t)(1<< 24)) >> 25;
    h_arr[0] += carry_arr[9] * 19;
    h_arr[9] -= carry_arr[9] * ((uint64_t) 1<< 25);

    h_arr[0] -= ((h_arr[0] + (int64_t)(1<< 25)) >> 26)*((uint64_t) 1<< 26);
    h_arr[1] += (h_arr[0] + (int64_t)(1<< 25)) >> 26;

    for (int i = 0; i < 10; i++){
        h[i] = h_arr[i];
    }
}