void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t t[10]; // Creating intermediate array

    for(int i=0 ; i<10 ; i++)
    	t[i] = f[i]; // fi = f[i]
  
    for(int i=0 ; i<10 ; i++)
	t[i] = 2 * t[i]; //fi_2 = 2 * f[i]
	
    t[5] = 38 *f[5]; //f5_38 = 38*f5 
    t[7] = 38 *f[7]; //f7_38 = 38*f7	
    t[9] = 38 *f[9]; //f9_38 = 38*f9
    t[6] = 19 *f[6]; //f6_19 = 19*f6 
    t[8] = 19 *f[8]; //f8_19 = 19*f8	

    int64_t g[45];
  
    for(int i=0; i<10 ; i++)
	for(int j=i ; j<10 ; j++)
	    if(i == j)
	    	if((i == 2 || i ==5 || i ==6) && (j == 2 || j ==5 || j ==6))
	  		g[i*10+j] = t[i] * (int64_t)t[j];			
        	else if(j%2)
	  		g[i*10+j] = t[i] * (int64_t)t[j] / 2; 
        	else
		  g[i*10+j] = t[i] / 2 * (int64_t)t[j];		
 	    else if(i%2)
	  		g[i*10+j] = f[i] * (int64_t)t[j];
       	    else
	  	  g[i*10+j] = f[i] * (int64_t)f[j];

    int64_t h_ = [10] = {0};

    h_[0] += g[0] + g[19] + g[38];	
    h_[1] += g[1] + g[27];	
    h_[2] += g[2] + g[28] + g[11] + g[39] + g[46];
    h_[3] += g[3] + g[12] + g[40];
    h_[4] += g[24] + g[4] + g[44];
    h_[5] += g[5] + g[13] + g[22] + g[41];
    h_[6] += g[6] + g[14] + g[23] + g[15] + g[47] + g[20];
    h_[7] += g[7] + g[16] + g[42];
    h_[8] += g[8] + g[17] + g[43] + g[26] + g[37];
    h_[9] += g[18] + g[9] + g[45] + g[10];

    int64_t qr[10] = {0};

    for(int i=0; i<10 ; i++)
    {
         qr[i] = (h_[i] + (1L << ((i==4 || i==5 || i==6 || i==7 || i==8 || i==9) ? 24:25))) >> ((i==4 || i==5 || i==6 || i==7 || i==8 || i==9) ? 25:26);
	 h_[(i+1)%10] += q[i];
	 h_[i] -= q[i] * ((i==4 || i==5 || i==6 || i==7 || i==8 || i==9) ? (1L << 25): (1L << 26 ));
    }

    h_[0] += carry9 * 19;

    carry0 = (h_[0] + (int64_t)(1L << 25)) >> 26;
    h_[1] += carry0;
    h_[0] -= carry0 * ((uint64_t) 1L << 26);

    for(int i=0 ; i<10 ; i++)
	h[i] = h_[i];
}
