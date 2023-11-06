The following variant does exactly the same as the original function. It just changes the way in which the process is carried out:


btc_read32le(const uint8_t *xp) {
    uint32_t z = 0;

#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 4; i++) {
        z = ((z << 8) + xp[i]);
    }
#else
    memcpy(&z, xp, 4);
#endif

    return z;
}


This procedure involves byte-wise reading and subsequent aggregation which serves the same purpose as shifting and OR-ing. For instance, if BTC_BIGENDIAN is defined, it does a more readable bit-by-bit read instead of the whole operation at once like the original method.
The bit shift isn't anymore visible as an operation, but a consequence of adding the xp value to a number previously shifted. Also the direct process sequence of the referenced bytes from the shifting's multiplicities (0, 8, 16, 24) becomes evident by the iteration numbers (0, 1, 2, 4).