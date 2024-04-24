mpool_put(mp, page, flags)
	MPOOL *mp;
	void *page;
	u_int flags;
{
	BKT *bp;

#ifdef STATISTICS
	++mp->pageput;
#endif
	bp = (void *)((char *)page - sizeof(BKT));
#ifdef DEBUG
	if (!(bp->flags & MPOOL_PINNED)) {
		(void)fprintf(stderr,
		    "mpool_put: page %d not pinned\n", bp->pgno);
		abort();
	}
#endif
	bp->flags &= ~MPOOL_PINNED;
	if (flags & MPOOL_DIRTY)
		bp->flags |= flags & MPOOL_DIRTY;
	return (RET_SUCCESS);
}