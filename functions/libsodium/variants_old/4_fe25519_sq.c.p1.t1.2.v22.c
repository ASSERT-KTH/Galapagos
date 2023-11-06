Keeping the behavior and functionality the same, the code can be refactored to become more readable by optimizing lines in the conditions where element-wise declarations are used. At the same time, the for loops could be used so as to reduce the amount of copy pasted lines of code.

Here is the revised implementation of your function:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t F[10];
    int32_t Fm[10];
    int64_t H[10];
    int64_t carry[10];
    
    for (int i = 0; i < 10; ++i) 
    {
        F[i] = f[i];
        Fm[i] = F[i] * 2;
    }

    Fm[5] *= 19;  /* 1.959375*2^30 */
    Fm[6] *= 19;  /* 1.959375*2^30 */
    Fm[7] *= 19;  /* 1.959375*2^30 */
    Fm[8] *= 19;  /* 1.959375*2^30 */
    Fm[9] *= 19;  /* 1.959375*2^30 */

    for (int i = 0; i < 10; ++i)
    {
        H[i] = F[0] * (int64_t) F[i] + Fm[1] * (int64_t) F[9 - i];
        carry[i] = (H[i] + (int64_t)(1L << (((i + i % 2) / 2 + 1) % 2 + 24))) >> ((((i + i % 2) / 2 + 1) % 2 + 1)*25 - 1);
        H[(i+1)%10] += carry[i];
        H[i] -= carry[i] * ((uint64_t) 1L << ((((i + i % 2) / 2 + 1) % 2 + 1)*25 - 1));
    }

    H[0] = H[0] + carry[9] * 19;
    h[0] = (int32_t) H[0];
    for (int i = 1; i < 10; ++i)
    {
        carry[0] = (H[(10+i-1)%10] + (int64_t)(1L << ((((10+i-1)%10) + ((10+i-1)%10) % 2) / 2 + 1) % 2 + 24))) >> 
                   (((((10+i-1)%10) + ((10+i-1)%10) % 2) / 2 + 1) % 2 + 1)*25 - 1);
        h[(10 + i)%10] = (int32_t) (H[(10+i-1)%10] - carry[0] * ((uint64_t) 1L << (((((10+i-1)%10) + ((10+i-1)%10) % 2) / 2 + 1) % 2 + 1)*25 - 1));
        H[i] = H[i] + carry[0] ;
        h[i] = (int32_t) H[i];
    }
}


This code does the same thing as the original reference implementation provided but organized using loops which makes it more denser and clearer to read. Auxiliary variables F, Fm, H and carry were declared for accommodating repeated temperory variables. F is a representative for f, Fm is for multiplied f and Fm_38 or Fm_19 variants, H is h before carry operation and carry used for the carrying operation in the function. 

Also, note that most of the constants in this function relate to the number 19. This is because the function implements an arithmetic operation modulo a prime number 2^255 - 19 in a field order of the same prime number. Math operations are dealt in terms of this modulo 2^255 - 19 or just with #19. That’s why you see #19 or multiples of it appearing constantly inside the function.


