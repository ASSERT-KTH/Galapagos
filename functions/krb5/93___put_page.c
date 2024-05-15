__put_page(HTAB *hashp, PAGE16 *pagep, int32_t addr_type, int32_t is_dirty)
{
#if DEBUG_SLOW
	account_page(hashp,
	    ((BKT *)((char *)pagep - sizeof(BKT)))->pgno, -1);
#endif

	return (mpool_put(hashp->mp, pagep, (is_dirty ? MPOOL_DIRTY : 0)));
}