BIO *BIO_new_file(const char *filename, const char *mode)
{
    BIO  *ret;
    FILE *file = openssl_fopen(filename, mode);
    int fp_flags = BIO_CLOSE;

    if (strchr(mode, 'b') == NULL)
        fp_flags |= BIO_FP_TEXT;

    if (file == NULL) {
        ERR_raise_data(ERR_LIB_SYS, get_last_sys_error(),
                       "calling fopen(%s, %s)",
                       filename, mode);
        if (errno == ENOENT
#ifdef ENXIO
            || errno == ENXIO
#endif
            )
            ERR_raise(ERR_LIB_BIO, BIO_R_NO_SUCH_FILE);
        else
            ERR_raise(ERR_LIB_BIO, ERR_R_SYS_LIB);
        return NULL;
    }
    if ((ret = BIO_new(BIO_s_file())) == NULL) {
        fclose(file);
        return NULL;
    }

    /* we did fopen -> we disengage UPLINK */
    BIO_clear_flags(ret, BIO_FLAGS_UPLINK_INTERNAL);
    BIO_set_fp(ret, file, fp_flags);
    return ret;
}