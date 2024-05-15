libssh2_scp_recv2(LIBSSH2_SESSION *session, const char *path,
                  libssh2_struct_stat *sb)
{
    LIBSSH2_CHANNEL *ptr;
    BLOCK_ADJUST_ERRNO(ptr, session, scp_recv(session, path, sb));
    return ptr;
}