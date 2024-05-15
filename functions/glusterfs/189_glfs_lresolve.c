glfs_lresolve (struct glfs *fs, xlator_t *subvol, const char *origpath,
	       loc_t *loc, struct iatt *iatt, int reval)
{
	int ret = -1;

	ret = glfs_resolve_path (fs, subvol, origpath, loc, iatt, 0, reval);

	return ret;
}