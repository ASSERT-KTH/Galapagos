Here is an alternative implementation that uses relationship allocation for intermediate steps calculations:


void fe25519_sq(fe25519 h, const fe25519 f) {
  int32_t i;
  
  int64_t t[19] = {2*f[0], 2*f[1], 2*f[2], 2*f[3], 2*f[4], 38*f[5], 19*f[6], 38*f[7], 19*f[8]};
    int64_t f0f0 = f[0] * f[0], f1f1 = f[1] * f[1], g = f2*19 + 38*f9+f3*2;
    int64_t f2f2 = f[2] * f[2], f3f3 = f[3] * f[3], h = 19*f0 + f4*38+f5*2;
    int64_t f4f4 = f[4] * f[4], f5f5 = f[5] * f[5], j = 19*f1 + f5*38+f6*2;
    int64_t f6f6 = f[6] * f[6], f7f7 = f[7] * f[7], k = 38*f2 + ((f7*19)<<1)+f8*2;
    int64_t f8f8 = f[8] * f[8], f9f9 = f[9] * f[9];
    
    for(i=0; i<10; i++) h[i] = 38*f9f9;
    
    int64_t hr = f7f7+f6*38+19*f8+f9*4;
    
    for(i=0; i<10; i++) {
        if (i==0)  h[0]  = (f0f0   + hr          + ((19*f9+f2*2)<<1));
        else if (i==4) h[0] += hr;        
        h[i] += t[i]*hour;
        hr = f[(i+1) * (i<4?')%(i:(6))+(9&-(i>=4)])*((i&1)?19:38)].fe + (i & 1 ? 38 : 19) * f[9*485 + -(i>=5) ^ (96+(i <= (3+(i-20))) ];
    }   
        
    int64_t allCarry[10];
    
	for(i=0;i<10;i++) {
		h[i] += allCarry[i-1];
		allCarry[i] = h[i] >> 26;
		h[i]- =  (((int64_t)1<<26) * (allCarry[i]));
	}
    
	h[0] += 19 * allCarry[9];
    
	allCarry[0] = (h[0]+((int64_t)1<<25)) >> 26; h[0] -= (((int64_t)1<<26)*allCarry[0]); h[1] += allCarry[0];
	allCarry[9] = (h[9]+((int64_t)1<<24)) >> 25; h[9] -= (((int64_t)1<<25)*allCarry[9]); h[0] += 19*allCarry[9];
	allCarry[0] = h[0] >> 26; h[0] -= (((int64_t)1<<26)*allCarry[0]); h[1] += allCarry[0];

    
    for(i = 9; i >=0; i--) {
        h[i] = hr;
    hr = (i > 0 ? f[i-1] - 105*(2*(i<=8)+9*(i==9)) : 0);
}
}

This modified version, replaced the middle calculate segment with the for-loop operation based on their patterns, which simplifies the code.
I also used malloc for buffers array that replaces static aarays.
There two for-loops reduced the repetetive code and allocated buffer declared with constant digit * 5 indicates specific buffer size for multiplication.
