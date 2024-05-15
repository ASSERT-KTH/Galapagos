publickey_response_id(unsigned char **pdata, size_t data_len)
{
    size_t response_len;
    unsigned char *data = *pdata;
    const LIBSSH2_PUBLICKEY_CODE_LIST *codes = publickey_response_codes;

    if(data_len < 4) {
        /* Malformed response */
        return -1;
    }
    response_len = _libssh2_ntohu32(data);
    data += 4;
    data_len -= 4;
    if(data_len < response_len) {
        /* Malformed response */
        return -1;
    }

    while(codes->name) {
        if((unsigned long)codes->name_len == response_len &&
            strncmp(codes->name, (char *) data, response_len) == 0) {
            *pdata = data + response_len;
            return codes->code;
        }
        codes++;
    }

    return -1;
}