_gcry_pk_single_data_push (gcry_ctx_t *r_ctx,
                          const unsigned char *p, size_t len)
{
  gcry_ctx_t ctx;
  struct pk_single_data *psd;
  int data_type = CONTEXT_TYPE_SINGLE_DATA;

  if (!p)
    return GPG_ERR_EINVAL;

  ctx = _gcry_ctx_alloc (data_type,
			 offsetof (struct pk_single_data, area) + len,
                         NULL, *r_ctx);
  if (!ctx)
    return gpg_err_code_from_syserror ();
  psd = _gcry_ctx_get_pointer (ctx, data_type);
  psd->len = len;
  memcpy (psd->area, p, len);

  *r_ctx = ctx;
  return 0;
}