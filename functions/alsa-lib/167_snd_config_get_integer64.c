int snd_config_get_integer64(const snd_config_t *config, long long *ptr)
{
	assert(config && ptr);
	if (config->type != SND_CONFIG_TYPE_INTEGER64)
		return -EINVAL;
	*ptr = config->u.integer64;
	return 0;
}