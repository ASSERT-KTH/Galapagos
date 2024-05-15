meta_ops_set (inode_t *inode, xlator_t *this, struct meta_ops *ops)
{
	uint64_t value = 0;
	int ret = 0;

	meta_defaults_init (&ops->fops);

	value = (long) ops;

	ret = inode_ctx_set2 (inode, this, NULL, &value);

	return ret;
}