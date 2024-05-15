client_addr(SVCXPRT *xprt)
{
    static char abuf[128];
    struct sockaddr_storage ss;
    socklen_t len = sizeof(ss);
    const char *p = NULL;

    if (getpeername(xprt->xp_sock, ss2sa(&ss), &len) != 0)
        return "(unknown)";
    if (ss2sa(&ss)->sa_family == AF_INET)
        p = inet_ntop(AF_INET, &ss2sin(&ss)->sin_addr, abuf, sizeof(abuf));
    else if (ss2sa(&ss)->sa_family == AF_INET6)
        p = inet_ntop(AF_INET6, &ss2sin6(&ss)->sin6_addr, abuf, sizeof(abuf));
    return (p == NULL) ? "(unknown)" : p;
}