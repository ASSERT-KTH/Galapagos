inline uint32_t __attribute__ ((__const__)) csp_htole32(uint32_t h32) {
#if (CSP_LITTLE_ENDIAN)
	return h32;
#else
	return (((h32 & 0xff000000) >> 24) |
			((h32 & 0x000000ff) << 24) |
			((h32 & 0x0000ff00) <<  8) |
			((h32 & 0x00ff0000) >>  8));
#endif
}