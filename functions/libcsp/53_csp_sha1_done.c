void csp_sha1_done(csp_sha1_state_t * sha1, uint8_t * out) {

	uint32_t i;

	/* Increase the length of the message */
	sha1->length += sha1->curlen * 8;

	/* Append the '1' bit */
	sha1->buf[sha1->curlen++] = 0x80;

	/* If the length is currently above 56 bytes we append zeros
	 * then compress. Then we can fall back to padding zeros and length
	 * encoding like normal.
	 */
	if (sha1->curlen > 56) {
		while (sha1->curlen < 64)
			sha1->buf[sha1->curlen++] = 0;
		csp_sha1_compress(sha1, sha1->buf);
		sha1->curlen = 0;
	}

	/* Pad up to 56 bytes of zeroes */
	while (sha1->curlen < 56)
		sha1->buf[sha1->curlen++] = 0;

	/* Store length */
	STORE64H(sha1->length, sha1->buf + 56);
	csp_sha1_compress(sha1, sha1->buf);

	/* Copy output */
	for (i = 0; i < 5; i++)
		STORE32H(sha1->state[i], out + (4 * i));

}