static void copy_props(const struct pw_properties *props, struct pw_properties *target,
		const char *key)
{
	const char *str;
	if ((str = pw_properties_get(props, key)) != NULL) {
		if (pw_properties_get(target, key) == NULL)
			pw_properties_set(target, key, str);
	}
}