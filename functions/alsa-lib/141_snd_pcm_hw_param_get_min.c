int snd_pcm_hw_param_get_min(const snd_pcm_hw_params_t *params, snd_pcm_hw_param_t var,
			     unsigned int *val, int *dir)
{
	if (hw_is_mask(var)) {
		const snd_mask_t *m = hw_param_mask_c(params, var);
		assert(!snd_mask_empty(m));
		if (dir)
			*dir = 0;
		if (val)
			*val = snd_mask_min(m);
		return 0;
	} else if (hw_is_interval(var)) {
		const snd_interval_t *i = hw_param_interval_c(params, var);
		assert(!snd_interval_empty(i));
		if (dir)
			*dir = i->openmin;
		if (val)
			*val = snd_interval_min(i);
		return 0;
	}
	assert(0);
	return 0;
}