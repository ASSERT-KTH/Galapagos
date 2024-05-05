int csp_xtea_encrypt_packet(csp_packet_t * packet) {

	/* Create nonce */
	const uint32_t nonce = (uint32_t)rand();
	const uint32_t nonce_n = csp_hton32(nonce);

	if ((packet->length + sizeof(nonce_n)) > csp_buffer_data_size()) {
		return CSP_ERR_NOMEM;
	}

	/* Create initialization vector */
	uint32_t iv[2] = {nonce, 1};

	/* Encrypt data */
	if (csp_xtea_encrypt(packet->data, packet->length, iv) != CSP_ERR_NONE) {
		return CSP_ERR_XTEA;
        }

	memcpy(&packet->data[packet->length], &nonce_n, sizeof(nonce_n));
	packet->length += sizeof(nonce_n);

	return CSP_ERR_NONE;

}