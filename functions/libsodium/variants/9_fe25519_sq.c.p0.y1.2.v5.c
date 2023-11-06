void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0 = f[0];
    int64_t f1 = f[1];
    int64_t f2 = f[2];
    int64_t f3 = f[3];
    int64_t f4 = f[4];
    int64_t f5 = f[5];
    int64_t f6 = f[6];
    int64_t f7 = f[7];
    int64_t f8 = f[8];
    int64_t f9 = f[9];

    int64_t mult_res_arr[45];
    for(int i = 0; i < 10; ++i)
        for(int j = i ,coef = (j==i) ? 1 : 2; j < 10; ++j )
            mult_res_arr[i * 9 + j] = coef * mult_safe(f[i], f[j]);

    int64_t add_res_arr[10] = {0};
    add_res_arr[0] = add_rg_elem(mult_res_arr, {0, 4, 16, 9, 30, 25});
    add_res_arr[1] = add_rg_elem(mult_res_arr, {1, 18, 10, 27, 17});
    add_res_arr[2] = add_rg_elem(mult_res_arr, {2, 20, 3, 32, 11, 36, 13});
    add_res_arr[3] = add_rg_elem(mult_res_arr, {19, 5, 22, 7, 34, 15});
    add_res_arr[4] = add_rg_elem(mult_res_arr, {36, 14, 4, 24, 8, 33, 9});
    add_res_arr[5] = add_rg_elem(mult_res_arr, {21, 6, 26, 10, 35, 12});
    add_res_arr[6] = add_rg_elem(mult_res_arr, {6, 24, 37, 11, 7, 30, 8, 39, 13});
    add_res_arr[7] = add_rg_elem(mult_res_arr, {23, 7, 31, 12, 24, 22, 9});
    add_res_arr[8] = add_rg_elem(mult_res_arr, {38, 12, 8, 33, 9, 28, 14, 4, 39});
    add_res_arr[9] = add_rg_elem(mult_res_arr, {25, 10, 34, 14, 29, 17, 5, 22});

    For64bitBitsShift(add_res_arr,10,{1<< 25,1<< 24, 1 << 25, 1 << 24, 1<< 25, 1<< 24, 1 << 25, 1 << 24, 1<< 25});

    add_res_arr[0] += idiv(mult_res_arr, 9, 1 << 25) * 19;

    For64bitBitsShift(add_res_arr,1,{1<< 25});

    for (int i = 0; i < 10; i++) h[i] = (int32_t)add_res_arr[i];
}