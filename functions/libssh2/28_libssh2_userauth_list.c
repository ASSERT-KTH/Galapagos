libssh2_userauth_list(LIBSSH2_SESSION * session, const char *user,
                      unsigned int user_len)
{
    char *ptr;
    BLOCK_ADJUST_ERRNO(ptr, session,
                       userauth_list(session, user, user_len));
    return ptr;
}