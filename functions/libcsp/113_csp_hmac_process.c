static int csp_hmac_process(hmac_state * hmac, const uint8_t * in, uint32_t inlen) {

	/* NULL pointer check */
	if (!hmac || !in)
		return CSP_ERR_INVAL;

	/* Process data */
	csp_sha1_process(&hmac->md, in, inlen);

	return CSP_ERR_NONE;
}