libssh2_session_free(LIBSSH2_SESSION * session)
{
    int rc;

    BLOCK_ADJUST(rc, session, session_free(session));

    return rc;
}