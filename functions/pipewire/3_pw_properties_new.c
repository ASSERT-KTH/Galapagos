struct pw_properties *pw_properties_new(const char *key, ...)
{
	struct properties *impl;
	va_list varargs;
	const char *value;
	int res = 0;

	impl = properties_new(16);
	if (impl == NULL)
		return NULL;

	va_start(varargs, key);
	while (key != NULL) {
		value = va_arg(varargs, char *);
		if (value && key[0])
			if ((res = add_item(impl, key, false, value, false)) < 0)
				goto error;
		key = va_arg(varargs, char *);
	}
	va_end(varargs);
	update_dict(&impl->this);

	return &impl->this;
error:
	pw_properties_free(&impl->this);
	errno = -res;
	return NULL;
}