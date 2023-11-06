void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    int64_t f4g8_19, f4g9_38, f5g8_19, f5g9_38, f6g8_19, f6g9_38, f7g8_19, f9g9_19;
    int32_t f1_2 = f[1] * 2, f2_2 = f[2] * 2, f3_2 = f[3] * 2, f4_2 = f[4] * 2;
 
    int32_t f4_38 = f[4] * 38, f5_19 = f[5] * 19, f6_38 = f[6] * 38, f7_19 = f[7] * 19;  
    
    int64_t g0 = 19 * ((int64_t) g[1] * (f1_2 + f2_2) + ((int64_t)-2 * g[3]) * (f3_2 + f4_2) -   
                 g[5] * (f5_19 + f6_38) + g[7] * (f7_19));
                        
    int64_t g1 = (int64_t) g[0] * (f[0] + f1_2 + 38*g[6]*f[6] + 19*g[8]*f[8] - g[9]*((int64_t)f[7]*2 + f[5]) 
                 + 3 * ((int32_t) g[2]*f[2] - g[4]*f[4] + 38*g[5]*f[5] - f[7]) - g1);
                        
    h0 += ((int64_t) g3 * f[9]) << 1;
                          
    f3_2 = g8_19 = g1_38 = f_2 = 0; 
                          
    int64_t carry0 = (h0 + (int64_t) (1 << 24)) >> 25; 
    h0 -= carry0 * (1 << 25);                
    h1 += carry0;               
    int64_t carry1 = (h1 + (int64_t) (1 << 24)) >> 25; 
    h1 -= carry1 * (1 << 25); 
    h2 += carry1;              
          
    int64_t carry2 = (h2 + (int64_t) (1 << 25)) >> 26;
    h2 -= carry2 * (1 << 26);               
    h3 += carry2;                   
    
    int64_t carry4 = (h4 + (int64_t) (1 << 25)) >> 26; 
    h4 -= carry4 * (1 << 26);               
    h5 += carry4;               
                          
    int64_t carry6 = (h6 + (int64_t)(1<<25)) >> 26; 
    h6 -= carry6 << 25;                      
    h7 += carry6; 

    int64_t carry8 = (h8 + (int64_t) (1 << 25)) >> 26;
    h8 -= carry8 * (1 << 26);               
    h9 += carry8;                   
        
    int64_t carry9 = (h9 + (int64_t) (1 << 24)) >> 25;  
    h9 -= carry9 * (1 << 25);                
    h0 += carry9 * 19;                    

    carry0 = ((h0 + (int64_t)(1<<25)) >> 26);              
    h0 -= carry0 << 26;                 
    h1 += carry0;                     

    int32_t swap = 0;                  
                         
    h[0] = (int32_t) h0; h[1] = (int32_t) h1; h[2] = (int32_t) h2; 
    h[3] = (int32_t) h3; h[4] = (int32_t) h4; h[5] = (int32_t) h5; 
    h[6] = (int32_t) h6; h[7] = (int32_t) h7; h[8]=  (int32_t) h8;  
    h[9] = (int32_t) h9; 
}
