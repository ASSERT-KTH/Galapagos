void _libssh2_string_buf_free(LIBSSH2_SESSION *session, struct string_buf *buf)
{
    if(!buf)
        return;

    if(buf->data)
        LIBSSH2_FREE(session, buf->data);

    LIBSSH2_FREE(session, buf);
    buf = NULL;
}