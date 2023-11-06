Here is a program variant to the function:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffff;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f_values[5];
    uint128_t r_values[5];
    uint64_t r_index[5];
    uint64_t carry=0;
    
    for(int i=0; i<5; i++) f_values[i] = f[i];

    f0 = f_values[0];
    f1 = f_values[1];
    f2 = f_values[2];
    f3 = f_values[3];
    f4 = f_values[4];

    r_values[0] =  f0*f0 + 38ULL*f1*f4 + 38ULL*f2*f3;
    r_values[1] = 2ULL*f0*f1 + 38ULL*f4*f2 + 19ULL*f3*f3;
    r_values[2] = 2ULL*f0*f2 + f1*f1 + 38ULL*f3*f4;
    r_values[3] = 2ULL*f0*f3 + 2ULL*f1*f2 + 19ULL*f4*f4;
    r_values[4] = 2ULL*f0*f4 + 2ULL*f1*f3 + f2*f2;

    for(int i=0; i<5; i++)
    {
        r_index[i] =  r_values[i] & mask;
        carry = r_values[i] >> 51;     //check only for i!=4
        if(i<4)
        {
            r_values[i+1]+= carry;
        }
    }
    r_index[0] += 19ULL*carry;
    carry = r_index[0] >> 51;
    r_index[0] = r_index[0] & mask;
    r_index[1] += carry;
    
    for(int i=0; i<5; i++) h[i] = r_index[i];
}


This program doesn't change any functionality of the original code however it rearranges and simplifies the operations.