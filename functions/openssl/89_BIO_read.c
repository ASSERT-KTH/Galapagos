int BIO_read(BIO *b, void *data, int dlen)
{
    size_t readbytes;
    int ret;

    if (dlen < 0)
        return 0;

    ret = bio_read_intern(b, data, (size_t)dlen, &readbytes);

    if (ret > 0) {
        /* *readbytes should always be <= dlen */
        ret = (int)readbytes;
    }

    return ret;
}