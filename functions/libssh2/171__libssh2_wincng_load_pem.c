_libssh2_wincng_load_pem(LIBSSH2_SESSION *session,
                         const char *filename,
                         const unsigned char *passphrase,
                         const char *headerbegin,
                         const char *headerend,
                         unsigned char **data,
                         size_t *datalen)
{
    FILE *fp;
    int ret;

    fp = fopen(filename, FOPEN_READTEXT);
    if(!fp) {
        return -1;
    }

    ret = _libssh2_pem_parse(session, headerbegin, headerend,
                             passphrase,
                             fp, data, datalen);

    fclose(fp);

    return ret;
}