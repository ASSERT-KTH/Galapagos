
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t carry[10];
    int64_t prod[10];
    int32_t fval[10], gval[10];
    for(int i=0; i<10; i++)
    {
        fval[i] = f[i];
        gval[i] = g[i];
    }

    int32_t gval19[10] = {gval[0],19*gval[1],19*gval[2],19*gval[3],19*gval[4],19*gval[5],19*gval[6],19*gval[7],19*gval[8],19*gval[9]};
    int32_t fval2[10] = {fval[0],2*fval[1],fval[2],2*fval[3],fval[4],2*fval[5],fval[6],2*fval[7],fval[8],2*fval[9]};

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            {if((j==1 || j==3 || j==5 || j==7 || j==9) &&(j==1 || j==3 || j==5 || j==7 || j==9))
                prod[i+j] = fval2[i/2] * (int64_t)gval[i%2];
            else if((i==1 || i==3 || i==5 || i==7 || i==9) && (i==1 || i==3 || i==5 || i==7 || i==9))
                prod[i+j] = fval[i/2] * (int64_t)gval19[i%2];
            else
                prod[i+j] = fval[i] * (int64_t)gval[j];
            }

    for(int i=0; i<9; i++)
    {
        carry[i] = (prod[i] + (int64_t)(1L << 24+i%2)) >> (25+!(i%2));
        prod[i+1] += carry[i];
        prod[i] -= carry[i] * ((uint64_t) 1L << (25+!(i%2)));
    }

    carry[9] = (prod[9] + (int64_t)(1L << 24)) >> 25;
    prod[0] += carry[9]*19;
    prod[9] -= carry[9] * ((uint64_t) 1L << 25);

    carry[0] = (prod[0] + (int64_t)(1L << 25)) >> 26;
    prod[1] += carry[0];
    prod[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i=0;i<10;i++)
        h[i]=(int32_t) prod[i];
}

Different transformations can be made. The one above tries to minimize code repetition by using loops for some repetitive operations.