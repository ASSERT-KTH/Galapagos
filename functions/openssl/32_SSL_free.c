void SSL_free(SSL *s)
{
    int i;

    if (s == NULL)
        return;
    CRYPTO_DOWN_REF(&s->references, &i, s->lock);
    REF_PRINT_COUNT("SSL", s);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL, s, &s->ex_data);

    if (s->method != NULL)
        s->method->ssl_free(s);

    SSL_CTX_free(s->ctx);
    CRYPTO_THREAD_lock_free(s->lock);

    OPENSSL_free(s);
}