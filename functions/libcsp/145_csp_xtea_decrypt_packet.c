int csp_xtea_decrypt_packet(csp_packet_t * packet) {

	/* Read nonce */
	uint32_t nonce;

	if (packet->length < sizeof(nonce)) {
		return CSP_ERR_XTEA;
	}

        memcpy(&nonce, &packet->data[packet->length - sizeof(nonce)], sizeof(nonce));
	nonce = csp_ntoh32(nonce);

	/* Create initialization vector */
	uint32_t iv[2] = {nonce, 1};

	/* Decrypt data */
	if (csp_xtea_decrypt(packet->data, packet->length, iv) != CSP_ERR_NONE) {
		return CSP_ERR_XTEA;
	}

	packet->length -= sizeof(nonce);

	return CSP_ERR_NONE;

}