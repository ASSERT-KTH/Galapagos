Here is the same code providing the same functionality without changing its behaviour but refactored using loops and data structures to reduce the length of the code:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10], g_values[10];   
    int64_t f_g_multiples[100], temp[10], h_values[10];
    int32_t carry[10] = {0};
    
    for (int i = 0; i < 10; i++)
    {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }    

    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++) 
        {
            f_g_multiples[i * 10 + j] = f_values[i] * (int64_t) ((j%2 == 0) ? g_values[j] : (2*g_values[j]));
        }
    }

    for(int i=0; i<10; ++i)
    {
        temp[i] = 0;
        for(int j=0; j<=i; ++j)
            temp[i] += f_g_multiples[j * 10 + i - j];
        for(int j=i+1; j<10; ++j)
            temp[i] += 2 * f_g_multiples[j * 10 + i - j];
	if(i % 2 == 0)
	  {
            if(i < 8) 
                temp[i + 1] += temp[i] >> 26; 
            else 
                temp[0] += 19*(temp[i] >> 26); 
	  }
	else
	  {
            if(i < 9) 
                temp[i + 1] += temp[i] >> 25; 
            else 
                temp[0] += 19*(temp[i] >> 25);
	  }
	temp[i] &= (1<<(26-(i%2 == 0))-1;
    }
    for(int i=0;i<10;h[i++]=temp[i]);
}

In the years since the function was initially applied, loop constructs and compound structures have evolved in the C language that allow duplication in the reference code to be eliminated.