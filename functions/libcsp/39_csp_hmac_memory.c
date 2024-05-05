int csp_hmac_memory(const void * key, uint32_t keylen, const void * data, uint32_t datalen, uint8_t * hmac) {
	hmac_state state;

	/* NULL pointer check */
	if (!key || !data || !hmac)
		return CSP_ERR_INVAL;

	/* Init HMAC state */
	if (csp_hmac_init(&state, key, keylen) != 0)
		return CSP_ERR_INVAL;

	/* Process data */
	if (csp_hmac_process(&state, data, datalen) != 0)
		return CSP_ERR_INVAL;

	/* Output HMAC */
	if (csp_hmac_done(&state, hmac) != 0)
		return CSP_ERR_INVAL;

	return CSP_ERR_NONE;
}