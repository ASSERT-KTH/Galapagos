static int parse_flag(snd_config_t *n, unsigned int mask_in,
		      void *mask, void *flags)
{
	int ret;

	ret = snd_config_get_bool(n);
	if (ret < 0)
		return ret;

	unaligned_put32(mask, unaligned_get32(mask) | mask_in);
	if (ret)
		unaligned_put32(flags, unaligned_get32(flags) | mask_in);
	else
		unaligned_put32(flags, unaligned_get32(flags) & (~mask_in));

	return 0;
}