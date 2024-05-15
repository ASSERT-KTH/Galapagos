glfs_resolve_fd (struct glfs *fs, xlator_t *subvol, struct glfs_fd *glfd)
{
	fd_t *fd = NULL;

	glfs_lock (fs);
	{
		fd = __glfs_resolve_fd (fs, subvol, glfd);
	}
	glfs_unlock (fs);

	return fd;
}