
void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t factors[] = {0,0,0,0,0,0,0,0,0,0};
    int64_t multipliers[] = {0,0,0,0,0,0,0,0,0,0};
    int64_t carry[] = {0,0,0,0,0,0,0,0,0,0,0};
    int64_t calculations[] = {0,0,0,0,0,0,0,0,0,0};
     
    for (int i = 0; i < 10; i++) {
        factors[i] = f[i];
    }

    for (int i = 0; i < 10; i += 2) {
        multipliers[i] = 2 * factors[i];
    }

    for (int i = 5; i < 10; i++) {
        multipliers[i] = 38 * factors[i];
    }

    for (int i = 6; i < 10; i += 2) {
        multipliers[i] = 19 * factors[i];
    }

    multipliers[9] *= 2;

    for (int i = 0; i < 10; i++) {
        calculations[i] = factors[i] * ((i % 2 != 0 && i < 6) ? multipliers[i+1] : multipliers[i]);
    }

    for (int i = 0; i < 10; i += 2) {
        calculations[i] += calculations[9-i];
    }

    for (int i = 1; i < 10; i += 2) {
        calculations[i] += calculations[8-i];
    }

    for (int i = 0; i < 10; i++) {
        calculations[1] += carry[(i + 9) % 10];
        calculations[i] -= carry[(i + 9) % 10] * ((uint64_t) 1L << 26);
        carry[i] = (calculations[i] + (int64_t)(1L << 25)) >> 26;
    }

    calculations[9] -= carry[8] * ((uint64_t) 1L << 25);
    calculations[0] += carry[9] * 19;

    carry[0] = (calculations[0] + (int64_t)(1L << 25)) >> 26;
    calculations[1] += carry[0];
    calculations[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; ++i) {
        h[i] = (uint32_t)calculations[i];
    }
}
