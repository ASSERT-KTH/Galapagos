static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b / c;
	if (v > 2147483647) {
		return 2147483647;
	}
	if (v < -2147483648) {
		return -2147483648;
	}
	return v;
}
