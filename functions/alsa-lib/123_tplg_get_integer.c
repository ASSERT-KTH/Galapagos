int tplg_get_integer(snd_config_t *n, int *val, int base)
{
	const char *str;
	long lval;
	int err;

	switch (snd_config_get_type(n)) {
	case SND_CONFIG_TYPE_INTEGER:
		err = snd_config_get_integer(n, &lval);
		if (err < 0)
			return err;
		goto __retval;
	case SND_CONFIG_TYPE_STRING:
		err = snd_config_get_string(n, &str);
		if (err < 0)
			return err;
		err = safe_strtol_base(str, &lval, base);
		if (err < 0)
			return err;
		goto __retval;
	default:
		return -EINVAL;
	}
  __retval:
	if (lval < INT_MIN || lval > INT_MAX)
		return -ERANGE;
	*val = lval;
	return 0;
}