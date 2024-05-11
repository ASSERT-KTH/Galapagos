int snd_config_imake_integer(snd_config_t **config, const char *id, const long value)
{
	int err;
	
	err = snd_config_make(config, id, SND_CONFIG_TYPE_INTEGER);
	if (err < 0)
		return err;
	(*config)->u.integer = value;
	return 0;
}