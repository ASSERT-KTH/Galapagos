libssh2_userauth_publickey_fromfile_ex(LIBSSH2_SESSION *session,
                                       const char *user,
                                       unsigned int user_len,
                                       const char *publickey,
                                       const char *privatekey,
                                       const char *passphrase)
{
    int rc;

    if(!passphrase)
        /* if given a NULL pointer, make it point to a zero-length
           string to save us from having to check this all over */
        passphrase = "";

    BLOCK_ADJUST(rc, session,
                 userauth_publickey_fromfile(session, user, user_len,
                                             publickey, privatekey,
                                             passphrase));
    return rc;
}