int snd_pcm_hw_param_set_last(snd_pcm_t *pcm, 
			      snd_pcm_hw_params_t *params,
			      snd_pcm_hw_param_t var,
			      unsigned int *rval, int *dir)
{
	int err;

	err = _snd_pcm_hw_param_set_last(params, var);
	if (err < 0)
		return err;
	if (params->rmask) {
		err = snd_pcm_hw_refine(pcm, params);
		if (err < 0)
			return err;
	}
	return snd_pcm_hw_param_get(params, var, rval, dir);
}