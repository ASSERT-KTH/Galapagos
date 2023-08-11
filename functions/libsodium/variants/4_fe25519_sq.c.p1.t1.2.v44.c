You can express the same function with just a few structural changes, basically breaking the problem into smaller pieces. This is less efficient, but the code is easier to understand.


void fe25519_sq(fe25519 h, const fe25519 f) {
    int i, j;
    int64_t products[19] = {};
    int64_t carry;
    
    // Calculate all the 11 unique products f[i]*f[j] and sum the duplicate like terms together.
    for (i = 4; i--; ) {
        for(j = 0; j <= i; j++) {
            products[i + j] += f[i] * (int64_t) f[j];
            if(i == j) continue;
            products[i + j + 5] += 4 * f[i] * (int64_t) f[j];
        }
    }
    
    // Adjust products based on the fact that a*i means a subtraction when a is odd and i is above 4
    // E.g. f9*25 = f9*19 + f9*2^2
    products[3] += f[3] * 38;
    products[4] += f[4] * 19;
    products[5] += f[4] * 38 + f[5] * 38;
    products[6] += f[5] * 19;
    products[7] += f[6] * 19;
    products[8] += f[6] * 38;
    products[9] += f[7] * 19;
    
    // Perform reduction and normalization
    // Removes the redundancy set by {f[0]+19f[9]..f[4]+19f[5]} and performs carry
    for(i = 0; i < 10; i++)  {
        carries[i + 1] = (products[i] + (1 << 26)) >> 27; products[i] -= carry[i + 1] * ((uint64_t) 1ULL << 27);
        i++;
        carries[i + 1] = (products[i] + (1 << 25)) >> 26; products[i] -= carry[i + 1] * ((uint64_t) 1ULL << 26);
    }
    
    // finals steps to accomplishes Longhi reduction
    products[0] += carry[10] * 19;
    carry[0] = (products[0] + (1 << 26)) >> 27; products[0] -= carry[0] * ((uint64_t) 1ULL << 27);
    products[1] += carry[0];
    
    // change products from int64_t* to int32_t*
    for(i = 0; i < 10; i++) { h[i] = products[i]; }
}

This version is easier to understand but might be less efficient due to usage of loops and merging all the calculation steps to one. The iterative approach used in loops increases time complexity. It divides term calculation i steps and does each step separately.One step signifies one loop operation. And finally, completing performing the carry and conversion remains constant for both the versions.