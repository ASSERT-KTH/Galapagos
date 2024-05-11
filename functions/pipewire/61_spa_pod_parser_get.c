static inline int spa_pod_parser_get(struct spa_pod_parser *parser, ...)
{
	int res;
	va_list args;

	va_start(args, parser);
	res = spa_pod_parser_getv(parser, args);
	va_end(args);

	return res;
}