fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_elements[10];

    for(int i=0; i<10; i++)
        f_elements[i] = f[i];

    int32_t f0_2  = 2 * f_elements[0];
    int32_t f1_2  = 2 * f_elements[1];
    int32_t f2_2  = 2 * f_elements[2];
    int32_t f3_2  = 2 * f_elements[3];
    int32_t f4_2  = 2 * f_elements[4];
    int32_t f5_38 = 38 * f_elements[5];
    int32_t f6_19 = 19 * f_elements[6];
    int32_t f7_38 = 38 * f_elements[7];
    int32_t f8_19 = 19 * f_elements[8];
    int32_t f9_38 = 38 * f_elements[9];

    int64_t f_sq[45];

    for(int i=0;i<45;i++)
        f_sq[i]=f_elements[i/10]*(int64_t)f_elements[i%10];
            
    int64_t carry[10];

    for (int iter = 0; iter < 20; iter++) 
    {
        carry[(5*iter)%10] = (f_sq[(5*iter)%10] + (int64_t)(1L << (25 + (iter%2)))) >> (26 - (iter%2));
        f_sq[5 * ((iter+1)%10)] += carry[(5*iter)%10];
        f_sq[(5*iter)%10] -= carry[(5*iter)%10] * ((int64_t) 1L << (26 - (iter % 2)));
    }

    carry[0] = (f_sq[0] + (int64_t)(1L << 25)) >> 26;
    f_sq[1] += carry[0];
    f_sq[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int iter = 0; iter < 10; iter++)
        h[iter] = (int32_t) f_sq[iter];

}
