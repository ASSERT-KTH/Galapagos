reporter (const char *domain, int algo, const char *what, const char *errtxt)
{
  if (!errtxt && !_gcry_log_verbosity (2))
    return;

  log_info ("libgcrypt selftest: %s %s%s (%d): %s%s%s%s\n",
            !strcmp (domain, "hmac")? "digest":domain,
            !strcmp (domain, "hmac")? "HMAC-":"",
            !strcmp (domain, "cipher")? _gcry_cipher_algo_name (algo) :
            !strcmp (domain, "digest")? _gcry_md_algo_name (algo) :
            !strcmp (domain, "hmac")?   _gcry_md_algo_name (algo) :
            !strcmp (domain, "pubkey")? _gcry_pk_algo_name (algo) : "",
            algo, errtxt? errtxt:"Okay",
            what?" (":"", what? what:"", what?")":"");
}