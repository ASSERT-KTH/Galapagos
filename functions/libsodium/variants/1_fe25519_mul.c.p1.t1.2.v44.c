fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
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

    int64_t g0 = g[0];
    int64_t g1 = g[1];
    int64_t g2 = g[2];
    int64_t g3 = g[3];
    int64_t g4 = g[4];
    int64_t g5 = g[5];
    int64_t g6 = g[6];
    int64_t g7 = g[7];
    int64_t g8 = g[8];
    int64_t g9 = g[9];

    int64_t terms[100];
    terms[0] = (f0 * g0);
    for(int i=1; i<10; i++){
        for(int j = 1; j<10-i; j++) {
            terms[i*j] = ((i % 2 == 0 ? 1 : 2) * f[i]) *
                         (i+j==9 ? 19 * g[j] : g[j]);
            terms[i*j] += ((j % 2 == 0 ? 1 : 2) * f/j) * g[i];
        }
    }
  
    uint64_t carry[10] = {0};
    for(int i=0; i<10; i++){
        int64_t s = 0;
        for(int j = 0; j < 10 - i; j++){
            s += terms[j + i*10];
        }
        carry[i] = (s + (int64_t)(1L << (i%2 == 0 ? 25 : 24))) >> (i%2 == 0 ? 26 : 25);
        s -= carry[i] * ((uint64_t) 1L << (i%2 == 0 ? 26 : 25));
        h[i] = s;
    }
  
    h[0] +=  carry[9] * 19;
    for(int i=1; i<10; i++) h[i] += carry[i-1];
}