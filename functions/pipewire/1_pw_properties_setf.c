int pw_properties_setf(struct pw_properties *properties, const char *key, const char *format, ...)
{
	int res;
	va_list varargs;

	va_start(varargs, format);
	res = pw_properties_setva(properties, key, format, varargs);
	va_end(varargs);

	return res;
}