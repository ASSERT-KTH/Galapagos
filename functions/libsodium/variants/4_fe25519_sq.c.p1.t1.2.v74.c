#define _2(X) ((X)<<1)
#define _19(X) ((X)*19)
#define _38(X) ((X)*38)
#define ___add_from(h, f0f0, f0__[ae]_4, f2fc_4, f80__[ai]_76, faf[bi]_76, fcfd_76 )  h += f0f0 + f0f1_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
#define ___swap(x) t = x; x = _19(x); x = t

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t t;
    int32_t L[20];
    int i,j;
    for(i=0;i<10;i++)
        L[i] = f[i];
    for(i=0;i<5;i++)
    {
        L[10+2*i] = _2(L[i]);
        L[11+2*i] = _38(L[i+5]);
    }
    for(i=0;i<10;i++)
        for(j=0;j<=i;j++)
            h[i+j] += L[i]*L[j];
    for(i=0;i<9;i++)
        L[10+i] += _2(h[10+i]);

    // final carry
    {
        int64_t c = h[9];
        c = (c + (int64_t)(1L << 24)) >> 25;
        h[0] += c * 19;
        h[9] -= c * ((uint64_t) 1L << 25);
    }
    for(i=0;i<10;i++)
    {
        int64_t c = h[i];
        c = (c + (int64_t)(1L << 25) -(i&1)) >> 26;
        h[i+1] += c;
        h[i] = c<<(26 ^ (i&1));
    }
}