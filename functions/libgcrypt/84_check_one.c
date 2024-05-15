check_one (int algo, int hash_algo,
           const void *passphrase, size_t passphraselen,
           const void *salt, size_t saltlen,
           unsigned long iterations,
           const void *expect, size_t expectlen)
{
  unsigned char key[512]; /* hardcoded to avoid allocation */
  size_t keysize = expectlen;
  int rv;

  if (keysize > sizeof(key))
    return "invalid tests data";

  rv = _gcry_kdf_derive (passphrase, passphraselen, algo,
                         hash_algo, salt, saltlen, iterations,
                         keysize, key);
  /* In fips mode we have special requirements for the input and
   * output parameters */
  if (fips_mode ())
    {
      if (rv && (passphraselen < 8 || saltlen < 16 ||
                 iterations < 1000 || expectlen < 14))
        return NULL;
      else if (rv)
        return "gcry_kdf_derive unexpectedly failed in FIPS Mode";
    }
  else if (rv)
    return "gcry_kdf_derive failed";

  if (memcmp (key, expect, expectlen))
    return "does not match";

  return NULL;
}