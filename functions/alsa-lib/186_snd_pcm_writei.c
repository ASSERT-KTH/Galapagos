snd_pcm_sframes_t snd_pcm_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size)
{
	int err;

	assert(pcm);
	assert(size == 0 || buffer);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	if (pcm->access != SND_PCM_ACCESS_RW_INTERLEAVED) {
		SNDMSG("invalid access type %s", snd_pcm_access_name(pcm->access));
		return -EINVAL;
	}
	err = bad_pcm_state(pcm, P_STATE_RUNNABLE, 0);
	if (err < 0)
		return err;
	return _snd_pcm_writei(pcm, buffer, size);
}