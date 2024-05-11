int _snd_pcm_hw_param_set_mask(snd_pcm_hw_params_t *params,
			       snd_pcm_hw_param_t var, const snd_mask_t *val)
{
	int changed;
	assert(hw_is_mask(var));
	changed = snd_mask_refine(hw_param_mask(params, var), val);
	if (changed) {
		params->cmask |= 1 << var;
		params->rmask |= 1 << var;
	}
	return changed;
}