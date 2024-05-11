int snd_config_get_bool(const snd_config_t *conf)
{
	long v;
	const char *str, *id;
	int err;

	err = snd_config_get_id(conf, &id);
	if (err < 0)
		return err;
	err = snd_config_get_integer(conf, &v);
	if (err >= 0) {
		if (v < 0 || v > 1) {
		_invalid_value:
			SNDERR("Invalid value for %s", id);
			return -EINVAL;
		}
		return v;
	}
	err = snd_config_get_string(conf, &str);
	if (err < 0) {
		SNDERR("Invalid type for %s", id);
		return -EINVAL;
	}
	err = snd_config_get_bool_ascii(str);
	if (err < 0)
		goto _invalid_value;
	return err;
}