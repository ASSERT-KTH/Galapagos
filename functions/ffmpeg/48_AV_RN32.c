static av_always_inline uint32_t AV_RN32(const void *p)
{
    const struct __attribute__((packed)) { uint32_t v; } *q = p;
    uint32_t v;
    __asm__ ("ldr  %0, %1" : "=r"(v) : "m"(*q));
    return v;
}