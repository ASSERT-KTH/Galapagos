static int parse_string_substitute3(snd_use_case_mgr_t *uc_mgr,
			     snd_config_t *n, char **res)
{
	if (uc_mgr->conf_format < 3)
		return parse_string(n, res);
	return parse_string_substitute(uc_mgr, n, res);
}