fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_2[5], f_19[5], f_38[5];   
    uint64_t carry;

    for(int i=0; i<5; i++){
       f_2[i] = ((uint128_t)f[i]) << ((i < 2) ? 1 : 0 ); 
       f_38[i] = ((i < 3) ? 38 : 0) * ((uint128_t) f[i]);
       f_19[i] = ((i >= 3) ? 38 : 0) * ((uint128_t) f[i]);
    }

    r[0] =   f_2[0] *  f[0] + f_38[1] *  f[4] + f_38[2] *  f[3];
    r[1] =   f_2[0] *  f[1] + f_38[2] *  f[4] + f_19[3] *  f[3];
    r[2] =   f_2[0] *  f[2] +  f_2[1] *  f[1] + f_38[3] *  f[4];
    r[3] =   f_2[0] *  f[3] +  f_2[1] *  f[2] + f_19[4] *  f[4];
    r[4] =   f_2[0] *  f[4] +  f_2[1] *  f[3] +  f_2[2] *  f[2];

    for(int i=0; i<5; i++)
    { 
        r[i]   &= mask;
        carry   = r[i] >> 51;
        r[i+1] += ((i<4)? carry: 0);

        r[i]  += 19ULL * ((i==0) ? carry: 0 );
        carry  = r[i] >> 51;

        r[i]  &= mask;
        r[i+1] += ((i<4)? carry: 0);
    }

    for (int i=0; i<5; i++) h[i]=r[i];
}