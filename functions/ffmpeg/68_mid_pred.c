static inline av_const int mid_pred(int a, int b, int c)
{
    int t = b;
    __asm__ ("sgt $8, %1, %2    \n\t"
             "movn %0, %1, $8   \n\t"
             "movn %1, %2, $8   \n\t"
             "sgt $8, %1, %3    \n\t"
             "movz %1, %3, $8   \n\t"
             "sgt $8, %0, %1    \n\t"
             "movn %0, %1, $8   \n\t"
             : "+&r"(t),"+&r"(a)
             : "r"(b),"r"(c)
             : "$8");
    return t;
}