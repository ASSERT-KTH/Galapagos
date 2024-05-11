void snd_pcm_mmap_appl_forward(snd_pcm_t *pcm, snd_pcm_uframes_t frames)
{
	snd_pcm_uframes_t appl_ptr = *pcm->appl.ptr;
	appl_ptr += frames;
	if (appl_ptr >= pcm->boundary)
		appl_ptr -= pcm->boundary;
	*pcm->appl.ptr = appl_ptr;
}