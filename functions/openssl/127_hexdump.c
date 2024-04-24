OPENSSL_UNUSED static void hexdump(const void *void_in, size_t len) {
  const uint8_t *in = (const uint8_t *)void_in;
  for (size_t i = 0; i < len; i++) {
    printf("%02x", in[i]);
  }
  printf("\n");
}