_libssh2_wincng_load_private(LIBSSH2_SESSION *session,
                             const char *filename,
                             const unsigned char *passphrase,
                             unsigned char **ppbEncoded,
                             size_t *pcbEncoded,
                             int tryLoadRSA, int tryLoadDSA)
{
    unsigned char *data = NULL;
    size_t datalen = 0;
    int ret = -1;

    if(ret && tryLoadRSA) {
        ret = _libssh2_wincng_load_pem(session, filename, passphrase,
                                       PEM_RSA_HEADER, PEM_RSA_FOOTER,
                                       &data, &datalen);
    }

    if(ret && tryLoadDSA) {
        ret = _libssh2_wincng_load_pem(session, filename, passphrase,
                                       PEM_DSA_HEADER, PEM_DSA_FOOTER,
                                       &data, &datalen);
    }

    if(!ret) {
        *ppbEncoded = data;
        *pcbEncoded = datalen;
    }

    return ret;
}