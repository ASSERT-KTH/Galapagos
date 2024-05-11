static int bad_pcm_state(snd_pcm_t *pcm, unsigned int supported_states,
			 unsigned int noop_states)
{
	snd_pcm_state_t state;
	int err;

	if (pcm->own_state_check)
		return 0; /* don't care, the plugin checks by itself */
	state = snd_pcm_state(pcm);
	if (noop_states & (1U << state))
		return 1; /* OK, return immediately */
	if (supported_states & (1U << state))
		return 0; /* OK */
	err = pcm_state_to_error(state);
	if (err < 0)
		return err;
	return -EBADFD;
}