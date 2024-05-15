libssh2_userauth_keyboard_interactive_ex(LIBSSH2_SESSION *session,
                                         const char *user,
                                         unsigned int user_len,
                                         LIBSSH2_USERAUTH_KBDINT_RESPONSE_FUNC
                                             ((*response_callback)))
{
    int rc;
    BLOCK_ADJUST(rc, session,
                 userauth_keyboard_interactive(session, user, user_len,
                                               response_callback));
    return rc;
}