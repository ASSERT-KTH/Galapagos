int snd_output_stdio_attach(snd_output_t **outputp, FILE *fp, int _close)
{
	snd_output_t *output;
	snd_output_stdio_t *stdio;
	assert(outputp && fp);
	stdio = calloc(1, sizeof(*stdio));
	if (!stdio)
		return -ENOMEM;
	output = calloc(1, sizeof(*output));
	if (!output) {
		free(stdio);
		return -ENOMEM;
	}
	stdio->fp = fp;
	stdio->close = _close;
	output->type = SND_OUTPUT_STDIO;
	output->ops = &snd_output_stdio_ops;
	output->private_data = stdio;
	*outputp = output;
	return 0;
}