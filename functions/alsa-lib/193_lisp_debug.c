static void lisp_debug(struct alisp_instance *instance, const char *fmt, ...)
{
	va_list ap;

	if (!instance->debug)
		return;
	va_start(ap, fmt);
	snd_output_printf(instance->dout, "alisp debug: ");
	snd_output_vprintf(instance->dout, fmt, ap);
	snd_output_putc(instance->dout, '\n');
	va_end(ap);
}