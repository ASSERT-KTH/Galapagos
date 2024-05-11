static inline bool spa_atou32(const char *str, uint32_t *val, int base)
{
	char *endptr;
	unsigned long long v;

	if (!str || *str =='\0')
		return false;

	errno = 0;
	v = strtoull(str, &endptr, base);
	if (errno != 0 || *endptr != '\0')
		return false;

	if (v != (uint32_t)v)
		return false;

	*val = v;
	return true;
}