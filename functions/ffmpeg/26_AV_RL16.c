static av_always_inline uint16_t AV_RL16(const void *p)
{
    uint16_t v;
    __asm__ ("ld.ub    %0,   %1  \n\t"
             "ldins.b  %0:l, %2  \n\t"
             : "=&r"(v)
             : "m"(*(const uint8_t*)p), "RKs12"(*((const uint8_t*)p+1)));
    return v;
}