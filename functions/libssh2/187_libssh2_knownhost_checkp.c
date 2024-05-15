libssh2_knownhost_checkp(LIBSSH2_KNOWNHOSTS *hosts,
                         const char *hostp, int port,
                         const char *key, size_t keylen,
                         int typemask,
                         struct libssh2_knownhost **ext)
{
    return knownhost_check(hosts, hostp, port, key, keylen,
                           typemask, ext);
}