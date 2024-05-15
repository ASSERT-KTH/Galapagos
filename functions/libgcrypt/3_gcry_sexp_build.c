gcry_sexp_build (gcry_sexp_t *retsexp, size_t *erroff,
                 const char *format, ...)
{
  gcry_err_code_t rc;
  va_list arg_ptr;

  va_start (arg_ptr, format);
  rc = _gcry_sexp_vbuild (retsexp, erroff, format, arg_ptr);
  va_end (arg_ptr);
  return gpg_error (rc);
}