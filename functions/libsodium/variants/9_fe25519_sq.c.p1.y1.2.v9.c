Here's one variant - here computation processes of h0 to h9 are grouped together:


void fe25519_sq(fe25519 h, const fe25519 f){
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5;  
    int32_t f6_19 = 19 * f6; 
    int32_t f7_38 = 38 * f7; 
    int32_t f8_19 = 19 * f8; 
    int32_t f9_38 = 38 * f9;

    int64_t carry[10];
    for (int i = 0 ; i<10 ; i++){
    carry[i] = 0;
    }

    int64_t h_values[10];


    int64_t computations[131] = {f0 * (int64_t) f0, f0_2 * (int64_t) f1, f0_2 * (int64_t) f2, f0_2 * (int64_t) f3, f0_2 * (int64_t) f4,
                              f0_2 * (int64_t) f5, f0_2 * (int64_t) f6, f0_2 * (int64_t) f7, f0_2 * (int64_t) f8, f0_2 * (int64_t) f9,
                              f1_2 * (int64_t) f1, f1_2 * (int64_t) f2, f1_2 * (int64_t) f3_2, f1_2 * (int64_t) f4, f1_2 * (int64_t) f5_2,
                              f1_2 * (int64_t) f6, f1_2 * (int64_t) f7_2, f1_2 * (int64_t) f8, f1_2 * (int64_t) f9_38, f2 * (int64_t) f2,
                              f2_2 * (int64_t) f3, f2_2 * (int64_t) f4, f2_2 * (int64_t) f5, f2_2 * (int64_t) f6, f2_2 * (int64_t) f7,
                              f2_2 * (int64_t) f8_19, f2 * (int64_t) f9_38, f3_2 * (int64_t) f3, f3_2 * (int64_t) f4, f3_2 * (int64_t) f5_2,
                              f3_2 * (int64_t) f6, f3_2 * (int64_t) f7_38, f3_2 * (int64_t) f8_19, f3_2 * (int64_t) f9_38, f4 * (int64_t) f4,
                              f4_2 * (int64_t) f5, f4_2 * (int64_t) f6_19, f4 * (int64_t) f7_38, f4_2 * (int64_t) f8_19, f4 * (int64_t) f9_38,
                              f5 * (int64_t) f5_38, f5_2 * (int64_t) f6_19, f5_2 * (int64_t) f7_38, f5_2 * (int64_t) f8_19, f5_2 * (int64_t) f9_38,
                              f6 * (int64_t) f6_19, f6 * (int64_t) f7_38, f6_2 * (int64_t) f8_19, f6 * (int64_t) f9_38, f7 * (int64_t) f7_38,
                              f7_2 * (int64_t) f8_19, f7_2 * (int64_t) f9_38, f8 * (int64_t) f8_19, f8 * (int64_t) f9_38, f9 * (int64_t) f9_38};

    int indexes[10][6] = {{0, 10, 21, 34, 45, 55}, {1, 11, 22, 35, 46}, {2, 11, 23, 36, 47, 58}, {3, 13, 24, 37, 48},
                      {4, 13, 23, 38, 50, 59}, {5, 14, 25, 39, 51}, {6, 15, 26, 36, 51, 60}, {7, 16, 27, 40, 52}, 
                      {8, 17, 28, 37, 41, 53, 61}, {9, 18, 29, 38, 42, 52}};

    for(int j = 0 ; j < 10 ; j++)
    {
    h_values[j] = 0;
    if (j == 1 || j == 5 || j == 9)
    {
        for (int i = 0 ; i < 5 ; i++){
            h_values[j] += computations[indexes[j][i]];
        }
    }
    else if(j == 0 || j == 4 || j == 8)
    {
        for (int i = 0 ; i < 6 ; i++){
            h_values[j] += computations[indexes[j][i]];
        }
    }
    else{
        for (int i = 0 ; i < 5 ; i++){
            h_values[j] += computations[indexes[j][i]];
        }
    }
    }

    for(int j = 0; j < 10 ; j++){
        if(j%2 ==0){
            carry[j] = (h_values[j] + (int64_t)(1L << 25)) >> 26;
            h_values[(j+1)%10] += carry[j];
            h_values[j] -= carry[j] *((uint64_t) 1L << 26);
        }
        else{
            carry[j] = (h_values[j] + (int64_t)(1L << 24)) >> 25;
            h_values[(j+1)%10] += carry[j];
            h_values[j] -= carry[j] *((uint64_t) 1L << 25);
        }
    }
    carry[9] = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += carry[9] *19;
    h_values[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry[0];
    h_values[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int j =0 ; j < 10 ; j++){
        h[j] = (int32_t) h_values[j];
    }
}

This variant uses single 2-D array (for return value h[n]) and single 1-D array to hold products of different combinations of f[i], f[j] terms. Operations of each h[i] are grouped together to respect data locality and enhance readability.