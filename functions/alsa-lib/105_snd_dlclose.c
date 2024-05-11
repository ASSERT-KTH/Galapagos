int snd_dlclose(void *handle)
{
#ifndef PIC
	if (handle == &snd_dlsym_start)
		return 0;
#endif
#ifdef HAVE_LIBDL
	return dlclose(handle);
#else
	return 0;
#endif
}