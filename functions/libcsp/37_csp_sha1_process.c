void csp_sha1_process(csp_sha1_state_t * sha1, const void * data, uint32_t inlen) {

	const uint8_t * in = data;
	uint32_t n;
	while (inlen > 0) {
		if (sha1->curlen == 0 && inlen >= CSP_SHA1_BLOCKSIZE) {
			csp_sha1_compress(sha1, in);
			sha1->length += (CSP_SHA1_BLOCKSIZE * 8);
			in += CSP_SHA1_BLOCKSIZE;
			inlen -= CSP_SHA1_BLOCKSIZE;
		} else {
			n = MIN(inlen, (CSP_SHA1_BLOCKSIZE - sha1->curlen));
			memcpy(sha1->buf + sha1->curlen, in, (size_t)n);
			sha1->curlen += n;
			in += n;
			inlen -= n;
			if (sha1->curlen == CSP_SHA1_BLOCKSIZE) {
				csp_sha1_compress(sha1, sha1->buf);
				sha1->length += (CSP_SHA1_BLOCKSIZE * 8);
				sha1->curlen = 0;
			}
		}
	}

}