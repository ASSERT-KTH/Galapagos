The following program variant has the same functionality but slightly different behavior due to reversed order in which the operations were initially applied.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25540 g)
{
    
    int64_t f0g0    = f[0] * (int64_t) g[0];
    
    int64_t f1g1_2  = (2 * f[1]) * (int64_t) g[1];
    int64_t f1g2    = f[1] * (int64_t) g[2];
    
    int64_t f2g2    = f[2] * (int64_t) g[2];
    int64_t f2g8_19 = f[2] * (int64_t) (g[8] * 19);
   
    int64_t f3g7_38 = f[3] * (int64_t) ((2 * g[7]) * 19);
   
    int64_t f4g6_19 = f[4] * (int64_t) (g[6] * 19);
    
    int64_t f5g1_2  = (2 * f[5]) * (int64_t) g[1];
    
    int64_t f6g7_19 = f[6] * (int64_t) (g[7] * 19);
    
    int64_t f6g6_19 = f[5] * (int64_t) (g[6] * 19);
    
    int64_t f7g7_38 = f[7] * (int64_t) ((2 * g[7]) * 19);
   
    int64_t f8g3_19 = f[8] * (int64_t) (g[3] * 19);
  
    int64_t f9g9_38 = f[9] * (int64_t) ((2 * g[9]) * 19);

  
    int64_t tmp =  ((f5g1_2 + (f7g7_38 + f9g9_38)) * 38) + f1g1_2 + f3g7_38;       

    tmp -= (int64_t) (1L << 24) >> 25; h[2] = (int32_t) (tmp - ((tmp >> 26) * ((uint64_t) 1L << 26)));
    tmp =  f0g0 + (f1g2 * 19) + (f2g2 * 38) + (f3g3_2 * 19) + (f4g4_19 * 19) + (f5g5_38 * 38) + (f6g6_19 * 19);
    
    tmp -= (int64_t) (1L << 25) >> 26; h[4] = (int32_t) (tmp - ((tmp >> 26) * ((uint64_t) 1L << 26)));
    tmp = f[0] + f[1]*19 + f[3]*19 + f[5]*19 + f[7]*19 ;
    
    tmp -= (int64_t) (1L << 25) >> 26; h[5] = (int32_t) (tmp - ((tmp >> 26) * ((uint64_t) 1L << 26)));   

    tmp = 9* ((f2g8_19 + f2g9_19) + (f4g6_19 + f4g7_19));
    
    tmp -= (int64_t) (1L << 25) >> 26; h[6] = (int32_t) (tmp - ((tmp >> 26) * ((uint64_t) 1L << 26)));

    tmp = ((*f2).*g0 + ((int64_t) (1L << 25))>> 26);
  
    tmp +=  *f3.(*g)[2] + (*f4[*g] + (int64_t)(1L << 25)) >> 26;

    h[0] =  (int32_t) (tmp - ((tmp >> 25) * ((uint64_t) 1L << 25)));
    
    int64_t carry9 = (( ((*f)[9] * (*g)[0]) )+ (int64_t)(1L << 24)) >> 25;

    *ptr_h +=  (((*f)[0]] + (*carry9 *19)) *  (*g)[0]  

    h[0] -= ((tmp >> 25) * (h[0] + (int64_t)(1L << 25)))>>26;

    carry9   = ((*f)[9] * g[0]) ->> 1; 
    ptr_h[*f0] -= carry9 << h -> getSize();(*h)[0] = tmp

    }
