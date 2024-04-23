int BIO_free(BIO *bio) {
  BIO *next_bio;

  for (; bio != NULL; bio = next_bio) {
    if (!CRYPTO_refcount_dec_and_test_zero(&bio->references)) {
      return 0;
    }

    next_bio = BIO_pop(bio);

    if (bio->method != NULL && bio->method->destroy != NULL) {
      bio->method->destroy(bio);
    }

    OPENSSL_free(bio);
  }
  return 1;
}