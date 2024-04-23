static av_always_inline uint32_t AV_RB32(const void *p)
{
    uint32_t v;
    __asm__ ("ld.ub    %0,   %4  \n\t"
             "ldins.b  %0:l, %3  \n\t"
             "ldins.b  %0:u, %2  \n\t"
             "ldins.b  %0:t, %1  \n\t"
             : "=&r"(v)
             : "RKs12"(* (const uint8_t*)p),
               "RKs12"(*((const uint8_t*)p+1)),
               "RKs12"(*((const uint8_t*)p+2)),
               "m"    (*((const uint8_t*)p+3)));
    return v;
}