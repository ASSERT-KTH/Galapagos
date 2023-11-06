void fe25519_sq(fe25519 h, const fe25519 f) 
{ 
	// Variables
	int32_t i;
	int64_t tmp[10];
	
	// For each iteration, perform similar ops
	for (i = 0; i < 10; ++i)
	{
		int32_t fi = f[i];		
		int32_t fi_2 = 2 * fi;
		
		tmp[i] = fi * (int64_t)fi;
		if (i+1<10) 
			tmp[i+1] = fi_2 * (int64_t)f[i+1];
		  		
	  	if (i+2<10)
			tmp[i+2] = fi_2 * (int64_t)f[i+2];
			
		if(i+4<10)
			tmp[i+4] = fi_2 * (int64_t)f[i+4];

	    if (i % 2 == 0) 
		{
	      int64_t tmpi2 = 2 * tmp[i];
	      tmp[i+5] = fi * ((i < 5) ? (38 * (int64_t)f[i+5]) : (19 * (int64_t)f[i+5]));
	      tmp[i+6] = tmpi2 * (i < 5 ?(f[i+6]) : (f[i+6]));

	    } else 
		{
	      tmp[i+5] = fi * ((i < 4) ? (38 * (int64_t)f[i+5]) : (19 * (int64_t)f[i+5]));
	      tmp[i+6] = tmp[i] + fi * ((i < 5) ? (38 * (int64_t)f[i+6]) : (19 * (int64_t)f[i+6]));
	      tmp[i] += tmp[i-1];
		}
	}	 

	int64_t carry[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			carry[i] = (tmp[i] + (int64_t)(1L << 25)) >> 26; 
			tmp[i+1] += carry[i];
			tmp[i] -= carry[i] *((int64_t) 1L << 26);  

		} else 
		{
			carry[i] = (tmp[i] +(int64_t)(1L << 24)) >> 25;
			tmp[i+1] += carry[i];
			tmp[i] -= carry[i] *((uint64_t) 1L << 25);			
		}

		if (i == 4) 
		{
			carry[9] = (tmp[9] + (int64_t)(1L << 24)) >> 25;
	    	tmp[0] += carry[9] * 19;
	    	tmp[9] -= carry[9] * ((uint64_t) 1L << 25);

	    	carry[0] = (tmp[0] + (int64_t)(1L << 25)) >> 26;
	    	tmp[1] += carry[0];
	   		tmp[0] -= carry[0] * ((uint64_t) 1L << 26);
		}
	}
	
	for(int i = 0; i < 10; ++i)
	{
		h[i] = (int32_t)tmp[i];
	}
}