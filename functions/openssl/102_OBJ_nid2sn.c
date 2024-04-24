const char *OBJ_nid2sn(int nid) {
  const ASN1_OBJECT *obj = OBJ_nid2obj(nid);
  if (obj == NULL) {
    return NULL;
  }

  return obj->sn;
}