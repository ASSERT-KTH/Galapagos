libssh2_session_handshake(LIBSSH2_SESSION *session, libssh2_socket_t sock)
{
    int rc;

    BLOCK_ADJUST(rc, session, session_startup(session, sock));

    return rc;
}