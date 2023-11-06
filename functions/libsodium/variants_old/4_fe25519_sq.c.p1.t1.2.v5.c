void fe25519_sq(fe25519 h, const fe25519 f)
{  
    int64_t h_[10];
    int64_t f_[10];
    for(int i = 0; i < 10; ++i)
    {
        f_[i] = f[i];
    }

    int32_t f2_[5];
    for(int i=0; i<5;++i)
    {
      f2_[i] = 2*f_[i];
    }

    f_[0]  *=  2U;
    f_[1]  *=  2U;
    f_[2]  *=  2U;
    f_[3]  *=  2U;

    int64_t f0f0   =( f_[0]                 )*( f_[0]);
    int64_t f0f1_2  =( f_[0]+ f2_[1 -1]/2 )*( f_[1]);
    f2_[4]         *= 38;
    int64_t f0f2_2  =( f_[0]+ f2_[2 -1]/2 )*( f_[2]);
    int64_t f0f3_2  =( f_[0]+ f2_[3 -1]/2 )*( f_[3]);
    int64_t f0f4_2  =( f_[0]+ f2_[4 -1]/2 )*( f_[4]);
    int64_t f0f5_2  =( f_[0]+ f2_[5 -1]/2 )*( f_[5]);
    f_[6]          *= 19U;
    int64_t f0f6_2  =( f_[0]+= f_[1]/2 *(38U)) *(f_[6]);
    int64_t f0f7_2  =( f_[0]+=f2_[2]/2*(19U))   *(f_[7]);
    int64_t f0f8_2  =( f_[0]+f2_[3]/2 *(19U))   *(f_[8]);

    for(int i = 0; i < 10; ++i)
    {
        h_[i] = f0f0 + f0f1_2 + f0f2_2 + f0f3_2 + f0f4_2 + f0f5_2;
    }

    int64_t carry[10];
    for(int i=0;i<10;++i)
    {
      carry[i] = (h_[i] + (int64_t)(1 << 26)) >> 27;
      if (i<10 -1) h_[i+1] += carry[i];
      h_[i] -= carry[i] << 26;
      carry[i] = (h_[i] + (int64_t)(1 << 25)) >> 26;
      if (i<10 -1) h_[i+1] += carry[i];
      h_[i] -= carry[i] << 26;
    }

    for(int i = 0; i < 10; ++i)
    { 
        h[i] = h_[i];
    }
}