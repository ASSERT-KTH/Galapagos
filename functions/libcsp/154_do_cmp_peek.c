static int do_cmp_peek(struct csp_cmp_message *cmp) {

	cmp->peek.addr = csp_hton32(cmp->peek.addr);
	if (cmp->peek.len > CSP_CMP_PEEK_MAX_LEN)
		return CSP_ERR_INVAL;

	/* Dangerous, you better know what you are doing */
	csp_cmp_memcpy_fnc((csp_memptr_t) (uintptr_t) cmp->peek.data, (csp_memptr_t) (uintptr_t) cmp->peek.addr, cmp->peek.len);

	return CSP_ERR_NONE;

}