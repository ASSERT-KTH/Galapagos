DNS_NORETURN static void panic(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

#if _WIN32
	vfprintf(stderr, fmt, ap);

	exit(EXIT_FAILURE);
#else
	verrx(EXIT_FAILURE, fmt, ap);
#endif
} /* panic() */