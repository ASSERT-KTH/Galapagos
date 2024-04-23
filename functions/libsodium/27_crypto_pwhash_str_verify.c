crypto_pwhash_str_verify(const char * str,
                         const char * const passwd,
                         unsigned long long passwdlen)
{
    if (strncmp(str, crypto_pwhash_argon2id_STRPREFIX,
                sizeof crypto_pwhash_argon2id_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2id_str_verify(str, passwd, passwdlen);
    }
    if (strncmp(str, crypto_pwhash_argon2i_STRPREFIX,
                sizeof crypto_pwhash_argon2i_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2i_str_verify(str, passwd, passwdlen);
    }
    errno = EINVAL;

    return -1;
}