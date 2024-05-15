gcry_kem_decap (int algo,
                const void *seckey, size_t seckey_len,
                const void *ciphertext, size_t ciphertext_len,
                void *shared, size_t shared_len,
                const void *optional, size_t optional_len)
{
  return gpg_error (_gcry_kem_decap (algo,
                                     seckey, seckey_len,
                                     ciphertext, ciphertext_len,
                                     shared, shared_len,
                                     optional, optional_len));
}