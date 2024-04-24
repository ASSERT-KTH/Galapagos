static av_always_inline uint16_t AV_RB16(const void *p)
{
    uint16_t v;
    __asm__ ("ld.ub    %0,   %2  \n\t"
             "ldins.b  %0:l, %1  \n\t"
             : "=&r"(v)
             : "RKs12"(*(const uint8_t*)p), "m"(*((const uint8_t*)p+1)));
    return v;
}