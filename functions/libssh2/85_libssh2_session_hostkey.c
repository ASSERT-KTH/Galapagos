libssh2_session_hostkey(LIBSSH2_SESSION *session, size_t *len, int *type)
{
    if(session->server_hostkey_len) {
        if(len)
            *len = session->server_hostkey_len;
        if(type)
            *type = hostkey_type(session->server_hostkey,
                                 session->server_hostkey_len);
        return (char *) session->server_hostkey;
    }
    if(len)
        *len = 0;
    return NULL;
}