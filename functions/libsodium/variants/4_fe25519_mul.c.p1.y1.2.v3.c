Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g_components[5], f_components[5], r_components[5];
    uint64_t  carry;
    int i;

    for(i = 0; i < 5; i++) {
        f_components[i] = (uint128_t) f[i];
        g_components[i] = (uint128_t) g[i];
    }

    f1_19 = 19ULL * f_components[1];
    f2_19 = 19ULL * f_components[2];
    f3_19 = 19ULL * f_components[3];
    f4_19 = 19ULL * f_components[4];

    r_components[0] = f_components[0] * g_components[0] + f1_19 * g_components[4] + f2_19 * g_components[3] +
f3_19 * g_components[2] + f4_19 * g_components[1];

    for(i = 1; i < 5; i++)
        r_components[i] = f_components[0] * g_components[i] + f_components[i] * g_components[0] +
f2_19 * g_components[4-i] + f3_19 * g_components[3-i] + f4_19 * g_components[2-i];

    for(i = 0; i < 5; i++){
	r_components[i] += (i>0)? carry:0;
        h[i] = ((uint64_t) r_components[i]) & mask;
        carry = (uint64_t) (r_components[i] >> 51);
    }
    r_components[0]   += 19ULL * carry;
    h[0] &= mask;
    h[1]  += carry;
}


Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
	uint128_t f_terms[5], g_terms[5], r[5], f_terms_mul_19[4];
    uint64_t carry;
	int i, j;

	for (i = 0; i < 5; i++) {
		f_terms[i] = (uint128_t)f[i];
		g_terms[i] = (uint128_t)g[i];
	}
	for (i = 1; i < 5; i++)
		f_terms_mul_19[i - 1] = 19 * f_terms[i];

	memset(r, 0, 5 * sizeof(uint128_t));
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			r[(i + j)%5] += f_terms[i] * ((j+i>=5) ? g_terms[5-j] : g_terms[j]);

	h[0] = r[0] & mask;
	carry = r[0] >> 51;
	for (i = 1; i < 5; i++) {
		r[i] += carry;
		carry = r[i] >> 51;
		h[i] = r[i] & mask;
    }

	h[0] += 19ULL * carry;
}
