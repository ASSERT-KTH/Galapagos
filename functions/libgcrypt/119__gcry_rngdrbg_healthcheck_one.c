_gcry_rngdrbg_healthcheck_one (struct gcry_drbg_test_vector * test)
{
  gpg_err_code_t ret = GPG_ERR_ENOMEM;
  unsigned char *buf = xcalloc_secure (1, test->expectedlen);
  if (!buf)
    return GPG_ERR_ENOMEM;

  ret = _gcry_rngdrbg_cavs_test (test, buf);
  /* FIXME: The next line is wrong.   */
  ret = memcmp (test->expected, buf, test->expectedlen);

  xfree (buf);
  return ret;
}