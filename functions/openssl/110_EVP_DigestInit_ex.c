int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, ENGINE *engine) {
  if (ctx->digest != type) {
    assert(type->ctx_size != 0);
    uint8_t *md_data = OPENSSL_malloc(type->ctx_size);
    if (md_data == NULL) {
      OPENSSL_PUT_ERROR(DIGEST, ERR_R_MALLOC_FAILURE);
      return 0;
    }

    OPENSSL_free(ctx->md_data);
    ctx->md_data = md_data;
    ctx->digest = type;
  }

  assert(ctx->pctx == NULL || ctx->pctx_ops != NULL);

  ctx->digest->init(ctx);
  return 1;
}