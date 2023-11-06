void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_array[10];
    for(int32_t i=0; i<10; i++){ 
            f_array[i] = f[i]; 
    } 

    int32_t f_2_array[10];
    for(int32_t i=0; i<10; i++){ 
            f_2_array[i] = 2 * f_array[i]; 
    }

    int32_t f_newarray[5];
    f_newarray[0] = 38 * f_array[5];
    f_newarray[1] = 19 * f_array[6];
    f_newarray[2] = 38 * f_array[7];
    f_newarray[3] = 19 * f_array[8];
    f_newarray[4] = 38 * f_array[9];
    
    int64_t f_xf[45];
    f_xf[0] = f_array[0] * (int64_t) f_array[0];
    f_xf[1] = f_2_array[0] * (int64_t) f_array[1];
    for(int32_t i=2; i<10; i++){ 
            f_xf[i] = f_2_array[0] * (int64_t) f_array[i]; 
    }
    f_xf[10] = f_2_array[1] * (int64_t) f_array[1];
    for(int32_t i=1; i<9; i++){ 
            f_xf[10+i] = f_2_array[i] * (int64_t) f_array[i+1]; 
    }
    f_xf[20] = f_array[2] * (int64_t) f_array[2];
    for(int32_t i=1; i<8; i++){ 
            f_xf[20+i] = f_2_array[2] * (int64_t) f_array[i+2]; 
    }
    f_xf[30] = f_2_array[3] * (int64_t) f_array[3];
    for(int32_t i=1; i<7; i++){ 
            f_xf[30+i] = f_2_array[i] * (int64_t) f_array[i+3]; 
    }
    f_xf[40] = f_array[4] * (int64_t) f_array[4];
    for(int32_t i=1; i<5; i++){ 
            f_xf[40+i] = f_2_array[4] * (int64_t) f_array[i+4]; 
    }
    
    int64_t h_array[10];
    h_array[0] = f_xf[0] + 0.76 * f_xf[1] + 0.38 * f_xf[2] + 0.76 * f_xf[3] + 0.38 * f_xf[4] + f_newarray[0];
    h_array[1] = 0.5 * f_xf[0] + 0.38 * f_xf[9] + 0.38 * f_xf[8] + 0.38 * f_xf[7] + 0.38 * f_xf[6];
    for(int32_t i=2; i<10; i++){ 
            h_array[i] =0.5 * f_xf[i] + 0.5 * f_xf[i-1] + 0.76 * f_xf[9] + 0.38 * f_xf[8] + 0.76 * f_xf[i+1] + f_newarray[i-1]; 
    }

    int64_t carry_array[10];
    for(int32_t i=0; i<10; i++){ 
            carry_array[i]=0; 
    }
    
    for(int32_t i=0; i<10; i++){
        if(i==0 || i==4) 
	    {
	        carry_array[0] = (h_array[0] + (int64_t)(1L << 25)) >> 26;
	        h_array[1] += carry_array[0];
	        h_array[0] -= carry_array[0] * ((uint64_t) 1L << 26); 
	    }

	    else if(i%2 !=0)
	    {
		carry_array[i] = (h_array[i] + (int64_t)(1L << 24)) >> 25;
	        h_array[i+1] += carry_array[i];
            	h_array[i] -= carry_array[i] * ((uint64_t) 1L << 25);
	    } 

    	else {
		carry_array[i] = (h_array[i] + (int64_t)(1L << 25)) >> 26;
            	h_array[i+1] += carry_array[i];
            	h_array[i] -= carry_array[i] * ((uint64_t) 1L << 26);
	    }
    }

    carry_array[9] = (h_array[9] + (int64_t)(1L << 24)) >> 25;
    h_array[0] += carry_array[9] * 19;
    h_array[9] -= carry_array[9] * ((uint64_t) 1L << 25);

    carry_array[0] = (h_array[0] + (int64_t)(1L << 25)) >> 26;
    h_array[1] += carry_array[0];
    h_array[0] -= carry_array[0] * ((uint64_t) 1L << 26);
    
    for(int32_t i=0; i<10; i++){ 
    	h[i] = (int32_t) h_array[i];
    } 
}
