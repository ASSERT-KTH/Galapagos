iobref_new ()
{
        struct iobref *iobref = NULL;

        iobref = GF_CALLOC (sizeof (*iobref), 1,
                            gf_common_mt_iobref);
        if (!iobref)
                return NULL;

	iobref->iobrefs = GF_CALLOC (sizeof (*iobref->iobrefs),
				     16, gf_common_mt_iobrefs);
	if (!iobref->iobrefs) {
		GF_FREE (iobref);
		return NULL;
	}

	iobref->alloced = 16;
	iobref->used = 0;

        LOCK_INIT (&iobref->lock);

        iobref->ref++;

        return iobref;
}