Here's a variant where the procedure is conditioned at run-time instead of compile-time. Bitcoin big-endians platforms put the most significant byte first (0x12 0x34 vs 0x34 0x12). The big-endian swap sequence was transposed for clarity and portability reasons. The variant is as follow:


uint32_t btc_read32le(const uint8_t *xp)
{
    uint32_t value;

    bool isBigEndian = (*(unsigned char *)&(uint16_t){1});

    if (isBigEndian) // BTC_BIGENDIAN
    {
        value = ((uint32_t)xp[3] << 0)
              | ((uint32_t)xp[2] << 8)
              | ((uint32_t)xp[1] << 16)
              | ((uint32_t)xp[0] << 24);
    }
    else
    {
        memcpy(&value, xp, sizeof(value));
    }   
    return value;
}

The `isBigEndian` procedure uses pointer casting of an initialized `uint16_t` that will under the hood either initialize as `[0x00 0x01]` for big-endian modes, or `[0x01 0x00]` if little-endian mode making the final result that when `*unsigned char[0] == 0x1` the system is little-endian, and otherwise, it's big-endian. When checking then directly `*(unsigned_char*)&;(uint16_t){0x01} == 0x1` if true otherwise it's big-endian. This variant also tends to be more processor-agnostic compared to determining at compile time. Anyway, both methods have their usages, for platform-specific or portable application purposes.