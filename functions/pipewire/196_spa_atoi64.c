static inline bool spa_atoi64(const char *str, int64_t *val, int base)
{
	char *endptr;
	long long v;

	if (!str || *str =='\0')
		return false;

	errno = 0;
	v = strtoll(str, &endptr, base);
	if (errno != 0 || *endptr != '\0')
		return false;

	*val = v;
	return true;
}