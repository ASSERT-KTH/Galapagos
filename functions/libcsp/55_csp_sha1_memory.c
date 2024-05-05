void csp_sha1_memory(const void * msg, uint32_t len, uint8_t * hash) {

	csp_sha1_state_t md;
	csp_sha1_init(&md);
	csp_sha1_process(&md, msg, len);
	csp_sha1_done(&md, hash);

}