static void vec_mul(vec * h, const vec * f, const vec * g)
{
	int i, j;
	vec buf[ 2*GFBITS-1 ];

	for (i = 0; i < 2*GFBITS-1; i++)
		buf[i] = 0;

	for (i = 0; i < GFBITS; i++)
	for (j = 0; j < GFBITS; j++)
		buf[i+j] ^= f[i] & g[j];

	for (i = 2*GFBITS-2; i >= GFBITS; i--)
	{
		buf[i-GFBITS+4] ^= buf[i];
		buf[i-GFBITS+3] ^= buf[i];
		buf[i-GFBITS+1] ^= buf[i];
		buf[i-GFBITS+0] ^= buf[i];
	}

	for (i = 0; i < GFBITS; i++)
		h[i] = buf[i];
}