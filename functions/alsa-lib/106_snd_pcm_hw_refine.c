int snd_pcm_hw_refine(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
	int res;
#ifdef REFINE_DEBUG
	snd_output_t *log;
	snd_output_stdio_attach(&log, stderr, 0);
#endif
	assert(pcm && params);
#ifdef REFINE_DEBUG
	snd_output_printf(log, "REFINE called:\n");
	snd_pcm_hw_params_dump(params, log);
#endif
	if (pcm->ops->hw_refine)
		res = pcm->ops->hw_refine(pcm->op_arg, params);
	else
		res = -ENOSYS;
#ifdef REFINE_DEBUG
	snd_output_printf(log, "refine done - result = %i\n", res);
	snd_pcm_hw_params_dump(params, log);
	snd_output_close(log);
#endif
	return res;
}