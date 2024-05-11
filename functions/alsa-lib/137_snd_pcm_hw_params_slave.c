int snd_pcm_hw_params_slave(snd_pcm_t *pcm, snd_pcm_hw_params_t *params,
			    int (*cchange)(snd_pcm_t *pcm,
					   snd_pcm_hw_params_t *params,
					   snd_pcm_hw_params_t *sparams),
			    int (*sprepare)(snd_pcm_t *pcm,
					    snd_pcm_hw_params_t *params),
			    int (*schange)(snd_pcm_t *pcm,
					   snd_pcm_hw_params_t *params,
					   snd_pcm_hw_params_t *sparams),
			    int (*sparams)(snd_pcm_t *pcm,
					   snd_pcm_hw_params_t *sparams))

{
	snd_pcm_hw_params_t slave_params;
	int err;
	err = sprepare(pcm, &slave_params);
	if (err < 0)
		return err;
	err = schange(pcm, params, &slave_params);
	if (err < 0)
		return err;
	err = sparams(pcm, &slave_params);
	if (err < 0)
		cchange(pcm, params, &slave_params);
	return err;
}