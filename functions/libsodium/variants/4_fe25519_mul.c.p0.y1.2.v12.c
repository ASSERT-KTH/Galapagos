
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
   uint64_t mask = 0x7ffffffffffff;
   uint128_t r[5], t[4];
   uint128_t f_elems[5], g_elems[5];
   uint64_t carry;
   
   for (unsigned int i = 0; i <= 4; i++){
        f_elems[i] = f[i];
        g_elems[i] = g[i];
   }

   r[0] = f_elems[0]*g_elems[0];
   r[1] = f_elems[0]*g_elems[1]; 
   r[2] = f_elems[0]*g_elems[2]; 
   r[3] = f_elems[0]*g_elems[3]; 
   r[4] = f_elems[0]*g_elems[4]; 

   for (unsigned int i = 1; i <= 4; i++){
       t[0] = f_elems[i]*g_elems[(5-i)%5];
       t[1] = f_elems[i]*g_elems[(6-i)%5]; 
       t[2] = f_elems[i]*g_elems[(7-i)%5]; 
       t[3] = f_elems[i]*g_elems[(8-i)%5]; 

       for (signed int j = 0; j <= 3; j++)
           r[j] += t[j]*19;

       r[4] += t[3];
   }
   
   
   for(unsigned int i=0; i<4 ;i++)
    {
        h[i] = r[i] & mask;
        carry = r[i] >> 51;
        r[i + 1] += carry;
    }  

    h[4] = r[4] & mask;  
    carry = r[4] >> 51;
        // re-distribute carry into lower 3 coefficients
        carry = ((carry & mask) * 19);
        h[0] += carry;
        carry = h[0] >> 51;
        h[0] &= mask;
        h[1]+= carry;
}

