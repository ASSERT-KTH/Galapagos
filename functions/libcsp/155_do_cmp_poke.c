static int do_cmp_poke(struct csp_cmp_message *cmp) {

	cmp->poke.addr = csp_hton32(cmp->poke.addr);
	if (cmp->poke.len > CSP_CMP_POKE_MAX_LEN)
		return CSP_ERR_INVAL;

	/* Extremely dangerous, you better know what you are doing */
	csp_cmp_memcpy_fnc((csp_memptr_t) (uintptr_t) cmp->poke.addr, (csp_memptr_t) (uintptr_t) cmp->poke.data, cmp->poke.len);

	return CSP_ERR_NONE;

}