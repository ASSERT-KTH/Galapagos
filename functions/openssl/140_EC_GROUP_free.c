void EC_GROUP_free(EC_GROUP *group) {
  if (group == NULL ||
      // Built-in curves are static.
      group->curve_name != NID_undef ||
      !CRYPTO_refcount_dec_and_test_zero(&group->references)) {
    return;
  }

  if (group->meth->group_finish != NULL) {
    group->meth->group_finish(group);
  }

  ec_point_free(group->generator, 0 /* don't free group */);
  BN_free(&group->order);
  BN_MONT_CTX_free(group->order_mont);

  OPENSSL_free(group);
}