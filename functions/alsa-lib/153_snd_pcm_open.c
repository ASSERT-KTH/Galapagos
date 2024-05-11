int snd_pcm_open(snd_pcm_t **pcmp, const char *name, 
		 snd_pcm_stream_t stream, int mode)
{
	snd_config_t *top;
	int err;

	assert(pcmp && name);
	if (_snd_is_ucm_device(name)) {
		name = uc_mgr_alibcfg_by_device(&top, name);
		if (name == NULL)
			return -ENODEV;
	} else {
		err = snd_config_update_ref(&top);
		if (err < 0)
			return err;
	}
	err = snd_pcm_open_noupdate(pcmp, top, name, stream, mode, 0);
	snd_config_unref(top);
	return err;
}