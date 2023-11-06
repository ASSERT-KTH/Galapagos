Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffff;
    uint128_t f_values[5], g_values[5], multiples[] = {0, 19, 38, 57, 76};
    uint128_t r_values[5];
    uint64_t carries[5], tp_carries[5];

    int i, j;
    for (i = 0; i < 5; i++)
    {
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }

    for (i = 0; i < 5; i++)
    {
        r_values[i] = f_values[0] * g_values[i];
        
        for (j = 1; j < 5; j++)
        {
            r_values[i] += (j+i<5 ? f_values[j]*g_values[i-j] : f_values[j]*multiples[5-(j+i)]);
        }
    }

    for (i = 0; i < 5; i++)
    {
        tp_carries[i] = (((uint64_t) r_values[i]) >> 51);
        r_values[(i+1)%5] += tp_carries[i];
    }

    for (i = 0; i < 5; i++)
    {
        carries[i] = (uint64_t) tp_carries[i];
        r_values[i]&= mask;
        tp_carries[(i+1)%5] = r_values[i] >> 51;
    }

    for (i = 0; i < 5; i++)
    {
        r_values[i] += carries[i]*19;
    }
    h[0] = r_values[0];
    h[1] = r_values[1];
    h[2] = r_values[2];
    h[3] = r_values[3];
    h[4] = r_values[4];
}

Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffff;
    uint128_t fg[10];
    uint64_t carry;

    for (size_t i=0; i<5; ++i) {
        for (size_t j=0; j<5; ++j) {
            fg[i+j] += (uint128_t) f[i] * g[j];
        }
    }

    fg[5] = fg[0] + 19ULL*fg[5];
    fg[6] += fg[1];
    fg[7] += fg[2];
    fg[8] += fg[3];
    fg[9] += fg[4];

    for (size_t i=0; i<5; ++i) {
        carry = (uint64_t) (fg[i] >> 51); 
        h[i] = ((uint64_t) fg[i]) & mask;
        fg[i+1] += carry;
    }

    carry = h[0] >> 51;
    h[0] &= mask;
    h[1] += carry;
}



Variant 3:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_values[5], g_values[5];
    uint64_t h_values[5] = {0, 0, 0, 0, 0};
    uint64_t  carry;

    for(uint8_t i = 0; i < 5; i++){
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }
    
    for(uint8_t i = 0; i < 10; i++){
        uint8_t min_i = i < 4 ? i : 4;
        uint  mult = min_i == 1 || min_i == 3 ? 38 : min_i == 2 ? 19 : 1;
        uint end= 10-i <=6 ? 5:10-i
        for(uint8_t j = i < 5 ? 0: i - 4; j < end; j++){
            h_values[min_i] += f_values[j] * g_values[min_i - j] * mult;
        }
        uint8_t mask_index = min_i < 4 ? min_i + 1 : 0;
        carry = h_values[mask_index] >> 51;
        h_values[min_i]           = h_values[mask_index]          & mask;
        h_values[(mask_index + 1) % 5] = carry;
    }
    memcpy(h, h_values  , 5 * sizeof(uint64_t));
}
