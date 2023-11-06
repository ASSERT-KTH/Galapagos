fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t *feAliased = (int32_t*)f;
    int32_t f0 = feAliased[0];
    int32_t f1 = feAliased[1];
    int32_t f2 = feAliased[2];
    int32_t f3 = feAliased[3];
    int32_t f4 = feAliased[4];
    int32_t f5 = feAliased[5];
    int32_t f6 = feAliased[6];
    int32_t f7 = feAliased[7];
    int32_t f8 = feAliased[8];
    int32_t f9 = feAliased[9];

    int32_t f_arr_mult_2[7] = {2 * f0, 2 * f1, 2 * f2, 2 * f3, 2 * f4, 2 * f5, 2 * f6};
    
    int32_t f_multiples[5] = {38 * f5, 19 * f6, 38 * f7, 19 * f8, 38 * f9};

    int64_t squares[10];

    for (int i = 0; i < 10; i++) {
        squares[i] = feAliased[i] * (int64_t) feAliased[i];
    }

    int64_t products_twiced[45];

    int64_t products_quatrupled[4] = {f_arr_mult_2[1] * (int64_t) f_arr_mult_2[3],
                                       f_arr_mult_2[1] * (int64_t) f_arr_mult_2[5],
                                       f_arr_mult_2[2] * (int64_t) f_arr_mult_2[3],
                                       f_arr_mult_2[2] * (int64_t) f_arr_mult_2[5]};
  
    for (int i = 0; i < 10; i++) {
        products_twiced[i] = f_arr_mult_2[i/2] * (int64_t) feAliased[i];
    }

    int64_t tfresult[10] = { squares[0]+products_twiced[18]+products_twiced[22]+products_quatrupled[2]+products_twiced[27]+products_twiced[30],
                            products_twiced[0]+products_twiced[20]+products_twiced[24]+products_twiced[28]+products_twiced[31],
                            products_twiced[1]+squares[1]+products_quatrupled[0]+products_twiced[25]+products_quatrupled[3]+squares[6],
                            products_twiced[2]+products_twiced[10]+products_twiced[26]+products_twiced[29]+products_twiced[32],
                            products_twiced[3]+products_quatrupled[1]+squares[2]+products_twiced[33]+products_twiced[34]+squares[7],
                            products_twiced[4]+products_twiced[15]+products_twiced[23]+products_twiced[35]+products_twiced[36],
                            products_twiced[5]+products_quatrupled[2]+products_twiced[19]+products_quatrupled[3]+squares[3]+squares[8],
                            products_twiced[7]+products_twiced[21]+products_twiced[30]+products_twiced[37]+f_multiples[3],
                            products_twiced[8]+products_quatrupled[1]+products_twiced[22]+products_quatrupled[0]+squares[4]+products_twiced[38],
                            products_twiced[9]+products_twiced[16]+products_twiced[25]+products_twiced[28]+products_twiced[34]};

    int64_t carries[10];

    for (int i = 0; i < 10; i++) {
        carries[i] = (tfresult[i] + (int64_t)(1 << ((i % 2 + 1) * 25))) >> ((i % 2 + 1) * 25 + 1);
        tfresult[(i + 1) % 10] += carries[i];
        tfresult[i] -= carries[i] *((uint64_t) 1 << ((i % 2 + 1) * 25 + 1));
    }

    tfresult[0] += carries[9] * 19;
    carries[0] = (tfresult[0] + (int64_t)(((uint64_t) 1L << 25))) >> 26;
    tfresult[1] += carries[0];
    tfresult[0] -= carries[0] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t)tfresult[i];
    }
}