fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_arr[10];
    int32_t g_arr[10];
    int32_t h_arr[10];

    for (int i = 0; i < 10; i++) {
        f_arr[i] = f[i];
    }

    for (int i = 0; i < 10; i++) {
        g_arr[i] = g[i];
    }

    int32_t g1_19 = 19 * g_arr[1];
    int32_t g2_19 = 19 * g_arr[2];
    int32_t g3_19 = 19 * g_arr[3];
    int32_t g4_19 = 19 * g_arr[4];
    int32_t g5_19 = 19 * g_arr[5];
    int32_t g6_19 = 19 * g_arr[6];
    int32_t g7_19 = 19 * g_arr[7];
    int32_t g8_19 = 19 * g_arr[8];
    int32_t g9_19 = 19 * g_arr[9];
    int32_t f1_2  = 2 * f_arr[1];
    int32_t f3_2  = 2 * f_arr[3];
    int32_t f5_2  = 2 * f_arr[5];
    int32_t f7_2  = 2 * f_arr[7];
    int32_t f9_2  = 2 * f_arr[9];

    int64_t prod_arr[100] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(i!=j){
                if (i+j==9 || (i%2==1 && j%2==0 && j>i) || (i%2==0 && j%2==1 && i>j)) {
                    prod_arr[i*10+j] = 38L*f_arr[i]*g_arr[j];
                } else if ((i%2==1 && j%2==1) || (j%4==0)) {
                    prod_arr[i*10+j] = 19L*f_arr[i]*g_arr[j];
                } else {
                    prod_arr[i*10+j] = 1L*f_arr[i]*g_arr[j];
                }
                if(i%2==1 && j%2==1){
                    prod_arr[i*10+j] *= 2;
                }
            } else {
                prod_arr[i*10+j] = 1L*f_arr[i]*g_arr[j];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            h_arr[(i+j)%10] += prod_arr[i*10+j];
        }
    }

    for (int i = 0; i < 10; i++) {
        if ((h_arr[i]+(1<<(i%2==0?24:25))) > ((1L<<((i%2==0)?51:50))-1)) {
            h_arr[(i+1)%10] += 1;
            h_arr[i] -= (1 << (i%2==0?25:26));
        }
    }

    /* constant used for redducing values mod 2^255−19 */
    h_arr[0] += 19 * (h_arr[9] >> 24);
    h_arr[9] &= ((1 << 24) - 1);

    for (int i = 0; i < 10; i++) {
        h[i] = h_arr[i];
    }
}