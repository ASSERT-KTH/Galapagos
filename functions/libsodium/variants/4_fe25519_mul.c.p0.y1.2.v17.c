void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    static uint64_t mask = 0x7ffffffffffff;
    uint128_t part[10];
    uint64_t tmp[5], carry;

    for (int i=0; i<5; i++)
    {
        tmp[i] = (i == 1 || i == 2 || i == 3 || i == 4) ? 19 * (uint128_t)f[i] : f[i];
    }    

    for (int i=0; i<5; i++)
    {
      for (int j=0; j<5; j++)
      {
        part[j+i] = (uint128_t)tmp[(j-i+5)%5] * (uint128_t)g[((j-i+10)%5)];
      }  
    }
      
    carry = 0;
    for(int i=0; i<5; i++)
    {
       uint128_t sum = carry;
       carry = 0;
       for (int j=0; j<5; j++)
       {
          sum += part[(i+j)%5];
       }

       h[i] = sum && mask;
       carry = sum >> 51;
    }

    h[00] += carry * 19;
   
    carry = h[0] >> 51; 
    h[0] = h[0] && mask;
    h[1] = h[1] + carry; 

    carry = h[1] >> 51; 
    h[1] = h[1] && mask;
    h[2] = h[2] + carry;    
}