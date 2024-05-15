meta_ctx_set (inode_t *inode, xlator_t *this, void *ctx)
{
	uint64_t value = 0;
	int ret = 0;

	value = (long) ctx;

	ret = inode_ctx_set2 (inode, this, &value, 0);

	return ret;
}