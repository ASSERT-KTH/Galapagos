crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                              const unsigned char *in, unsigned long long inlen)
{
    crypto_hash_sha256_update(&state->ictx, in, inlen);

    return 0;
}