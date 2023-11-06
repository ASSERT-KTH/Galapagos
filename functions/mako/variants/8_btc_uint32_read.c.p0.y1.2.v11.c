int btc_uint32_read(uint32_t* zp, const uint8_t** xp, size_t* xn) {
    if (*xn < 4) {
        return 0;
    }

    int i;
    *zp = 0;
  
#if defined(BTC_BIGENDIAN)
    for (i = 0; i < 4; i++) {
        *zp |= ((uint32_t)(*xp)[i]) << (8 * i);
    }
#else
    memcpy(zp, *xp, 4);
#endif

    // Move the pointer 4 bytes ahead and reduce the remaining size by 4
    (*xp) += 4;
    (*xn) -= 4;

    return 1;
}