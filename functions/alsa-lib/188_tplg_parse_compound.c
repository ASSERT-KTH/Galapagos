int tplg_parse_compound(snd_tplg_t *tplg, snd_config_t *cfg,
			int (*fcn)(snd_tplg_t *, snd_config_t *, void *),
			void *private)
{
	const char *id;
	snd_config_iterator_t i, next;
	snd_config_t *n;
	int err = -EINVAL;

	if (snd_config_get_id(cfg, &id) < 0)
		return -EINVAL;

	if (snd_config_get_type(cfg) != SND_CONFIG_TYPE_COMPOUND) {
		SNDERR("compound type expected for %s", id);
		return -EINVAL;
	}

	/* parse compound */
	snd_config_for_each(i, next, cfg) {
		n = snd_config_iterator_entry(i);

		if (snd_config_get_type(cfg) != SND_CONFIG_TYPE_COMPOUND) {
			SNDERR("compound type expected for %s, is %d",
				id, snd_config_get_type(cfg));
			return -EINVAL;
		}

		err = fcn(tplg, n, private);
		if (err < 0)
			return err;
	}

	return err;
}