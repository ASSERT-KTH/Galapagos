You can modify the algorithm for the above function without changing the final result. 

Below is a variant of the function which starts with higher index of the f array, and then works its way down:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f9 = f[9];
    int32_t f8 = f[8];
    int32_t f7 = f[7];
    int32_t f6 = f[6];
    int32_t f5 = f[5];
    int32_t f4 = f[4];
    int32_t f3 = f[3];
    int32_t f2 = f[2];
    int32_t f1 = f[1];
    int32_t f0 = f[0];

    // Same calculations...

}


This alternative function is logically equivalent to the original given function as it calculates the exact same expressions and assigns those results to the correct variables. In this variant, however, the computation starts in the reverse order, calculating f9 before f0. Code readability depends on prior knowledge about what f[n] is and common domain knowledge; if you know what fzero to fnine are for instance, then it won't hinder readability.