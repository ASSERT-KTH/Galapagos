glfs_resolve_inode (struct glfs *fs, xlator_t *subvol,
		    struct glfs_object *object)
{
	inode_t *inode = NULL;

	glfs_lock (fs);
	{
		inode = __glfs_resolve_inode(fs, subvol, object);
	}
	glfs_unlock (fs);

	return inode;
}