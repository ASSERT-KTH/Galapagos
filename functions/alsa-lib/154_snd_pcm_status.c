int snd_pcm_status(snd_pcm_t *pcm, snd_pcm_status_t *status)
{
	int err;

	assert(pcm && status);
	snd_pcm_lock(pcm->fast_op_arg);
	if (pcm->fast_ops->status)
		err = pcm->fast_ops->status(pcm->fast_op_arg, status);
	else
		err = -ENOSYS;
	snd_pcm_unlock(pcm->fast_op_arg);

	return err;
}