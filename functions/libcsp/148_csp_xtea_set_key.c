int csp_xtea_set_key(const void * key, uint32_t keylen) {

	/* Use SHA1 as KDF */
	uint8_t hash[CSP_SHA1_DIGESTSIZE];
	csp_sha1_memory(key, keylen, hash);

	/* Copy key */
	memcpy(csp_xtea_key, hash, XTEA_KEY_LENGTH);

	return CSP_ERR_NONE;

}