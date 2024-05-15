gcry_kem_encap (int algo,
                const void *pubkey, size_t pubkey_len,
                void *ciphertext, size_t ciphertext_len,
                void *shared, size_t shared_len,
                const void *optional, size_t optional_len)
{
  return gpg_error (_gcry_kem_encap (algo,
                                     pubkey, pubkey_len,
                                     ciphertext, ciphertext_len,
                                     shared, shared_len,
                                     optional, optional_len));
}