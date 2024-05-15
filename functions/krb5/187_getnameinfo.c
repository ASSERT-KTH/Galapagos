int getnameinfo (const struct sockaddr *sa, socklen_t len,
                 char *host, socklen_t hostlen,
                 char *service, socklen_t servicelen,
                 int flags)
{
    return fake_getnameinfo(sa, len, host, hostlen, service, servicelen,
                            flags);
}