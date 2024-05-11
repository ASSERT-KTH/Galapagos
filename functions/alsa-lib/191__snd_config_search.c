static int _snd_config_search(snd_config_t *config, 
			      const char *id, int len, snd_config_t **result)
{
	snd_config_iterator_t i, next;
	snd_config_for_each(i, next, config) {
		snd_config_t *n = snd_config_iterator_entry(i);
		if (len < 0) {
			if (strcmp(n->id, id) != 0)
				continue;
		} else if (strlen(n->id) != (size_t) len ||
			   memcmp(n->id, id, (size_t) len) != 0)
				continue;
		if (result)
			*result = n;
		return 0;
	}
	return -ENOENT;
}