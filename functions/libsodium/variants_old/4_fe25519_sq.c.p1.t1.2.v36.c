Here's a compact variant of your function that should behave equivalently:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0f[] = {(int64_t)f[0]*f[0], (int64_t)2*f[0]*f[1],  (int64_t)2*f[0]*f[2], 
                     (int64_t)2*f[0]*f[3], (int64_t)2*f[0]*f[4], (int64_t)2*f[0]*f[5], 
                     (int64_t)2*f[0]*f[6], (int64_t)2*f[0]*f[7],(int64_t)2*f[0]*f[8], 
                     (int64_t)2*f[0]*f[9]};
                     
    int64_t fxf[] = {(int64_t)2*f[1]*f[1], (int64_t)2*f[1]*f[2], 4*f[1]*f[3], 
                     2*f[1]*f[4], 4*f[1]*f[5],2*f[1]*f[6],4*f[1]*f[7],
                     2*f[1]*f[8],76*f[1]*f[9],f[2]*f[2], 2*f[2]*f[3],2*f[2]*f[4], 
                     2*f[2]*f[5], 2*f[2]*f[6], 2*f[2]*f[7], 38*f[2]*f[8],
                     38*f[2]*f[9], 2*f[3]*f[3],2*f[3]*f[4], 4*f[3]*f[5], 
                     2*f[3]*f[6], 76*f[3]*f[7], 38*f[3]*f[8], 76*f[3]*f[9],
                     f[4]*f[4], 2*f[4]*f[5], 38*f[4]*f[6], 38*f[4]*f[7],
                     38*f[4]*f[8], 38*f[4]*f[9], 38*f[5]*f[5], 
                     38*f[5]*f[6], 76*f[5]*f[7], 38*f[5]*f[8], 
                     76*f[5]*f[9], 19*f[6]*f[6], 38*f[6]*f[7], 
                     38*f[6]*f[8], 38*f[6]*f[9], 38*f[7]*f[7], 
                     38*f[7]*f[8],76*f[7]*f[9], 19*f[8]*f[8], 38*f[8]*f[9],
                     38*f[9]*f[9]};
                    
    int64_t h_temp[] = {f0f[0] +76*fxf[51]+38*fxf[49]+76*fxf[47]+38*fxf[43]+38*fxf[39],
                        f0f[1] +38*fxf[52]+38*fxf[50]+38*fxf[46]+38*fxf[44],
                        f0f[2] +fxf[48]+76*fxf[51]+38*fxf[49]+76*fxf[45]+fxf[41],
                        f0f[3] +fxf[49]+38*fxf[52]+38*fxf[50]+38*fxf[46],
                        f0f[4] +fxf[50]+2*fxf[48]+fxf[42]+76*fxf[52]+38*fxf[50]+38*fxf[46],
                        f0f[5] +2*fxf[51]+2*fxf[49]+38*fxf[53]+38*fxf[51],
                        f0f[6] +2*fxf[52]+2*fxf[50]+2*fxf[48]+76*fxf[54]+19*fxf[40],
                        f0f[7] +2*fxf[53]+2*fxf[51]+2*fxf[49]+38*fxf[55],
                        f0f[8] +2*fxf[54]+2*fxf[52]+2*fxf[50]+fxf[44] +38*fxf[56],
                        f0f[9] +2*fxf[55]+2*fxf[53]+2*fxf[51]+2*fxf[49]+2*fxf[45]};

                        
    int64_t carry[10];

    for(int i = 0; i<10; i+=4){
        carry[i] = (h_temp[i]+ (int64_t)(1L << ((i%2==0)? 25: 24)))>> ((i%2==0)? 26: 25);
        h_temp[i+1] = h_temp[i+1] + carry[i];
        h_temp[i] = h_temp[i] - carry[i] * ((uint64_t) 1 << ((i%2==0)? 26: 25)); 

        carry[i+1] = (h_temp[i+1]+ (int64_t)(1L << ((i%2==1)? 25: 24)))>> ((i%2==1)? 26: 25);
        h_temp[i+2] = h_temp[i+2] + carry[i+1];
        h_temp[i+1] = h_temp[i+1] - carry[i+1] * ((uint64_t) 1 << ((i%2==1)? 26: 25));
  
        carry[i+2] = (h_temp[i+2]+ (int64_t)(1L << ((i%2==0)? 25: 24)))>> ((i%2==0)? 26: 25);
        h_temp[i+3] = h_temp[i+3] + carry[i+2];
        h_temp[i+2] = h_temp[i+2] - carry[i+2] * ((uint64_t) 1 << ((i%2==0)? 26: 25)); 
  
        carry[i+3] = (h_temp[i+3]+ (int64_t)(1L << ((i+1%2==1)? 25: 24)))>> ((i+1%2==1)? 26: 25);
        h_temp[i+4] = h_temp[i+4] + carry[i+3];
        h_temp[i+3] = h_temp[i+3] - carry[i+3] * ((uint64_t) 1 << ((i+1%2==1)? 26: 25));  
    }      

    carry[0] = (h_temp[0] + (int64_t)(1L << 25)) >> 26;
    h_temp[1] = h_temp[1] + carry[0];
    h_temp[0] = h_temp[0] - carry[0] * ((uint64_t) 1 << 26); 

    for(int i= 0; i<10; i++)
        h[i]=(int32_t) h_temp[i];
}

Please keep in mind that the formatting of this piece of code could make it difficult to read and maintain. Other programmers reading this code in the future may thank you if you take a small amount of additional time now to make the source more easily readable. Let's refactor continue formatting the code to build more readable, maintainable code.

This function features quite a few constants — the naming of these constants could also significantly improve the readability of the code.

If the primary goal is optimizing for runtime performance, the compiler should do a good job at it; consider benchmarking it. The modern compilers are quite excellent at optimization. The assembly code once compiled will be the same in this case. Performance improvement can happen when fundamental algorithms or data structures are being changed, not while manually manipulating compiled code in these kinds of circumstances.