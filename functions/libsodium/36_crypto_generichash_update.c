crypto_generichash_update(crypto_generichash_state *state,
                          const unsigned char *in,
                          unsigned long long inlen)
{
    return crypto_generichash_blake2b_update
        ((crypto_generichash_blake2b_state *) state, in, inlen);
}