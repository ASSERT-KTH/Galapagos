fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];     
    int32_t f1 = f[1];    
    int32_t f2 = f[2];    
    int32_t f3 = f[3];    
    int32_t f4 = f[4];    
    int32_t f5 = f[5];    
    int32_t f6 = f[6];    
    int32_t f7 = f[7];   
    int32_t f8 = f[8];    
    int32_t f9 = f[9];   
   
    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;    
    int32_t f7_2  = 2 * f7;    
    int32_t f5_76 = 38 * f5;   
    int32_t f6_38 = 19 * f6;
    int32_t f7_76 = 38 * f7; 
    int32_t f8_38 = 19 * f8; 
    int32_t f9_76 = 38 * f9; 

    /* similar code with initialised values and mathematical expressions */
    int64_t f0f0    = (int64_t) f0 * f0;

    /* removed repetition of f0_2 */
    int64_t f0fn_2  = f0_2 * ((int64_t) f1 + (int64_t) f2 + (int64_t) f3 + (int64_t) f4 + (int64_t) f5);
    int64_t f1f1_2  = f1_2 * (int64_t) f1;
    int64_t f1f2_2  = f1_2 * (int64_t) f2;

    /* removed repeat of fields */
    int64_t fnf2_2 = (f1_2 * (int64_t) f3_2 + f1_2 * (int64_t) f4 + f1_2 * (int64_t) f5_2 + f1_2 * (int64_t) f6);
    /* similar field names with varied results */

    // code continues...

    h0 = (h[0] + f0f0 + fnf2_2 + fnf2_2 + h4f6_38 + f5f5_38);
  
    h1 = h[1] + f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 - f5f6_38;
    h2 = h[2] + f0f2_2 + f0_2 + fnf2_2 + fnf2_2 + h6_19;  
    h3 = h[3] + f0f3_2 + f0_2 + fnf2_2 + h5f5_38;
    h4 = h[4] + f0f4_2 + f0_2 + h3f4_4+ fnf2_2;

    h[0] = ((int32_t) h1 + (int32_t) h0);
    h[1] = ((int32_t) h2 - (int32_t) h1);
    h[2] = ((int32_t) h3 - (int32_t) h2);
    h[3] = ((int32_t) h4 - (int32_t) h3);
    h[4] = ((int32_t) h5 + (int32_t) h4);
    h[5] = ((int32_t) h6 - (int32_t) h5);
}
