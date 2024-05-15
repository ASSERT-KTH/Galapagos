drbg_add_buf (unsigned char *dst, size_t dstlen,
              unsigned char *add, size_t addlen)
{
  /* implied: dstlen > addlen */
  unsigned char *dstptr, *addptr;
  unsigned int remainder = 0;
  size_t len = addlen;

  dstptr = dst + (dstlen - 1);
  addptr = add + (addlen - 1);
  while (len)
    {
      remainder += *dstptr + *addptr;
      *dstptr = remainder & 0xff;
      remainder >>= 8;
      len--;
      dstptr--;
      addptr--;
    }
  len = dstlen - addlen;
  while (len && remainder > 0)
    {
      remainder = *dstptr + 1;
      *dstptr = remainder & 0xff;
      remainder >>= 8;
      len--;
      dstptr--;
    }
}