void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t fg[10][10] = { 0 };
    int64_t ex[10] = { 0 };

    for (int a=0;a<10;++a)
    {
        ex[a%2]     += (f[a]/2) * (19*((a%2==0)?2:1) * (g[a%2]/2));
        ex[(a+1)%2] += (f[a]/2) * g[(a+1)%2];
        for (int b=0;b<10;++b)
            fg[a][b] = f[a] * ((b==1 || b==3 || b==5 || b==7 || b==9) ? (g[b]*38) : g[b]);
    }

    int64_t sum = 0;
    int64_t carry = 0;
    for(int i=0; i<10; ++i)
    {
        sum = ex[(i+1)%2];
        for (int a=0; a<(10-i); ++a)
            sum += fg[a][i+a];
        for (int a=(10-i); a<5; ++a)
            sum += fg[a][(i+a)%10] * 19;
        for (int a=5; a>(10-i); a--)
            sum += fg[10+a][(i+a-10)%10] * 19;

        carry = sum >> ((i==2 || i==4 || i==6 || i==8) ? 26:25);
        h[i] = (int32_t)(sum - (carry << ((i==2 || i==4 || i==6 || i==8) ? 26:25));
        if(i<9)
            fg[i+1][0] += carry;
    }
    h[0] += (int32_t)(carry*19);
}