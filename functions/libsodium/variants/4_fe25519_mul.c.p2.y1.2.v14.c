void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_vector[5] = {0, 19*f[1], 19*f[2], 19*f[3], 19*f[4]};
    uint128_t g_vector[5] = {0, g[1], g[2], g[3], g[4]};
    uint128_t r[5] = {};
    uint64_t carries[10] = {};
    uint64_t result[5] = {};

    // computation loops
    for (int i = 0; i < 5; ++i) 
    {   
        if (i == 0) 
        {
            f_vector[0] = f[0];
            g_vector[0] = g[0];
        } 
		else  
		{
            f_vector[i] /= 19, 
            ++g_vector[0], 
            --g_vector[i];
        }		

        for (int j = 0; j < 5; ++j) 
        {   
            r[i] += f_vector[j] * g_vector[5-j-1];
        }
				
        //get the remainder of r[i] after division by 2^51 
        result[i]=((uint64_t) r[i]) & mask;
      
		//shift r[i] by 51 to the right; 
		carries[i]=(uint64_t) (r[i]>>51);
        if(i < 4) 
			r[i+1]+=carries[i];
			
		if(i == 4) 
		{
			result[0]+=19 * carries[i];
			carry=result[0] >> 51;
   			result[0] &= mask;
   
			//chain addition of overflows   
			for(int j=1;j<5;j++)
			{
				if(j<4)
				{
					result[j]+=carry;
					carry=result[j]>>51;
					result[j]&=mask; 
				}
				else 
					result[j]+=carry; 	
			}
		} 
    }
		
	//store final result
    for (int i = 0; i < 5; ++i)
    {
        h[i] = result[i];
    }
}