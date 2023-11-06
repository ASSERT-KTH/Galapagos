void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t f_numbers[10], g_numbers[10];
    for (int i = 0; i < 10; i++) {
        f_numbers[i] = f[i];
        g_numbers[i] = g[i];
    }

    int32_t g_times_19[10], f_times_2[5];
    int64_t multiplications[95], h_temp[10];
    for (int i = 1; i < 10; i++) {
        g_times_19[i] = 19 * g_numbers[i];
    }
    for (int i = 1; i < 5; i++) {
        f_times_2[i] = 2 * f_numbers[2 * i - 1];
    }

    int t = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++, t++) {
            if (i == j)
                multiplications[t] = f_numbers[i] * (int64_t)g_numbers[j];
            else if (i == 0 || i % 2 == 0){  
                multiplications[t] = f_numbers[i] * (int64_t)g_numbers[j];
                if (j != i + 1 || i == 8){
                    multiplications[t] += f_numbers[j] * (int64_t)g_numbers[i];
                }else{
                    multiplications[t] += f_times_2[j / 2] * (int64_t)g_times_19[i];
                }
            }

        }
    }

    static int index_list[10][10] = {
        {0, 10, 19, 27, 34, 40, 45, 49, 52, 54},
        {1, 11, 20, 28, 35, 41, 46, 50, 53,555},
        {2, 12, 21, 29, 36, 42, 47, 51, 55,-1},
        {3, 13, 22, 30, 37, 43, 48, 56,-1,-1},
        {4, 14, 23, 31, 38, 44, 49, 57,-1,-1},
        {5, 15, 24, 32, 39, 45, 58, -1, -1, -1},
        {6, 16, 25, 33, 40, 59, -1, -1, -1, -1},
        {7, 17, 26, 34, 60, -1, -1,-1,-1,-1},
        {8, 18, 27, 61, -1, -1, -1,-1,-1,-1},
        {9, 28, 62, -1, -1, -1, -1,-1,-1,-1},
    };
    for(int i=0;i<10;i++)
    {
        h_temp[i]=0;
        for(int j=0;j<10;j++)
        {
            if(index_list[i][j]!=-1)
                h_temp[i]+=multiplications[index_list[i][j]];
        }
    }

    int64_t carry[10];
    static int carry_list[10] = {26, 25, 26, 25, 26, 25, 26, 25, 26, 25};
    for (int i = 0; i < 9; i++) {
        carry[i] = (h_temp[i] + (int64_t)(1L << carry_list[i] - 1)) >> carry_list[i];
        h_temp[i + 1] += carry[i];
        h_temp[i] -= carry[i] * ((uint64_t)1L << carry_list[i]);
    }
    carry[9] = (h_temp[9] + (int64_t)(1L << 24)) >> 25;
    h_temp[0] += carry[9] * 19;
    h_temp[9] -= carry[9] * ((uint64_t)1L << 25);
    carry[0] = (h_temp[0] + (int64_t)(1L << 25)) >> 26;
    h_temp[1] += carry[0];
    h_temp[0] -= carry[0] * ((uint64_t)1L << 26);

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t)h_temp[i];
    }
}