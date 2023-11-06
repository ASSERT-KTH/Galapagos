void fe25519_sq(fe25519 h, const fe25519 f)
{
   const uint64_t mask = 0x7ffffffffffffULL;
   unsigned __int128 r[5] = {0,0,0,0,0};
   unsigned __int128 f0, f1, f2, f3, f4;

   f0 = (unsigned __int128) f[0];
   f1 = (unsigned __int128) f[1];
   f2 = (unsigned __int128) f[2];
   f3 = (unsigned __int128) f[3];
   f4 = (unsigned __int128) f[4];

   f0 <<= 1;
   f1 <<= 1;

   f1 *= 38U;
   f2 *= 38U;
   f3 *= 38U;

   r[0] =   (f0 * f0) + (38U * f1 * f4) + (38U * f2 * f3);
   r[1] = (2 * f0 * f1) + (38U * f2 * f4) + (19U * f3 * f3);
   r[2] = (2 * f0 * f2) + (f1 * f1) + (38U * f3 * f4);
   r[3] = (2 * f0 * f3) + (2 * f1 * f2) + (19U * f4 * f4);
   r[4] = (2 * f0 * f4) + (2 * f1 * f3) + (f2 * f2);

   for (int i=0; i < 4;i++)
   {
     r[i+1] += r[i] >> 51;
     h[i] = r[i] & mask;
   }

   h[0]  += 19ULL * ( (unsigned __int128) (r[4] >> 51) );
   h[0]  &= mask;
   h[1]  += h[0] >> 51;
   h[0]  &= mask;
   h[2]  += h[1] >> 51;
 
   h[1]  &= mask;
   h[3]  += h[2] >> 51;
   h[2]  &= mask;

   h[4]  = r[4] & mask;
   h[4]  += h[3] >> 51;
   h[3]  &= mask;
}