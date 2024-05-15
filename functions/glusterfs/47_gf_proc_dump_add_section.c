gf_proc_dump_add_section (char *key, ...)
{
	va_list ap;
	int ret = 0;

	va_start (ap, key);
	if (gf_dump_strfd)
		ret = gf_proc_dump_add_section_strfd (key, ap);
	else
		ret = gf_proc_dump_add_section_fd (key, ap);
	va_end (ap);

	return ret;
}