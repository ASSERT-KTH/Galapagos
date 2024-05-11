static inline bool spa_atoi32(const char *str, int32_t *val, int base)
{
	char *endptr;
	long v;

	if (!str || *str =='\0')
		return false;

	errno = 0;
	v = strtol(str, &endptr, base);
	if (errno != 0 || *endptr != '\0')
		return false;

	if (v != (int32_t)v)
		return false;

	*val = v;
	return true;
}