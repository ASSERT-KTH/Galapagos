_libssh2_pem_decode_integer(unsigned char **data, size_t *datalen,
                            unsigned char **i, unsigned int *ilen)
{
    size_t len;
    int lenlen;

    if(*datalen < 1) {
        return -1;
    }

    if((*data)[0] != '\x02') {
        return -1;
    }

    (*data)++;
    (*datalen)--;

    lenlen = read_asn1_length(*data, *datalen, &len);
    if(lenlen < 0 || lenlen + len > *datalen) {
        return -1;
    }

    *data += lenlen;
    *datalen -= lenlen;

    *i = *data;
    *ilen = (unsigned int)len;

    *data += len;
    *datalen -= len;

    return 0;
}