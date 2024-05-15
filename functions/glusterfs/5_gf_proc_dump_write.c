gf_proc_dump_write (char *key, char *value, ...)
{
	int ret = 0;
	va_list ap;

	va_start (ap, value);
	if (gf_dump_strfd)
		ret = gf_proc_dump_write_strfd (key, value, ap);
	else
		ret = gf_proc_dump_write_fd (key, value, ap);
	va_end (ap);

	return ret;
}