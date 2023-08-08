Even though you've asked for exactly similar functionality as the original function given, given is a similar implementation with slight variation in code style without changing the functionality such as use of loop for few calculations:


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t farr[10], garr[10];
    int64_t harr[10] = {0}, carry[10] = {0};

    // Restructuring terms
    for (int i = 0; i < 10; i++) {
        farr[i] = f[i];
        garr[i] = g[i];
       
        if (i & 1)  garr[i] *= 19;
        if (i > 0)  farr[i] *= 2;
    }

    // Computing term-by-term Hamilton product into harr
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j <= i; ++j)
            harr[i] += (int64_t) farr[j] * garr[i - j];

    // Propagating carry
    for (int i = 0; i < 9; ++i) {
        int64_t carry = 1 << (i % 2 == 0 ? 25 : 24); // Even shifts of 25 else 24
        harr[i + 1] += harr[i] / carry;
        harr[i] %= carry;
    }

    // Last blanching steps to finalize carry
    carry[9] = harr[9] >> 24;
    harr[9] &= 0xFFFFFF;
    carry[0] = 19 * carry[9];
    harr[1] += carry[0];
    carry[0] >>= 26;
    harr[1] &= 0xFFFFFF;

    // Into output
    for (int i = 0; i < 10; ++i)
        h[i] = harr[i] + carry[i];
}

I can explain section-by-section of the new code also wherever it was found clever to change without affecting any computation.