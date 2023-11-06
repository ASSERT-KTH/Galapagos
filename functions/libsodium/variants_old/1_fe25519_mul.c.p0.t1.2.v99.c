void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    int32_t g_values[10];
    int32_t g_19_values[10];
    int32_t fi_2_values[5] = {0};

    for (int either_fg = 0; either_fg < 10; either_fg++) {
        f_values[either_fg] = f[either_fg];
        g_values[either_fg] = g[either_fg];

        if (either_fg % 2 != 0){
          fi_2_values[(either_fg-1)/2] = 2 * f_values[either_fg];
        }

        if (either_fg != 0) 
          g_19_values[either_fg] = 19 * g_values[either_fg];
    }

    int64_t fg_values[100] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 == 0)
              fg_values[i * 10 + j] = f_values[i] * (int64_t) g_values[j];
            else
              if ((i % 2 != 0)&&(j % 2 != 0)){
                fg_values[i * 10 + j] = fi_2_values[(i-1)/2] * (int64_t) g_19_values[j];
              } else {
                fg_values[i * 10 + j] = f_values[i] * (int64_t) g_values[j];
                if (i % 2 == 0)
                  fg_values[i * 10 + j] = f_values[i] * (int64_t) g_19_values[j];
              }
        }
    }

    int64_t h_values[10] = {0};

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++) 
        {
            if ( j > i)
              break;
              
            h_values[i] += fg_values[i*10+j];
            
            if ( j < i)
              h_values[i] += fg_values[j*10+i];
        }              
    }
     
    for(int i=0; i<10; i++){
        int64_t carry = (h_values[i] + ((i == 4 || i == 0)? (int64_t)(1L << 25) : (int64_t)(1L << 24))) >>((i == 4 || i == 0)?26:25);
        int temidx = i == 9? 0 : i + 1;
        if (temidx == 0){
          carry = carry * 19;
        }
        
        h_values[temidx]+=carry;
        h_values[i] -= carry * ((i == 4 || i == 0)?((uint64_t) 1L << 26):((uint64_t) 1L << 25));
    }

    memcpy(h, h_values, sizeof(int64_t) * 10);

    return;
}
