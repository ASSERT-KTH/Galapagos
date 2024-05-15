libssh2_userauth_password_ex(LIBSSH2_SESSION *session, const char *username,
                             unsigned int username_len, const char *password,
                             unsigned int password_len,
                             LIBSSH2_PASSWD_CHANGEREQ_FUNC
                             ((*passwd_change_cb)))
{
    int rc;
    BLOCK_ADJUST(rc, session,
                 userauth_password(session, username, username_len,
                                   (unsigned char *)password, password_len,
                                   passwd_change_cb));
    return rc;
}