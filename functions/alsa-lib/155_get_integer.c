static long get_integer(const char **ptr, long min, long max)
{
	long val = min;
	char *p = (char *)*ptr, *s;

	if (*p == ':')
		p++;
	if (*p == '\0' || (!isdigit(*p) && *p != '-'))
		goto out;

	s = p;
	val = strtol(s, &p, 0);
	if (*p == '.') {
		p++;
		(void)strtol(p, &p, 10);
	}
	if (*p == '%') {
		val = (long)convert_prange1(strtod(s, NULL), min, max);
		p++;
	}
	val = check_range(val, min, max);
	if (*p == ',')
		p++;
 out:
	*ptr = p;
	return val;
}