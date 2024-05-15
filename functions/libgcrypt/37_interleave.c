static inline void interleave(vec *in, int idx0, int idx1, vec *mask, int b)
{
	int s = 1 << b;

	vec x, y;

	x = (in[idx0] & mask[0]) | ((in[idx1] & mask[0]) << s);
	y = ((in[idx0] & mask[1]) >> s) | (in[idx1] & mask[1]);

	in[idx0] = x;
	in[idx1] = y;
}