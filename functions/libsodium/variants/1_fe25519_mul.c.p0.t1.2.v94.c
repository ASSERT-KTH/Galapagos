fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_[10] = { f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9] };

    int32_t g_[10] = { g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9] };

    for(int i=1; i<10; i+=2) {
        f_[i] = 2*f_[i];
    }

    int32_t g1_19 = 29; /* 1.959375*2^29 */
    int32_t g2_19 = 30; /* 1.959375*2^30; still ok */
    for(int i=2; i<4; i++) {
        g_[i] = 19*g_[i];
    }
    int32_t g1_2  = 2 * g_[1];
    int32_t g3_2  = 2 * g_[3];
    int32_t g5_2  = 2 * g_[5];
    int32_t g7_2  = 2 * g_[7];
    int32_t g9_2  = 2 * g_[9];

    for(int i=4; i<10; i++) {
        g_[i] = 19*g_[i];
    }

    size_t len=81;
    int64_t fg[81]={0};

    int fg_pos[45][2] = {{0, 0}, {0, 1},    {1, 0}, { 0, 2}, {2, 0}, {0, 3}, {3, 0},
                         {0, 4}, {4, 0},    {1, 1}, { 2, 1}, {1, 2}, {2, 2}, {3, 1},
                         {1, 3}, {3, 2},    {2, 3}, { 3, 3}, {4, 1}, {1, 4}, {5, 0},
                         {0, 5}, {4, 2},    {2, 4}, { 5, 1}, {1, 5}, {3, 4}, {4, 3},
                         {0, 6}, {5, 2},    {2, 5}, { 6, 0}, {6, 1}, {1, 6}, {3, 5},
                         {5, 3}, {4, 4},    {0, 7}, { 6, 2}, {7, 0}, {2, 6}, {7, 1},
                         {1, 7}, {3, 6},    {6, 3}, {4, 5}, {5, 4}};

    for(size_t i=0;i<45;i++) {
        int xpos = fg_pos[i][0];
        int ypos = fg_pos[i][1];
        fg[(xpos*10+ypos)%len] += (xpos%2==0?1:2) * f_[xpos] * g_[ypos];
    }

    int64_t carry[len]={0};

    // performing carry operations
    for(size_t i = 0;i < len; i++){
        carry[(i+1)%len] = (fg[i] + (int64_t) (1 << 24)) >> 25;
        fg[i+1] += carry[i];
        fg[i] -= carry[i] * ((uint64_t) (1 << 25));
    }

    for(int i=0; i<10; ++i){
        h[i] = fg[i];
    }
}