static inline unsigned int add(unsigned int a, unsigned int b)
{
	if (a >= 4294967295 - b)
		return 4294967295;
	return a + b;
}
