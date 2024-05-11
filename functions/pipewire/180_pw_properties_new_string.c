pw_properties_new_string(const char *object)
{
	struct properties *impl;
	int res;

	impl = properties_new(16);
	if (impl == NULL)
		return NULL;

	if ((res = pw_properties_update_string(&impl->this, object, strlen(object))) < 0)
		goto error;

	return &impl->this;
error:
	pw_properties_free(&impl->this);
	errno = -res;
	return NULL;
}