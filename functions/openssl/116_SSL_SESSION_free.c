void SSL_SESSION_free(SSL_SESSION *ss)
{
    int i;

    if (ss == NULL)
        return;
    CRYPTO_DOWN_REF(&ss->references, &i, ss->lock);
    REF_PRINT_COUNT("SSL_SESSION", ss);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL_SESSION, ss, &ss->ex_data);

    OPENSSL_cleanse(ss->master_key, sizeof(ss->master_key));
    OPENSSL_cleanse(ss->session_id, sizeof(ss->session_id));
    X509_free(ss->peer);
    EVP_PKEY_free(ss->peer_rpk);
    OSSL_STACK_OF_X509_free(ss->peer_chain);
    OPENSSL_free(ss->ext.hostname);
    OPENSSL_free(ss->ext.tick);
#ifndef OPENSSL_NO_PSK
    OPENSSL_free(ss->psk_identity_hint);
    OPENSSL_free(ss->psk_identity);
#endif
#ifndef OPENSSL_NO_SRP
    OPENSSL_free(ss->srp_username);
#endif
    OPENSSL_free(ss->ext.alpn_selected);
    OPENSSL_free(ss->ticket_appdata);
    CRYPTO_THREAD_lock_free(ss->lock);
    OPENSSL_clear_free(ss, sizeof(*ss));
}