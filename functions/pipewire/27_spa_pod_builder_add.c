static inline int spa_pod_builder_add(struct spa_pod_builder *builder, ...)
{
	int res;
	va_list args;

	va_start(args, builder);
	res = spa_pod_builder_addv(builder, args);
	va_end(args);

	return res;
}