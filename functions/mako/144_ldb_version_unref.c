ldb_version_unref(ldb_version_t *ver) {
  assert(ver != &ver->vset->dummy_versions);
  assert(ver->refs >= 1);

  --ver->refs;

  if (ver->refs == 0)
    ldb_version_destroy(ver);
}