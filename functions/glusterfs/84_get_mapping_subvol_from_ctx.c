get_mapping_subvol_from_ctx (xlator_t *this, inode_t *inode)
{
	uint64_t subvol = 0;
	int      ret    = -1;

	ret = inode_ctx_get (inode, this, &subvol);
	if (ret != 0) 
		return NULL;

	return (xlator_t *)(long)subvol;
}