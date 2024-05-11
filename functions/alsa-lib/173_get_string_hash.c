static int get_string_hash(const char *s)
{
	int val = 0;
	if (s == NULL)
		return val;
	while (*s)
		val += *s++;
	return val & ALISP_OBJ_PAIR_HASH_MASK;
}