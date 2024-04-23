crypto_auth_hmacsha512_update(crypto_auth_hmacsha512_state *state,
                              const unsigned char *in, unsigned long long inlen)
{
    crypto_hash_sha512_update(&state->ictx, in, inlen);

    return 0;
}