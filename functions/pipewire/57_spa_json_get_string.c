static inline int spa_json_get_string(struct spa_json *iter, char *res, int maxlen)
{
	const char *value;
	int len;
	if ((len = spa_json_next(iter, &value)) <= 0)
		return len;
	return spa_json_parse_stringn(value, len, res, maxlen);
}