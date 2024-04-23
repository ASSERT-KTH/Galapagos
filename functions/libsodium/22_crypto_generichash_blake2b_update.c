crypto_generichash_blake2b_update(crypto_generichash_blake2b_state *state,
                                  const unsigned char *in,
                                  unsigned long long inlen)
{
    return blake2b_update((blake2b_state *) (void *) state,
                          (const uint8_t *) in, (uint64_t) inlen);
}