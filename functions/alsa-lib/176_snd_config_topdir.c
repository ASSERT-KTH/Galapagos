const char *snd_config_topdir(void)
{
	static char *topdir;

	if (!topdir) {
		topdir = getenv("ALSA_CONFIG_DIR");
		if (!topdir || *topdir != '/' || strlen(topdir) >= PATH_MAX)
			topdir = ALSA_CONFIG_DIR;
	}
	return topdir;
}