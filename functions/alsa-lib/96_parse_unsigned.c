static int parse_unsigned(snd_config_t *n, void *dst)
{
	int ival;

	if (tplg_get_integer(n, &ival, 0) < 0)
		return -EINVAL;

	unaligned_put32(dst, ival);
#if TPLG_DEBUG
	{
		const char *id;
		if (snd_config_get_id(n, &id) >= 0)
			tplg_dbg("\t\t%s: %d", id, ival);
	}
#endif
	return 0;
}