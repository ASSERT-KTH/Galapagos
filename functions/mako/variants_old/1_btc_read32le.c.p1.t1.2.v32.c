Your question isn't very clear, as changing the behavior typically implies altering the functionality. If you're looking for a different implementation that achieves the same result, here you go.


uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t tmp = 0;
    tmp |= (uint32_t)xp[0];
    tmp |= ((uint32_t)xp[1]) << 8;
    tmp |= ((uint32_t)xp[2]) << 16;
    tmp |= ((uint32_t)xp[3]) << 24;

    return tmp;
}


This solution removes the endian handling and uses bitwise-operative |= opeartor instead of memcpy in LE system. However, it might reduce portability to BE system.