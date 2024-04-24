BN_CTX *BN_CTX_new(void) {
  BN_CTX *ret = OPENSSL_malloc(sizeof(BN_CTX));
  if (!ret) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    return NULL;
  }

  // Initialise the structure
  ret->bignums = NULL;
  BN_STACK_init(&ret->stack);
  ret->used = 0;
  ret->error = 0;
  ret->defer_error = 0;
  return ret;
}