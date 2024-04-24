static void hexdump(const void *a, size_t len) {
  const unsigned char *in = (const unsigned char *)a;
  for (size_t i = 0; i < len; i++) {
    printf("%02x", in[i]);
  }

  printf("\n");
}