void _snd_pcm_hw_params_any(snd_pcm_hw_params_t *params)
{
	unsigned int k;
	memset(params, 0, sizeof(*params));
	for (k = SND_PCM_HW_PARAM_FIRST_MASK; k <= SND_PCM_HW_PARAM_LAST_MASK; k++)
		_snd_pcm_hw_param_any(params, k);
	for (k = SND_PCM_HW_PARAM_FIRST_INTERVAL; k <= SND_PCM_HW_PARAM_LAST_INTERVAL; k++)
		_snd_pcm_hw_param_any(params, k);
	params->rmask = ~0U;
	params->cmask = 0;
	params->info = ~0U;
}