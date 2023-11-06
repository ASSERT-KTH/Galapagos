The current function definition bounds all arithmetic operations within the range of int32_t. Any variant program that maintains the original functionality needs to respect this bound and operate on each digit individually. An approach to vary the program can be running multiple threads to process these arithmetic operations in a parallel manner, but this will substantially lengthen the program and require heavy modification to the current function.

Progessively stacking the operations in multiple instructions by variables and delaying the integer truncations can be another way of introducing a different behavior. In this case, as the intXX_t specific truncating and rounding loses information, which negatively affects precision of the computation.

The given variant of `fe25519_mul` will perform similar operations, but not in the order as was previously defined. It computes all multiplications in the first part of the function, then computes each 64bit large field element and then executes integer reduction. This last step therefore performs all carry-propagitations in sequence, which reduces integer overhead by factor 9.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t tmp[10];  

    for (int i = 0; i < 10; ++i)
    {
        tmp[i] = 0;
        for (int j = 0; j < 10; ++j)
        {
            if(i+j >= 10)
                tmp[i] += 19*(int64_t)f[j]*g[i+j-10];
            else
                tmp[i] += (int64_t)f[j]*g[i+j];
           	if(j&1 && j < i) 
   	       		tmp[i] *= 2;
        }
    }
    
    int64_t carry;
  
    for (int i = 0; i < 9; ++i)
    {
        carry = tmp[i] >> 26;
        tmp[(i + 1)%10] += carry;
        tmp[i] -= carry << 26;
    }
    tmp[0] += (tmp[9] >> 25) * 19;
    tmp[9] &= (1 << 25) - 1;
   
    for (int i = 0; i < 10; ++i)
    {
        h[i] = tmp[i];
    }
}


Function computes up to high integer precision and then reduces mod p in the final steps. That way we can follow overall gains in the precision and introduce completely different property behavior.