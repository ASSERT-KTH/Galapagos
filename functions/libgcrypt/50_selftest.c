selftest(void)
{
  ARCFOUR_context ctx;
  byte scratch[16];

  /* Test vector from Cryptlib labeled there: "from the
     State/Commerce Department". */
  static const byte key_1[] =
    { 0x61, 0x8A, 0x63, 0xD2, 0xFB };
  static const byte plaintext_1[] =
    { 0xDC, 0xEE, 0x4C, 0xF9, 0x2C };
  static const byte ciphertext_1[] =
    { 0xF1, 0x38, 0x29, 0xC9, 0xDE };

  arcfour_setkey( &ctx, key_1, sizeof(key_1), NULL);
  encrypt_stream( &ctx, scratch, plaintext_1, sizeof(plaintext_1));
  if ( memcmp (scratch, ciphertext_1, sizeof (ciphertext_1)))
    return "Arcfour encryption test 1 failed.";
  arcfour_setkey( &ctx, key_1, sizeof(key_1), NULL);
  encrypt_stream(&ctx, scratch, scratch, sizeof(plaintext_1)); /* decrypt */
  if ( memcmp (scratch, plaintext_1, sizeof (plaintext_1)))
    return "Arcfour decryption test 1 failed.";
  return NULL;
}