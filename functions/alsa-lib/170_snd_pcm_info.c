int snd_pcm_info(snd_pcm_t *pcm, snd_pcm_info_t *info)
{
	int err = 0;

	assert(pcm && info);
	if (pcm->ops->info)
		err = pcm->ops->info(pcm->op_arg, info);
	else
		err = -ENOSYS;
	return err;
}