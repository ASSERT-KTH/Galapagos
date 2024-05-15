_gcry_pk_verify (gcry_sexp_t s_sig, gcry_sexp_t s_hash, gcry_sexp_t s_pkey)
{
  gcry_err_code_t rc;
  gcry_pk_spec_t *spec;
  gcry_sexp_t keyparms;

  rc = spec_from_sexp (s_pkey, 0, &spec, &keyparms);
  if (rc)
    goto leave;

  if (spec->flags.disabled)
    rc = GPG_ERR_PUBKEY_ALGO;
  else if (!spec->flags.fips && fips_mode ())
    rc = GPG_ERR_PUBKEY_ALGO;
  else if (spec->verify)
    rc = spec->verify (s_sig, s_hash, keyparms);
  else
    rc = GPG_ERR_NOT_IMPLEMENTED;

 leave:
  sexp_release (keyparms);
  return rc;
}