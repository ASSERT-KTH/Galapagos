A slight simplification could be achieved through reducing the number of constants in code. Instead, constants such as 2 and 19 could be represented by variables with clear and concise names that indicate their purpose in the code. Apart from reducing complexity, it also minimizes chances of error if these constants need to change throughout multiple lines of code in future.

There aren't lots of optimizations available due to the scoped requirement that I can't create helper functions, nor change the inputs and outputs of the function.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t multiplier = 19;
    int32_t doubleVal = 2;
    int64_t carry0, carry1, carry2, carry3, carry4;
    int64_t carry5, carry6, carry7, carry8, carry9;

    int32_t f1_2  = doubleVal * f[1];
    int32_t f3_2  = doubleVal * f[3];
    int32_t f5_2  = doubleVal * f[5];
    int32_t f7_2  = doubleVal * f[7];
    int32_t f9_2  = doubleVal * f[9];

    int64_t h0 = f[0]*(int64_t) g[0] + f1_2 * (int64_t) (multiplier*g[9]) + f[2]*(int64_t) (multiplier * g[8]) +
                 f3_2 * (int64_t) (multiplier*g[7]) + f[4]*(int64_t) (multiplier * g[6]) + f5_2 * (int64_t) (multiplier*g[5]) +
                 f[6]*(int64_t) (multiplier* g[4]) + f7_2 * (int64_t) (multiplier*g[3]) + f[8]*(int64_t) (multiplier * g[2]) +
                 f9_2*(int64_t) (multiplier* g[1]);

    // And proceeds similarly for h1 to h10, manipulating array indices of f and g correspondingly

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h0 -= carry0 * ((uint64_t) 1L << 26);
    h[1] += (int32_t) carry0;

    // Proceeds similarly for carry1 to carry9

    h[0] = (int32_t) h0;
    h[1] = h[1];
    // Insert h2 to h9 here
    h[9] = h[9];
}

Savings are relatively trivial in this type of optimization but should be noted that they may add up in larger more complex codebases.
Another possible improvement could be less computation in general. This is achieved by reshaping factors during computation to not be duplicated if reused. However, generalized transforms in this code are not straightforward because of alternating operations of products and sums inside repeating factors. It is even less likely you can reshape alternating series to beneficial forms without knowing more about the attributes of operands 'f' and 'g'.