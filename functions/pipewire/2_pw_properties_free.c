void pw_properties_free(struct pw_properties *properties)
{
	struct properties *impl;

	if (properties == NULL)
		return;

	impl = SPA_CONTAINER_OF(properties, struct properties, this);
	pw_properties_clear(properties);
	pw_array_clear(&impl->items);
	free(impl);
}