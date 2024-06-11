static int int16_t_nonzero_mask (int16_t x)
{
  uint16_t u = x;
  uint32_t v = u;
  v = -v;
  v >>= 31;
  return -v;
}
