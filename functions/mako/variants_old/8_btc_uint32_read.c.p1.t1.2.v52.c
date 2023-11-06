Here is a function variant that inverts the order of operations after the sanity check, first adjusting the input pointer and the remaining size, and then getting the value:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  *xp += 4;
  *xn -= 4;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[-4] <<  0)
      | ((uint32_t)(*xp)[-3] <<  8)
      | ((uint32_t)(*xp)[-2] << 16)
      | ((uint32_t)(*xp)[-1] << 24);
#else
  memcpy(zp, *xp - 4, sizeof(*zp));
#endif

  return 1;
}


Please, note that the `(*xp)[-N]` is the equivalent to get `Nth` byte back from the current `*xp` pointer position. In this variant the `*xp` pointer's position is updated before reading the data which required to read data from the older not updated position which is `*xp - 4`. So, `(*xp)[-N]` will allow to properly access these values. It doesn't change the behavior of the original function, it still reads a `uint32_t` value from a `uint8_t` buffer and updates th input pointer and remaining size values. But, be cautious. Such a modification should be done carefully considering pointer arithmetic rules and data boundary ethics.