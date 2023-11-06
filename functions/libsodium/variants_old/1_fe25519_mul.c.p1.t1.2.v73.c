You can maintain the functionality of the original function while changing its behaviour in various ways. 

A common and simple way to do this is to change the order of operations without changing the calculations done. Of course, this will change the function's behavior (since order of operation is part of behaviour), but it will not affect the final output (which always sums the elements at the corresponding indexes thus maintaining the property of commutativity) according to its functionality parameter.

Given the code example provided, you can replace most of the calculation with two `for` loops combining vital computation parts inside as listed below:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_mul[10];
    int32_t g_mul[10];
    int64_t h_mul[10] = {0};

    for(int i = 0, ind = 0; i < 10; i++)
    {
        // Calculating corresponding pairs of arguements f[i] , g[i] coefficients 
        f_mul[ind] = (i & 1) ? f[ind]<<1 : f[ind] ;
        g_mul[ind] = (i & 1) ? 19 * g[ind] : g[ind];

        // Intermediate steps for preparation of later terms in sum 
        for(int j = 0; j <= i; j++)
        {
            h_mul[ind] += f_mul[j