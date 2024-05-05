int csp_hmac_append(csp_packet_t * packet, bool include_header) {

	if ((packet->length + (unsigned int)CSP_HMAC_LENGTH) > csp_buffer_data_size()) {
		return CSP_ERR_NOMEM;
	}

	/* Calculate HMAC */
	uint8_t hmac[CSP_SHA1_DIGESTSIZE];
	if (include_header) {
		csp_hmac_memory(csp_hmac_key, sizeof(csp_hmac_key), &packet->id, packet->length + sizeof(packet->id), hmac);
	} else {
		csp_hmac_memory(csp_hmac_key, sizeof(csp_hmac_key), packet->data, packet->length, hmac);
	}

	/* Truncate hash and copy to packet */
	memcpy(&packet->data[packet->length], hmac, CSP_HMAC_LENGTH);
	packet->length += CSP_HMAC_LENGTH;

	return CSP_ERR_NONE;

}