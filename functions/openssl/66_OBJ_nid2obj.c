ASN1_OBJECT *OBJ_nid2obj(int nid) {
  if (nid >= 0 && nid < NUM_NID) {
    if (nid != NID_undef && kObjects[nid].nid == NID_undef) {
      goto err;
    }
    return (ASN1_OBJECT *)&kObjects[nid];
  }

  CRYPTO_STATIC_MUTEX_lock_read(&global_added_lock);
  if (global_added_by_nid != NULL) {
    ASN1_OBJECT *match, template;

    template.nid = nid;
    match = lh_ASN1_OBJECT_retrieve(global_added_by_nid, &template);
    if (match != NULL) {
      CRYPTO_STATIC_MUTEX_unlock_read(&global_added_lock);
      return match;
    }
  }
  CRYPTO_STATIC_MUTEX_unlock_read(&global_added_lock);

err:
  OPENSSL_PUT_ERROR(OBJ, OBJ_R_UNKNOWN_NID);
  return NULL;
}