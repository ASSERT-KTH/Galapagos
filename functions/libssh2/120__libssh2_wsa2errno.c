int _libssh2_wsa2errno(void)
{
    switch(WSAGetLastError()) {
    case WSAEWOULDBLOCK:
        return EAGAIN;

    case WSAENOTSOCK:
        return EBADF;

    case WSAEINTR:
        return EINTR;

    default:
        /* It is most important to ensure errno does not stay at EAGAIN
         * when a different error occurs so just set errno to a generic
         * error */
        return EIO;
    }
}