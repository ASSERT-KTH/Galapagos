map_itransform (xlator_t *this, xlator_t *subvol, uint64_t x, uint64_t *y_p)
{
	map_private_t *priv = NULL;
	int         cnt = 0;
	int         max = 0;
	uint64_t    y = 0;

	if (x == ((uint64_t) -1)) {
		y = (uint64_t) -1;
		goto out;
	}

	priv = this->private;

	max = priv->child_count;
	cnt = map_subvol_cnt (this, subvol);

	y = ((x * max) + cnt);

out:
	if (y_p)
		*y_p = y;

	return 0;
}