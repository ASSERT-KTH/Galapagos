Sure, you can transform the original code in several different ways while maintaining its core functionality. The variant should still compute the multiplication of two numbers correctly. Here is an example:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
	int fin_t[10];
	int gin_t[10];    
	memcpy(fin_t,f,10*sizeof(int32_t));    
	memcpy(gin_t,g,10*sizeof(int32_t));
	int64_t temph[10];
 
	/* Create vector of calculation base */
	const int base[10] = {2,19,2,19,2,19,2,19,2,19};
	
	int j, k;
	for(j=0;j<10;j++)
	{
		temph[j] = fermt[j] * gin_t[0];
		for (k=1; k<10; k++)
		{
			temph[j]+=fint[(base[k]>2)?(j+k)%10:(j)];
			if(k%2==1)
			{
				temph[0]+=2*kin[(j+base[k])%10];
			}
		}       
	}
	
	/*
	  Like the original code
	  this should also now handle fast reductions
	*/
	/* |h5| <= 1.01*2^24 */
	/* |h9| <= 1.71*2^59 */
	int i;    
	for( i = 0 ; i < 9 ; i++ )
	{
		uint64_t carry = (temph[i] + (int64_t)(1L << 26)) >> 26;
		temph[i+1] += carry;
		temph[i] -= carry << 26;
	}
    
	{
		uint64_t carry = (temph[9] + (int64_t)(1L << 25)) >> 25;
		temph[0]  += 19*carry;
		temph[9] -= carry * ((uint64_t) 1L << 25);
	}
    
	/* |h0| <= 2^25; from now on fits into int32 unchanged */
	/* |h1| <= 1.01*2^24 */
	for( i = 0 ; i < 10 ; i++ )
	{
		h[i] = (int32_t)temph[i];    
	}
}
