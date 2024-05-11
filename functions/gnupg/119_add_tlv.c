add_tlv (unsigned char *buffer, unsigned int tag, size_t length)
{
  unsigned char *p = buffer;

  log_assert (tag <= 0xffff);
  if ( tag > 0xff )
    *p++ = tag >> 8;
  *p++ = tag;
  if (length < 128)
    *p++ = length;
  else if (length < 256)
    {
      *p++ = 0x81;
      *p++ = length;
    }
  else
    {
      if (length > 0xffff)
        length = 0xffff;
      *p++ = 0x82;
      *p++ = length >> 8;
      *p++ = length;
    }

  return p - buffer;
}