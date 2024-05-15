OQS_API int OQS_CPU_has_extension(OQS_CPU_EXT ext) {
#if defined(OQS_DIST_BUILD)
#if defined(OQS_USE_PTHREADS)
	pthread_once(&once_control, &set_available_cpu_extensions);
#else
	if (0 == cpu_ext_data[OQS_CPU_EXT_INIT]) {
		set_available_cpu_extensions();
	}
#endif
	if (0 < ext && ext < OQS_CPU_EXT_COUNT) {
		return (int)cpu_ext_data[ext];
	}
#else
	(void)ext;
#endif
	return 0;
}