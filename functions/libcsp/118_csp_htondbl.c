inline double __attribute__ ((__const__)) csp_htondbl(double d) {
#if (CSP_BIG_ENDIAN)
	return d;
#else
	union v {
		double       d;
		uint64_t     i;
	};
	union v val;
	val.d = d;
	val.i = csp_hton64(val.i);
	return val.d;
#endif
}