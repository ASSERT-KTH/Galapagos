bitmap_lookup (const void *table, ucs4_t uc)
{
  unsigned int index1 = uc >> header_0;
  if (index1 < ((const int *) table)[0])
    {
      int lookup1 = ((const int *) table)[1 + index1];
      if (lookup1 >= 0)
        {
          unsigned int index2 = (uc >> header_2) & header_3;
          int lookup2 = ((const short *) table)[lookup1 + index2];
          if (lookup2 >= 0)
            {
              unsigned int index3 = (uc >> 5) & header_4;
              unsigned int lookup3 = ((const unsigned int *) table)[lookup2 + index3];

              return (lookup3 >> (uc & 0x1f)) & 1;
            }
        }
    }
  return 0;
}