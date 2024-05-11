EXPORT_SYMBOL int INTERNAL(snd_pcm_sw_params_get_xfer_align)(const snd_pcm_sw_params_t *params ATTRIBUTE_UNUSED, snd_pcm_uframes_t *val)
#else
int snd_pcm_sw_params_get_xfer_align(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val)
#endif
{
	*val = 1;
	return 0;
}