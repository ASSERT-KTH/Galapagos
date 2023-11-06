The modified function with minimized call to multiplication operation is as below.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
     int32_t g1_19 = g[1]*19,
             g2_19 = g[2]*19,
             f1_2  = f[1]*2,
             f9_2  = f[9]*2,
             g_nines [10] = { g[0], g1_19, g [2], g[3]*19, g[4], g[5]*19, g[6], g[7]*19, g[8], g[9]*19 },
             farray [10]  = { f[0], f1_2,  f[2],  f[3]*2,  f[4],  f[5]*2,  f[6],  f[7]*2,  f[8],  f[9]*2 };
     int64_t fg[100]={0};

     for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
            fg[i+j] += farray[i]*(int64_t)g_nines[j];
         }
     }

    int64_t carry [10];
    for(int g = 0,i=0; g <100; g+=10,i++ )
    {
        h[i] = fg[g] + fg[g+5];
        if(i!=9)
            h[i] += fg[g+4]/19 + fg[g+6]/19;
        h[i]=h[i]+((int64_t)(1L << ((i%2)?24:25)));
        carry[i] = h[i]>>((i%2)?25:26);
        h[i] -= carry[i]* ((uint64_t) 1L << ((i%2)?25:26));
    }


    carry[9]   = (h[9] + (int64_t)(1L << 24)) >> 25;
    h[0] += carry[9] * 19;
    h[9] -= carry[9] * ((uint64_t) 1L << 25);
    
    carry[0]   = (h[0] + (int64_t)(1L <<25)) >> 26;
    h[1] += carry[0];
    h[0] -= carry[0]* ((uint64_t) 1L << 26);

    for(int i=0;i<10;i++){
        h[i] = (int32_t)h[i];
    }
}
                           
This program optimization uses the opportunity of collecting similar operation, reduces branching ratio and increases loop count.