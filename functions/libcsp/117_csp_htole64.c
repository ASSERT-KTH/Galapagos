inline uint64_t __attribute__ ((__const__)) csp_htole64(uint64_t h64) {
#if (CSP_LITTLE_ENDIAN)
	return h64;
#else
	return (((h64 & 0xff00000000000000LL) >> 56) |
			((h64 & 0x00000000000000ffLL) << 56) |
			((h64 & 0x00ff000000000000LL) >> 40) |
			((h64 & 0x000000000000ff00LL) << 40) |
			((h64 & 0x0000ff0000000000LL) >> 24) |
			((h64 & 0x0000000000ff0000LL) << 24) |
			((h64 & 0x000000ff00000000LL) >>  8) |
			((h64 & 0x00000000ff000000LL) <<  8));
#endif
}