path_this_to_that (xlator_t *xl, const char *path)
{
	path_private_t *priv = xl->private;
	char *priv_path = NULL;
	int32_t path_len = strlen (path);
	int32_t i = 0, j = 0;

	if (priv->end_off && (path_len > priv->start_off)) {
		priv_path = GF_CALLOC (1, path_len, gf_path_mt_char);
		ERR_ABORT (priv_path);

		if (priv->start_off && (path_len > priv->start_off))
			memcpy (priv_path, path, priv->start_off);
		if (path_len > priv->end_off) {
			j = priv->start_off;
			for (i = priv->start_off; i < priv->end_off; i++) {
				if (path[i] == '/')
					continue;
				priv_path[j++] = path[i];
			}
			memcpy ((priv_path + j), 
				(path + priv->end_off), 
				(path_len - priv->end_off));
			priv_path[(path_len - (priv->end_off - j))] = '\0';
		}
		return priv_path;
	}
	return (char *)path;
}