static int csp_hmac_done(hmac_state * hmac, uint8_t * out) {

	if (!hmac || !out)
		return CSP_ERR_INVAL;

	/* Get the hash of the first HMAC vector plus the data */
	uint8_t isha[CSP_SHA1_DIGESTSIZE];
	csp_sha1_done(&hmac->md, isha);

	/* Create the second HMAC vector vector */
	uint8_t buf[CSP_SHA1_BLOCKSIZE];
	for(unsigned int i = 0; i < sizeof(buf); i++) {
		buf[i] = hmac->key[i] ^ 0x5C;
	}

	/* Now calculate the outer hash */
	csp_sha1_init(&hmac->md);
	csp_sha1_process(&hmac->md, buf, sizeof(buf));
	csp_sha1_process(&hmac->md, isha, sizeof(isha));
	csp_sha1_done(&hmac->md, buf);

	/* Copy to output  */
	memcpy(out, buf, CSP_SHA1_DIGESTSIZE);

	return CSP_ERR_NONE;
}