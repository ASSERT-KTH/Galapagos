Here is a slightly optimized variant that sticks to original behavior by moving immutable calculation operations to a higher order of calculations for even tiny speed gain:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7FFFFFFFFFFFFULL;
    uint128_t r[5], f_[5], f__[] = {f[0] << 1, f[1] << 1, 38ULL * f[2], 38ULL * f[3], 19 * f[4]};
    uint64_t carry;

    for (int i = 0; i < 5; i++)
        f_[i] = f[i];

    r[0] = f[0]*f[0] + 38*f_[1]*f_[4] + f__[2]*f[3];
    r[1] = f__[0]*f[1] + 38*f_[2]*f_[4] + f__[4]*f_[3];
    r[2] = f__[0]*f_[2] + f_[1]*f_[1] + f__[3]*f_[4];
    r[3] = f__[0]*f_[3] + f__[1]*f_[2] + f__[4]*f_[4];
    r[4] = f__[0]*f_[4] + f__[1]*f_[3] + f__[2]*f_[2];

    r[0] = (r[0] &= mask) + (carry = (r[0] >> 51) * 19);
    r[1] = (r[1] += (carry >>= 51)) & mask;
    r[2] = (r[2] += (carry = r[1] >> 51)) & mask;
    r[3] = (r[3] += (carry = r[2] >> 51)) & mask;
    r[4] = (r[4] += (carry = r[3] >> 51)) & mask;

    h[0] = r[0] + 19 * (carry = r[4] >> 51);
    h[1] = r[1] + (carry = h[0] >> 51);
    h[0] &= mask;
    h[2] = r[2] + (carry = h[1] >> 51);
    h[1] &= mask;
    h[3] = r[3] + (carry = h[2] >> 51);
    h[4] = r[4] - (76 * (carry == mask));
    h[2] &= mask;
    h[3] &= mask;
}