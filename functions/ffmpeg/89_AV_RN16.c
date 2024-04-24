static av_always_inline unsigned AV_RN16(const void *p)
{
    const uint8_t *q = p;
    unsigned v;
#if AV_GCC_VERSION_AT_MOST(4,5)
    __asm__ ("ldrh %0, %1" : "=r"(v) : "m"(*(const uint16_t *)q));
#elif defined __thumb__
    __asm__ ("ldrh %0, %1" : "=r"(v) : "m"(q[0]), "m"(q[1]));
#else
    __asm__ ("ldrh %0, %1" : "=r"(v) : "Uq"(q[0]), "m"(q[1]));
#endif
    return v;
}