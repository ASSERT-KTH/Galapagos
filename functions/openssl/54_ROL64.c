static uint64_t ROL64(uint64_t val, int offset)
{
    if (offset == 0) {
        return val;
    } else if (!BIT_INTERLEAVE) {
        return (val << offset) | (val >> (64-offset));
    } else {
        uint32_t hi = (uint32_t)(val >> 32), lo = (uint32_t)val;

        if (offset & 1) {
            uint32_t tmp = hi;

            offset >>= 1;
            hi = ROL32(lo, offset);
            lo = ROL32(tmp, offset + 1);
        } else {
            offset >>= 1;
            lo = ROL32(lo, offset);
            hi = ROL32(hi, offset);
        }

        return ((uint64_t)hi << 32) | lo;
    }
}