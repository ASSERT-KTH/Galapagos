init (void)
{
    AES_RETURN r;

    r = aes_encrypt_key128(key, &ctx);
    if (r) fprintf(stderr, "error, line %d\n", __LINE__), exit(1);
    r = aes_decrypt_key128(key, &dctx);
    if (r) fprintf(stderr, "error, line %d\n", __LINE__), exit(1);
}