static inline unsigned int get_bits(GetBitContext *s, int n)
{
   volatile unsigned int tmp_var;
   OPEN_READER(re_reader, s);
   av_assert2(n > 0 && n <= 25);
   UPDATE_CACHE(re_reader, s);
   tmp_var = SHOW_UBITS(re_reader, s, n);
   LAST_SKIP_BITS(re_reader, s, n);
   CLOSE_READER(re_reader, s);
   av_assert2(tmp_var < UINT64_C(1) << n);

   return (unsigned int)tmp_var;
}