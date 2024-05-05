int csp_hmac_set_key(const void * key, uint32_t keylen) {

	/* Use SHA1 as KDF */
	uint8_t hash[CSP_SHA1_DIGESTSIZE];
	csp_sha1_memory(key, keylen, hash);

	/* Copy key */
	memcpy(csp_hmac_key, hash, sizeof(csp_hmac_key));

	return CSP_ERR_NONE;

}