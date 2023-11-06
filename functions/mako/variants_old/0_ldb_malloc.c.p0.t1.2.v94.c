size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL) {
    puts("Out of memory"); /* user could determine why the program failed */
    exit(1); /* changing from abort() to exit(), which won't cause ctrap on many platforms*/
  }

  memset(ptr, 0, size + 1); /* Initialize memory to zero. */

  return ptr;
}