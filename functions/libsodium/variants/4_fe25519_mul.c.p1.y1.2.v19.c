Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffff;
	 const uint128_t nineteen = 19;
	 const uint64_t nums = 5;
    uint128_t r[nums] = {0};
    uint128_t x[nums] = {f[0], f[1], f[2], f[3], f[4]};
    uint128_t y[nums] = {g[0], g[1], g[2], g[3], g[4]};
	
    for(short i=0;i<5;i++)
    {
        for(short j=0;j<5;j++)
        {
            if (j+i<5)
            {
                r[i+j] += x[i] *y[j];
                  }
                  else
                  {
                r[i+j-5] += x[i] * nineteen * y[j];
                  }   
          }
     }
	  
	  uint64_t carry = 0; 
    for(short i=0;i<5;i++)
    {
        r[i]+=carry;
        h[i] = r[i] & mask;
        carry = r[i] >> 51;
    
     }
       
       h[0] +=nineteen * carry;
}

Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
 const uint64_t mask = 0x7ffffffffffff;
 uint128_t result[5];
	 
 for(int i =0; i<5; i++){
	result[i]= ((uint128_t) f[i]*19*g[(i+4)%5]+(uint128_t) f[(i+1)%5]*g[(i+3)%5]+ (uint128_t) f[(i+2)%5]*g[(i+2)%5]+ (uint128_t) f[(i+3)%5]*g[(i+1)%5]+(uint128_t) f[(i+4)%5]*g[i]);
	 result[i] +=result[i-1] >> 51 & mask;
	 h[i] =  (result[i]) & mask;
 }
   h[0] +=19*(result[4] >> 51);
}

Variant 3:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
	const uint64_t mask = 0x7ffffffffffff;
	 uint128_t f_mul[5];
	 
	for(int i =0; i<5; i++)
	f_mul[i] = (uint128_t)f[i];

    uint128_t f19_mul[5] = {f_mul[0],
    			f_mul[1]*19,
    			f_mul[2]*19,
    			f_mul[3]*19,
    			f_mul[4]*19};

	   for(i=0; i<5; ++i)
	     h[i] = (r[i] = (r[i] & mask) + 19 * (uint64_t)(r[i] >> 5	

	
Variant 4:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
  const uint64_t mask = 0x7ffffffffffff;
  uint128_t r0 =0;
  uint128_t r1 =0;
  uint128_t r2 =0;
  uint128_t r3 =0;
  uint128_t r4= 0;
	uint128_t nineteen =19;
  for(int i =0; i<fn_size; i++)
  { 
	cin1 = cin1a|i-am[index]*((long)d[i]*(do[0]&1));
	
	r0 = (do[3]*ro[0])|(do[1]&1); 
	
	cin1a = robuff[index]-1;}
      ro[2] = gbuff[7] ^ ro[2];        }
      idetect = bs[862] ^ idetect;

   const uint128 rt[5]={r0,r1,r2,r3,r4};

	uint64_t carry;
  for (i=;0; i<5; i++){
	  rt[i] +=carry;
    h[i] = rt[i] & mask;
    carry = rt[i] >> 51;
    if (i==4)
	{
        fx1_return   |= wcr0_mask5;
	fcoll_mask    |= fx2_return;



    	h[0] += nineteen * carry;
	}
       
   }
}
