void *snd_dlsym(void *handle, const char *name, const char *version)
{
	int err;

#ifndef PIC
	if (handle == &snd_dlsym_start) {
		/* it's the funny part: */
		/* we are looking for a symbol in a static library */
		struct snd_dlsym_link *link = snd_dlsym_start;
		while (link) {
			if (!strcmp(name, link->dlsym_name))
				return (void *)link->dlsym_ptr;
			link = link->next;
		}
		return NULL;
	}
#endif
#ifdef HAVE_LIBDL
#ifdef VERSIONED_SYMBOLS
	if (version) {
		err = snd_dlsym_verify(handle, name, version);
		if (err < 0)
			return NULL;
	}
#endif
	return dlsym(handle, name);
#else
	return NULL;
#endif
}