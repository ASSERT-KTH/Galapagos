libssh2_knownhost_readfile(LIBSSH2_KNOWNHOSTS *hosts,
                           const char *filename, int type)
{
    FILE *file;
    int num = 0;
    char buf[4092];

    if(type != LIBSSH2_KNOWNHOST_FILE_OPENSSH)
        return _libssh2_error(hosts->session,
                              LIBSSH2_ERROR_METHOD_NOT_SUPPORTED,
                              "Unsupported type of known-host information "
                              "store");

    file = fopen(filename, FOPEN_READTEXT);
    if(file) {
        while(fgets(buf, sizeof(buf), file)) {
            if(libssh2_knownhost_readline(hosts, buf, strlen(buf), type)) {
                num = _libssh2_error(hosts->session, LIBSSH2_ERROR_KNOWN_HOSTS,
                                     "Failed to parse known hosts file");
                break;
            }
            num++;
        }
        fclose(file);
    }
    else
        return _libssh2_error(hosts->session, LIBSSH2_ERROR_FILE,
                              "Failed to open file");

    return num;
}