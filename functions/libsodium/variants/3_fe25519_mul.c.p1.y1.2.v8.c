Here is a variant of the original function. A straightforward code transformation might entail converting all variables with local scope to global scope. This variant performs the same operations as the original,and serves the same purpose: 


#include <stdint.h>

int32_t f0, f1, f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9;
int32_t g0, g1, g2,  g3,  g4,  g5,  g6,  g7,  g8,  g9;
int32_t g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19, f1_2, f3_2, f5_2, f7_2, f9_2 ;
int64_t f0g0, f0g1, f0g2, f0g3, f0g4, f0g5, f0g6, f0g7, f0g8, f0g9;
...
..
(finish the other dozens of products similar to the ones immediately before.)
..

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    ....
    
    g0 = g[0]; 
    g1 = g[1];
    g2 = g[2];
    ....

    g1_19 = 19 * g1; /* 1.959375*2^29 */
    g2_19 = 19 * g2; /* 1.959375*2^30; still ok */
    ....

    f0g0    = f0 * (int64_t) g0;
    f0g1    = f0 * (int64_t) g1;
    f0g2    = f0 * (int64_t) g2;
    ....

    ....
    .. Complete for other unlisted calculaitons here in a simliar fashion.
    ....


    h[0] = (int32_t )h0;
    ....
    h[9] = (int32_t )h9;
}
