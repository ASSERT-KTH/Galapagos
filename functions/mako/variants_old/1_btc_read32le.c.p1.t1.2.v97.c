You have stated "changes the behavior ... while maintaining its original functionality" which may appear controversial and depends on interpretation. I will provide alternative implementation maintaining original function's input/output scenario.


uint32_t btc_read32le(const uint8_t *xp) {
  uint32_t res = 0;
  for (int i = 0; i < 4; i++) {
    res += xp[i] << (i * 8);
  }
  return res;
}
