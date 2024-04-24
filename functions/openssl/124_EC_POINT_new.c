EC_POINT *EC_POINT_new(const EC_GROUP *group) {
  if (group == NULL) {
    OPENSSL_PUT_ERROR(EC, ERR_R_PASSED_NULL_PARAMETER);
    return NULL;
  }

  EC_POINT *ret = OPENSSL_malloc(sizeof *ret);
  if (ret == NULL) {
    OPENSSL_PUT_ERROR(EC, ERR_R_MALLOC_FAILURE);
    return NULL;
  }

  ret->group = EC_GROUP_dup(group);
  ec_GFp_simple_point_init(&ret->raw);
  return ret;
}