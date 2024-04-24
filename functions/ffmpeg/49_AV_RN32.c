static av_always_inline uint32_t AV_RN32(const void *p)
{
    struct __attribute__((packed)) u32 { uint32_t v; };
    const uint8_t *q = p;
    const struct u32 *pl = (const struct u32 *)(q + 3 * !HAVE_BIGENDIAN);
    const struct u32 *pr = (const struct u32 *)(q + 3 *  HAVE_BIGENDIAN);
    uint32_t v;
    __asm__ ("lwl %0, %1  \n\t"
             "lwr %0, %2  \n\t"
             : "=&r"(v)
             : "m"(*pl), "m"(*pr));
    return v;
}