void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};

    int32_t dbl_f_values[10];
    int32_t new_f_values[5]; 

    for(int i = 0; i < 10; i++)
    {
        dbl_f_values[i]= 2 * f_values[i]; 
    }

    new_f_values[0] = 38 * f[5];
    new_f_values[1] = 19 * f[6];
    new_f_values[2] = 38 * f[7];
    new_f_values[3] = 19 * f[8];
    new_f_values[4] = 38 * f[9];

    
    int64_t temps[15];
    int a = 0;
    for(int i = 0; i <= 8; i ++) {
        for(int j = i; j <= 9; j ++) {
            temps[a] = dbl_f_values[i] * (int64_t) f_values[j];
            a++;
        }
    }

    int64_t h_values[10] = {
	    temps[0] + temps[10] + temps[15] + temps[19] + temps[22] + temps[27],
	    temps[1] + temps[16] + temps[20] + temps[23] + temps[28],
	    dbl_f_values[0]*temps[4] + temps[2]*2 + temps[21] + temps[24] + temps[29],
	    temps[3]*2 + temps[11] + temps[25] + temps[30],
	    temps[5]*2 + temps[4]*2 + temps[6] + temps[12] + temps[31] + temps[33],
	    temps[7]*2 + temps[5]*2 + temps[26] + temps[32],
	    temps[8]*2 + temps[6]*4 + temps[9]+ temps[18] + temps[34] + temps[13],
	    temps[17] + temps[10]*2 + temps[7]*2 + temps[14],
	    temps[8]*dbl_f_values[0] + temps[11]*dbl_f_values[3] + temps[9]*dbl_f_values[2] + temps[16]*dbl_f_values[5] + temps[0] + temps[35],
	    temps[12]*dbl_f_values[2] + temps[21]*2 + temps[31]*2 + temps[34]*2 + temps[7]*dbl_f_values[4],
    };

    int64_t carry[10];
    
    for (int i = 0; i < 10; i ++) {
        carry[i] = (h_values[i] + (int64_t) (1L << (25 + (1 - (i % 2))))) >> (26 - (i % 2));
    	
		    h_values[(i + 1)%10] += carry[i];
	     	h_values[i] -= carry[i] * ((uint64_t)1L << (26 - (i % 2)));
    }
	
	  carry[9] = (h_values[9] + (int64_t)(1L << 24)) >> 25;
	  h_values[0] += carry[9] * 19;
	  h_values[9] -= carry[9] * ((uint64_t) 1L << 25);

	  carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
  	h_values[1] += carry[0];
  	h_values[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i = 0; i < 10; i ++)
    {
        h[i] = (int32_t) h_values[i];
    }
}