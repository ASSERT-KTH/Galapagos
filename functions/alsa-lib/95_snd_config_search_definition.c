int snd_config_search_definition(snd_config_t *config,
				 const char *base, const char *name,
				 snd_config_t **result)
{
	snd_config_t *conf;
	char *key;
	const char *args = strchr(name, ':');
	int err;
	if (args) {
		args++;
		key = alloca(args - name);
		memcpy(key, name, args - name - 1);
		key[args - name - 1] = '\0';
	} else {
		key = (char *) name;
	}
	/*
	 *  if key contains dot (.), the implicit base is ignored
	 *  and the key starts from root given by the 'config' parameter
	 */
	snd_config_lock();
	err = snd_config_search_alias_hooks(config, strchr(key, '.') ? NULL : base, key, &conf);
	if (err < 0) {
		snd_config_unlock();
		return err;
	}
	err = snd_config_expand(conf, config, args, NULL, result);
	snd_config_unlock();
	return err;
}