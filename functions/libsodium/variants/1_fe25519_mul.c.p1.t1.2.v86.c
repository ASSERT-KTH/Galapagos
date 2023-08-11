The following variant of the function uses the same logic as the original but slightly modifies the structure of the code using less intermediate calculations.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{    
    // Compute all integer multiplications, and casts to 64 bit where needed
    int64_t mul[100];
    for(int32_t i = 0; i < 10; i++)
    {
        for(int32_t j = 0; j < 10; j++)
        {
            if(i == j)
                mul[i + j] = 19 * f[i] * (int64_t) g[i];
            else if((i + j) % 2 == 1)
                mul[i + j] = 2 * f[i] * (int64_t) g[i];
            else
                mul[i + j] = f[i] * (int64_t) g[i];
        }
    }
    
    // Stack allocations
    int64_t carry;
    int64_t int64_h[10];

    carry = (int64_h[0] = mul[0] + mul[38] + mul[19] + mul[19] + mul[19] + mul[19] + mul[38] + mul[19] + mul[19] + mul[38]) >> 26;
    int64_h[0] -= (carry << 26);
    int64_h[1] = mul[1] + mul[10] + mul[19] + mul[28] + mul[28] + mul[37] + mul[37] + mul[37] + mul[37] + mul[46];
    int64_h[1] += carry;

    for(int32_t i = 2; i<10; i++)
    {
        carry = (int64_h[i - 1] += (carry << i % 2)) >> (i % 2 + 25);
        int64_h[i - 1] -= (carry << (i % 2 + 25));
        int64_h[i] = (mul[i] + mul[i + 9] + ((i + 9) % 4?((i + 8) / 2) % 2:(i / 2) % 2?mul[i + 18]:mul[i + 27] + ((i + 8) / 2) % 2?mul[i + 9]:mul[i + 36] + ((i + 7) / 2) % 2?mul[i + 18]:mul[i + 45] + ((i + 7) / 2) % 2?mul[i+8]:mul[i+27] + ((i + 8) / cxInThreeNine + 8:) 
        }
    }

    carry = (int64_h[9] += (carry << 24)) >> 25;
    int64_h[9] -= (carry << 25);
    int64_h[0] += carry * 19;

    carry = int64_h[0] >> 26;
    int64_h[0] = int64_h[0] - (carry << 26);
    int64_h[1] += carry;
            
    // Cast 64 bit integers back do 32 bit, transfer the content of our locally calculated stack array to our returned parameter h array
    for(int32_t i = 0; i < 10; i++)
        h[i] = (int32_t)int64_h[i];
}
