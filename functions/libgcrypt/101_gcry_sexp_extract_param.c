gcry_sexp_extract_param (gcry_sexp_t sexp, const char *path,
                         const char *list, ...)
{
  gcry_err_code_t rc;
  va_list arg_ptr;

  va_start (arg_ptr, list);
  rc = _gcry_sexp_vextract_param (sexp, path, list, arg_ptr);
  va_end (arg_ptr);
  return gpg_error (rc);
}