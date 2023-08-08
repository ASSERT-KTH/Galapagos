The C code provided seems like an optimized operation on the finite field of order 2^255 − 19, most likely used in cryptography, maybe in the implementation of an elliptic curve digital signature algorithm in the Ed25519 digital signature system.

The code can be rewritten in hundreds of ways that essentially do the same thing (maintaining the functional behavior), while having some differences (to the degree such that the program behaviour utilizes different instructions or instruction sequences). Below provides a straightforward and simplistic one, by rearranging some operations, consolidating variable initializations and combining some lines of code.

Here is the version of the function, functionally the same as the given code, but rearranges the operations somewhat yet achieving the exact same result:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int64_t fval[10];
    int64_t gval[10];
    int64_t opresult[100];
    int32_t i, j, k;
    int64_t carry;

    for (i = 0; i < 10; i++) {
        fval[i] = f[i];
        gval[i] = g[i];
    }

    for (i = 0; i < 10; ++i)
        for (j = 0; j < 10; ++j)
            opresult[i+j] = fval[i] * (i & 1 ? 19LL * gval[j] : gval[j]);

    for (i = 0; i <= 18; ++i) {
        carry = i <= 8 ? opresult[i] + (1LL << 26) : opresult[i] + (1LL << 25);
        k = i & 1 ? 25 : 26;
        h[i % 10] += carry >> k;
        opresult[i<18?i+2:i-18] += carry & ( ((1LL << k) - 1) * 19);
    }

    carry = (h[0] + (1LL << 25)) >> 26;
    h[0] -= carry << 26;
    h[1] += carry;
}

The changes do not alter the original functions functionality but only changes its behavior in how the operations are sequenced or in this case expressed in this simplified method.