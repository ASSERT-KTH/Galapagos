static inline vec vec_set1_16b(uint16_t v)
{
	vec ret;

	ret = v;
	ret |= ret << 16;
	ret |= ret << 32;

	return ret;
}