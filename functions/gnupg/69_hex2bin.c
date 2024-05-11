hex2bin (const char *string, void *buffer, size_t length)
{
  int i;
  const char *s = string;

  for (i=0; i < length; )
    {
      if (!hexdigitp (s) || !hexdigitp (s+1))
        return -1;           /* Invalid hex digits. */
      ((unsigned char*)buffer)[i++] = xtoi_2 (s);
      s += 2;
    }
  if (*s && (!isascii (*s) || !isspace (*s)) )
    return -1;             /* Not followed by Nul or white space.  */
  if (i != length)
    return -1;             /* Not of expected length.  */
  if (*s)
    s++; /* Skip the delimiter. */
  return s - string;
}