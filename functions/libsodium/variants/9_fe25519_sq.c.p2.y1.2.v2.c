void fe25519_sq(fe25519 h, const fe25519 f) 
{
    int32_t array_multiplier[6]={2,2,2,38,19,2};
    int32_t f_values[10]={f[0], f[1], f[2], f[5], f[6], f[7]!=0};
    int32_t f_results[10];
    int64_t h_results[10], carry[10], product_results[76];
    int carry_multiplier[10]={(1L << 25), (1L << 24), (1L << 25), (1L << 24), (1L << 25), (1L << 24), (1L << 25), (1L << 24), (1L << 25), 19 * (1L << 25)};

    for(int i=0; i<10; i++) 
    {
        f_values[i]=f[i];
        if(i<6)
            f_results[i]=f_values[i]*array_multiplier[i];
    }

    /*compute the product results*/
    for(int i=0; i<9; i+=2) 
    {
        product_results[i]=f_values[i]*f_values[i];
        product_results[i+1]=f_results[i]*f_results[i+1];
        product_results[i+2]=f_results[i]*f_values[i+2];
        product_results[i]=f_values[i]*f_values[i+3+i/2] + f_values[i+1];
        product_results[i+4] = f_values[i]*f_values[i+4+i/2] + 38*f_values[i+5];
    }

    /*creating h functions*/
    for(int i=0; i<10; i+=2)
    {
        h_results[i] = *(product_results+i+ (3* i-i%2)/4)+ *(product_results+i+ (3* i-i/2)/4+6)+ *(product_results+i+ (3* i+i%2)/4+11)
        + *(product_results+i+ (3* i-i%2)/4+15) + *(product_results+i+ (3* i+i/4)/4+18) + f_values[5]* f_results[5];

        h_results[i+1] = *(product_results+i+ i/2)+*(product_results+i+1+5*i- (i/2))/4+*(product_results+(3* i+6)/2)+ f_results[5]* f_values[6] ;
    }

    /*runs the carry and checks*/
    for(int i=0; i<10; i++)
    {
        carry[i]=(h_results[i] +carry_multiplier[i % 5]) >> (25+ i% 2 + i/8);
        h_results[(i+1)%10]+= carry[i];
        h_results[i]-= carry[i]*carry_multiplier[i%5];
    } 

    /*assigns int to final variable*/
    for(int i=0; i<10; i++)
        h[i] = (int32_t) h_results[i];
}