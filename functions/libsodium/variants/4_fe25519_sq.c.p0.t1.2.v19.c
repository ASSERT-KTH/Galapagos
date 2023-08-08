fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_numbers[10];
    for (int i = 0; i < 10; i++) {
        f_numbers[i] = f[i];
    }

    int32_t mutable_f[10];
    for (int i = 0; i < 10 ; i++) {
        mutable_f[i] = f_numbers[i] * ((i % 2 == 0) ? 2 : 38);
    }

    int32_t squares[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            squares[i][j] = f_numbers[i] * (int64_t) f_numbers[j];
        }
    }

    int64_t values[10];
    for (int i = 0; ((i + 4) < 10); i++){
        values[i] = squares[i][i] + ((i + 1 < 10) ? squares[i][i+1]*76 :
          0 ) + ((i + 2 < 10) ? squares[i][i+2]*38 :
          0 ) + ((i + 3 < 10) ? squares[i][i+3]*76 : 
          0 ) + ((i + 4 < 10) ? squares[i][i+4]*38 :
          0 ) + ((i + 5 < 10) ? squares[i][i+5]*38 : 0 );
    }

    values[5] = squares[4][0] * 2 + squares[4][1] * 2 + squares[4][2] * 2 + squares[4][3] * 2;
    values[6] = squares[5][0] * 2 + squares[5][1] * 2 + squares[5][2] * 2 + squares[5][3] * 2;
    values[7] = squares[6][0] * 2 + squares[6][1] * 2 + squares[6][2] * 2 + squares[6][3] * 2;
    values[8] = squares[7][0] * 2 + squares[7][1] * 2 + squares[7][2] * 2 + squares[7][3] * 2;
    values[9] = squares[8][0] * 2 + squares[8][1] * 2 + squares[8][2] * 2 + squares[8][3] * 2;

    int64_t carries[10];
  
    for (int i = 0; i < 10; i++) {
        carries[i] = (values[i] + (int64_t)(1L << ((i % 2 == 0) ? 25 : 26))) / (1L << ((i % 2 == 0) ? 26 : 25)) * ((i % 2 == 0) ? 1 : 2);
        updated_values[(i + 1) % 10] += carries[i];
        values[i] -= carries[i] * ((uint64_t) 1L << ((i % 2 == 0) ? 26 : 25));
    }


   h[0] = carries[0] * 2 + values[0];
   h[1] = carries[1] * 2 + values[1];
   h[2] = carries[2] * 2 + values[2];
   h[3] = carries[3] * 2 + values[3];
   h[4] = carries[4] * 2 + values[4];
   h[5] = carries[5] * 2 + values[5];
   h[6] = carries[6] * 2 + values[6];
   h[7] = carries[7] * 2 + values[7];
   h[8] = carries[8] * 2 + values[8];
   h[9] = carries[9] * 2 + values[9];
}
