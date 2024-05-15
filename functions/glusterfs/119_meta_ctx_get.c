meta_ctx_get (inode_t *inode, xlator_t *this)
{
	void *ctx = NULL;
	uint64_t value = 0;

	inode_ctx_get2 (inode, this, &value, 0);

	ctx = (void *) value;

	return ctx;
}