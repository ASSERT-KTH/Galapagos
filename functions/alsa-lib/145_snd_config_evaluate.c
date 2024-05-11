int snd_config_evaluate(snd_config_t *config, snd_config_t *root,
		        snd_config_t *private_data, snd_config_t **result)
{
	/* FIXME: Only in place evaluation is currently implemented */
	assert(result == NULL);
	return snd_config_walk(config, root, result, _snd_config_evaluate, NULL, private_data);
}