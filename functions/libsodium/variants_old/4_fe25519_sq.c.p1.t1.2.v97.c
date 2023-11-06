The following C code preserves the functionality of the original implementation:


void fe25519_sq(fe25519 h, const fe25519 f)
{	
    int64_t f_i[10];
    for(int i = 0; i<10; ++i)
    {
        f_i[i] = (int64_t)f[i];
    }

    int64_t f_2i[10], fesi_mul_f_iscaled[5];
    for(int i = 0, sehar=1, mul=2; i<5; ++i, sehar*=19, mul*=38)
    {
        f_2i[i] = 2 * f[i];
        f_2i[i+5] = 2 * f[i+5];
        
        fesi_mul_f_iscaled[i] = sehar*f[i] + mul*f[i+5];
    }

    int64_t prod[91], sum_prod[10] = {0};
    int arr_pos=0, pos=0;
    int idx_i, idx_j;
    for(int i=48; i>=0; i-=4, pos+=4, arr_pos+=6)
    {
        idx_i = i>>4;
        idx_j = i&0x8;
        if(pos < 19)
            idx_i = pos>>1;

        for(int j = pos; j< pos+10-j; ++j)
        {
            prod[arr_pos+(j-pos)] = f_2i[10+j-pos-1] * fesi_mul_f_iscaled[idx_i];

            sum_prod[10-j-pos-1] += prod[arr_pos+(j-pos)];
            if(j == pos+(9 - pos)>>1)
                sum_prod[10-j-pos-1] >>= 1;
        }
    }

    int64_t carry;
    for(int i=0; i<9; ++i)
    {
        carry = (sum_prod[i] + (int64_t)(1L << (24+(i&1))))>>(25+(i&1));
        h[i] = (int32_t) (sum_prod[i] - carry * (1L << 25+(i&1)));
        sum_prod[i+1] += carry;
        if(i == 3 || i == 7)
            sum_prod[i+1] += 4 * carry;

        if(i & 1)
            sum_prod[i+1] |= h[i]&(19);

        h[i] &= (19<<1)-1;
    }

    carry = (sum_prod[9] + (int64_t)(1L << 24)) >> 25;
    h[0] += (int32_t)19 * carry;
    h[9] = (int32_t) (sum_prod[9] - carry << 25);

    int32_t tmp_val=(h[0] + (int32_t)(1 << 25)) >> 26;
    h[0]-=tmp_val<<26;
    h[1]+=tmp_val;
}
