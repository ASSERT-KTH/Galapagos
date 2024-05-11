EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_set_access_first)(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *access)
#else
int snd_pcm_hw_params_set_access_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *access)
#endif
{
	return snd_pcm_hw_param_set_first(pcm, params, SND_PCM_HW_PARAM_ACCESS, access, NULL);
}