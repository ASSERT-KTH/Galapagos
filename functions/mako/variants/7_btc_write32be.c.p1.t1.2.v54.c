Here you go:


void btc_write32be(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
        *(uint32_t *)zp = x;
    #else
        zp[0] = (uint8_t)(x >> 24) & 0xFF;
        zp[1] = (uint8_t)(x >> 16) & 0xFF;
        zp[2] = (uint8_t)(x >> 8)  & 0xFF;
        zp[3] = (uint8_t)x         & 0xFF;
    #endif
}


The above function modifies the original function in the sense that it uses bitwise masking with `0xFF` (255) to assume there's no data present in each byte slice above 255, regardless of how the compiler treats shifts (arithmetically- or logically-shifted).

By the way, another variance in the code's behavior from the original function is how it stores `x` directly into `zp` instead if it's running on a big-endian machine. It uses a pointer typecast to `uint32_t *` necessary to treat `zp` like a pointer to a `uint32_t` than to a `uint8_t`, which provides the handle for it to hold the entirety of `x`. Remember to ensure that the address stored in `zp` is properly aligned for a `uint32_t` if you apply direct writing like this.

Take note that the variant must not inherently work exactly the way as your original reference implementation, but results would be identical. One could add safeguards though to secure optimal portability, if that’s what you need. Various quality of life improvements could emerge from taking different contexts into account.