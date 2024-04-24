static inline av_const int mid_pred(int a, int b, int c)
{
    int m;
    __asm__ ("mov   %0, %2  \n\t"
             "cp.w  %1, %2  \n\t"
             "movgt %0, %1  \n\t"
             "movgt %1, %2  \n\t"
             "cp.w  %1, %3  \n\t"
             "movle %1, %3  \n\t"
             "cp.w  %0, %1  \n\t"
             "movgt %0, %1  \n\t"
             : "=&r"(m), "+r"(a)
             : "r"(b), "r"(c));
    return m;
}