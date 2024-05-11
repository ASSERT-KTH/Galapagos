int snd_pcm_dump(snd_pcm_t *pcm, snd_output_t *out)
{
	int err = 0;

	assert(pcm);
	assert(out);
	if (pcm->ops->dump)
		pcm->ops->dump(pcm->op_arg, out);
	else
		err = -ENOSYS;
	return err;
}