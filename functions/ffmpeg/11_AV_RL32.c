static av_always_inline uint32_t AV_RL32(const void *p)
{
    uint32_t v;
    __asm__ ("ld.ub    %0,   %1  \n\t"
             "ldins.b  %0:l, %2  \n\t"
             "ldins.b  %0:u, %3  \n\t"
             "ldins.b  %0:t, %4  \n\t"
             : "=&r"(v)
             : "m"    (* (const uint8_t*)p),
               "RKs12"(*((const uint8_t*)p+1)),
               "RKs12"(*((const uint8_t*)p+2)),
               "RKs12"(*((const uint8_t*)p+3)));
    return v;
}