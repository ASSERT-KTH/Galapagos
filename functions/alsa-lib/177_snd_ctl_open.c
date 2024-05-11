int snd_ctl_open(snd_ctl_t **ctlp, const char *name, int mode)
{
	snd_config_t *top;
	int err;

	assert(ctlp && name);
	if (_snd_is_ucm_device(name)) {
		name = uc_mgr_alibcfg_by_device(&top, name);
		if (name == NULL)
			return -ENODEV;
	} else {
		err = snd_config_update_ref(&top);
		if (err < 0)
			return err;
	}
	err = snd_ctl_open_noupdate(ctlp, top, name, mode, 0);
	snd_config_unref(top);
	return err;
}