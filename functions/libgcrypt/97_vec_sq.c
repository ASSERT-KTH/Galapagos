static void vec_sq(vec * out, vec * in)
{
	int i;
	vec result[GFBITS], t;

	t = in[11] ^ in[12];

	result[0] = in[0] ^ in[11];
	result[1] = in[7] ^ t;
	result[2] = in[1] ^ in[7];
	result[3] = in[8] ^ t;
	result[4] = in[2] ^ in[7];
	result[4] = result[4] ^ in[8];
	result[4] = result[4] ^ t;
	result[5] = in[7] ^ in[9];
	result[6] = in[3] ^ in[8];
	result[6] = result[6] ^ in[9];
	result[6] = result[6] ^ in[12];
	result[7] = in[8] ^ in[10];
	result[8] = in[4] ^ in[9];
	result[8] = result[8] ^ in[10];
	result[9] = in[9] ^ in[11];
	result[10] = in[5] ^ in[10];
	result[10] = result[10] ^ in[11];
	result[11] = in[10] ^ in[12];
	result[12] = in[6] ^ t;

	for (i = 0; i < GFBITS; i++)
		out[i] = result[i];
}