inline float __attribute__ ((__const__)) csp_htonflt(float f) {
#if (CSP_BIG_ENDIAN)
	return f;
#else
	union v {
		float       f;
		uint32_t	i;
	};
	union v val;
	val.f = f;
	val.i = csp_hton32(val.i);
	return val.f;
#endif
}