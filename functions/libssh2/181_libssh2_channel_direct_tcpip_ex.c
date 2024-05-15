libssh2_channel_direct_tcpip_ex(LIBSSH2_SESSION *session, const char *host,
                                int port, const char *shost, int sport)
{
    LIBSSH2_CHANNEL *ptr;

    if(!session)
        return NULL;

    BLOCK_ADJUST_ERRNO(ptr, session,
                       channel_direct_tcpip(session, host, port,
                                            shost, sport));
    return ptr;
}