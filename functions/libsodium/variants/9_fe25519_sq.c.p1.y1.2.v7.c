Variant 1: Direct Assigment to `h`
In this approach, each element of `h` will be directly assigned without carrying or calculating carry separately.

void fe25519_sq(fe25519 h, const fe25519 f)
{
   // keep initial operations same
   // ......
   
   h[0] = (int32_t) ( ( (h0 + (int64_t) (1 << 25)) >> 26) * 19 );
   h[1] = (int32_t) ( (h1 + (int64_t) (1L << 25)) >> 26);
   
   h[2] = (int32_t) ( (h2 + (int64_t) (1L << 25)) >> 26);
   h[3] = (int32_t) ( (h3 + (int64_t) (1L << 25)) >> 26);
   
   h[4] = (int32_t) ( (h4 + (int64_t) (1L << 25)) >> 26);
   
   h[5] = (int32_t) ( (h5 + (int64_t) (1L << 25)) >> 26);
   h[6] = (int32_t) ( (h6 + (int64_t) (1L << 25)) >> 26);
   
   h[7] = (int32_t) ( (h7 + (int64_t) (1L << 25)) >> 26);
   h[8] = (int32_t) ( (h8 + (int64_t) (1L << 25)) >> 26);
   
   h[9] = (int32_t) ( (h9 + (int64_t) (1L << 25)) >> 26);
}

Variant 2: Jointed Array
Using an array which holds both `f` and `h` values might save separate variable declarations, but changes internal calculation from being in constants' perspective to original `f` values.

void fe25519_sq(fe25519 h, const fe25519 f)
{
   int64_t fh[8];
   
   for(int i=0; i<8; i++){
       fh[i] = f[i];
       fh[i+1] = f[i+1];
       fh[i+2] = f[i+i];
       fh[i+8] = f[i+8];
   }
   
   for(int j=0; j<8; j++){
       fh[j] = fh[j] * fh[j+1] + fh[j+8];
       fh[j] = (int64_t) ( (fh[j] + (int64_t) (1 << 25)) >> 26 );
   }
   
   for(int k=0; k<10; k++){
       h[k] = (int32_t) fh[k+10];
   }
}
