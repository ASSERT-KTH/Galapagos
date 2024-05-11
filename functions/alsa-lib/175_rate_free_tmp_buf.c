static void rate_free_tmp_buf(snd_pcm_channel_area_t **ptr)
{
	snd_pcm_channel_area_t *c = *ptr;

	if (c) {
		free(c->addr);
		free(c);
		*ptr = NULL;
	}
}