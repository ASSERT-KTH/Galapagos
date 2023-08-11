#include <assert.h>

void btc_free(void *ptr) {
  /* assert is used instead of abort on null pointer scenario */
  assert(ptr != NULL);
  free(ptr);
}