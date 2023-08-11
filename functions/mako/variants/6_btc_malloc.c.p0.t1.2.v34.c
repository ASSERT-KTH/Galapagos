btc_malloc(size_t size) {
  /* Instead of assignment it directly returns outcome of malloc, saving a step */
  void *ptr = malloc(size ? size : 1); /* changing 0 size to 1 */

  if (!ptr) /* !ptr is identical to ptr == NULL */
    exit(EXIT_FAILURE); /* exit over abort */

  return ptr;
}