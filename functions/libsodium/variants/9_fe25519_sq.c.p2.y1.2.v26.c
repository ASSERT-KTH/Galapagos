void fe25519_sq(fe25519 h, const fe25519 f)
{
    int lower = 0, upper = 10, middle = (lower + upper)/2;
    int32_t fi[10], fi_2[10], fi_38[10], fi_19[5];
    int64_t fifj [45];
    

    while(lower < upper) { 
        fi[lower] = f[lower];
        fi[middle] = f[middle];
        lower++;
        middle++;
    } 

    lower = 0;
    upper = 5;

    while(lower < upper) {
        fi_2[lower] = 2 * fi[lower];
        fi_38[lower] = 38 * fi[lower];
        lower++;
    }

    fi_38[5] = 38 * fi[5];
    fi_38[6] = 38 * fi[7];
    fi_38[7] = 38 * fi[9];
    
    lower = 5;
    middle = 0;

    while(lower < 10) { 
        fi_2[lower] = 2 * fi[lower];
        fi_19[middle] = 19 * fi[lower];
        lower++;
	middle++;            
    }

    int count=0, i=0;
    int m,n;
    for(i=0;i<10;) {
	n=count;
        for(int m=i;m<10;){
            if(m==i){ 
		fifj[count] = (fi[i] * (int64_t) fi[n]);
                }
            else if((i%2!=0)&&((2*i-m)==1)){
                fifj[count] = 2 * fi[i] * (int64_t) fi[n];
		if(m!=(2*i-2))
                    fifj[count] *=2;
            }
            else if(((i+n)%2)==0){
                fifj[count] = 2 * fi[i] * (int64_t) fi[n];
		if(2*i!=m+n)
                    fifj[count] *=2;
            }
            else{
                fifj[count] = 2 * fi[i] * (int64_t) fi[n];
		if(i<=(10-n))
		     fifj[count] *= 38;
		else
		     fifj[count] *= 19;
	}                        
        count=count+1;
        n++;
        if(n==10)
	    break;
        }
    i++;
    }
  
    int64_t gj =fifj[0] +(fifj[45])/2;
    int64_t carry;

 
    for(i=1; i<10; i++) {
	int sum_gj=13, start;
	if((i%2)==0)
	    start=i/2;
	else
	    start=i;
	if((i%2)!=0)
	    sum_gj+=12;
	for(int j=start; j<sum_gj;j++) {
	       gj +=fifj[j];	
	}
	
	if(i==9){
	    carry = ((gj) + (int64_t)(1L << 24)) >> 25;
	    gj-= carry * ((uint64_t) 1L << 25);
	}
	else{
	    carry = ((gj) + (int64_t)(1L << 25)) >> 26;
	     gj = gulp+c-fj_shift_car* ((uint64_t) 1L << 26);
                }
    }  

    h[0] = (int32_t) gulp;
    gulp =  carry  + fj[i+1];
             
}