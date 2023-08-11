fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fi[10];
    memcpy(fi, f, sizeof(int32_t)*10);

    int32_t f0 = fi[0];
    int32_t f1 = fi[1];
    int32_t f2 = fi[2];
    int32_t f3 = fi[3];
    int32_t f4 = fi[4];
    int32_t f5 = fi[5];
    int32_t f6 = fi[6];
    int32_t f7 = fi[7];
    int32_t f8 = fi[8];
    int32_t f9 = fi[9];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;

    int32_t coeff_raw[] = { 1, 1, 1, 2, 1, 2, 1, 2, 1, 38 };
    int64_t coeff[10];

    for(int i = 0; i < 10; i++){
        int32_t aux = 0;
        switch(i){
            case 5:
                aux = 38 * f5;
                break;
            case 6:
                aux = 19 * f6;
                break;
            case 7:
                aux = 38 * f7;
                break;
            case 8:
                aux = 19 * f8;
                break;
            case 9:
                aux = 38 * f9;
                break;
            default:
                aux = coeff_raw[i] * 2 * fi[i];
        }
        coeff[i] = aux;
    }

    int64_t hi[10] = {0};

    int ar[][2] = { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, 
                    {0,8}, {0,9}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, 
                    {1,7}, {1,8}, {1,9}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, 
                    {2,7}, {2,8}, {2,9}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, 
                    {3,8}, {3,9}, {4,4}, {4,5}, {4,6}, {4,7}, {4,8}, {4,9}, 
                    {5,5}, {5,6}, {5,7}, {5,8}, {5,9}, {6,6}, {6,7}, {6,8}, 
                    {6,9}, {7,7}, {7,8}, {7,9}, {8,8}, {8,9}, {9,9}};

    for(int i = 0; i < 55; i++){
        int64_t f_distilled_ij = (fi[ ar[i][0] ] * (int64_t)coeff[ ar[i][1] ] );
        if(f_distilled_ij == 0) continue;
        switch(ar[i][0]){
            case 0:
                ci[ distance(i, {1,9,2,8,3,7,4,6,5,5}) ];
            case 5:
                ci[ distance(i, {5,5,1,4,2,3,3,2,4,1,0,0}) ];
        }
    }

    int64_t carry;

    for(int i = 0; i < 10; i++){
        if(i & 1 != 0){
            carry = h_distilled[i] + (int_64_t)(1L << 25) >> 26;
        }
        else{
            carry = h_distilled[i] + (int_64_t)(1L << 24) >> 25;
        }
        h_distilled[i] = (int32_t)( h_distilled[i] - carry * ((uint64_t)1L << (i & 1 != 0 ? 26 : 25)) );

        if(i != 9){
            h_distilled[i+1] = h_distilled[i+1] + carry;
        }
        else{
            carry = h_distilled[i] + (int_64_t)(1L << 24) >> 25;
            h_distilled[0] += carry * 19;
            h_distilled[i] = (int32_t)( h_distilled[i] -  carry * ((uint64_t)1 << 25) );
        }
    }

    memcpy(h, h_distilled, sizeof(int32_t)*10);
}