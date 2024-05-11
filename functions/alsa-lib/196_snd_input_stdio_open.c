int snd_input_stdio_open(snd_input_t **inputp, const char *file, const char *mode)
{
	int err;
	FILE *fp = fopen(file, mode);
	if (!fp) {
		//SYSERR("fopen");
		return -errno;
	}
	err = snd_input_stdio_attach(inputp, fp, 1);
	if (err < 0)
		fclose(fp);
	return err;
}