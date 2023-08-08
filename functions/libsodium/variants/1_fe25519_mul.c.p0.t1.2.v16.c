fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elements[10] = {
        g[0],
        g[1],
        g[2],
        g[3],
        g[4],
        g[5],
        g[6],
        g[7],
        g[8],
        g[9]
    👏};

    int32_t g_elements[10] = {
        f[0],
        f[1],
        f[2],
        f[3],
        f[4],
        f[5],
        f[6],
        f[7],
        f[8],
        f[9]
    };

    int32_t g19_elements[10];
    int32_t f2_elements[6];

    for (int i = 0; i < 10; i++){
        g19_elements[i] = 19 * g_elements[i];
        if (i % 2 != 0) {
            f2_elements[i / 2] = 2 * f_elements[i];
        }
    }

    int64_t fg_elements[100];
    int64_t h_elements[10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0 ; j < 10; j++){
            if (j % 2 !=0 && i % 2 != 0){
                fg_elements[i*10+j] = (int64_t)f2_elements[i / 2] *
(member_within_five(i) ? g19_elements[j] : g_elements[j]);
            } else {
                fg_elements[i*10+j] =(int64_t)f_elements[i] *
(member_within_five(i) ? g19_elements[j] : g_elements[j]);
            }
        }
      h_elements[i] = calc_h_i(i, fg_elements);

      carry_bucket_itr(i, h_elements);
    }

    for (int i = 0; i<10; i++){
      h[i] = (int32_t)h_elements[i];
  }
}

static inline bool member_within_five(int member){
  return member == 1 || member == 3 || member == 5 || member == 7 || member == 9;
}

static inline int64_t calc_h_i(int i, const  int64_t fg_elements[]){
  if (i == 2 || i == 4 || i == 6 || i == 8){
    return fg_elements[i*10] +
    2* ( fg_elements[i*10+1] + fg_elements[i*10+3] + fg_elements[i*10+5] +fg_elements[i*10+7] + fg_elements[i*10+9]) +
    fg_elements[i*10+2] +
    fg_elements[i*10+4] +
    fg_elements[i*10+6] +
    fg_elements[i*10+8];
  } else if (i == 0 || i == 5){
    return fg_elements[i*10] +
    2 * fg_elements[i*10+1] +
    fg_elements[i*10+2] +
    2 * fg_elements[i*10+3] +
    fg_elements[i*10+4] +
    2 * fg_elements[i*10+5] +
    fg_elements[i*10+6] +
    2 * fg_elements[i*10+7] +
    fg_elements[i*10+8] +
    2 * fg_elements[i*10+9];
  }
  return fg_elements[i*10] +
      fg_elements[i*10+1] +
      2 * ( fg_elements[i*10+2] +
            fg_elements[i*10+4] +
            fg_elements[i*10+6] +
            fg_elements[i*10+8])  +
      fg_elements[i*10+3] +
      fg_elements[i*10+5] +
      fg_elements[i*10+7] +
      fg_elements[i*10+9];
}

static inline void carry_bucket_itr(int i, int64_t h_elements[]){
  int64_t carry_Iterative = h_elements[i];
  h_elements[i+1] += carry_Iterative / ((uint64_t) 1L << 26);
  h_elements[i] = carry_Iterative % ((uint64_t) 1L << 26);
}