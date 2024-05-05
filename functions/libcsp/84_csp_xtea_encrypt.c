int csp_xtea_encrypt(void * plain, const uint32_t len, uint32_t iv[2]) {

	unsigned int i;
	uint32_t stream[2];

	uint32_t blocks = (len + XTEA_BLOCKSIZE - 1)/ XTEA_BLOCKSIZE;
	uint32_t remain;

	/* Initialize stream */
	stream[0] = csp_htobe32(iv[0]);
	stream[1] = csp_htobe32(iv[1]);

	for (i = 0; i < blocks; i++) {
		/* Create stream */
		csp_xtea_encrypt_block((uint8_t *)stream, (uint8_t *)csp_xtea_key);

		/* Calculate remaining bytes */
		remain = len - i * XTEA_BLOCKSIZE;

		/* XOR plain text with stream to generate cipher text */
		csp_xtea_xor_byte(&((uint8_t*)plain)[len - remain], (uint8_t *)stream, remain < XTEA_BLOCKSIZE ? remain : XTEA_BLOCKSIZE);

		/* Increment counter */
		stream[0] = csp_htobe32(iv[0]);
		stream[1] = csp_htobe32(iv[1]++);
	}

	return CSP_ERR_NONE;

}