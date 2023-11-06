Sure, you can refactor the function while maintaining its functionality. Here's a variant implementation which uses a loop to accomplish much of the original function's repeated code:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fg[10][10];
    int64_t h_acc[10] = {0};

    for (int i = 0; i < 10; ++i)
    {   
        int j;
        for (j = 0; j < 10; ++j)
        {
            int64_t mult = (int64_t)f[i] * (int64_t) g[j];

            if ((1==j||0==j)&&(i % 2 == 0))
                mult *= 19;

            if ((1==j||0==j)&&(i%2==1))
                mult *= 38;
            
            fg[i][j] = mult;
        }   
    }

    for (int i = 9; i > 0; --i)
    {   
        int j;
        for (j = i ; j < 10; ++j)
        {
            h_acc[(i+j)%10] += fg[i][j];
            h_acc[(i+j-1)%10] += fg[i][j-i] * 38;
        }
    }

    for(int i = 0; i < 10; ++i)
    {   
        int64_t carry = (h_acc[i] + (int64_t)(1L <<((i <=2 || i == 5 || i == 6)?25:24)))  >>(i < 5? 25:24);
        h_acc[i+1] += carry;

        if(i!=9)
            h_acc[i] -= carry * ((uint64_t) 1L << (i < 5? 25:24));
        else
            h_acc[0] += 19 * carry;

        if(i > 2 && 7 > i && i % 2 == 0)
            h_acc[i+1] += carry * ((uint64_t) 1L << 25); //calcualate twice carry

        h[i] = (int32_t) h_acc[(i==9? 0 :i)];
    }
}


This refactoring using loop and matrix will be more concise and easier to understand, hoping to achieve the same effect as the original function.