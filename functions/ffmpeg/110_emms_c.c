static av_always_inline void emms_c(void)
{
/* Some inlined functions may also use mmx instructions regardless of
 * runtime cpuflags. With that in mind, we unconditionally empty the
 * mmx state if the target cpu chosen at configure time supports it.
 */
#if !defined(__MMX__)
    if(av_get_cpu_flags() & AV_CPU_FLAG_MMX)
#endif
        __asm__ volatile ("emms" ::: "memory");
}