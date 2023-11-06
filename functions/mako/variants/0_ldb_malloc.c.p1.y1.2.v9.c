1. Simple without variable intermediate storage:


ldb_malloc(size_t size) {
  void *ptr = NULL;

  if ((ptr = malloc(size)) == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


2. Explicit suppression to calloc:


ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


3. Swap null check logic:


ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr != NULL)
    return ptr;

  abort(); /* LCOV_EXCL_LINE */
}


4. Apply bit operations instead of logical comparison:


ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


5. Three-array element with assign-check strategy:


ldb_malloc(size_t size) {
  void *ptr[3];

  ptr[0] = ptr[1] = ptr[2] = malloc(size);

  if (!ptr[0] || !ptr[1] || !ptr[2])
    abort(); /* LCOV_EXCL_LINE */

  return ptr[0];
}
