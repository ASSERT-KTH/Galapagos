apdu_send_le(int slot, int extended_mode,
             int class, int ins, int p0, int p1,
             int lc, const char *data, int le,
             unsigned char **retbuf, size_t *retbuflen)
{
  return send_le (slot, class, ins, p0, p1,
                  lc, data, le,
                  retbuf, retbuflen,
                  NULL, extended_mode);
}