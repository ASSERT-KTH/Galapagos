You can achieve the same functionality while changing the behaviour by getting rid of the individual variables for each index of the array. Instead, you can deal directly with the array indices. This will make the code more compact. Here is an example:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h1[10];
    int64_t carry[10];

    for (int i = 0; i < 10; i++) {
        h1[i] = f[i] * (int64_t)f[i];
    }
    
    for (int i = 0; i < 9; i++) {
        h1[i] += 38 * f[i+1] * (int64_t)f[i+1];
    }
    
    h1[9] += 19 * (f[0] * (int64_t)f[0] + 38 * f[4] * (int64_t)f[4]);

    for (int i = 1; i < 5; i++) {
        h1[2 * i - 1] += f[i] * (int64_t)f[i] * 19;
        h1[2 * i] += 38 * f[i] * (int64_t)f[i] * 19;
    }

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) h1[i];
    }

    for (int i = 0; i < 10; i+=2) {
        carry[i] = (h1[i] + (int64_t)(1L << 25)) >> 26;
        h1[i+1] += carry[i];
        h1[i] -= carry[i] * ((uint64_t) 1L << 26);
    }

    for (int i = 1; i < 9; i+=2) {
        carry[i] = (h1[i] + (int64_t)(1L << 24)) >> 25;
        h1[i+1] += carry[i];
        h1[i] -= carry[i] * ((uint64_t) 1L << 25);
    }
    
    carry[9] = (h1[9] + (int64_t)(1L << 24)) >> 25;
    h1[0] += carry[9] * 19;
    h1[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0]= (h1[0] + (int64_t)(1<<25)) >> 26; h1[1]+=carry[0]; h1[0]-=carry[0]<<26;
    
    for (int i = 0; i < 10; i++) {
        h[i] = h1[i];
    }
}
 

Please note: This variant assumes that `fe25519` is a type that defines an array of 10 `int32_t` values. In the original code, `fe25519` is used as a type but we don't have a definition of it. Therefore, it may represent an array, a struct, or any other structure that contains at least 10 `int32_t` variables.