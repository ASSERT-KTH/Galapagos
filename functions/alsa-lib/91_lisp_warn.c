static void lisp_warn(struct alisp_instance *instance, const char *fmt, ...)
{
	va_list ap;

	if (!instance->warning)
		return;
	va_start(ap, fmt);
	snd_output_printf(instance->wout, "alisp warning: ");
	snd_output_vprintf(instance->wout, fmt, ap);
	snd_output_putc(instance->wout, '\n');
	va_end(ap);
}