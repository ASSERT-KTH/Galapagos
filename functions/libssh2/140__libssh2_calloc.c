void *_libssh2_calloc(LIBSSH2_SESSION* session, size_t size)
{
    void *p = LIBSSH2_ALLOC(session, size);
    if(p) {
        memset(p, 0, size);
    }
    return p;
}