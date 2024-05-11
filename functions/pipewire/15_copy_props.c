static void copy_props(struct impl *impl, struct pw_properties *props, const char *key)
{
	const char *str;
	if ((str = pw_properties_get(props, key)) != NULL) {
		if (pw_properties_get(impl->sink_props, key) == NULL)
			pw_properties_set(impl->sink_props, key, str);
		if (pw_properties_get(impl->source_props, key) == NULL)
			pw_properties_set(impl->source_props, key, str);
	}
}