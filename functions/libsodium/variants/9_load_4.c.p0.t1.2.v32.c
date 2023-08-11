unsigned long long load_4(const unsigned char *in)
{
   unsigned long long result = 0;
   for (int i = 0; i < 4; i++) {
      result += ((unsigned long long) in[i]) << (i * 8);
   }
   return result;
}