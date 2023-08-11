Here is a variant of your original function, which maintains its functionality. The difference here is that instead of manipulating the pointer within the then clause of the if-statement, we introduce separate counters to keep track of where we are assigning the shifted byte values:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t counter = 0;
    zp[counter] = (x >>  0); counter++;
    zp[counter] = (x >>  8); counter++;
    zp[counter] = (x >> 16); counter++;
    zp[counter] = (x >> 24); counter++;
    zp = zp + counter;
#else
    memcpy(zp, &x, sizeof(x));
    zp = zp + 4;
#endif
    return zp;
}


In this variant, btc_uint32_write function copies the contents of type uint32_t variable x into an array of type uint8_t , in the order of higher byte order to lower byte order if BTC_BIGENDIAN macro is set/defined, irrespective of processor's endianess. Else copies using standard library function memcpy in the way of processor's (could be either little endian or big endian) natural byte-order.