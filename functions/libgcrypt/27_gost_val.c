gost_val (u32 subkey, u32 cm1, const u32 *sbox)
{
  cm1 += subkey;
  cm1 = sbox[0*256 + ((cm1 >>  0) & 0xff)] |
        sbox[1*256 + ((cm1 >>  8) & 0xff)] |
        sbox[2*256 + ((cm1 >> 16) & 0xff)] |
        sbox[3*256 + ((cm1 >> 24) & 0xff)];
  return cm1;
}