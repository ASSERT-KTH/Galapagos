libssh2_channel_forward_listen_ex(LIBSSH2_SESSION *session, const char *host,
                                  int port, int *bound_port, int queue_maxsize)
{
    LIBSSH2_LISTENER *ptr;

    if(!session)
        return NULL;

    BLOCK_ADJUST_ERRNO(ptr, session,
                       channel_forward_listen(session, host, port, bound_port,
                                              queue_maxsize));
    return ptr;
}