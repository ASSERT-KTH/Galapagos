_libssh2_wincng_load_private_memory(LIBSSH2_SESSION *session,
                                    const char *privatekeydata,
                                    size_t privatekeydata_len,
                                    const unsigned char *passphrase,
                                    unsigned char **ppbEncoded,
                                    size_t *pcbEncoded,
                                    int tryLoadRSA, int tryLoadDSA)
{
    unsigned char *data = NULL;
    size_t datalen = 0;
    int ret = -1;

    (void)passphrase;

    if(ret && tryLoadRSA) {
        ret = _libssh2_pem_parse_memory(session,
                                        PEM_RSA_HEADER, PEM_RSA_FOOTER,
                                        privatekeydata, privatekeydata_len,
                                        &data, &datalen);
    }

    if(ret && tryLoadDSA) {
        ret = _libssh2_pem_parse_memory(session,
                                        PEM_DSA_HEADER, PEM_DSA_FOOTER,
                                        privatekeydata, privatekeydata_len,
                                        &data, &datalen);
    }

    if(!ret) {
        *ppbEncoded = data;
        *pcbEncoded = datalen;
    }

    return ret;
}