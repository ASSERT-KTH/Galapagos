drbg_hash (drbg_state_t drbg, const drbg_string_t *buf)
{
  gcry_md_hd_t hd = (gcry_md_hd_t)drbg->priv_data;

  _gcry_md_reset(hd);
  for (; NULL != buf; buf = buf->next)
    _gcry_md_write (hd, buf->buf, buf->len);
  _gcry_md_final (hd);
  return _gcry_md_read (hd, drbg->core->backend_cipher);
}