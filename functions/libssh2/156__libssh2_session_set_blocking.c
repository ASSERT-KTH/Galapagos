_libssh2_session_set_blocking(LIBSSH2_SESSION *session, int blocking)
{
    int bl = session->api_block_mode;
    _libssh2_debug((session, LIBSSH2_TRACE_CONN,
                   "Setting blocking mode %s", blocking ? "ON" : "OFF"));
    session->api_block_mode = blocking;

    return bl;
}