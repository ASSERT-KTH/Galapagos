gcry_kem_keypair (int algo,
                  void *pubkey, size_t pubkey_len,
                  void *seckey, size_t seckey_len)

{
  return gpg_error (_gcry_kem_keypair (algo,
                                       pubkey, pubkey_len,
                                       seckey, seckey_len));
}