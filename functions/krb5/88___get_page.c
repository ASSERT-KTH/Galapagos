__get_page(HTAB *hashp, u_int32_t addr, int32_t addr_type)
{
	PAGE16 *pagep;
	db_pgno_t paddr;

	switch (addr_type) {			/* Convert page number. */
	case A_BUCKET:
		paddr = BUCKET_TO_PAGE(addr);
		break;
	case A_OVFL:
	case A_BITMAP:
		paddr = OADDR_TO_PAGE(addr);
		break;
	default:
		paddr = addr;
		break;
	}
	pagep = (PAGE16 *)mpool_get(hashp->mp, paddr, 0);

#if DEBUG_SLOW
	account_page(hashp, paddr, 1);
#endif
#ifdef DEBUG
	assert(ADDR(pagep) == paddr || ADDR(pagep) == 0 ||
	    addr_type == A_BITMAP || addr_type == A_HEADER);
#endif

	return (pagep);
}