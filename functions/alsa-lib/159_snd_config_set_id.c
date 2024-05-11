int snd_config_set_id(snd_config_t *config, const char *id)
{
	snd_config_iterator_t i, next;
	char *new_id;
	assert(config);
	if (id) {
		if (config->parent) {
			snd_config_for_each(i, next, config->parent) {
				snd_config_t *n = snd_config_iterator_entry(i);
				if (n != config && strcmp(id, n->id) == 0)
					return -EEXIST;
			}
		}
		new_id = strdup(id);
		if (!new_id)
			return -ENOMEM;
	} else {
		if (config->parent)
			return -EINVAL;
		new_id = NULL;
	}
	free(config->id);
	config->id = new_id;
	return 0;
}