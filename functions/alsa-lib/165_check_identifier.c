static int check_identifier(const char *identifier, const char *prefix)
{
	int len;

	len = strlen(prefix);
	if (strncmp(identifier, prefix, len) != 0)
		return 0;

	if (identifier[len] == 0 || identifier[len] == '/')
		return 1;

	return 0;
}