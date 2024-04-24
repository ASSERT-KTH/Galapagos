BIO *BIO_new_file(const char *filename, const char *mode) {
  BIO *ret;
  FILE *file;

  file = fopen(filename, mode);
  if (file == NULL) {
    OPENSSL_PUT_SYSTEM_ERROR();

    ERR_add_error_data(5, "fopen('", filename, "','", mode, "')");
    if (errno == ENOENT) {
      OPENSSL_PUT_ERROR(BIO, BIO_R_NO_SUCH_FILE);
    } else {
      OPENSSL_PUT_ERROR(BIO, BIO_R_SYS_LIB);
    }
    return NULL;
  }

  ret = BIO_new_fp(file, BIO_CLOSE);
  if (ret == NULL) {
    fclose(file);
    return NULL;
  }

  return ret;
}