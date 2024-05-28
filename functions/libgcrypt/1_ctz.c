static inline int ctz(uint64_t in)
{
	int i, b, m = 0, r = 0;

	for (i = 0; i < 64; i++)
	{
		b = (in >> i) & 1;
		m |= b;
		r += (m^1) & (b^1);
	}

	return r;
}