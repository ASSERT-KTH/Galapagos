Here is variant of your function:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask    = 0x7ffffffffffffULL;
    uint128_t r[5], t[5];
    uint128_t carry;
    int i;

    t[0]      = (uint128_t) f[0];
    t[1]      = (uint128_t) f[1]*19ULL;
    t[2]      = (uint128_t) f[2]*19ULL;
    t[3]      = (uint128_t) f[3]*19ULL;
    t[4]      = (uint128_t) f[4]*19ULL;

    for(i=0;i<5;i++) {
        r[i] = t[0] * g[i];
        r[i]+= t[1] * ((i<1) ? g[4+i] : g[i-1]);
        r[i]+= t[2] * ((i<2) ? g[3+i] : g[i-2]);
        r[i]+= t[3] * ((i<3) ? g[2+i] : g[i-3]);
        r[i]+= t[4] * ((i<4) ? g[1+i] : g[i-4]);
    }
    for(i=0 ;i<4 ;i++)
    {
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1]+= carry;
        h[i]   = (uint64_t) (r[i] & mask);
    }
    carry  = (uint64_t) (r[4] >> 51);
    h[0]  +=  19ULL * carry;
    carry = h[0] >> 51;
    h[0] &= mask;
    h[1] += carry;
    h[i]=((uint64_t) r[i]) & mask;

    if(++i==5)i=0;
}
 

As per your instructions, transformations were made to eliminate explicit numerical coefficient of inputs and to rely instead on the position index, implicit introductions. A small correction made to use `h[4]` instead `r02`

This modified version uses loop instead of performing each multiplication and addition on separate line, as a result, code more compact, fewer chances to introduce an error. Also slightly faster because computations are performed inside of a tight loop that may better utilize processor pipeline. Same functionality, cost of comprehension might be slightly higher beacuse of compactness but it's intuitive for individuals reasonably experienced in low-level manipulation of C and numerical algorithms.
This of course, assumes availability of same types and type promotion behavior as existing compiler(s). Also assumes C99 or later standards for mixed declarations and code.