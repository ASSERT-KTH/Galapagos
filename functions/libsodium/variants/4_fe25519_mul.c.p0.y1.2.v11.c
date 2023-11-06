void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp[5], temp_f[5], temp_fg[4];
    uint64_t r0, r1, r2, r3, r4;
	uint64_t carry;

    for (int i = 0; i < 5; i++) {
        temp_f[i] = (uint128_t) f[i];
    }

	for (int i = 1; i < 5; i++) {
		temp_fg[i - 1] = 19ULL * temp_f[i];
	}

	temp[0] = temp_f[0] * g[0] + temp_fg[0] * g[4] + temp_fg[1] * g[3] + temp_fg[2] * g[2] + temp_fg[3] * g[1];
	temp[1] = temp_f[0] * g[1] + temp_f[1] * g[0] + temp_fg[1] * g[4] + temp_fg[2] * g[3] + temp_fg[3] * g[2];
	temp[2] = temp_f[0] * g[2] + temp_f[1] * g[1] + temp_f[2] * g[0] + temp_fg[2] * g[4] + temp_fg[3] * g[3];
	temp[3] = temp_f[0] * g[3] + temp_f[1] * g[2] + temp_f[2] * g[1] + temp_f[3] * g[0] + temp_fg[3] * g[4];
	temp[4] = temp_f[0] * g[4] + temp_f[1] * g[3] + temp_f[2] * g[2] + temp_f[3] * g[1] + temp_f[4] * g[0];

	for (int i = 0; i < 5; ++i) {
		r0    = ((uint64_t) temp[i]) & mask;
		carry = (uint64_t) (temp[i] >> 51);
		if (i + 1 < 5)
			temp[i + 1] += carry;

		if (i == 4) {
			r0 += 19ULL * carry;
			carry = r0 >> 51;
			r0 &= mask;
		}

		if (i + 1 < 4) {
			h[i + 1] = r0 + carry;
			carry = h[i + 1] >> 51;
			h[i + 1] &= mask;
		}

        h[i] = r0;
	}
}