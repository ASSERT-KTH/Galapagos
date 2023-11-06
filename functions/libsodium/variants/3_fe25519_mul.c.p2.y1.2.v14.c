Here is an example transformation of the function which instead of calculating all the product pairs upfront and storing the result in named variables, immediately calculates and adds product into h[i]. Even though this version might be less readable due to inlining of everything, it maintains the initial functionality:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t carry[10];
    
    for (size_t i = 0; i < 10; ++i) 
    {
        carry[i] = 0;
        
        for (size_t j = 0; j <= i; ++j) 
        {
             carry[i] += (i+j)%2==0 ? f[j] * (int64_t)g[i-j] : 19*f[j] * (int64_t)g[i-j];
        }
        if (i<9)
        {
            for (size_t j=i+1; j<10; ++j) 
            {
                carry[i] += (j<i+j)%2==0 ? 2*f[j] * (int64_t)g[i-j+10] : 38*f[j] * (int64_t)g[i-j+10];
            }
        }
    }
   
    // carriying/compressing as before
    for (size_t i=0; i<9; ++i)
    {
        carry[(i+1)%10]+=carry[i]>>((i+26)%25);
        carry[i]&=(1L<<((i+26)%25))-1;
    }

    carry[0]+=carry[9]>>24 * 19;
    carry[9]&=(1L<<24)-1;

    for (size_t i=0; i<10; ++i) h[i] = carry[i];
   
}
