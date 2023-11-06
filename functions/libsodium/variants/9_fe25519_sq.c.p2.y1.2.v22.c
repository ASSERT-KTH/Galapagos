void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t a[10], b[10];
    int64_t temp[10], h1[10];
    uint32_t i = 0, carry = 0;

    // Prepare all a[i] and b[i] arrays
    for(i = 0; i<10; i++)
    {
        a[i] = f[i];
        b[i] = 2 * a[i];
        if(i == 5 || i == 7 || i == 9)
           b[i] = 38 * a[i];
        if(i == 6 || i == 8)
           b[i] = 19 * a[i];
    }

    // Prepare all temp[i]
    for(i = 0; i <10; i++)
    {
         temp[i] = a[i] * (int64_t)b[i];
         if (i%2==0)
           {
                temp[i] += a[i/2] * (int64_t)b[i/2] * (1<<1); 
           }
        if (i<3 && i != 0)
            {
                temp[i] += a[i/2] * (int64_t)b[i/2] * 38;  
            }
        if (i>4 && i != 7)
            {
                temp[i] += a[i/2] * (int64_t)b[i/2] * 38; 
            }
       
    }
    
    for(i = 0; i <10; i++)
    {
      h1[i] = temp[i>>1];
      if((i&1) == 1)
      h1[i]+=temp[i];
      if(i!=9)
         c[i] = (carry + (int64_t)(1<<((26-(i&1)))) - 1) >> (26-(i&1));
      else
         carry9 = (h1[9] + (int64_t)(1 << 24)) >> 25;
    }
   
    h1[0] = carry0 * (int64_t) 19;
    carry0 = ((carry9*19 + (int64_t)(1<<25))-1) >> 26;


    for(i = 0; i<10; i++)
    {
        h[i] = (int32_t)h1[i];
    }

}