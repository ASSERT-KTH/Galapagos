int OBJ_obj2nid(const ASN1_OBJECT *obj) {
  if (obj == NULL) {
    return NID_undef;
  }

  if (obj->nid != 0) {
    return obj->nid;
  }

  CRYPTO_STATIC_MUTEX_lock_read(&global_added_lock);
  if (global_added_by_data != NULL) {
    ASN1_OBJECT *match;

    match = lh_ASN1_OBJECT_retrieve(global_added_by_data, obj);
    if (match != NULL) {
      CRYPTO_STATIC_MUTEX_unlock_read(&global_added_lock);
      return match->nid;
    }
  }
  CRYPTO_STATIC_MUTEX_unlock_read(&global_added_lock);

  const uint16_t *nid_ptr =
      bsearch(obj, kNIDsInOIDOrder, OPENSSL_ARRAY_SIZE(kNIDsInOIDOrder),
              sizeof(kNIDsInOIDOrder[0]), obj_cmp);
  if (nid_ptr == NULL) {
    return NID_undef;
  }

  return kObjects[*nid_ptr].nid;
}