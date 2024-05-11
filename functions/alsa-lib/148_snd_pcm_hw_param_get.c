int snd_pcm_hw_param_get(const snd_pcm_hw_params_t *params, snd_pcm_hw_param_t var,
			 unsigned int *val, int *dir)
{
	if (hw_is_mask(var)) {
		const snd_mask_t *mask = hw_param_mask_c(params, var);
		if (snd_mask_empty(mask) || !snd_mask_single(mask))
			return -EINVAL;
		if (dir)
			*dir = 0;
		if (val)
			*val = snd_mask_value(mask);
		return 0;
	} else if (hw_is_interval(var)) {
		const snd_interval_t *i = hw_param_interval_c(params, var);
		if (snd_interval_empty(i) || !snd_interval_single(i))
			return -EINVAL;
		if (dir)
			*dir = i->openmin;
		if (val)
			*val = snd_interval_value(i);
		return 0;
	}
	assert(0);
	return -EINVAL;
}