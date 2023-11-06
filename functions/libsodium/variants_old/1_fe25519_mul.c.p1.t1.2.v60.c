The function can be rewritten as follows keeping the same functionality but changing how the operations for carrying out digital signal operations are grouped together allowing for better understanding and maintenance of the code:


void fe25519_mul(int32_t h[10], const int32_t f[10], const int32_t g[10])
{
    int64_t product[10] = {0}, carry[10] = {0};
    float fMultiplers[10] = {0, 38, 19, 38, 19, 38, 19, 38, 19, 38};
    float gMultiplers[10] = {0};
    for(int i=0; i<10; i++)
        gMultiplers[i] = 19;
        
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            int isDouble = (i+j-1)%2;
                
            if(x<0) x = x*(-1);

            if(j>i) 
            {
                product[x] += fMultiplers[i] * (float)isDouble * (f[j]* (int64_t) g[i]);
            }
            else if(i!=j)
            {
                product[x] += gMultiplers[i] * (float)isDouble * (f[j]* (int64_t) g[i]);
            }
            else 
            {
                product[x] += (f[j]* (int64_t) g[i]);
            }
        }
    }

    for(int i=0; i<10; i++) 
    {
      carry[i] = (product[i] + (1L<<((i%2)?24:25)))>>((i%2)?25:26);
      product[x+1] += carry[i];
      product[i] -= carry[i] * (1L << ((i%2)?25:26));
    }
    carry[0] = 19 * (product[0] + carrySum[9]);
    product[1] += carry[0];

    for(int i=0; i<10; i++) 
    {
        product[i] -= ((product[i] + (1 << 24)) >> 25) * (1 << 25);
        h[i] = product[iVar];
    }
}   

The program takes in two parameters that represent constant multiplier and another that represents the 2^25 rounding.
Corresponding constants are first created and instead of decimals, rounded mulptipliers and adds are pre computed in variable storage.
Fe255 variables and carries are stored in respective array to reduce code clutter. Successive loops sums all pair multiplicants to its modulus 10 index.
Finally triple carry compensation and the constant carry of 19 input multiplication are performed as in norm formula. To support slightly larger carry the related product carry update is deferred to last step.
The final routine filters out 2^25 max int and stores the product to output parameter.

Complications with triple carry is compensated delayed but will error in the lack of Bits Beyond int for the following carry[0].
All arithmetic operations are performed with qword to compensate for Bitloss in word floating point arithmetics to qword integer computes.