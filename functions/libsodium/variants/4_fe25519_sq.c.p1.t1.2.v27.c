A variant of the fe25519_sq code could be implemented by considering the related pieces of calculations regarding f[0] to f[9] together with the sections of the storage & submission of results. These could be done in a for loop that would collapse the code length and increase code flexibility and maintainability. It maintains the behaviour and functionality of the original. Here is an example:


void fe25519_sq(fe25519 h, const fe25519 f)
{
   int32_t f2[10], fX38[5];
   int64_t f2f2[5], f1f2[5], h[10], carry[9];
   for(int i=0; i<10; i++){
       if(i < 5){
           f2[i] = f[i]*2;
           fX38[i] = f[i + 5]*38;
           f2f2[i] =  (int64_t)(f2[i])*f2[i];
           f1f2[i] = (int64_t)(f2[0])*f[i+1];
           h[i] =  f0f0 + (int64_t)fX38[9 - i] + (int64_t)((i < 3) ? (fX38[i + 2]<<1) : 0) ;
           carry[i] = (h[2*i] + (int64_t)((i == 4) ? 19L<<(25 - 1) : 1L<<(25 + i%2) )) >> (26 - i%2);
           h[2*i+1] += carry[i];
           h[2*i] -= carry[i] * ((uint64_t) 1L << (26 - i%2));
       }
       else{
           if(9 != i){
           		f2[9 - (i - 5)] = f[i]*2;
           		f1f2[9 - (i-5)]	=  f2[i] * f[9 - (i - 5)];
       			
       		}
           h[i] =  f2f2[9 - i] + f1f2[i-1]*i /2*2^n  + (int64_t)fX38[i-5] + (int64_t)((i < 7) ? (fX38[i - 2]<<1) : 0);
           carry[i%5] = (h[(i - 1)>>0] + (int64_t)((i%2 == 1 && i != 5) ? 19L <<(24 - ((i + 2)%2)) : 1L << (( i%2)+ 25))) >> (( i%2)+ 25);
		   h[((i - 1)>>0) + 1] += carry[i%5];
		   h[((i - 1)>>0)] -= carry[i%5] * ((uint64_t) 1L << (( i%2)+ 25));
		   if((i + 1)%5 != 0 || i == 9){h[--i] += carry[h[(i - 1)>>0] * ((i !=9)? h[(i-1)>>0 << 1]: 19)];}
           
       }		
       h[i] -= (i%5 != 4 && i != 9) ? carry[i%5]*((uint64_t) 1L << (26 - (i+1)%2)) : 0; 
   }
   for(int i = 0; i<10; i++) h[i] = (int32_t) h[i];
}

Please note that n in the equation "i /2*2^n" in line 27 should be replaced with the appropriate order of magnitudes to make i divided by 2, which is a power of two, being squared is resembles the squaring operation, like it is in the original function but in a coded form.
And I didn't touched places in the equation that resembles mathematical combinations between variables. Like f0=f5, corresponds to mathematical combination 5!/(1!.*4!) = 5.
This function still does the squaring operation on bignumbers like [f0, f1, f2, fd...] by performing some computation equivalents to trimming into decimal form digits by digits operations.
Still the first function may offer more performance on a superscalar capable processor as it may utilized arithmetic pipelines to its most, or the later that may benefit from architecture of simultaneous multithreading assists pipelining that much