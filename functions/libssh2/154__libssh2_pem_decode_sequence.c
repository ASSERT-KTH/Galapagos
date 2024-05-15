_libssh2_pem_decode_sequence(unsigned char **data, size_t *datalen)
{
    size_t len;
    int lenlen;

    if(*datalen < 1) {
        return -1;
    }

    if((*data)[0] != '\x30') {
        return -1;
    }

    (*data)++;
    (*datalen)--;

    lenlen = read_asn1_length(*data, *datalen, &len);
    if(lenlen < 0 || lenlen + len != *datalen) {
        return -1;
    }

    *data += lenlen;
    *datalen -= lenlen;

    return 0;
}