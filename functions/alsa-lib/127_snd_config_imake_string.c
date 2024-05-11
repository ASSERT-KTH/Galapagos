int snd_config_imake_string(snd_config_t **config, const char *id, const char *value)
{
	int err;
	snd_config_t *tmp;
	
	err = snd_config_make(&tmp, id, SND_CONFIG_TYPE_STRING);
	if (err < 0)
		return err;
	if (value) {
		tmp->u.string = strdup(value);
		if (!tmp->u.string) {
			snd_config_delete(tmp);
			return -ENOMEM;
		}
	} else {
		tmp->u.string = NULL;
	}
	*config = tmp;
	return 0;
}