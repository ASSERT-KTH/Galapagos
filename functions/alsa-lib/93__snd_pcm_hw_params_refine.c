int _snd_pcm_hw_params_refine(snd_pcm_hw_params_t *params,
			      unsigned int vars,
			      const snd_pcm_hw_params_t *src)
{
	int changed, err = 0;
	unsigned int k;
	for (k = 0; k <= SND_PCM_HW_PARAM_LAST_INTERVAL; ++k) {
		if (!(vars & (1 << k)))
			continue;
		changed = _snd_pcm_hw_param_refine(params, k, src);
		if (changed < 0)
			err = changed;
	}
	params->info &= src->info;
	params->flags = src->flags; /* propagate all flags to slave */
	return err;
}