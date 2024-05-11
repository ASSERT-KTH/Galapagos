int snd_config_is_array(const snd_config_t *config)
{
	int idx;
	snd_config_iterator_t i, next;
	snd_config_t *node;

	assert(config);
	if (config->type != SND_CONFIG_TYPE_COMPOUND)
		return -EINVAL;
	idx = 0;
	snd_config_for_each(i, next, config) {
		node = snd_config_iterator_entry(i);
		if (!check_array_item(node->id, idx))
			return 0;
		idx++;
	}
	return idx;
}