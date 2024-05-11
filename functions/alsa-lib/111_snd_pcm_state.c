snd_pcm_state_t snd_pcm_state(snd_pcm_t *pcm)
{
	snd_pcm_state_t state;

	assert(pcm);
	snd_pcm_lock(pcm->fast_op_arg);
	state = __snd_pcm_state(pcm);
	snd_pcm_unlock(pcm->fast_op_arg);
	return state;
}