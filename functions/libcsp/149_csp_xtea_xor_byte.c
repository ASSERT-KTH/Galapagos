static inline void csp_xtea_xor_byte(uint8_t * dst, uint8_t * src, uint32_t len) {

	unsigned int i;
	for (i = 0; i < len; i++)
		dst[i] ^= src[i];

}