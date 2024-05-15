modp_ninv31(uint32_t p) {
    uint32_t y;

    y = 2 - p;
    y *= 2 - p * y;
    y *= 2 - p * y;
    y *= 2 - p * y;
    y *= 2 - p * y;
    return (uint32_t)0x7FFFFFFF & -y;
}