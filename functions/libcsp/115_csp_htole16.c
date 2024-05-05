inline uint16_t __attribute__ ((__const__)) csp_htole16(uint16_t h16) {
#if (CSP_LITTLE_ENDIAN)
	return h16;
#else
	return (((h16 & 0xff00) >> 8) |
			((h16 & 0x00ff) << 8));
#endif
}