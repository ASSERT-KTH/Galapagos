gcry_create_nonce (void *buffer, size_t length)
{
  (void)buffer;
  (void)length;

  log_fatal ("unexpected call to gcry_create_nonce\n");
}