snd_pcm_sframes_t snd_pcm_avail_update(snd_pcm_t *pcm)
{
	snd_pcm_sframes_t result;

	snd_pcm_lock(pcm->fast_op_arg);
	result = __snd_pcm_avail_update(pcm);
	snd_pcm_unlock(pcm->fast_op_arg);
	return result;
}