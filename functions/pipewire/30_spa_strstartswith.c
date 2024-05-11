static inline bool spa_strstartswith(const char *s, const char *prefix)
{
	if (SPA_UNLIKELY(s == NULL))
		return false;

	spa_assert_se(prefix);

	return strncmp(s, prefix, strlen(prefix)) == 0;
}