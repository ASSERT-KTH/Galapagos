fe25519_sq(fe25519 h, const fe25519 f)
{
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

    int64_t h0 = f0 * (int64_t)f0 + 76*(int64_t)f1*f9 + 38*(int64_t)(f2*f8 + f3*f7 + f4*f6 + f5*f5);
    int64_t h1 = 2*f0*(int64_t)f1 + 76*(int64_t)f3*f8 + 38*(int64_t)(f2*f9 + f4*f7 + f5*f6);
    int64_t h2 = f1*f1 + 2*f0*(int64_t)f2 + 76*(int64_t)f3*f9 + 38*(int64_t)(f1*f1 + f4*f8 + f5*f7) + 19*(int64_t)f6*f6;
    int64_t h3 = 2*(f0*(int64_t)f3 + f1*(int64_t)f2) + 76*(int64_t)f4*f9 + 38*(int64_t)(f5*f8 + f6*f7);
    int64_t h4 = f2*f2 + 2*(f0*(int64_t)f4 + f1*(int64_t)f3) + 76*(int64_t)f5*f9 + 38*(int64_t)(f6*f8 + f7*f7);
    int64_t h5 = 2*(f0*(int64_t)f5 + f1*(int64_t)f4 + f2*(int64_t)f3) + 76*(int64_t)f6*f9 + 38*(int64_t)f7*f8;
    int64_t h6 = f3*f3 + 2*(f0*(int64_t)f6 + f1*(int64_t)f5 + f2*(int64_t)f4) + 76*(int64_t)f7*f9 + 19*(int64_t)f8*f8;
    int64_t h7 = 2*(f0*(int64_t)f7 + f1*(int64_t)f6 + f2*(int64_t)f5 + f3*(int64_t)f4) + 76*(int64_t)f8*f9;
    int64_t h8 = f4*f4 + 2*(f0*(int64_t)f8 + f1*(int64_t)f7 + f2*(int64_t)f6 + f3*(int64_t)f5) + 76*(int64_t)f9*f9;
    int64_t h9 = 2*(f0*(int64_t)f9 + f1*(int64_t)f8 + f2*(int64_t)f7 + f3*f6 + f4*f5);

    int64_t carry[10];
    for(int32_t i=0;i<10;i++)
    {
        carry[i] = (h[i] + (int64_t)(1<<24-((i+1)%2))/2) >> 25-((i+1)%2);
        h[(i+1)%10] += carry[i];
        h[i] -= carry[i] * ((uint64_t) 1L << (25-((i+1)%2)));
    }
    carry[9] = (h[9] + (int64_t)(1L << 24)) >> 25;
    h[0] += carry[9] * 19;
    h[9] -= carry[9] << 25;
    carry[0] = (h[0] + (int64_t)(1L << 25)) >> 26;
    h[1] += carry[0];

    for(int32_t i=0;i<10;i++) h[i] -= carry[(i-1+10)%10] << 26;

    for(int32_t i=0;i<10;i++) h[i] = (int32_t) h[i];
}
