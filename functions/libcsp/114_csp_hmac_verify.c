int csp_hmac_verify(csp_packet_t * packet, bool include_header) {

	if (packet->length < (unsigned int)CSP_HMAC_LENGTH) {
		return CSP_ERR_HMAC;
	}

	uint8_t hmac[CSP_SHA1_DIGESTSIZE];

	/* Calculate HMAC */
	if (include_header) {
		csp_hmac_memory(csp_hmac_key, sizeof(csp_hmac_key), &packet->id, packet->length + sizeof(packet->id) - CSP_HMAC_LENGTH, hmac);
	} else {
		csp_hmac_memory(csp_hmac_key, sizeof(csp_hmac_key), packet->data, packet->length - CSP_HMAC_LENGTH, hmac);
	}

	/* Compare calculated HMAC with packet header */
	if (memcmp(&packet->data[packet->length] - CSP_HMAC_LENGTH, hmac, CSP_HMAC_LENGTH) != 0) {
		/* HMAC failed */
		return CSP_ERR_HMAC;
	}

	/* Strip HMAC */
	packet->length -= CSP_HMAC_LENGTH;
	return CSP_ERR_NONE;

}