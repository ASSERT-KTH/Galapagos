int snd_config_delete(snd_config_t *config)
{
	assert(config);
	if (config->refcount > 0) {
		config->refcount--;
		return 0;
	}
	switch (config->type) {
	case SND_CONFIG_TYPE_COMPOUND:
	{
		int err;
		struct list_head *i;
		i = config->u.compound.fields.next;
		while (i != &config->u.compound.fields) {
			struct list_head *nexti = i->next;
			snd_config_t *child = snd_config_iterator_entry(i);
			err = snd_config_delete(child);
			if (err < 0)
				return err;
			i = nexti;
		}
		break;
	}
	case SND_CONFIG_TYPE_STRING:
		free(config->u.string);
		break;
	default:
		break;
	}
	if (config->parent)
		list_del(&config->list);
	free(config->id);
	free(config);
	return 0;
}