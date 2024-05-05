static inline void csp_xtea_encrypt_block(uint8_t *block, uint8_t const *key) {

	uint32_t i, v0, v1, delta = 0x9E3779B9, sum = 0, k[4];

	LOAD32L(k[0], &key[0]);
	LOAD32L(k[1], &key[4]);
	LOAD32L(k[2], &key[8]);
	LOAD32L(k[3], &key[12]);

	LOAD32L(v0, &block[0]);
	LOAD32L(v1, &block[4]);

	for (i = 0; i < XTEA_ROUNDS; i++) {
		v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
		sum += delta;
		v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum >> 11) & 3]);
	}

	STORE32L(v0, &block[0]);
	STORE32L(v1, &block[4]);

}