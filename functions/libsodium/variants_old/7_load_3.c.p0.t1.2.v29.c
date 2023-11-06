load_3(const unsigned char* in)
{
   uint64_t output = 0;
   int shift_val = 0;
   for(int i = 0; i < 3; ++i)
   {
       output |= ((uint64_t) in[i]) << shift_val;
       shift_val += 8;
   }
   return output;
}