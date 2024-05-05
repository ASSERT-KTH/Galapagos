static int csp_hmac_init(hmac_state * hmac, const uint8_t * key, uint32_t keylen) {
	uint32_t i;
	uint8_t buf[CSP_SHA1_BLOCKSIZE];

	/* NULL pointer and key check */
	if (!hmac || !key || keylen < 1)
		return CSP_ERR_INVAL;

	/* Make sure we have a large enough key */
	if(keylen > CSP_SHA1_BLOCKSIZE) {
		csp_sha1_memory(key, keylen, hmac->key);
		if(CSP_SHA1_DIGESTSIZE < CSP_SHA1_BLOCKSIZE)
			memset((hmac->key) + CSP_SHA1_DIGESTSIZE, 0, (CSP_SHA1_BLOCKSIZE - CSP_SHA1_DIGESTSIZE));
	} else {
		memcpy(hmac->key, key, keylen);
		if(keylen < CSP_SHA1_BLOCKSIZE)
			memset((hmac->key) + keylen, 0, (CSP_SHA1_BLOCKSIZE - keylen));
	}

	/* Create the initial vector */
	for(i = 0; i < CSP_SHA1_BLOCKSIZE; i++) {
		buf[i] = hmac->key[i] ^ 0x36;
	}

	/* Prepend to the hash data */
	csp_sha1_init(&hmac->md);
	csp_sha1_process(&hmac->md, buf, CSP_SHA1_BLOCKSIZE);

	return CSP_ERR_NONE;
}